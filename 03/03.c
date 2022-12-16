#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
    char line[256];
    int sum = 0;
    while (scanf("%s\n",&line) != -1){
        char left[256] = {0};
        char right[256] = {0};
        int l = strlen(line);
        for(int i=0; i<l; i++){
            if(i < l/2)
                left[line[i]]++;
            else
                right[line[i]]++;
        }

        for(int i=0; i<256; i++)
            if(left[i] > 0 && right[i] > 0){
                //printf("%s -> l[%c] = %d, r[%c]=%d\n",line,i,left[i],i,right[i]);
                if(i >= 'a' && i <= 'z')
                    sum += i - 'a' + 1;
                else if (i >= 'A' && i <= 'Z')
                    sum += i - 'A' + 27;
            }
    }

    printf("%d\n",sum);
}

