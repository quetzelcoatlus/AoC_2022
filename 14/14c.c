#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 200

char tab[MAX_WIDTH][MAX_HEIGHT];

void main(){
    for(int i=0;i<MAX_WIDTH;i++)
        for(int j=0;j<MAX_HEIGHT;j++)
            tab[i][j]='.';

    tab[500][0] = '+';


    int dx1,dy1,dx2,dy2, maxy=-1;
    while(scanf("%d,%d",&dx1,&dy1) == 2){
        while(scanf(" -> %d,%d",&dx2,&dy2) == 2){
            if(dy1>maxy) maxy=dy1;
            if(dy2>maxy) maxy=dy2;
            if(dx1<=dx2) for(int i=dx1;i<=dx2;i++) tab[i][dy1]='#';
            if(dx1>=dx2) for(int i=dx1;i>=dx2;i--) tab[i][dy1]='#';
            if(dy1<=dy2) for(int i=dy1;i<=dy2;i++) tab[dx1][i]='#';
            if(dy1>=dy2) for(int i=dy1;i>=dy2;i--) tab[dx1][i]='#';
            dx1=dx2;
            dy1=dy2;
        }
    }

    for(int i=0;i<MAX_WIDTH;i++) tab[i][maxy+2]='#';

    int fell=0,k=0,sx=500,sy=0;
    while(!fell){
        if(tab[sx][sy+1] == '.'){
            sy++;
        } else if(tab[sx-1][sy+1] == '.'){
            sx--;
            sy++;
        } else if(tab[sx+1][sy+1] == '.'){
            sx++;
            sy++;
        } else {
            tab[sx][sy]='o';
            k++;
            sx=500;
            sy=0;
        }
        if(tab[500][0]=='o') fell=1;
    }

    printf("%d\n",k);
}
