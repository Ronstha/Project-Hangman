#include "hangman.h"
#include "highscore.h"
//structure for word and hint
struct word
{
    char word[100];
    char hint[100];
};
struct word words[1000];
//GameOver Screens
void GameOver(char difficulty[20], int score, char currentword[100], int gameover)
{
    system("cls");

    int i = 0;
    //draw complete hangman
    while (i < 6)
    {
        drawHangman(&i);
    }
    gotoxy(0, 0);
    setcolor(12);
    printf("!!Game Over!!\n");
    setcolor(14);
    printf("Your score is %d.\n", score);//display score
    setcolor(13);
    if (gameover == 2)//User Gussed all Words
    {

        printf("You have Completed the game!!");
    }
    else//Gameover
    {

        printf("The correct word is %s.\n", currentword);
    }
    int hs = checkhighscore(score);//check highscore 

    if (hs >= 0)//score in highscore
    {
        char name[30];
        setcolor(10);
        printf("!!New High Score!!\n");
        printf("Your Name:");
        cursorVisiblity(1);
        scanf("%s", name);//ask name
        saveHighScore(name, difficulty, score, hs);
        fseek(stdin, 0, SEEK_END);
        cursorVisiblity(0);
    }
    setcolor(8);
    printf("\nPress Any Key to Continue...");

    while (!kbhit()) //wait for keyboard input
    {
    }
}
//load word according to difficulty
int loadWords(char diff[20])
{
    FILE *fptr;
    char difficulty[20], q[100], c;
    strcpy(difficulty, diff);
    fptr = fopen(strcat(difficulty, ".txt"), "r");
    int i = 0, ec = 0, z = 0, m[1000], random;
    while (1)
    {
        i = 0;

        while ((c = fgetc(fptr)) != ',')
        {
            if (c == EOF)
            {
                ec = 1;
                break;
            }
            words[z].word[i] = c;
            i += 1;
        }
        if (ec == 1)
        {
            break;
        }
        i = 0;
        while ((c = fgetc(fptr)) != '\n')
        {
            if (c == EOF)
            {
                ec = 1;
                break;
            }
            words[z].hint[i] = c;
            i += 1;
            if (ec == 1)
            {
                break;
            }
        }

        z += 1;
    }
    fclose(fptr);
    return z;
}

void StartGame(int diff)
{
    char difficulty[20];
    switch (diff)
    {
    case 0:
        //easy  
        strcpy(difficulty, "easy");
        break;
    case 1:
        //medium
        strcpy(difficulty, "medium");
        break;
    case 2:
        //hard
        strcpy(difficulty, "hard");
        break;
    default:
        break;
    }
    srand(time(NULL));
    int count = loadWords(difficulty);//load word and return last index
    char currentword[100], currenthint[100], character, chars[30];
    int score = 0, mistakes, i, charcount, draw, correct, gameover = 0; //initialize score
    while (1)
    {
        int random = rand() % count; //random number
        mistakes = 0; //initialize mistakes
        strcpy(currentword, words[random].word);//copy word
        strcpy(currenthint, words[random].hint);//copy hint
        strcpy(words[random].hint, words[count - 1].hint);//copy word from last index to index of current word
        strcpy(words[random].word, words[count - 1].word);//copy hint from last index to index of current hint
        count -= 1;//decrement of index by 1
        correct = 0;//initialize correct guesses
        system("cls");
        setcolor(6); 
        printf("Difficulty=%s", difficulty);//display difficulty
        gotoxy(110, 0);
        setcolor(6); 
        printf("Score=%d", score);//display score
        gotoxy(43, 8);
        setcolor(11); 
        printf("Hint:%s", currenthint);//display hint
        gotoxy(43, 10);
        for (i = 0; i < strlen(currentword); i++)
        {
            setcolor(3); 
            if (currentword[i] != ' ')
            {
                printf("_ ");//display dashes for word to guess
            }
            else
            {
                printf("  ");
                correct += 1;
            }
        }
        gotoxy(5, 15);
        setcolor(13); 
        printf("Characters:");
        charcount = 0;//initialize valid character count
        while (1)
        {
            while (!kbhit())//wait for keyboard input
            {
            }
            character = getch();
    
            if ((character >= 97 && character <= 122) || (character >= 65 && character <= 90)) //only alphabetical character
            {

                if (character < 97)//upper case
                {
                    character += 32;//convert upper case to lower case alphabet
                }
                //check current character in previous character array
                for (i = 0; i < charcount; i++)
                {
                    if (chars[i] == character)
                    {
                        goto ctd;
                    }
                }

                chars[charcount] = character;//add current character to previous character arrayS
                charcount += 1;
                gotoxy(18, 15);
                setcolor(10); 
                //display entered characters in screen
                for (i = 0; i < charcount; i++)
                {

                    printf("%c, ", chars[i]);
                }
                draw = 1;//mistake:True
                setcolor(3);
                for (i = 0; i < strlen(currentword); i++)
                {
                    //check if current character is in current word
                    if (currentword[i] == character)
                    {
                        gotoxy(43 + (i * 2), 10);
                        correct += 1;
                        draw = 0;//mistake:false
                        printf("%c", character);//replace _ by character in required position
                    }
                }
                if (draw)//mistake
                {
                    drawHangman(&mistakes);

                    if (mistakes == 6)
                    {
                        gameover = 1;//gameover
                        break;
                    }
                }
            }
            if (correct == strlen(currentword))//Gussed all characters of current word
            {
                score += 15 - (mistakes * 2);//add (15-(2 x mistakes)) to score 
                break;
            }

        ctd:
            continue;
        }

        if (count == 1)//user guessed all words
        {

            gameover = 2;
        }

        if (gameover)
        {
            GameOver(difficulty, score, currentword, gameover);

            break;
        }
    }
}
