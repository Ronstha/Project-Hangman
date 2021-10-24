#include "color.h"
#include <stdio.h>
int main(){
    int i;
    for(i=0;i<16;i++){  
        setcolor(i);
        printf("Color %d\n",i);
    }
    return 0;
}