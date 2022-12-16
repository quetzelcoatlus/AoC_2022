#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#define MAX_SENSORS 25
#define QUESTION_Y 2000000

int compare_ranges(const void *r1, const void *r2){
    int a1 = *(int *)r1;
    int b1 = *(int *)(r1+sizeof(int));
    int a2 = *(int *)r2;
    int b2 = *(int *)(r2+sizeof(int));
    if(a1 < a2) return -1;
    if(a1 == a2) return b1-b2;
    return 1;
}

void main(){
    int range[MAX_SENSORS][2], r=0;
    int beacon[MAX_SENSORS], b=0;

    int sx,sy,bx,by,dist,found,i;
    while(scanf("Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n",&sx,&sy,&bx,&by) == 4){
        dist=abs(sx-bx)+abs(sy-by);
        if(dist>=abs(sy-QUESTION_Y)){
            range[r][0]=sx-(dist-abs(sy-QUESTION_Y));
            range[r++][1]=sx+(dist-abs(sy-QUESTION_Y));
        }
        if(by == QUESTION_Y) {
            for(found=0,i=0;i<b;i++) if(beacon[i]==bx) found=1;
            if(!found) beacon[b++]=bx;
        }
    }

    qsort(range,r,sizeof(int)*2,compare_ranges);

    for(i=0; i<r-1;i++){ //merge overlaping ranges
        if(range[i+1][0] >= range[i][0] && range[i+1][0] <= range[i][1]){
            range[i+1][0]=range[i][0];
            range[i+1][1]=MAX(range[i][1],range[i+1][1]);
            range[i][0]=0;
            range[i][1]=-1;
        }
    }

    int sum=0;
    for(i=0;i<r;i++){
        sum+=range[i][1]-range[i][0]+1;
        for(int j=0;j<b;j++) if(beacon[j]>=range[i][0] && beacon[j]<=range[i][1]) sum--;
    }

    printf("Sum = %d\n",sum);
}

