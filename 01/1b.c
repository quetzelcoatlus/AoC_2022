#include <stdio.h>
#include <stdlib.h>



void main(){
    int max_sum[3] = {0};
    int sum = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int d;

    while ((nread = getline(&line, &len, stdin)) != -1) {
        if (nread == 1){
            for(int i=0; i<3; i++){
                if (sum > max_sum[i]){
                    int temp = max_sum[i];
                    for(int j=i+1; j<3; j++){
                        if (temp > max_sum[j]){
                            int temp2 = max_sum[j];
                            max_sum[j] = temp;
                            temp = temp2;
                        }
                    }
                    max_sum[i] = sum;
                    break;
                }
            }
            sum = 0;
            continue;
        }

        sscanf(line, "%d", &d);
        sum+=d;
    }
    for(int i=0; i<3; i++){
        if (sum > max_sum[i]){
            int temp = max_sum[i];
            for(int j=i+1; j<3; j++){
                if (temp > max_sum[j]){
                    int temp2 = max_sum[j];
                    max_sum[j] = temp;
                    temp = temp2;
                }
            }
            max_sum[i] = sum;
            break;
        }
    }
    sum = 0;
    for(int i=0; i<3; i++){
        sum += max_sum[i];
    }

    printf("%d\n", sum);
    free(line);
}

