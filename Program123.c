#include<stdio.h>
#include<stdbool.h>

void Replace(char *str)
{
    int iCnt = 0;
     while(*str != '\0')
    {
        if(*str == 'a')
        {
          *str = '_';
        }
           str++;
    }
}

int main()
{
    char Arr[20];

    printf("Enter the String: \n");
    scanf("%[^\n]s", Arr);

    Replace(Arr);
    printf("Updated dtring is: %s\n", Arr);

    return 0;
}