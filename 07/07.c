#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char type;
    int n;
    int p;
    char *name;
};

#define MAX_SIZE 1024
#define MAX_DEPTH 256
#define MAX_LENGTH 64

#define QUESTION_SIZE 100000

void main(){
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;


    struct Node *tree = malloc(sizeof(struct Node) * MAX_SIZE);

    int i=0;
    tree[i].type='d';
    tree[i].n=0;
    tree[i].p=-1;
    tree[i].name = strdup("/");

    int p=0;
    int parents[MAX_DEPTH];
    parents[p]=tree[i].n;

    char tmp[MAX_LENGTH];
    int j,d;

    while ((nread = getline(&line, &len, stdin)) != -1) {
        if(strstr(line, "$ cd /") != NULL){
            p=0;
        } else if(strstr(line, "$ ls") != NULL){
            continue;
        } else if(strstr(line, "$ cd ..") != NULL){
            p--;
        } else if(strstr(line, "$ cd") != NULL){
            sscanf(line, "$ cd %s\n", tmp);
            for(j=i; j>0; j--)
                if(tree[j].type == 'd' && tree[j].p == parents[p] && !strcmp(tmp,tree[j].name))
                    break;

            parents[++p] = j;
        } else if (strcmp("dir", line) < 0){
            sscanf(line, "dir %s\n", tmp);
            tree[++i].type='d';
            tree[i].n=0;
            tree[i].p=parents[p];
            tree[i].name=strdup(tmp);
        } else if(sscanf(line, "%d %s\n",&d,tmp) == 2){
            tree[++i].type='f';
            tree[i].n=d;
            tree[i].p=parents[p];
            tree[i].name=strdup(tmp);

            int temp_parent = parents[p];
            while(temp_parent != -1){
                tree[temp_parent].n+=d;
                temp_parent=tree[temp_parent].p;
            }
        } else {
            printf("Unrecognised line: |%s|\n", line);
        }
    }

    int sum=0;
    for(int j=0; j<=i; j++){
        if (tree[j].type == 'd' && tree[j].n <= QUESTION_SIZE)
           sum += tree[j].n;
        //printf("id=|%d| n=|%d| t=|%c| p=|%d| name=|%s|\n",j,tree[j].n,tree[j].type,tree[j].p,tree[j].name);
    }

    printf("%d\n",sum);

    for(int j=i; j>=0; j--)
        free(tree[j].name);

    free(tree);
    free(line);
}

