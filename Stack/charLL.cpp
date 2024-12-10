#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

class Stack
{
    Node *top = NULL;
public:

    void push(char data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = top;

        top = newNode;
    }

    char pop()
    {
        Node *temp = top;
        char data = temp->data;
        top = top->next;

        delete temp;

        return data;
    }

    char getTop()
    {
        return top->data;
    }

    bool isEmpty()
    {
        if(top == NULL)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
};



int main()
{

    return 0;
}