
//goto position x,y in the console
void gotoxy(int x,int y){
  HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);

}
//set cursor visiblity on console
void cursorVisiblity(int bool)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;

   info.bVisible =bool;
   SetConsoleCursorInfo(consoleHandle, &info);
}