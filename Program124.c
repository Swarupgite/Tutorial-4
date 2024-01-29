#include<stdio.h>
#include<stdbool.h>

void ReplaceVowels(char *str)
{
    int iCnt = 0;
     while(*str != '\0')
    {
        if(*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u')
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

    ReplaceVowels(Arr);
    printf("Updated dtring is: %s\n", Arr);

    return 0;
}