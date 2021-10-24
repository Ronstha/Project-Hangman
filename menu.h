#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



void renderMenu(char a[4][20],int len,int index){
  

    int i;
    for(i=0;i<len;i++){
        gotoxy(52,12+i);
        if(i==index%len){
            setcolor(12);
        }
        else{
            setcolor(15);
            
        }
        printf("%s\n",a[i]);
    }
        
    

}
int menu(char a[4][20],int len){
    system("cls");
    int index=0;
    char c;
    renderMenu(a,len,index);
    

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
    else if(c==27){
        return -1;
    }

    }
    
    

    }

    return 0;

}
