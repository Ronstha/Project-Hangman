#include <stdio.h>
#include <stdlib.h>
#include "start.h"

#include "menu.h"
#include "game.h"
#include <windows.h>

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
int main()
{
    hidecursor();

    SetConsoleTitle("Project Hangman");

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
            diff = menu(b, 3);
            StartGame(diff);
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
    }

    return 0;
}
