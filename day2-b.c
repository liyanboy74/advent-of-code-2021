#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <string.h>

#define SIZE_OF_DATA 1000
#define FILE_NAME "day2-data.txt"

int main()
{
    FILE *fp;
    int i;
    int input,x=0,h=0,aim=0;
    char command[32];

    fp=fopen(FILE_NAME,"r");
    for(i=0;i<SIZE_OF_DATA;i++)
    {
        fscanf(fp,"%s %d",&command,&input);

        if(strcmp(command,"forward")==0)
        {
            x+=input;
            h=h+(input*aim);
        }
        else if(strcmp(command,"down")==0)
        {
            aim+=input;
        }
        else if(strcmp(command,"up")==0)
        {
            aim-=input;
        }

    }
    printf("x is %d & Depth is %d -> ans is %ld \r\n",x,h,(long)x*h);
    fclose(fp);
    return 0;
}