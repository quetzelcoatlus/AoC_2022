#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char line[3][256];
    int sum = 0;
    while (scanf("%s\n%s\n%s\n",&(line[0]),&(line[1]),&(line[2])) != -1){
        char badge[3][256] = {0};
        for(int j=0; j<3; j++){
            for(int i=0; i<strlen(line[j]); i++){
                (badge[j][line[j][i]])++;
            }
        }

        for(int i=0; i<256; i++)
            if(badge[0][i] > 0 && badge[1][i] > 0 &&badge[2][i] > 0){
                if(i >= 'a' && i <= 'z')
                    sum += i - 'a' + 1;
                else if (i >= 'A' && i <= 'Z')
                    sum += i - 'A' + 27;
            }
    }

    printf("%d\n",sum);
}

