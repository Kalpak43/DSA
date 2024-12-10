#include <iostream>
using namespace std;

int *incSize(int *arr, int size)
{
    int *temp = new int[size];
    for (int i = 0; i < size / 2; i++)
    {
        temp[i] = arr[i];
    }

    return temp;
}

class Stack
{
    int size = 0;
    int *arr;
    int top = -1;

public:
    Stack()
    {
        size = 2;
        arr = new int[size];
    }

    void push(int data)
    {
        if (top >= size - 1)
        {
            size *= 2;
            arr = incSize(arr, size);
        }

        arr[++top] = data;
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

    void getSize()
    {
        cout << size << endl;
    }
};

int main()
{
    Stack S;
    S.push(2);
    S.push(2);
    S.push(2);
    S.push(2);
    S.push(3);

    S.getSize();
    S.getTop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    cout << S.pop() << endl;
    return 0;
}