#include<iostream>
using namespace std;

class Stack 
{
    int size = 0;
    int *arr;
    int top = -1;
public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
    }

    void push(int data)
    {
        if(top < size - 1)
        {
            arr[++top] = data;
        }
        else
        {
            cout << "OverFlow\n";
        }
    }

    int pop()
    {
        if(top > -1)
        {
            return arr[top--];
        }
        else {
            return INT8_MIN;
        }
    }

    void getTop()
    {
        cout << arr[top] << endl;
    }
};

int main()
{
    Stack S(5);





    return 0;   
}