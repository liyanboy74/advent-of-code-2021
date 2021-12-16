#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <string.h>

#define SIZE_OF_DATA 2000
#define FILE_NAME "day1-data.txt"

int main()
{
    FILE *fp;
    int i,read=0,input,c=0;
    char buf[64];

    fp=fopen(FILE_NAME,"r");
    for(i=0;i<SIZE_OF_DATA;i++)
    {
        fscanf(fp,"%d",&input);
        if(i==0)read=input;
        //printf("%d: %d",i,input);
        if(input>read)
        {
            c++;
            //printf(" *");
        }
        read=input;
        //puts("\r\n");
    }
    printf("Ans is %d\r\n",c);
    fclose(fp);
    return 0;
}