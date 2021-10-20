//Display High Score in Screen
#include <stdio.h>
struct HighScores
{
    char name[30];
    char Difficulty[20];
    int score;
};
struct HighScores hs[10];
void saveHighScore(char name[30], char difficulty[20], int score, int rank)
{
    FILE *ptr;
    ptr = fopen("highscore.txt", "w");
    int z = 0;
    while (z != 9)
    {
        if (rank == z)
        {
            fprintf(ptr, "%s %s %d\n", name, difficulty, score);
            if(z==8) break;
        }
        fprintf(ptr, "%s %s %d\n", hs[z].name, hs[z].Difficulty, hs[z].score);
        z += 1;
    }
    fclose(ptr);
}

int checkhighscore(int score)
{

    FILE *ptr;
    ptr = fopen("highscore.txt", "r");
    if (ptr == NULL)
    {
        return 0;
    }
    int i = 0,rank=-1;
    while (i != 10)
    {

        fscanf(ptr, "%s %s %d\n", hs[i].name, hs[i].Difficulty, &hs[i].score);
   
        if (hs[i].score <= score && rank<0)
        {
            
            rank=i;
        }
        i += 1;
    }
    fclose(ptr);

    return rank;
}

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
    gotoxy(5,0);
    printf("Name");
    gotoxy(30,0);
    printf("Difficulty");
    gotoxy(55,0);
    printf("Score");
while (i != 10)
    {

    

  fscanf(ptr, "%s %s %d\n", high.name, high.Difficulty, &high.score);
        
    gotoxy(5,i+1);
    printf("%s",high.name);
    gotoxy(30,i+1);
    printf("%s",high.Difficulty);
    gotoxy(55,i+1);
    printf("%d",high.score);
        i+=1;
 
    }
    fclose(ptr);
while(1){
    while(!kbhit()){

    }
    if(getch()==27) break;
}
}
}