#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 50

char tab[MAX_HEIGHT][MAX_WIDTH];
int values[MAX_HEIGHT][MAX_WIDTH];
int h=0,w;

void resolve(int y, int x, int val){
    if(x<0 || y<0 || x==w || y==h) return;
    val++;
    if(values[y][x] == -1 || val < values[y][x]){
        values[y][x] = val;

        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
                if(abs(i)+abs(j)==1)
                    if(tab[y+j][x+i] >= tab[y][x]-1)
                        resolve(y+j,x+i,val);
    }
}

void main(){
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int sx,sy,ex,ey;

    char *p;
    while ((nread = getline(&line, &len, stdin)) != -1) {
        w=nread-1;
        if((p=strstr(line,"S")) != NULL){
            sx=p-line;
            sy=h;
            *p='a';
        }
        if((p=strstr(line,"E")) != NULL){
            ex=p-line;
            ey=h;
            *p='z';
        }
        strncpy(tab[h],line,nread);
        h++;
    }

    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            values[i][j]=-1;


    resolve(ey,ex,-1);

    printf("val[%d][%d] = %d\n",sx,sy,values[sy][sx]);

}
