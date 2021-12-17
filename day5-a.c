#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SAZE 500
#define MAT_SIZE 1000
#define FILE_NAME "day5-data.txt"

typedef struct{
    int x,y;
}point_s;

typedef struct{
    point_s p1,p2;
}points_s;

points_s point[DATA_SAZE];

int mat[MAT_SIZE][MAT_SIZE];

void delay(int milli_seconds)
{
    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void getPoints(FILE *fp)
{
    int i;
    for(i=0;i<DATA_SAZE;i++)
    {
        fscanf(fp,"%d,%d -> %d,%d",&point[i].p1.x,&point[i].p1.y,&point[i].p2.x,&point[i].p2.y);
    }
}

void printPoints()
{
    int i=0;
    for(i=0;i<DATA_SAZE;i++)
    {
        printf("%d: %d,%d -> %d,%d\r\n",i,point[i].p1.x,point[i].p1.y,point[i].p2.x,point[i].p2.y);
    }
}

void clearMat()
{
    int i,j;
    for(i=0;i<MAT_SIZE;i++)
    {
        for(j=0;j<MAT_SIZE;j++)
        {
            mat[i][j]=0;
        }
    }
}

void printMat()
{
    int i,j;
    for(i=0;i<MAT_SIZE;i++)
    {
        for(j=0;j<MAT_SIZE;j++)
        {
            printf("%d ",mat[j][i]);
        }
        printf("\r\n");
    }
}

void drawPoints()
{
    int i;
    point_s p;
    for(i=0;i<DATA_SAZE;i++)
    {
        if(point[i].p1.x==point[i].p2.x)
        {
            if(point[i].p1.y>=point[i].p2.y)
            {
                p.x=point[i].p2.x;
                p.y=point[i].p2.y;
                do
                {
                    mat[p.x][p.y]++;
                    p.y++;
                } while (point[i].p1.y>=p.y);
            }else
            {
                p.x=point[i].p1.x;
                p.y=point[i].p1.y;
                do
                {
                    mat[p.x][p.y]++;
                    p.y++;
                } while (point[i].p2.y>=p.y);
            }
        }
        else if(point[i].p1.y==point[i].p2.y)
        {
            if(point[i].p1.x>=point[i].p2.x)
            {
                p.x=point[i].p2.x;
                p.y=point[i].p2.y;
                do
                {
                    mat[p.x][p.y]++;
                    p.x++;
                } while (point[i].p1.x>=p.x);
            }else
            {
                p.x=point[i].p1.x;
                p.y=point[i].p1.y;
                do
                {
                    mat[p.x][p.y]++;
                    p.x++;
                } while (point[i].p2.x>=p.x);
            }
        }
    }

}

int CountRisk()
{
    int i,j,r=0;
    for(i=0;i<MAT_SIZE;i++)
    {
        for(j=0;j<MAT_SIZE;j++)
        {
            if(mat[i][j]>=2)r++;
        }
    }
    return r;
}

int main()
{
    FILE *fp;
    int r;

    fp=fopen(FILE_NAME,"r");
    getPoints(fp);
    //printPoints();
    clearMat();
    //printMat();
    drawPoints();
    //printMat();
    r=CountRisk();
    printf("The Risk Num is: %d\r\n",r);

    fclose(fp);
    return 0;
}

