#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define NumBufferSize 300
#define DAYS_COUNT 80
#define FILE_NAME "day6-data.txt"

typedef struct fishss{
    uint8_t FC;
    struct fishss *NEX;
}fish_s;

int NumLen;
uint8_t NumBuffer[NumBufferSize];
fish_s *head=NULL;
long int listLen=0;

void getNum(FILE *fp)
{
    int i,index;
    char NumSBuffer[610];

    fscanf(fp,"%s",&NumSBuffer);
    for(index=0,i=0;index<strlen(NumSBuffer);i++)
    {
        sscanf(&NumSBuffer[index],"%d",&NumBuffer[i]);
        if(NumBuffer[i]>=10)index+=3;
        else index+=2;
        NumLen++;
    }
}

void printNum()
{
    int i;
    for(i=0;i<NumLen;i++)printf("%d,",NumBuffer[i]);
}

void head_init(uint8_t val)
{
    head=(fish_s*)malloc(sizeof(fish_s));
    head->NEX=NULL;
    head->FC=val;
    listLen=1;
}

void add(uint8_t val)
{
    fish_s * current=head;
    while(current->NEX!=NULL)
    {
        current=current->NEX;
    }
    current->NEX=(fish_s*)malloc(sizeof(fish_s));
    current->NEX->FC=val;
    current->NEX->NEX=NULL;

    listLen++;
}

void addNumToList()
{
    int i;
    for(i=0;i<NumLen;i++)
    {
        if(i==0)
        head_init(NumBuffer[i]);
        else
        add(NumBuffer[i]);
    }
}

void printList()
{
    fish_s * current=head;
    while(1)
    {
        printf("%d ",current->FC);
        if(current->NEX==NULL)break;
        else
        {
            current=current->NEX;
        }
    }
}

long int getListLen()
{
    return listLen;
}

fish_s * selectFish(int id)
{
    int i;
    fish_s * current=head;
    for(i=0;i<id;i++)
    {
        current=current->NEX;
    }
    return current;
}

int main()
{
    int i,j,l;
    FILE *fp;
    fish_s *fish;

    fp=fopen(FILE_NAME,"r");
    getNum(fp);
    //printNum();

    addNumToList();
    //printList();


    for(i=0;i<DAYS_COUNT;i++)
    {
        l=getListLen();
        for(j=0;j<l;j++)
        {
            fish=selectFish(j);

            if(fish->FC>0)fish->FC--;
            else
            {
                fish->FC=6;
                add(8);
            }
        }
        printf("Day %02d\r\n",i+1);
    }

    //printList();
    printf("List Len: %ld\r\n",getListLen());

    fclose(fp);
    return 0;
}