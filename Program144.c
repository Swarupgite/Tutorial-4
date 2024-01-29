#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PNODE *Head, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if (*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE Temp = *Head;
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
}

void Display(PNODE Head)
{
    printf("Elements of linked list are: \n");

    while (Head != NULL)
    {
        printf("| %d | ->", Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
}

int Count(PNODE Head)
{
    int iCnt = 0;

    while (Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

void DeleteFirst(PPNODE Head)
{
    PNODE Temp = *Head;
    if (*Head == NULL)
    {
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free(Temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;
    PNODE Prev = NULL;
    if (*Head == NULL)
    {
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while (Temp->next != NULL)
        {
            Prev = Temp;
            Temp = Temp->next;
        }
        free(Temp);
        Prev->next = NULL;
    }
}

void InsertAtPos(PPNODE Head, int No, int iPos)
{
    int Size = Count(*Head);
    int i = 0;
    PNODE temp = *Head;

    // Case 1: Invalid Position (Ex : 11/-2/8)
    if (iPos < 1 || iPos > Size + 1)
    {
        printf("Invalid Position\n");
        return;
    }
    // Case 2: First Position (Ex : 1)
    if (iPos == 1)
    {
        InsertFirst(Head, No);
    }
    // Case 3: Last Position (Ex : 7)
    else if (iPos == Size + 1)
    {
        InsertLast(Head, No);
    }
    // Case 4: Position is in between First And Last (Ex : 5)
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn->next = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int Size = Count(*Head);
    int i = 0;
    PNODE temp = *Head;
    PNODE targetedNode = NULL;

    // Case 1: Invalid Position (Ex : 11/-2/8)
    if (iPos < 1 || iPos > Size)
    {
        printf("Invalid Position\n");
        return;
    }
    // Case 2: First Position (Ex : 1)
    if (iPos == 1)
    {
        DeleteFirst(Head);
    }
    // Case 3: Last Position (Ex : 7)
    else if (iPos == Size)
    {
        DeleteLast(Head);
    }
    // Case 4: Position is in between First And Last (Ex : 5)
    else
    {
        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        targetedNode = temp->next;
        temp->next = temp->next->next;
        free(targetedNode);
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 111);
    InsertFirst(&First, 101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);
    InsertLast(&First, 121); // Pass the address of the head node

    InsertAtPos(&First, 105, 5);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are: %d\n", iRet);

    DeleteAtPos(&First, 5);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are: %d\n", iRet);

    // Free the allocated memory
    while (First != NULL)
    {
        PNODE Temp = First;
        First = First->next;
        free(Temp);
    }

    return 0;
}
