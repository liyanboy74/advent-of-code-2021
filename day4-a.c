#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>

#define NumBufferSize 200
#define TableNum 100
#define FILE_NAME "day4-data.txt"

typedef struct{
    uint8_t mat[5][5];
    uint8_t sel[5][5];
} bingo;

int NumBuffer[NumBufferSize];
int NumLen=0;
bingo Table[TableNum];
int Score[TableNum];
int Score[TableNum];

void bingoClear(int id)
{
    memset(&Table[id].sel,1,25);
}

void getNum(FILE *fp)
{
    int i,index;
    char NumSBuffer[500];

    fscanf(fp,"%s",&NumSBuffer);
    for(index=0,i=0;index<strlen(NumSBuffer);i++)
    {
        sscanf(&NumSBuffer[index],"%d",&NumBuffer[i]);
        if(NumBuffer[i]>=10)index+=3;
        else index+=2;
        NumLen++;
    }
}

void printTable(int id)
{
    int i,j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(!Table[id].sel[i][j])
            {
                printf("(%2d)",Table[id].mat[i][j]);
            }
            else
            {
                printf(" %2d ",Table[id].mat[i][j]);
            }
        }
        puts("\r");
    }
}

void getTable(FILE *fp,int id)
{
    int i,j;

    for(i=0;i<5;i++)
    fscanf(fp,"%d %d %d %d %d\r\n",
    &Table[id].mat[i][0],
    &Table[id].mat[i][1],
    &Table[id].mat[i][2],
    &Table[id].mat[i][3],
    &Table[id].mat[i][4]);

    bingoClear(id);
}

int CTable(int id,int Num)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(Table[id].mat[i][j]==Num)
            {
                Table[id].sel[i][j]=0;
                return i*5+j;
            }
        }
    }
    return -1;
}

int STable(int id)
{
    int i;

    for(i=0;i<5;i++)
    {
        if(Table[id].sel[i][0]==0&&
        Table[id].sel[i][1]==0&&
        Table[id].sel[i][2]==0&&
        Table[id].sel[i][3]==0&&
        Table[id].sel[i][4]==0)
        {
            return -1*(i+1);
        }
    }

    for(i=0;i<5;i++)
    {
        if(Table[id].sel[0][i]==0&&
        Table[id].sel[1][i]==0&&
        Table[id].sel[2][i]==0&&
        Table[id].sel[3][i]==0&&
        Table[id].sel[4][i]==0)
        {
            return (i+1);
        }
    }

    return 0;
}

int GetMinScoreID()
{
    int i,ret;
    int min=99;
    for(i=0;i<TableNum;i++)
    {
        if(Score[i]<min)
        {
            min=Score[i];
            ret=i;
        }
    }
    return ret;
}

int SumOfUncheked(int id)
{
    int i,j,sum=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(Table[id].sel[i][j]==1)sum+=Table[id].mat[i][j];
        }
    }
    return sum;
}

int main()
{
    FILE *fp;
    int i,j,t;

    fp=fopen(FILE_NAME,"r");

    getNum(fp);

    for(t=0;t<TableNum;t++)
    {
        getTable(fp,t);
        for(i=0;i<NumLen;i++)
        {
            j=CTable(t,NumBuffer[i]);
            //system("clear");
            printf("%02d : %02d : %02d : %s\r\n",t,i,NumBuffer[i],(j==-1)?"NF":"OK");
            //printf("--------------------\r\n");
            //printTable(t);
            if(j=STable(t),j!=0)
            {
                Score[t]=i;
                break;
            }
        }
    }
    system("clear");
    j=GetMinScoreID();
    printf("Best Table ID IS : %d\r\n--------------------\r\n",j);
    printTable(j);
    printf("--------------------\r\n");
    i=NumBuffer[Score[j]];
    t=SumOfUncheked(j);

    printf("Ans is %d x %d = %ld",t,i,t*i);

    fclose(fp);
    return 0;
}
/*
void delay(int milli_seconds)
{
    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
*/
