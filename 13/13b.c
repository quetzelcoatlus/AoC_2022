#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 400

int is_digit(const char c){
    if(c>='0' && c<='9') return 1;

    return 0;
}

struct List{
    char* s;
    int n;
};

int compare_lists(const void *a, const void *b){
    struct List *l1 = (struct List*)a;
    struct List *l2 = (struct List*)b;
    char *s1=l1->s;
    int n1=l1->n;
    char *s2=l2->s;

    int depth, k[2], ret, j;
    char *p[2], *tmp, num[6];
    struct List lt[2];
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
                    lt[i].s=p[i];
                    for(tmp=lt[i].s+1,depth=0; *tmp!=']' || depth!=0; tmp++) depth += *tmp=='[' ? 1 : *tmp==']' ? -1 : 0;
                    lt[i].n = tmp-lt[i].s+1;
                } else { //number
                    (p[i])--;
                    for(j=0,tmp=p[i]; *tmp != ']' && *tmp != ','; tmp++) num[j++]=*tmp;
                    num[j++]=']';
                    num[j]=0;
                    lt[i].s=num;
                    lt[i].n = j;
                }
            }
            ret = compare_lists(&(lt[0]),&(lt[1]));

            for(int i=0;i<2;i++) p[i] += lt[i].n;

            if(ret !=0) return ret;
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

    struct List **list = malloc(sizeof(struct List*)*MAX_SIZE);
    int i=0;

    while ((nread = getline(&line, &len, stdin)) != -1 && (nread2 = getline(&line2, &len2, stdin)) != -1) {
        list[i]=malloc(sizeof(struct List));
        list[i]->s=strdup(line);
        list[i++]->n=nread-1;

        list[i]=malloc(sizeof(struct List));
        list[i]->s=strdup(line2);
        list[i++]->n=nread2-1;

        if(compare_lists(list[i-2],list[i-1]) <= 0) sum+=index;

        getline(&line,&len,stdin);
        index++;
    }
    list[i]=malloc(sizeof(struct List));
    list[i]->s=strdup("[[2]]\n");
    list[i++]->n=5;

    list[i]=malloc(sizeof(struct List));
    list[i]->s=strdup("[[6]]\n");
    list[i++]->n=5;

    printf("bede sortowac \n");

    qsort(list, i, sizeof(struct List*), compare_lists);

    for(int j=0; j<i; j++)
        printf("%d %d -> %d -> %s",i,j,list[j]->n,list[j]->s);

    for(int j=0; j<i; j++){
        free(list[j]->s);
        free(list[j]);
    }

    free(list);
    free(line);
    free(line2);

    printf("Sum = %d\n", sum);
}
