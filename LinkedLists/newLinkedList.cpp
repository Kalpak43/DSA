#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *getMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *res = new Node(-1);
    Node *curr = res;

    while (left and right)
    {
        if (left->data <= right->data)
        {
            curr->next = left;
            left = left->next;
        }
        else
        {
            curr->next = right;
            right = right->next;
        }

        curr = curr->next;
    }

    if (left)
    {
        curr->next = left;
    }

    if (right)
    {
        curr->next = right;
    }

    return res->next;
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *mid = getMiddle(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

Node *getToEnd(Node *head)
{
    while (head->next)
        head = head->next;

    return head;
}

Node *quickSort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *pivot = getToEnd(head);

    Node *maxNode = NULL;

    Node *curr = head;

    while (curr)
    {
        if (curr->data < pivot->data)
        {
            swapNodes(&head, maxNode, curr);
        } else {
            maxNode->data < curr->data ? maxNode = curr : maxNode = maxNode;
        }
        curr = curr->next;
    }

    swapNodes(&head, pivot, maxNode);

    Node *prevPi = NULL;

    while(head) {
        prevPi = head;
    }

    return head;
}

void swapNodes(Node **head_ref, Node *x, Node *y)
{
    if (x == y) return;

    Node **a = NULL, **b = NULL;

    for (Node **temp = head_ref; *temp; temp = &((*temp)->next)) {
        if (*temp == x) a = temp;
        else if (*temp == y) b = temp;
    }

    if (a == NULL || b == NULL) return;

    Node *temp = *a;
    *a = *b;
    *b = temp;

    temp = (*a)->next;
    (*a)->next = (*b)->next;
    (*b)->next = temp;
}

int main()
{

    Node *A = new Node(1);

    A->next = new Node(2);

    A->next->next = new Node(3);

    A->next->next->next = new Node(4);

    A->next->next->next->next = new Node(5);

    A->next->next->next->next->next = new Node(6);

    printList(A);

    swapNodes(&A, A, A->next->next->next);

    return 0;
}