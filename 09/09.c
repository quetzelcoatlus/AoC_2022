#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int near(int x1, int y1, int x2, int y2){
    return((abs(x1-x2)<=1 && abs(y1-y2)<=1));
}

void main(){
    char *been=calloc(sizeof(char),MAX_SIZE*MAX_SIZE);
    int sum=0;

    int hx=0,hy=0,tx=0,ty=0;

    char c;
    int d;
    while (scanf("%c %d\n",&c,&d) == 2){
        for(int k=0;k<d;k++){
            if(c == 'R') hx++;
            if(c == 'U') hy++;
            if(c == 'L') hx--;
            if(c == 'D') hy--;

            if(!near(hx,hy,tx,ty))
                for(int i=-1;i<=1;i++)
                    for(int j=-1;j<=1;j++)
                        if(abs(i)+abs(j)==1)
                            if(near(tx,ty,hx+i,hy+j)){
                                tx=hx+i;
                                ty=hy+j;
                                goto exit;
                            }

exit:
            been[MAX_SIZE/2+tx+(MAX_SIZE/2+ty)*MAX_SIZE]=1;
        }
    }
    for(int i=0; i<MAX_SIZE*MAX_SIZE;i++){
        sum+=been[i];
    }


    printf("%d\n", sum);

    free(been);
}

