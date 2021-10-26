

void renderMenu(char a[4][20], int len, int index)
{
    //print menu on screen

    int i;
    for (i = 0; i < len; i++)
    {
        gotoxy(52, 12 + i); //goto position x,y on console
        if (i == index % len)
        {
            setcolor(12);
        }
        else
        {
            setcolor(15);
        }
        printf("%s\n", a[i]);
    }
}
int menu(char a[4][20], int len, char title[20])
{
    system("cls");
    setcolor(9);
    gotoxy(50, 11);
    printf("%s", title);
    int index = 0;
    char c;
    renderMenu(a, len, index);

    while (1)
    {
        if (kbhit())
        { //wait for keyboardinput
            c = getch();

            if (c == 119)
            { //W Key
                index -= 1;
                if (index < 0)
                    index = len - 1;

                renderMenu(a, len, index);
            }
            else if (c == 115)
            { //S Key
                index += 1;
                renderMenu(a, len, index);
            }
            else if (c == 13)
            { //Return Key
                return index % len;
            }
            else if (c == 27)
            { //Esc Key
                return -1;
            }
        }
    }

    return 0;
}
