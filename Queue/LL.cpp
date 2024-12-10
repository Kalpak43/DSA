#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Queue
{
    Node* front = NULL;
    Node* rear = NULL;
public:

    void enqueue(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if(getSize() == 0)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = rear->next;
        }
    }

    int dequeue()
    {
        if(getSize() == 0)
        {
            cout << "Underflow\n";
            return 0;
        }

        if(front == rear)
        {
            rear = rear->next;
        }
        
        Node* temp = front;
        front = front->next;

        int data = temp->data;

        delete temp;

        return data;
    }

    int getSize()
    {
        if(front == NULL)
        {
            return 0;
        }

        Node* temp = front;
        int size = 0;
        while(temp != NULL)
        {
            size++;
            temp = temp->next;
        }

        return size;
    }

    int getFront()
    {
        if(!getSize())
        {
            return -1;
        }

        return front->data;
    }

    int getRear()
    {
        if(!getSize())
        {
            return -1;
        }

        return rear->data;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(3);
    
    q.dequeue();

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << q.getSize() << endl;

    return 0;
}