#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void white(){
    printf("\033[0;37m");
}
void red(){
    printf("\033[0;31m");
}

void renderMenu(char a[4][20],int len,int index){
    system("cls");
    int i;
    for(i=0;i<len;i++){
        if(i==index%len){
            red();
        }
        else{
            white();
        }
        printf("%s\n",a[i]);
    }
    

}
int menu(char a[4][20],int len){
    int index=0;
    char c;
    renderMenu(a,len,index);
    
    // printf("%d",arr_length(a));
    while (1){
    if(kbhit()){
c=getch();
    if(c==119){
        index-=1;
        if(index<0) index=len-1;
     renderMenu(a,len,index);
    }
    else if(c==115){
        index+=1;
     renderMenu(a,len,index);
    
    }
    else if(c==13){
        return index%len;
    }
    }
    
    

    }

    return 0;

}
