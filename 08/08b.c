#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
    char tab[100][100];
    int i=0;

    while (scanf("%s\n",tab[i++]) == 1);

    int max=0;
    for(int i=0;i<99;i++){
        for(int j=0;j<99;j++){
            int l=0,r=0,u=0,d=0,k;
            for(k=j-1;k>=0 && tab[i][k] < tab[i][j];k--) l++;
            if(k>=0) l++;

            for(k=j+1;k<=98 && tab[i][k] < tab[i][j];k++) r++;
            if(k<=98) r++;

            for(k=i-1;k>=0 && tab[k][j] < tab[i][j];k--) u++;
            if(k>=0) u++;

            for(k=i+1;k<=98 && tab[k][j] < tab[i][j];k++) d++;
            if (k<=98) d++;

            if(l*r*u*d > max) max=l*r*u*d;
        }
    }

    printf("%d\n", max);
}

