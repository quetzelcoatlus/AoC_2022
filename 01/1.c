#include <stdio.h>
#include <stdlib.h>



void main(){
    int max_sum = 0;
    int sum=0;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int d;

    while ((nread = getline(&line, &len, stdin)) != -1) {
        if (nread == 1){
            if (sum > max_sum){
                max_sum = sum;
            }
            sum = 0;
            continue;
        }

        sscanf(line, "%d", &d);
        sum+=d;
    }
    if (sum > max_sum){
        max_sum = sum;
    }

    printf("%d\n", max_sum);
    free(line);
}

