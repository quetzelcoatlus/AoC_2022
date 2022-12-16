#include <stdio.h>
#include <stdlib.h>

#define SIGN(x) (((x) < 0) ? (-1) : (1))

#define MAX_SENSORS 25
#define QUESTION_CONSTANT 4000000

void main(){
    int sensors[MAX_SENSORS][3], s=0, bx, by;

    while(scanf("Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n",&(sensors[s][0]),&(sensors[s][1]),&bx,&by) == 4){
        sensors[s][2]=abs(sensors[s][0]-bx)+abs(sensors[s][1]-by);
        s++;
    }

    int x1,x2,y1,y2,qx,qy,good,k;
    for(int i=0; i<s;i++){
        for(int j=i+1;j<s;j++){
            if(abs(sensors[i][0]-sensors[j][0])+abs(sensors[i][1]-sensors[j][1]) == sensors[i][2]+sensors[j][2]+2){ //"neighbours"
                x1=sensors[i][0] + SIGN(sensors[j][0]-sensors[i][0])*(sensors[i][2]+1);
                y1=sensors[i][1];
                x2=sensors[i][0];
                y2=sensors[i][1] + SIGN(sensors[j][1]-sensors[i][1])*(sensors[i][2]+1);

                for(qx=x1,qy=y1; qx!=x2 && qy!=y2; qx+=SIGN(x2-x1),qy+=SIGN(y2-y1)){ //for every point between them
                    //check if this point is out of scan range of every scanner
                    for(good=1, k=0;k<s;k++) if(abs(qx-sensors[k][0])+abs(qy-sensors[k][1]) <= sensors[k][2]) good=0;
                    if(good) goto exit;
                }
            }
        }
    }

exit:
    printf("%d * %d + %d = %lld\n",qx,QUESTION_CONSTANT,qy,(long long)qx*QUESTION_CONSTANT+qy);
}
