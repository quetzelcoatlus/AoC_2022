#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
    int a1,a2,b1,b2;
    int sum=0;

    while (scanf("%d-%d,%d-%d\n",&a1,&a2,&b1,&b2) != -1){
        if((a1>=b1 && a2<=b2) || (b1>=a1 && b2<=a2)){
            sum++;
        }
    }

    printf("%d\n",sum);
}

