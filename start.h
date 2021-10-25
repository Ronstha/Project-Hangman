#include <stdio.h>
#include <conio.h>

void Welcome(){
    
    int i=0;
setcolor(14);
 
 printf("\n\n\t\t\t\t  _    _                                          \n");
 printf("\t\t\t\t | |  | |                                         \n");
 printf("\t\t\t\t | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __   \n");
 printf("\t\t\t\t |  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\  \n");
 printf("\t\t\t\t | |  | | (_| | | | | (_| | | | | | | (_| | | | | \n");
 printf("\t\t\t\t |_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
 printf("\t\t\t\t                      __/ |                       \n");
 printf("\t\t\t\t                     |___/                        \n");
 
    while(!kbhit()){
      gotoxy(45,17);
      setcolor(i);
      printf("Press any Key to Start...");  
      i+=1;
      if(i==16) i=0;
   
    }
 

}
