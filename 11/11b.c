#include <stdio.h>
#include <string.h>

#define ROUNDS 10000
#define N 10

void main(){
    long int item[N][200],mul=1;
    int p[N]={0},ins[N]={0};
    char op[N];
    int val[N],div[N],tru[N],fals[N];

    int m=0,j;
    char c, tmp[N];
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
        mul*=div[m];
        scanf("If true: throw to monkey %d\n",&(tru[m]));
        scanf("If false: throw to monkey %d\n",&(fals[m]));

        m++;
    }

    for(int i=1; i<=ROUNDS; i++){
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
                item[j][k] %= mul;
                if(!(item[j][k] % div[j]))
                    item[tru[j]][p[tru[j]]++] = item[j][k];
                else
                    item[fals[j]][p[fals[j]]++] = item[j][k];
            }
            p[j]=0;
        }
    }
    long int max=0,max2=0,temp;
    for(int j=0;j<m;j++){
        temp=ins[j];
        if(ins[j]>max){
            temp=max;
            max=ins[j];
        }
        if(temp > max2)
            max2=temp;
    }

    printf("max = %ld, max2 = %ld -> %ld\n",max,max2,max*max2);
}
