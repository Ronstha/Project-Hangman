#include <stdio.h>
#include <stdlib.h>
#include "start.h"
// void Welcome();
#include "menu.h"
#include "game.h"

// #include "highscore.c"
// #include "instructions.c"
// void Welc`wome();
int main(){
    Welcome();
    getch();

    char a[4][20]={"Start Game","Instructions","High Score","Exit"};
    char b[3][20]={"Easy","Medium","Hard"};
    int c=menu(a  ,4);
    switch (c){
        case 0:
           menu(b  ,3);
           StartGame();
            //Start Game
           break;
        case 1:
        //INstruction
         break;
        case 2:
        //HighScore
         break;
        case 3:
        //Exit
         return 0;
         break;
        default:
         break;
    }
    // fseek(stdin,0,SEEK_END);
   
    // printf("%d",arr_length(a));
    
    return 0;

}
// StartScreen()
// while True:
//    choice=MEnu()
//    switch choice:
//      case 1{
//          Game()
//      }
//      case 2{
//          high()
//      }
//      case 3{
//          Instrctin()
//      }
//      case 4{
//          exit()
//      }

//StartScreen() :: start.c p
//while True
    //choice=Menu() ::menu.c
    //switch choice
        //Start Game
            //choice=Menu() ::menu.c
            //Start Game(Choice) ::game.c
        //High Score
            //highscore() ::highscore.c
        //Instruction
          //Instruction() :: instructions.c

        //Exit
            //Ask Do you want to exit()
            // break




