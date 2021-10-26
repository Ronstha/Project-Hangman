//Exit Screen
void exitScreen(){
    system("cls");

    setcolor(11);

 printf("  _    _                                         \n");
 printf(" | |  | |                                        \n");
 printf(" | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
 printf(" |  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
 printf(" | |  | | (_| | | | | (_| | | | | | | (_| | | | |\n");
 printf(" |_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n");
 printf("                      __/ |                      \n");
 printf("                     |___/                       \n");
 setcolor(8);
 printf("\n\n Created By:");
 setcolor(9);
 printf("\n Manoj Paudel THA077BCT025");
 printf("\n Prince Poudel THA077BCT036");
 printf("\n Ronish Shrestha THA077BCT040");
 printf("\n Sonish Poudel THA077BCT042");

    setcolor(14);
    cursorVisiblity(1);
    printf("\n\nPress any Key to exit...");
    while(!kbhit()){//wait for keyboard press

    }
}