#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "location.h"
#include <conio.h>
#include <string.h>
#include "hangman.h"
// #include "gameover.h"
#include "highscore.h"
struct word
{
    char word[100];
    char hint[100];
};
struct word words[1000];

int loadWords()
{
    FILE *fptr;
    char a[20], q[100], c;
    fptr = fopen("word.txt", "r");
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
        strcpy(difficulty, "easy");
        //easy
        break;
    case 1:
        strcpy(difficulty, "medium");
        //medium
        break;
    case 2:
        strcpy(difficulty, "hard");
        //hard
        break;
    default:
        break;
    }
    srand(time(NULL));
    int count = loadWords();
    char currentword[100], currenthint[100], character, chars[30];
    int score = 0, mistakes, i, charcount, draw, correct, gameover = 0;
    while (1)
    {
        int random = rand() % count;
        mistakes = 0;
        strcpy(currentword, words[random].word);
        strcpy(currenthint, words[random].hint);
        strcpy(words[random].hint, words[count - 1].hint);
        strcpy(words[random].word, words[count - 1].word);
        count -= 1;
        correct = 0;
        system("cls");
        setcolor(6);// yellow
        printf("Difficulty=%s", difficulty);
        gotoxy(112, 0);
        setcolor(6);//purple
        printf("Score=%d", score);
        gotoxy(43, 8);
        setcolor(11);//blue
        printf("Hint:%s", currenthint);
        gotoxy(43, 10);
        for (i = 0; i < strlen(currentword); i++)
        {
            setcolor(3);//blue;
            if (currentword[i] != ' ')
            {
                printf("_ ");
            }
            else
            {
                printf("  ");
                correct += 1;
            }
        }
        gotoxy(5, 15);
        setcolor(13);//violet
        printf("Characters:");
        charcount = 0;
        while (1)
        {
            while (!kbhit())
            {
            }
            character = getch();
            // 97/65
            if ((character >= 97 && character <= 122) || (character >= 65 && character <= 90))
            {

                if (character < 97)
                {
                    character += 32;
                }

                for (i = 0; i < charcount; i++)
                {
                    if (chars[i] == character)
                    {
                        goto ctd;
                    }
                }
                chars[charcount] = character;
                charcount += 1;
                gotoxy(18, 15);
                setcolor(10);//green
                for (i = 0; i < charcount; i++)
                {

                    printf("%c, ", chars[i]);
                }
                draw = 1;
                setcolor(3);
                for (i = 0; i < strlen(currentword); i++)
                {
                    if (currentword[i] == character)
                    {
                        gotoxy(43 + (i * 2), 10);
                        correct += 1;
                        draw = 0;
                        printf("%c", character);
                    }
                }
                if (draw)
                {
                    drawHangman(&mistakes);

                    if (mistakes == 6)
                    {
                        gameover = 1;
                        break;
                    }
                }
            }
            if (correct == strlen(currentword))
            {
                score += 15-(mistakes*2);
                break;
            }

        ctd:
            continue;
        }

        if (count == 1)
        {

            break;
        }

        if (gameover)
        {

            system("cls");

           
            i=0;
            while(i<6){
                drawHangman(&i);
            }
            gotoxy(0,0);
            printf("!!Game Over!!\n");
            printf("Score=%d\n",score);
            printf("The correct word is %s.\n",currentword);
            int hs=checkhighscore(score);

            if(hs>=0){
                char name[30];
                printf("!!New High Score!!\n");
                printf("Your Name:");
                cursorVisiblity(1);
                scanf("%s",name);
                saveHighScore(name,difficulty,score,hs);
                fseek(stdin,0,SEEK_END);    
                cursorVisiblity(0);
                
            }
                printf("\nPress Any Key to Continue...");
        

            while (!kbhit())
            {
                /* code */
            }

            break;
        }
    }
}
