#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <string.h>

#define SIZE_OF_DATA 1000
#define DATA_BIT_LEN 12
#define MIDDLE_OF_DATA (SIZE_OF_DATA/2.0)
#define FILE_NAME "day3-data.txt"

uint32_t binToDec(char* Str)
{
    size_t Len=strlen(Str);
    int i;
    uint32_t Base=1,Dec=0;
    for(i=Len-1;i>=0;i--)
    {
        if(Str[i]=='1')
            Dec+=Base;
        Base*=2;
    }
    return Dec;
}

int main()
{
    FILE *fp;
    int i,j;
    int input;

    char buffer[16];

    uint32_t Data[SIZE_OF_DATA];
    uint32_t Temp=0,Temp2=0;

    int BitC[DATA_BIT_LEN];

    fp=fopen(FILE_NAME,"r");
    for(i=0;i<SIZE_OF_DATA;i++)
    {
        fscanf(fp,"%s",&buffer);
        Data[i]=binToDec(buffer);
    }
    fclose(fp);

    for(j=0;j<DATA_BIT_LEN;j++)
    {
        BitC[DATA_BIT_LEN-1-j]=0;
        for(i=0;i<SIZE_OF_DATA;i++)
        {
            if((Data[i]>>j)&1)BitC[DATA_BIT_LEN-1-j]++;
        }
    }

    for(j=0;j<DATA_BIT_LEN;j++)
    {
        printf("%d ",BitC[j]);
    }
    puts("\r");

    for(j=0;j<DATA_BIT_LEN;j++)
    {
        if(BitC[j]>MIDDLE_OF_DATA) 
        {
            Temp|=(1<<(DATA_BIT_LEN-1-j));
            putchar('1');
        }
        else
        {
            Temp2|=(1<<(DATA_BIT_LEN-1-j));
            putchar('0');
        }
    }

    printf("\r\n%d x %d = %ld\r\n",Temp,Temp2,Temp*Temp2);



    /*
    for(i=0;i<SIZE_OF_DATA;i++)
    {
        printf("%d ",Data[i]);
    }
    puts("\r\n");


    //sort max to min
    for(i=0;i<SIZE_OF_DATA;i++)
    {
        for(j=i+1;j<SIZE_OF_DATA;j++)
        {
            if(Data[i]<Data[j])
            {
                Temp=Data[i];
                Data[i]=Data[j];
                Data[j]=Temp;
            }
        }
    }

    for(i=0;i<SIZE_OF_DATA;i++)
    {
        printf("%d ",Data[i]);
    }
    puts("\r\n");
    */


    return 0;
}