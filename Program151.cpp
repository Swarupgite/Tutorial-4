#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class SinglyCL
{
private:
    PNODE first;
    PNODE last;
    int Count;

public:
    SinglyCL();
    void InsertFirst(int no);
    void InsertLast(int no);
    void Display();
    int CountNode();
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int no, int ipos);
    void DeleteAtPos(int ipos);
};

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

void SinglyCL::InsertFirst(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }

    Count++;
}

void SinglyCL::InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }

    Count++;
}

void SinglyCL::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        PNODE temp = first;
        first = first->next;
        last->next = first;
        delete temp;
    }

    Count--;
}

void SinglyCL::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        PNODE temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }

    Count--;
}

void SinglyCL::Display()
{
    cout << "Elements of Linked List are: \n";

    if (first != NULL)
    {
        PNODE temp = first;
        do
        {
            cout << "| " << temp->data << " | -> ";
            temp = temp->next;
        } while (temp != first);

        cout << "Address of First node\n";
    }
}

int SinglyCL::CountNode()
{
    return Count;
}

void SinglyCL::InsertAtPos(int no, int ipos)
{
    int size = CountNode();
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    PNODE temp = first;

    if (ipos < 1 || ipos > size + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        Count++;
    }
}

void SinglyCL::DeleteAtPos(int ipos)
{
    int size = CountNode();

    PNODE temp = first;
    PNODE targatednode = NULL;

    if (ipos < 1 || ipos > size)
    {
        cout << "Invalid position\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == size)
    {
        DeleteLast();
    }
    else
    {
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;
        Count--;
    }
}

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.CountNode();
    cout << "Number of elements are: " << iRet << endl;

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.CountNode();
    cout << "Number of elements are: " << iRet << endl;

    obj.InsertAtPos(105, 5);
    obj.Display();
    iRet = obj.CountNode();
    cout << "Number of elements are: " << iRet << endl;

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.CountNode();
    cout << "Number of elements are: " << iRet << endl;

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.CountNode();
    cout << "Number of elements are: " << iRet << endl;

    obj.DeleteLast();
    obj.Display();
    iRet = obj.CountNode();
    cout << "Number of elements are: " << iRet << endl;

    return 0;
}
