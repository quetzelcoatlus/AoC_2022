#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(int pixel, int r){
    if(!(pixel%40)) printf("\n");

    pixel = pixel % 40;

    printf("%c", pixel>=r-1 && pixel<=r+1 ? '#' : ' ');
}

void main(){
    char op[10];
    int d=0;

    int pixel=0,regx=1;
    while(scanf("%s %d\n",op,&d) > 0){
        check(pixel,regx);
        if(!strcmp("noop",op)){
            pixel++;
        } else {
            check(++pixel,regx);
            pixel++;
            regx+=d;
        }
    }
}

