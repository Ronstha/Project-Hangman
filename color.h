#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void setcolor(unsigned short color)
{
 HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hCon,color);
}
