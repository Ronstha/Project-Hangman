#include <stdio.h>
#include<time.h>
#include <stdlib.h>
struct word{
char word[100];
char hint[100];
};

int main()
{
    srand(time(NULL));
    FILE *fptr;
    
    struct word words[1000];
    char a[20],q[100],c;
    fptr = fopen("word.txt","r");
    int i=0,ec=0,z=0,m[1000],random;
    while(1){
    i=0;

    while((c=fgetc(fptr))!=','){
        if(c==EOF){
            ec=1;
            break;
        }
        words[z].word[i]=c;
        i+=1;
    }
    if(ec==1){
        break;
    }
    i=0;
    while((c=fgetc(fptr))!='\n'){
           if(c==EOF){
            ec=1;
            break;
        }
        words[z].hint[i]=c;
   i+=1;
   if(ec==1){
        break;
    }
    }
    // printf("%s %s\n", words[z].word,words[z].hint);
    z+=1;
    }
    // i=0;

    for(i=0;i<100;i++){
    
    while(1){

    random=rand()%187;
    int x;
    for(x=0;x<i;x++){
        if (m[x]==random) continue;
    }
    break;
    }
    m[i]=random;
    printf("%s %s\n",words[random].word,words[random].hint);
    }




}