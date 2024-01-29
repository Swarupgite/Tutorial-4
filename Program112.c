#include<stdio.h>

void Display(char str[])
{
    printf("String is : %s\n",str);

}

int main()
{
    char Arr[20];


    printf("Enter the String : \n");
    scanf("%[^'\n']s",Arr);

    printf("Entered string is : %s\n",Arr);

    Display(Arr);

    return 0;
}