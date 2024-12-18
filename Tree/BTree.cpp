// Also check /BinaryTrees/binTree.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "BTree.h"
#include "../utils.h"
using namespace std;

int maxElement(Node<int> *root)
{
    if (!root)
    {
        return -1;
    }

    int leftMax = maxElement(root->left);
    int rightMax = maxElement(root->right);

    return max(root->data, max(leftMax, rightMax));
}

bool searchElement(Node<int> *root, int n)
{
    if (!root)
    {
        return 0;
    }

    if (root->data == n)
    {
        return 1;
    }

    // bool temp = searchElement(root->left, n);
    // if (temp)
    //     return 1;

    return searchElement(root->left, n) || searchElement(root->right, n);
}

void insertLevelOrder(Node<int> *root, int n)
{
    if (!root)
    {
        root = new Node<int>(n);
    }

    queue<Node<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        Node<int> *temp = q.front();
        q.pop();

        if (!temp->left)
        {
            temp->left = new Node<int>(n);
            break;
        }

        if (!temp->right)
        {
            temp->right = new Node<int>(n);
            break;
        }

        q.push(temp->left);
        q.push(temp->right);
    }
}

vector<Node<int> *> deepestNode(Node<int> *root)
{
    queue<Node<int> *> q;
    Node<int> *temp = nullptr;
    Node<int> *parent = nullptr;

    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
            parent = temp;
        }
        if (temp->right)
        {
            q.push(temp->right);
            parent = temp;
        }
    }

    return vector<Node<int> *>({temp, parent});
}

bool deleteElement(Node<int> *root, int data)
{
    if (!root)
        return 0;

    vector<Node<int> *> res = deepestNode(root);
    Node<int> *lastNode = res[0];
    Node<int> *parent = res[1];

    queue<Node<int> *> q;
    Node<int> *temp = nullptr;

    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == data)
            break;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    temp->data = lastNode->data;
    if (parent)
    {
        if (parent->left == lastNode)
            parent->left = nullptr;
        if (parent->right == lastNode)
            parent->right = nullptr;
    }

    // lastNode = nullptr;

    delete lastNode;

    return 1;
}

int countLeaves(Node<int> *root)
{
    if (!root)
        return 0;

    int count = 0;
    queue<Node<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        Node<int> *temp = q.front();
        q.pop();

        if (!temp->left && !temp->right)
            count++;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    return count;
}

int calculateDiameter(Node<int> *root)
{
    if (!root)
        return 0;

    int left = calculateDiameter(root->left);
    int right = calculateDiameter(root->right);

    return max(left, right) + 1;
}

Node<int> *LCA(Node<int> *root, Node<int> *a, Node<int> *b)
{
    if (!root)
        return root;

    if (root == a || root == b)
        return root;

    Node<int> *left = LCA(root->left, a, b);
    Node<int> *right = LCA(root->right, a, b);

    if (left && right)
        return root;

    return (left ? left : right);
}

void zigzagTraversal(Node<int> *root)
{

    if (!root)
        return;

    queue<Node<int> *> q;
    q.push(root);

    bool traverse = 0;

    while (!q.empty())
    {
        Node<int> *temp = q.front();
        q.pop();
        cout << temp->data;
        // incomplete
    }
}

Node<char> *postfixExpToTree(string exp)
{
    stack<Node<char> *> st;

    for (int i = 0; i < exp.length(); i++)
    {
        Node<char> *tmp = new Node<char>(exp[i]);

        if (charIsAnyOfThese(exp[i], "+-*/^"))
        {
            tmp->right = st.top();
            st.pop();

            if (!st.empty())
            {
                tmp->left = st.top();
                st.pop();
            }
        }

        st.push(tmp);
    }

    return st.top();
}

int main()
{

    // vector<int> data = {3, 9, 20, 16, 15, 7, 4, 55};

    // Node<int> *root = createTree(data);

    // drawTree(root);
    // cout << endl;

    // cout << searchElement(root, 97) << endl;

    drawTree(postfixExpToTree("31+2^74-2*+5-"));

    // Node<char> *root = new Node<char>('a');

    return 0;
}