#include <stdio.h>
#include "location.h"
#include "color.h"
#include <stdlib.h>
#include "start.h"

#include "game.h"
#include "exit.h"
#include "menu.h"
#include "instructions.h"
#include <windows.h>


int main()
{
    cursorVisiblity(0);

    SetConsoleTitle("Hangman");

    Welcome();
    getch();

    char a[4][20] = {"Start Game", "Instructions", "High Score", "Exit"};
    char b[3][20] = {"Easy", "Medium", "Hard"};
    while (1)
    {
        

        int c = menu(a, 4), diff;
        switch (c)
        {
        case 0:
        //Start Game
            
            diff = menu(b, 3);
            if(diff==-1){
                break;
            }
            StartGame(diff);
        
            break;
        case 1:
            //INstruction
            displayInstructions();
            break;
        case 2:
            //HighScore
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
