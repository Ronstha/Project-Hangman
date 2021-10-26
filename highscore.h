//Display High Score in Screen
#include <stdio.h>
struct HighScores
{
    char name[30];
    char Difficulty[20];
    int score;
};
struct HighScores hs[10];//Structure for HighScore
//save high score
void saveHighScore(char name[30], char difficulty[20], int score, int rank)
{
    FILE *ptr;
    ptr = fopen("highscore.txt", "w"); //open text file in write mode
    int z = 0;
    while (z != 10)
    {
        if (rank == z)
        {
            fprintf(ptr, "%s %s %d\n", name, difficulty, score);
        
            if(z==9) break;
        }
        fprintf(ptr, "%s %s %d\n", hs[z].name, hs[z].Difficulty, hs[z].score);
        z += 1;
    }
    fclose(ptr);
}

//check highscore
int checkhighscore(int score)
{

    FILE *ptr;
    ptr = fopen("highscore.txt", "r");//open txt file in read mode
    if (ptr == NULL)
    {
        return 0;
    }
    int i = 0,rank=-1;//initialize i and rank
    while (i != 10)
    {

        fscanf(ptr, "%s %s %d\n", hs[i].name, hs[i].Difficulty, &hs[i].score); //load data 
   
          
        if (hs[i].score <= score && rank<0)//score is greater than or equal to loaded data
        {
            
            rank=i;
        }
        i += 1;
    }
    fclose(ptr); //close file

    return rank;//return rank of score,-1 if not highscore
}

//display Highscores
void displayHighScore(){
    FILE *ptr;
    ptr = fopen("highscore.txt", "r"); 
    if (ptr == NULL)
    {
      
    }
        else{
    int i=0;
    struct HighScores high;
    system("cls");
    setcolor(3);
    printf("%*s!!HighScores!!\n",28,"");              
    gotoxy(5,1);
    setcolor(15);
    printf("Name");
    gotoxy(30,1);
    printf("Difficulty");
    gotoxy(55,1);
    printf("Score");
    setcolor(14);
while (i != 10)
    {


  fscanf(ptr, "%s %s %d\n", high.name, high.Difficulty, &high.score);
        
    gotoxy(5,i+2);
    printf("%s",high.name);
    gotoxy(30,i+2);
    printf("%s",high.Difficulty);
    gotoxy(55,i+2);
    printf("%d",high.score);
        i+=1;
 
    }
    setcolor(10);
    gotoxy(3,i+4);
    printf("Esc=Back");
    fclose(ptr);
while(1){
    while(!kbhit()){//Wait for Keyboard input

    }
    if(getch()==27) break; //Esc Key
}
}
}