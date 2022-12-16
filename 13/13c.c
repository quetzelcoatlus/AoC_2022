#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 400

int is_digit(const char c){
    if(c>='0' && c<='9') return 1;

    return 0;
}

int compare_lists(char* s1, int n1, char* s2){
    int depth, k[2], u[2], ret, j;
    char *p[2], *tmp, *tp[2], num[6];

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
                    tp[i]=p[i];
                    for(tmp=tp[i]+1,depth=0; *tmp!=']' || depth!=0; tmp++) depth += *tmp=='[' ? 1 : *tmp==']' ? -1 : 0;
                    u[i] = k[i] = tmp-p[i]+1;
                } else { //number
                    j=0;
                    num[j++]='[';
                    for(tmp=p[i]; *tmp != ']' && *tmp != ','; tmp++) num[j++]=*tmp;
                    num[j++]=']';
                    num[j]=0;
                    k[i]=j;
                    u[i]=k[i]-2;
                    tp[i]=num;
                }
            }
            if((ret = compare_lists(tp[0],k[0],tp[1])) != 0) return ret;

            for(int i=0;i<2;i++) p[i] += u[i];
        }
        for(int i=0;i<2;i++) if(*(p[i]) == ',') (p[i])++;
    }

    return -1; //s1 ran oob -> is lesser
}

void main(){
    char *line = NULL, *line2 = NULL;
    size_t len = 0, len2 = 0;
    ssize_t nread, nread2;

    int sum=0, index=1;

    char list[MAX_SIZE][MAX_SIZE], tmp[MAX_SIZE];
    int n[MAX_SIZE], k=0;

    while ((nread = getline(&line, &len, stdin)) != -1 && (nread2 = getline(&line2, &len2, stdin)) != -1) {
        strcpy(list[k],line);
        n[k++]=nread-1;
        strcpy(list[k],line2);
        n[k++]=nread2-1;

        if(compare_lists(line, nread-1, line2) <= 0) sum+=index;

        getline(&line,&len,stdin);
        index++;
    }

    strcpy(list[k],"[[2]]");
    n[k++]=5;
    strcpy(list[k],"[[6]]");
    n[k++]=5;

    int tn,j;
    for(int i=1;i<k;i++){ //insertion sort
        strcpy(tmp,list[i]); tn=n[i];
        j = i-1;
        while(j >= 0 && compare_lists(list[j],n[j],tmp) > 0){
            strcpy(list[j+1],list[j]); n[j+1]=n[j];
            j--;
        }
        strcpy(list[j+1],tmp); n[j+1]=tn;
    }

    int mul=1;
    for(int i=0;i<k;i++){
        if(!(strcmp(list[i],"[[2]]")) || !(strcmp(list[i],"[[6]]"))) mul*=i+1;
        //printf("%d %d -> %d -> %s",k,i,n[i],list[i]);
    }

    free(line);
    free(line2);

    printf("Sum = %d\n", sum);
    printf("Mul = %d\n", mul);
}
