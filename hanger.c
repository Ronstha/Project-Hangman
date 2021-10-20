#include <stdio.h>
#include <stdlib.h>
#include "location.h"

int main()
{

  system("cls");
  int j = 0;
  gotoxy(100, 4);
  printf("%c%c%c%c%c%c%c%c%c", 201, 20, 20, 20, 20, 20, 20, 20, 187);
  while (j < 16)
  {
    gotoxy(108,5+j);
    printf("%c", 186);
    j++;
  }
gotoxy(105,21);
  printf("%c%c%c%c%c%c%c", 205, 20, 20, 202, 205, 205, 205);
  // head
  gotoxy(99, 5);
  printf(" | ");
  gotoxy(99, 6);
  printf("0 0");
  gotoxy(99, 7);
  printf(" - ");
  //body
  gotoxy(100,8);printf("|");
  gotoxy(100,9);
  printf("|");
  gotoxy(100,10);
  printf("|");
  gotoxy(100,11);
  printf("|");
  //righthand
   gotoxy(101,9);
      printf("\\");
    gotoxy(101,10);printf(" \\ ");
    //lefthands
       gotoxy(97,9);
      printf(" /");
    gotoxy(97,10);printf("/");
    //legs
    gotoxy(99,6);printf("x x");
    gotoxy(99,7);printf(" x ");
    gotoxy(99,12 );printf("_|_");
    gotoxy(99,13);printf("| |");
    gotoxy(99,14);printf("| |");
    gotoxy(99,15);printf("| |");
    gotoxy(99,16);printf("| |");
  while (1)
  {
  }
  return 0;
}