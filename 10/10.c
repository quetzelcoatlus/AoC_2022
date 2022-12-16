#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum=0;

int checks[] = {20,60,100,140,180,220};

void check(int cycle, int r){
    for(unsigned int k=0;k<sizeof(checks)/sizeof(checks[0]);k++)
        if(cycle == checks[k])
            sum+=cycle*r;
}

void main(){
    char op[10];
    int d=0;

    int cycle=1,regx=1;
    while(scanf("%s %d\n",op,&d) > 0){
        check(cycle,regx);
        if(!strcmp("noop",op)){
            cycle++;
        } else {
            check(++cycle,regx);
            regx+=d;
            cycle++;
        }
    }

    printf("%d\n", sum);
}

