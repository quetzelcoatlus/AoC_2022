#include <stdio.h>
#include <stdlib.h>

int resolve(char a, char b){
    if(a == 'A'){
        if(b == 'X')
            return 3;
        if(b == 'Y')
            return 4;
        if(b == 'Z')
            return 8;
    } else if(a == 'B'){
        if(b == 'X')
            return 1;
        if(b == 'Y')
            return 5;
        if(b == 'Z')
            return 9;
    } else if(a == 'C'){
        if(b == 'X')
            return 2;
        if(b == 'Y')
            return 6;
        if(b == 'Z')
            return 7;
    }
    return -9999999;
}

void main(){
    char a,b;
    int sum = 0;
    while (scanf("%c %c\n",&a,&b) != -1){
        sum+=resolve(a,b);
    }
    printf("%d\n",sum);
}

