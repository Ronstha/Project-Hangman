//change color
void setcolor(unsigned short color)
{
 HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(hCon,color);
}
