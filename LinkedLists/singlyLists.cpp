#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int data;
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

int listSize(Node *head)
{
    int size = 0;
    while (head != NULL)
    {
        size++;
        head = head->next;
    }

    return size;
}

void insertAtBeginning(Node **head)
{
    int data;
    cout << "Enter data to be entered:\n";
    cin >> data;

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node *last = *head;

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;

    if (*head)
        printList(*head);
}

void insertAtPos(Node **head)
{
    int data;
    cout << "Enter data to be entered:\n";
    cin >> data;

    int pos;
    cout << "Enter the position:\n";
    cin >> pos;

    int k = 1;
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node *nodeAtPos = *head;
    Node *prev;

    if (pos == 1)
    {
        newNode->next = nodeAtPos;
        *head = newNode;
        printList(*head);
        return;
    }

    while (nodeAtPos != NULL && k < pos)
    {
        prev = nodeAtPos;
        nodeAtPos = nodeAtPos->next;
        k++;
    }

    prev->next = newNode;
    newNode->next = nodeAtPos;

    printList(*head);
}

void deleteAtFirst(Node **head)
{
    Node *prev = *head;
    *head = (*head)->next;

    delete prev;

    printList(*head);
}

void deleteAtEnd(Node **head)
{
    Node *prev = *head;
    Node *last = *head;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    delete (last);

    printList(*head);
}

void deleteAtPos(Node **head)
{
    int pos;
    cout << "Enter the position:\n";
    cin >> pos;

    if (pos > listSize(*head))
    {
        cout << "Invalid Position\n";
        return;
    }

    Node *prev = *head;
    Node *nodeAtPos = *head;
    if (pos == 1)
    {
        *head = (*head)->next;
        delete prev;
        printList(*head);
        return;
    }

    pos -= 1;
    while (nodeAtPos != NULL && pos != 0)
    {
        prev = nodeAtPos;
        nodeAtPos = nodeAtPos->next;
        pos--;
    }

    prev->next = nodeAtPos->next;
    delete nodeAtPos;

    printList(*head);
}

void reverseList(Node **head)
{
    Node *prev = NULL;
    Node *cur = *head;
    Node *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }

    *head = prev;
}

vector<int> listToArray(Node *head)
{
    vector<int> list;
    while (head != NULL)
    {
        list.push_back(head->data);
        head = head->next;
    }

    return list;
}

void fillValues(Node *head, vector<int> *list)
{
    if (head == NULL)
        return;
    list->push_back(head->data);
    fillValues(head->next, list);
}

vector<int> recurListToArray(Node *head)
{
    vector<int> list;
    fillValues(head, &list);
    return list;
}

int sumList(Node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum += head->data;
        head = head->next;
    }

    return sum;
}

int recurSumList(Node *head)
{
    if (head == NULL)
        return 0;
    return head->data + recurSumList(head->next);
}

bool findItem(Node *head, int find)
{
    if (head == NULL)
        return 0;
    if (head->data == find)
    {
        return 1;
    }
    else
    {
        return findItem(head->next, find);
    }
}

Node *zipperList(Node **A, Node **B)
{
    int count = 0;

    Node *list1 = *A;
    Node *list2 = *B;
    Node *temp = new Node();
    Node *tail = list1;
    Node *newNode = list1;

    while (list1 != NULL && list2 != NULL)
    {
        if (count % 2 == 0)
        {
            temp = list1->next;
            tail->next = list2;
            list1 = temp;
            tail = tail->next;
        }
        else if (count % 2 != 0)
        {
            temp = list2->next;
            tail->next = list1;
            list2 = temp;
            tail = tail->next;
        }
        count++;
    }

    return newNode;
}

Node *insertInsortedList(Node **head, int data)
{
    Node *list = *head;
    if (list == NULL)
    {
        list = new Node();
        list->data = data;
        list->next = NULL;
    }
    else
    {
        if (data >= list->data)
        {
            list->next = insertInsortedList(&list->next, data);
        }

        if (data < list->data)
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = list;
            list = newNode;
        }
    }

    return list;
}

void ReverseTillK(Node *head, int k)
{
    Node *prev = NULL, *next = NULL;
    Node *prevTail = head, *currTail = NULL;
    Node *newHead = NULL;

    int newK = k;

    while (head != NULL)
    {
        if (newK == k)
        {
            prevTail = currTail;
            currTail = head;
            prev = NULL;
        }
        else if (newK == 1)
        {
            if (prevTail)
            {
                prevTail->next = head;
            }
            else
            {
                newHead = head;
            }
            newK = k + 1;
        }

        next = head->next;
        head->next = prev;
        prev = head;
        head = next;

        newK--;
    }

    if (prevTail)
        prevTail->next = prev;

    while (newHead != NULL)
    {
        cout << newHead->data << "->";
        newHead = newHead->next;
    }

    cout << endl;
}

void productExceptSelf(vector<long long int> &nums, int n)
{

    // code here
    vector<long long> res, left(n), right(n);
    long long leftPr = 1, rightPr = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            leftPr *= nums[i - 1];
        }

        left[i] = leftPr;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i != n - 1)
            rightPr *= nums[i + 1];

        right[i] = rightPr;
    }

    for (int i = 0; i < n; i++)
    {
        res.push_back(left[i] * right[i]);
    }

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}

void removeDuplicates(Node *head)
{
    // your code goes here
    if (!head)
        return;

    map<int, int> mp;

    Node *p1 = head, *prev = NULL;

    while (p1 != NULL)
    {
        mp[p1->data]++;

        if (mp[p1->data] > 1)
        {
            prev->next = p1->next;
        }
        else
        {
            prev = p1;
        }

        p1 = p1->next;
    }

    printList(head);
}

void delAddLastNode(Node *head)
{
    // Write your code here.
    if (!head || !head->next || !head->next->next)
        return;

    Node *curr = head, *prev = NULL;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;

    curr->next = head;

    printList(curr);
}

void findIntersection(Node *head1, Node *head2)
{
    // code goes here.

    if (!head1 || !head2)
        return;

    Node *res = NULL, *temp;

    while (head1 != NULL and head2 != NULL)
    {
        if ((head1->data == head2->data) and (!temp || temp->data != head1->data))
        {
            if (!res)
            {
                res = new Node();
                res->data = head1->data;
                res->next = NULL;
                
                temp = res;
            }
            else
            {
                temp->next = new Node();
                temp->next->data = head1->data;
    
                temp = temp->next;
            }

            cout << head1->data << " ";

            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
    }

    printList(res);
}

int main()
{
    Node *A, *B;
    A->data = 1;
    A->next = NULL;

    insertAtEnd(&A, 2);
    insertAtEnd(&A, 3);
    insertAtEnd(&A, 4);
    insertAtEnd(&A, 6);

    B->data = 2;
    B->next = NULL;

    insertAtEnd(&B, 4);
    insertAtEnd(&B, 6);
    insertAtEnd(&B, 8);

    findIntersection(A, B);

    return 0;
}
