#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int sum=0,n,first=1;
    char *front,*back,*p,*seen,max;
    char **pots;

    while ((nread = getline(&line, &len, stdin)) != -1) {
        //printf("%s",line);
        if(first == 1){
            n=nread-1;
            front=malloc(sizeof(char)*n);
            back=malloc(sizeof(char)*n);
            pots=malloc(sizeof(char*)*n);
            p=calloc(sizeof(char),n);
            for(int i=0;i<n;i++){
                front[i]=-1;
                back[i]=-1;
                pots[i]=malloc(sizeof(char)*10);
            }
            first=0;
        }
        seen=calloc(sizeof(char),n);

        //left
        max=-1;
        for(int i=0; i<n; i++){
            if(line[i]>max){
                sum++;
                seen[i]=1;
                max=line[i];
            }
        }
        //printf("1 -> %d\n",sum);

        //right
        max=-1;
        for(int i=n-1;i>0;i--){
            if(line[i] > max){
                max=line[i];
                if(!seen[i]){
                    sum++;
                    seen[i]=1;
                }
            }
        }
        //printf("2 -> %d\n",sum);
        for(int i=0; i<n; i++){
            //up
            if(line[i] > front[i]){
                front[i] = line[i];
                if(!seen[i]){
                    sum++;
                    seen[i]=1;
                }
            }

            //down
            if(line[i] < back[i]){
                if(!seen[i])
                    pots[i][(int)(p[i])++]=line[i];
            } else {
                while(p[i]>0 && line[i] >= pots[i][(int)p[i]-1])
                    (p[i])--;
                if(!seen[i])
                    pots[i][(int)(p[i])++]=line[i];
            }
            back[i]=line[i];
        }
        //printf("3 -> %d\n",sum);
        free(seen);
    }
    for(int i=0;i<n;i++){
        //printf("4-> [%d] -> %d\n",i,p[i]);
        free(pots[i]);
        sum += p[i];
    }

    printf("%d\n",sum);

    free(front);
    free(back);
    free(pots);

    free(line);
}

