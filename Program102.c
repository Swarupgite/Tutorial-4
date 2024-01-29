#include<stdio.h>

int main()
{
    int iCnt = 0;

    printf("-----------------------------------------------");
    printf("-------------ASCII Table ----------------------");
    printf("-----------------------------------------------");

    for(iCnt = 0; iCnt <= 127; iCnt++)
    {
        printf("%c\t%d\t%o\t%x\n",iCnt,iCnt,iCnt,iCnt);
    }

    printf("------------------------------------------------");

    return 0;
}