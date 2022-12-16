#include <stdio.h>
#include <string.h>

#define ROUNDS 20

void main(){
    int item[10][200],p[10]={0},ins[10]={0};
    char op[10];
    int val[10],div[10],tru[10],fals[10];

    int m=0,j;
    char c, tmp[10];
    while(scanf("Monkey %d:\n", &j) == 1){
        scanf("Starting items: ");
        while(scanf("%d, ",&j) == 1)
            item[m][p[m]++]=j;

        scanf("Operation: new = old %c %s\n",&c,tmp);
        if(!strcmp("old",tmp)){
            op[m]= c == '+' ? 2 : 3;
        } else {
            op[m]= c == '+' ? 0 : 1;
            sscanf(tmp,"%d",&(val[m]));
        }

        scanf("Test: divisible by %d\n",&(div[m]));
        scanf("If true: throw to monkey %d\n",&(tru[m]));
        scanf("If false: throw to monkey %d\n",&(fals[m]));

        m++;
    }

    for(int i=0; i<ROUNDS; i++){
        for(int j=0;j<m;j++){
            for(int k=0; k<p[j];k++){
                ins[j]++;
                if(op[j] == 0){
                    item[j][k]+=val[j];
                } else if(op[j] == 1){
                    item[j][k]*=val[j];
                } else if(op[j] == 2){
                    item[j][k]+=item[j][k];
                } else if(op[j] == 3){
                    item[j][k]*=item[j][k];
                }
                item[j][k]/=3;
                if(!(item[j][k] % div[j]))
                    item[tru[j]][p[tru[j]]++] = item[j][k];
                else
                    item[fals[j]][p[fals[j]]++] = item[j][k];
            }
            p[j]=0;
        }

    }
    int max=0,max2=0,temp;
    for(int j=0;j<m;j++){
        temp=ins[j];
        if(ins[j]>max){
            temp=max;
            max=ins[j];
        }
        if(temp > max2)
            max2=temp;

        printf("ins[%d] = %d\n",j,ins[j]);
    }

    printf("max = %d, max2 = %d -> %d\n",max,max2,max*max2);
}
