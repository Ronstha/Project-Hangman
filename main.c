#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "color.h"
#include "location.h"
#include "start.h"
#include "game.h"
#include "exit.h"
#include "menu.h"
#include "instructions.h"


int main()
{
    //hides cursor from console
    cursorVisiblity(0);

    SetConsoleTitle("Hangman");
    //show welcome screen
    Welcome();

    char a[4][20] = {"Start Game", "Instructions", "High Score", "Exit"};
    char b[3][20] = {"Easy", "Medium", "Hard"};

    while (1)
    {
        
        //display Start Menu
        int c = menu(a, 4,""), diff;

        switch (c)
        {
        case 0:
        
            //display difficulty menu    
            diff = menu(b, 3,"Difficulty");
            if(diff==-1){
                //go back to start menu
                break;
            }
            //start the game
            StartGame(diff);
        
            break;
        case 1:
            //show instruction
            displayInstructions();
            break;
        case 2:
            //show HighScore
            displayHighScore();
            break;
        case 3:
            //Exit

   
            exitScreen();
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}
