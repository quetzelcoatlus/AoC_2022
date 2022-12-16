#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int BIG = 256;
    int n=0;
    char **data = NULL;
    char **p = NULL;

    while ((nread = getline(&line, &len, stdin)) != -1) {
        if(n == 0){
            n = (strlen(line)+1)/4;
            data = malloc(sizeof(char*)*n);
            p = malloc(sizeof(char*)*n);
            for(int i=0; i<n; i++){
                data[i] = calloc(sizeof(char), BIG);
                p[i] = &(data[i][BIG/2]);
            }
        }
        if (line[1] == '1')
            break;

        for(int i=0; i<n; i++)
            if(line[4*i+1] != ' ')
                *(p[i]++) = line[4*i+1];
    }

    for(int i=0; i<n; i++)
        while(*(p[i]-1))
            --p[i];

    if(getline(&line, &len, stdin) != 1)
        printf("WTF?");

    int a,b,c;
    while(scanf("move %d from %d to %d\n", &a, &b, &c) == 3){
        for(int i=a; i>0; i--)
           *(p[c-1]-i) = *(p[b-1]++);
        p[c-1] = p[c-1]-a;
    }

    for(int i=0; i<n; i++){
        printf("%c", *(p[i]));
    }

    for(int i=0; i<n; i++){
        free(data[i]);
    }
    free(data);
    free(p);
    free(line);
}

