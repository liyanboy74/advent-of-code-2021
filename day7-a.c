#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define DATA_LEN 1000
#define FILE_NAME "day7-data.txt"

int NumBuffer[DATA_LEN];
int miror[DATA_LEN];
int fuel[DATA_LEN];

void getNum(FILE *fp)
{
    int i=0;

    for(i=0;i<DATA_LEN;i++)
    {
        fscanf(fp,"%d,",&NumBuffer[i]);
    }
}

void printNum(int * Data)
{
    int i;
    for(i=0;i<DATA_LEN;i++)printf("%d ",Data[i]);
    printf("\r\n");
}


int main()
{
    int i,j;
    FILE *fp;
    int Temp=0x0fffffff;

    fp=fopen(FILE_NAME,"r");
    getNum(fp);
    //printNum();

    for(i=0;i<DATA_LEN;i++)
    {
        for(j=0;j<DATA_LEN;j++)
        {
            miror[j]=abs(NumBuffer[i]-NumBuffer[j]);
        }

        fuel[i]=0;
        for(j=0;j<DATA_LEN;j++)
        {
            fuel[i]+=miror[j];
        }
    }

    for(j=0;j<DATA_LEN;j++)
    {
        if(fuel[j]<Temp)
        {
            Temp=fuel[j];
            i=j;
        }
    }

    printf("Min Fuel is %d at loc %d\r\n",Temp,NumBuffer[i]);

    fclose(fp);
    return 0;
}