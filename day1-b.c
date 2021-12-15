#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <string.h>

#define SIZE_OF_DATA 2000
#define SIZE_OF_BUFFER SIZE_OF_DATA

#define FILE_NAME "day1-data.txt"

int buffer[SIZE_OF_BUFFER];

int main()
{
    FILE *fp,*fpt;
    int i,read=0,input,c=0;


    int buffer_index=0;

    fp=fopen(FILE_NAME,"r");

    fpt=fopen("day1-b-tmp.txt","w");

    for(i=0;i<SIZE_OF_DATA;i++)
    {
        fscanf(fp,"%d",&buffer[i]);
    }

    for(i=0;i<SIZE_OF_DATA-2;i++)
    {
        fprintf(fpt,"%d\r\n",buffer[i]+buffer[i+1]+buffer[i+2]);
    }
    fclose(fpt);
    fclose(fp);

    fp=fopen("day1-b-tmp.txt","r");

    for(i=0;i<SIZE_OF_DATA-2;i++)
    {
        fscanf(fp,"%d",&input);
        if(i==0)read=input;
        printf("%d: %d",i,input);
        if(input>read)
        {
            c++;
            printf(" *");
        }
        read=input;
        puts("\r\n");
    }
    printf("Ans is %d\r\n",c);
    fclose(fp);
    return 0;
}