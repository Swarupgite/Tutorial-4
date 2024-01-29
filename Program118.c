#include<stdio.h>
#include<stdbool.h>

int CountdSmall(char *str)
{
    int iCnt = 0;
    if(*str >= '1' && *str <= '9')
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

    iRet = CountVowels(Arr);
    printf("Count of letter is: %d\n", iRet);

    return 0;
}