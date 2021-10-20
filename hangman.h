#include <stdio.h>

void drawHangman(int *mistakes)
{
    *mistakes += 1;
    int j = 0;
    if (*mistakes == 1)
    {
        gotoxy(100, 4);
        printf("%c%c%c%c%c%c%c%c%c", 201, 20, 20, 20, 20, 20, 20, 20, 187);
        while (j < 16)
        {
            gotoxy(108, 5 + j);
            printf("%c", 186);
            j++;
        }
        gotoxy(105, 21);
        printf("%c%c%c%c%c%c%c", 205, 20, 20, 202, 205, 205, 205);
    }
    else if (*mistakes == 2)
    {
        //head
        gotoxy(99, 5);
        printf(" | ");
        gotoxy(99, 6);
        printf("0 0");
        gotoxy(99, 7);
        printf(" - ");
    }
    else if (*mistakes == 3)
    {
        //body
        gotoxy(100, 8);
        printf("|");
        gotoxy(100, 9);
        printf("|");
        gotoxy(100, 10);
        printf("|");
        gotoxy(100, 11);
        printf("|");
    }
    else if (*mistakes == 4)
    {
        //righthand
        gotoxy(101, 9);
        printf("\\");
        gotoxy(101, 10);
        printf(" \\ ");
    }
    else if (*mistakes == 5)
    {
        //left hand
        gotoxy(98, 9);
        printf(" /");
        gotoxy(98, 10);
        printf("/");
    }
    else if (*mistakes == 6)
    {
           //legs
    gotoxy(99,6);printf("x x");
    gotoxy(99,7);printf(" x ");
    gotoxy(99,12 );printf("_|_");
    gotoxy(99,13);printf("| |");
    gotoxy(99,14);printf("| |");
    gotoxy(99,15);printf("| |");
    gotoxy(99,16);printf("| |");
    }

}