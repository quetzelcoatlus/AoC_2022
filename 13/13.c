#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_digit(const char c){
    if(c>='0' && c<='9') return 1;

    return 0;
}

int compare_lists(char* s1, int n1, char* s2){
    int depth, k[2], ret;
    char *p[2], *tmp;
    for(p[0]=s1+1,p[1]=s2+1; p[0]-s1<n1;){
        if(*(p[0]) == ']'){
            if(*(p[1]) == ']')
                return 0;
            return -1;
        } else if(*(p[1]) == ']'){
            return 1;
        } else if(is_digit(*(p[0])) && is_digit(*(p[1]))){
            for(int i=0;i<2;i++){
                sscanf(p[i],"%d",&(k[i]));
                for(; *(p[i]) != ']' && *(p[i]) != ','; (p[i])++);
            }
            if(k[0]>k[1]) return 1;
            if(k[0]<k[1]) return -1;
        } else { //list vs list || list vs number || number vs list
            for(int i=0;i<2;i++){
                if (*(p[i]) == '['){ //list
                    for(tmp=p[i]+1,depth=0; *tmp!=']' || depth!=0; tmp++) depth += *tmp=='[' ? 1 : *tmp==']' ? -1 : 0;
                } else { //number
                    *(--p[i])='[';
                    for(tmp=p[i]; *tmp != ']' && *tmp != ','; tmp++);
                    *tmp=']';
                }
                k[i] = tmp-p[i]+1;
            }
            if((ret = compare_lists(p[0],k[0],p[1])) != 0) return ret;

            for(int i=0;i<2;i++) p[i] += k[i];
        }
        for(int i=0;i<2;i++) if(*(p[i]) == ',') (p[i])++;
    }

    return -1; //s1 ran oob -> is lesser
}

void main(){
    char *line = NULL, *line2 = NULL;
    size_t len = 0, len2 = 0;
    ssize_t nread, nread2;

    int sum = 0, index = 1;

    while ((nread = getline(&line, &len, stdin)) != -1 && (nread2 = getline(&line2, &len2, stdin)) != -1) {
        if(compare_lists(line, nread-1, line2) <= 0) sum+=index;

        getline(&line,&len,stdin);
        index++;
    }
    free(line);
    free(line2);

    printf("%d\n", sum);
}
