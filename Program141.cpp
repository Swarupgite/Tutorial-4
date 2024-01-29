#include<iostream>
using namespace std;

class String
{
    private:
        char *str;
        int iSize;

    public:
        String()
        {
            iSize = 20;
            str = new char[20];
        }    

        String(int X)
        {
            iSize = X;
            str = new char[iSize];
        }

        ~String()
        {
            delete []str;
        }

        void Accept()
        {
            cout<<"Enter the String : "<<endl;
            cin.getline(str,iSize);
        }

        void Display()
        {
            cout<<"String is : "<<str<<endl;
        }


};

int main()
{
    String *sobj = new String(30);

    sobj->Accept();
    sobj->Display();

    delete sobj;

    return 0;
}