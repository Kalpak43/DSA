#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front = -1, rear = -1;
    int size = 0, capacity = 0;
public:
    Queue(int size)
    {
        this->capacity = size;
        arr = new int[size];
    }

    void enqueue(int data)
    {
        if(this->size >= this->capacity)
        {
            cout << "Overflow\n";
        }
        else
        {
            if(this->size == 0)
            {
                front++;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = data;
            size++;
        }
    }

    int dequeue()
    {
        int data;
        if(this->size == 0)
        {
            cout << "Underflow\n";
        }
        else
        {
            data = arr[front];
            if(this->front == this->rear)
            {
                this->front = this->rear = -1;
            }
            else
            {
                front = (front + 1) % capacity;
            }
            size--;
        }
        
        return data;
    }

    int getSize()
    {
        return this->size;
    }

    int getFront()
    {
        if(this->size)
        {
            return arr[this->front];
        }

        return -1;
    }

    int getRear()
    {
        if(this->size)
        {
            return arr[this->rear];
        }

        return -1;
    }
};

int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(34);
    q.enqueue(36);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << q.getSize() << endl;

    return 0;
}