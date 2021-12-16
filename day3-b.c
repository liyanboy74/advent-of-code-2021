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

void DecToBin(uint32_t Dec,size_t Len)
{
    int i;
    for(i=0;i<Len;i++)
    {
        if((Dec>>(Len-1-i))&1)putchar('1');
        else putchar('0');
    }
}

int main()
{
    FILE *fp;
    int a,i,j,c;
    int input;

    char buffer[16];

    uint32_t Data[DATA_BIT_LEN][SIZE_OF_DATA];
    int Data_Size[DATA_BIT_LEN];

    uint32_t Temp=0,Temp2=0;

    int BitC=0,BitL=0;
    int DS;

    fp=fopen(FILE_NAME,"r");
    for(i=0;i<SIZE_OF_DATA;i++)
    {
        fscanf(fp,"%s",&buffer);
        Data[0][i]=binToDec(buffer);
    }
    fclose(fp);

    //-----------------------------------------------
    DS=SIZE_OF_DATA;
    Data_Size[0]=SIZE_OF_DATA;
    for(j=0,BitL=0;j<DATA_BIT_LEN;j++,BitL++)
    {
        for(BitC=0,i=0;i<DS;i++)
        {
            if((Data[j][i]>>(DATA_BIT_LEN-1-BitL))&1)BitC++;
        }

        if(BitC>=(DS/2.0))a=1;else a=0;

        for(i=0,c=0;i<DS;i++)
        {
            if(((Data[j][i]>>(DATA_BIT_LEN-1-BitL))&1)==a)
            {
                Data[j+1][c]=Data[j][i];
                c++;
            }
        }
        Data_Size[j+1]=c;
        DS=c;
    }

    for(i=0;i<DATA_BIT_LEN;i++)
        printf("%d ",Data_Size[i]);
    puts("\r");

    for(j=0;j<5;j++)
    {
        for(i=0;i<Data_Size[DATA_BIT_LEN-1-j];i++)
        {
            printf("%d: %d ",i,Data[DATA_BIT_LEN-1-j][i]);
            DecToBin(Data[DATA_BIT_LEN-1-j][i],DATA_BIT_LEN);
            puts("\r");
        }
        puts("-------------\r");
    }
    //-----------------------------------------------
    DS=SIZE_OF_DATA;
    Data_Size[0]=SIZE_OF_DATA;
    for(j=0,BitL=0;j<DATA_BIT_LEN;j++,BitL++)
    {
        for(BitC=0,i=0;i<DS;i++)
        {
            if((Data[j][i]>>(DATA_BIT_LEN-1-BitL))&1)BitC++;
        }

        if(BitC>=(DS/2.0))a=1;else a=0;

        for(i=0,c=0;i<DS;i++)
        {
            if(((Data[j][i]>>(DATA_BIT_LEN-1-BitL))&1)==!a)
            {
                Data[j+1][c]=Data[j][i];
                c++;
            }
        }
        Data_Size[j+1]=c;
        DS=c;
    }

    for(i=0;i<DATA_BIT_LEN;i++)
        printf("%d ",Data_Size[i]);
    puts("\r");

    for(j=0;j<5;j++)
    {
        for(i=0;i<Data_Size[DATA_BIT_LEN-1-j];i++)
        {
            printf("%d: %d ",i,Data[DATA_BIT_LEN-1-j][i]);
            DecToBin(Data[DATA_BIT_LEN-1-j][i],DATA_BIT_LEN);
            puts("\r");
        }
        puts("-------------\r");
    }

    return 0;
}