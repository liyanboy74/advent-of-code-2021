#include <stdio.h>
#include <string.h>

#define DATA_SIZE   200
#define FILE_NAME "day8-data.txt"

typedef struct{
    char SegTemp[10][8];
    char SegData[4][8];
} Seg_s;

void getRow(FILE *fp,Seg_s *Seg)
{
    int i;
    for(i=0;i<10;i++)
    {
        fscanf(fp,"%s",&Seg->SegTemp[i]);
    }
    fscanf(fp," | ");
    for(i=0;i<4;i++)
    {
        fscanf(fp,"%s",&Seg->SegData[i]);
    }
}

void printRow(Seg_s *Seg)
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("%s ",Seg->SegTemp[i]);
    }
    printf("| ");
    for(i=0;i<4;i++)
    {
        printf("%s ",Seg->SegData[i]);
    }
    printf("\r\n");
}

int main()
{
    int i,j,k=0,s;
    FILE *fp;

    Seg_s Seg[DATA_SIZE];

    fp=fopen(FILE_NAME,"r");

    for(i=0;i<DATA_SIZE;i++)
    {
        getRow(fp,&Seg[i]);
        printRow(&Seg[i]);
    }

    for(i=0;i<DATA_SIZE;i++)
    {
        for(j=0;j<4;j++)
        {
            s=strlen(Seg[i].SegData[j]);
            if(s==2 || s==3 ||s==4 ||s==7)k++;
        }
    }

    printf("Ans is %d\r\n",k);

    fclose(fp);
    return 0;
}
