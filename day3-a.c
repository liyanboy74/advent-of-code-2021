#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <string.h>

#define SIZE_OF_DATA 1000
#define MIDDLE_OF_DATA (SIZE_OF_DATA/2.0)
#define FILE_NAME "day3-data.txt"

int main()
{
    FILE *fp;
    int i,j=0;
    int input;

    int a=0,b=0,c=0,d=0;
    int a2=0,b2=0,c2=0,d2=0;
    int a3=0,b3=0,c3=0,d3=0;

    uint32_t ans=0,ans2=0;

    char buffer[16];

    fp=fopen(FILE_NAME,"r");
    for(i=0;i<SIZE_OF_DATA;i++)
    {
        fscanf(fp,"%s",&buffer);

        if(buffer[0]-'0')a++;
        if(buffer[1]-'0')b++;
        if(buffer[2]-'0')c++;
        if(buffer[3]-'0')d++;

        if(buffer[4]-'0')a2++;
        if(buffer[5]-'0')b2++;
        if(buffer[6]-'0')c2++;
        if(buffer[7]-'0')d2++;

        if(buffer[8]-'0')a3++;
        if(buffer[9]-'0')b3++;
        if(buffer[10]-'0')c3++;
        if(buffer[11]-'0')d3++;

    }

    if(a>MIDDLE_OF_DATA)a=1;else a=0;
    if(b>MIDDLE_OF_DATA)b=1;else b=0;
    if(c>MIDDLE_OF_DATA)c=1;else c=0;
    if(d>MIDDLE_OF_DATA)d=1;else d=0;

    if(a2>MIDDLE_OF_DATA)a2=1;else a2=0;
    if(b2>MIDDLE_OF_DATA)b2=1;else b2=0;
    if(c2>MIDDLE_OF_DATA)c2=1;else c2=0;
    if(d2>MIDDLE_OF_DATA)d2=1;else d2=0;

    if(a3>MIDDLE_OF_DATA)a3=1;else a3=0;
    if(b3>MIDDLE_OF_DATA)b3=1;else b3=0;
    if(c3>MIDDLE_OF_DATA)c3=1;else c3=0;
    if(d3>MIDDLE_OF_DATA)d3=1;else d3=0;

    ans=(a<<11)|(b<<10)|(c<<9)|(d<<8)| (a2<<7)|(b2<<6)|(c2<<5)|(d2<<4)| (a3<<3)|(b3<<2)|(c3<<1)|(d3<<0);
    ans2=(!a<<11)|(!b<<10)|(!c<<9)|(!d<<8)|(!a2<<7)|(!b2<<6)|(!c2<<5)|(!d2<<4)|(!a3<<3)|(!b3<<2)|(!c3<<1)|(!d3<<0);

    printf("%d%d%d%d%d%d%d%d%d%d%d%d -> %ld x %ld = %ld\r\n",a,b,c,d,a2,b2,c2,d2,a3,b3,c3,d3,ans,ans2,(long)ans*ans2);
    fclose(fp);
    return 0;
}