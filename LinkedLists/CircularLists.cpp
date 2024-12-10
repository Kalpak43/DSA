#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printList(Node *head)
{
    Node *list = head;
    if (list)
    {
        do
        {
            cout << list->data << " -> ";
            list = list->next;
        } while (list != head);
        cout << endl;
    }

}

void insertAtBeginning(Node **head, int data)
{
    Node *list = *head;
    Node *newNode = new Node();
    newNode->data = data;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        do
        {
            list = list->next;
        } while (list->next != *head);

        newNode->next = *head;
        list->next = newNode;
        *head = newNode;
    }
}


void deleteAtBeginning(Node **head) 
{
    Node *last = *head;
    while(last->next != *head) 
    {
        last = last->next; 
    }

    last->next = (*head)->next;

    delete *head;

    *head = last->next;
}

int main()
{
    Node *A = NULL;

    insertAtBeginning(&A, 1);
    insertAtBeginning(&A, 2);
    insertAtBeginning(&A, 3);
    insertAtBeginning(&A, 4);

    printList(A);

    deleteAtBeginning(&A);

    printList(A);
    return 0;
}