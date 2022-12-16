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

    int tx[10]={0},ty[10]={0};

    char c;
    int d;
    while (scanf("%c %d\n",&c,&d) == 2){
        for(int k=0;k<d;k++){
            if(c == 'R') tx[0]++;
            if(c == 'U') ty[0]++;
            if(c == 'L') tx[0]--;
            if(c == 'D') ty[0]--;

            for(int l=0;l<9;l++){
                if(!near(tx[l],ty[l],tx[l+1],ty[l+1])){
                    for(int i=-1;i<=1;i++)
                        for(int j=-1;j<=1;j++)
                            if(abs(i)+abs(j)==1)
                                if(near(tx[l+1],ty[l+1],tx[l]+i,ty[l]+j)){
                                    tx[l+1]=tx[l]+i;
                                    ty[l+1]=ty[l]+j;
                                    goto next;
                                }
                    for(int i=-1;i<=1;i++)
                        for(int j=-1;j<=1;j++)
                            if(abs(i)+abs(j)==2)
                                if(near(tx[l+1],ty[l+1],tx[l]+i,ty[l]+j)){
                                    tx[l+1]=tx[l]+i;
                                    ty[l+1]=ty[l]+j;
                                    goto next;
                                }
                }
next:
                ;
            }

            been[MAX_SIZE/2+tx[9]+(MAX_SIZE/2+ty[9])*MAX_SIZE]=1;
        }
    }

    for(int i=0; i<MAX_SIZE*MAX_SIZE;i++){
        sum+=been[i];
    }


    printf("%d\n", sum);

    free(been);
}

