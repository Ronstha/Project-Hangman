//Display Instruction in screen
#include <stdio.h>
void displayInstructions(){
system("cls");
printf("Instructions");
while(1){
    while(!kbhit()){

    }
    if(getch()==27) break;
}
}