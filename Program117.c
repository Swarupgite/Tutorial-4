#include<stdio.h>


int CountdCapital(char *str)
{
    int iCnt = 0;
    
    if(*str >= 'A' && *str <= 'Z')
    {
       return iCnt++;
    }
    str++;
}

int main()
{
    char Arr[20];
    int iRet = 0;

    printf("Enter the String: \n");
    scanf("%[^\n]s", Arr);

    iRet = CountdCapital(Arr);
    printf("Count of letter is: %d\n", iRet);

    return 0;
}