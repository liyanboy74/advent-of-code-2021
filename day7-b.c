#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define DATA_LEN 1000
#define FILE_NAME "day7-data.txt"

int NumBuffer[DATA_LEN];
int miror[DATA_LEN];
unsigned int fuel[DATA_LEN];

void getNum(FILE *fp)
{
    int i=0;

    for(i=0;i<DATA_LEN;i++)
    {
        fscanf(fp,"%d,",&NumBuffer[i]);
    }
}

void printNum(uint32_t * Data)
{
    int i;
    for(i=0;i<DATA_LEN;i++)printf("%d ",Data[i]);
    printf("\r\n");
}

int main()
{
    FILE *fp;

    int i,j,s;
    int l,k;
    unsigned int Temp=0xffffffff;

    fp=fopen(FILE_NAME,"r");
    getNum(fp);

    for(i=0;i<DATA_LEN;i++)
    {
        for(j=0;j<DATA_LEN;j++)
        {
            miror[j]=0;
            l=abs(NumBuffer[i]-NumBuffer[j]);

            for(k=1;k<l+1;k++)
            {
                miror[j]=k+miror[j];
            }
        }

        fuel[i]=0;
        for(s=0;s<DATA_LEN;s++)
        {
            fuel[i]+=miror[s];
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

    //printNum(fuel);
    printf("Min Fuel is %ld at loc %d\r\n",Temp,NumBuffer[i]);

    //for(int j=i-10;j<i+20;j++)
    //printf("%ld\r\n",fuel[j]);

    fclose(fp);
    return 0;
}