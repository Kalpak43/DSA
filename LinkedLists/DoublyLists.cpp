#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << endl;
}

void printRevList(Node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }

    while (head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->prev;
    }

    cout << endl;
}

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        Node *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = newNode;
        newNode->prev = last;
    }
}

void insertAtPos(Node **head, int data, int pos)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    Node *nodeAtPos = *head;
    while (nodeAtPos->next && pos)
    {
        nodeAtPos = nodeAtPos->next;
        pos--;
    }

    
    Node *before = nodeAtPos->prev;
    newNode->next = nodeAtPos;
    newNode->prev = before;

    nodeAtPos->prev = newNode;
    before->next = newNode;

}

int main()
{
    Node *head = NULL;

    insertAtBeginning(&head, 0);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    printList(head);

    insertAtPos(&head, 2, 1);

    printList(head);
    // printRevList(head);
    return 0;
}