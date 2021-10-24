//Display Instruction in screen
#include <stdio.h>
void displayInstructions(){
system("cls");
gotoxy(45,1);
setcolor(3);
printf("!!INSTRUCTIONS!!\n\n\n");
setcolor(14);
printf(" - The objective of this game is to guess the word with the help of given Hint.\n\n");
printf(" - There are three difficulty level: Easy, Medium and Hard.\n\n");
printf(" - The word to guess is represented by a row of dashes, representing each letter of the word.\n\n");
printf(" - A letter of the alphabet should be entered.\n\n");
printf(" - If the word contains the entered letter then it will appear in its correct position.\n\n");
printf(" - If the word does not contain the entered letter then one element hangman figure wil be drawn.\n\n");
printf(" - The game will be over after six guesses and the diagram of hanged man will be seen.\n\n");
printf(" - 15 points will be scored if you are able to guess the word and 2 points will  be deducted for every wrong guess.");
setcolor(10);
printf("\n\n\n Esc=Back");
while(1){
    while(!kbhit()){

    }
    if(getch()==27) break;

}
}