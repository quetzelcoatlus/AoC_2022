#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int uniques(const char* str){
    char count[256] = {0};
    int c = 0;
    for(unsigned int i=0; i<strlen(str); i++){
        count[(int)str[i]]=1;
    }
    for(int i=0; i<256; i++)
        c += count[i];

    return c;
}

void main(){
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;


    while ((nread = getline(&line, &len, stdin)) != -1) {
        char *l=line;
        char tmp[15];
        while(*(l+13)){
            strncpy(tmp,l,14);
            if(uniques(tmp) == 14){
                printf("%s - %ld\n",tmp, l-line+14);
                break;
            }
            l++;
        }
    }
    free(line);
}
