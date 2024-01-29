#include<stdio.h>

int main()
{
    char ch = '\0';

    printf("Enter the character  : \n",ch);
    scanf("%c",&ch);

    printf("ASCII value of the character in Decimal : %d\n",ch);
    printf("ASCII value of the character in Octal : %o\n",ch);
    printf("ASCII value of the character in Hexadecimal : %x\n",ch);

    return 0;
}