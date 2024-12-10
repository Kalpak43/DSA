#ifndef BTREE_H
#define BTREE_H

#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *left, *right;

    Node() {}

    Node(T data, Node<T> *right = nullptr, Node<T> *left = nullptr)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};

template <typename T1>
Node<T1> *createTree(vector<T1> data)
{
    Node<T1> *root = new Node<T1>();
    root->data = data[0];
    root->left = root->right = nullptr;

    vector<Node<T1> *> nodes;
    nodes.push_back(root);

    for (int i = 1; i < data.size(); i++)
    {
        Node<T1> *node = new Node<T1>();
        node->data = data[i];
        node->left = node->right = nullptr;

        nodes.push_back(node);
    }

    for (int i = 0; i < nodes.size(); i++)
    {
        if (2 * i + 1 < nodes.size())
        {
            nodes[i]->left = nodes[2 * i + 1];
        }

        if (2 * i + 2 < nodes.size())
        {
            nodes[i]->right = nodes[2 * i + 2];
        }
    }

    return root;
}

template <typename T>
void inOrder(Node<T> *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

template <typename T>
void preOrder(Node<T> *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

template <typename T>
void postOrder(Node<T> *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

template <typename T>
void levelOrder(Node<T> *root)
{
    if (!root)
        return;

    queue<Node<T> *> q;

    q.push(root);

    while (!q.empty())
    {
        Node<T> *node = q.front();
        q.pop();

        cout << node->data << " ";

        if (node->left)
        {
            q.push(node->left);
        }

        if (node->right)
        {
            q.push(node->right);
        }
    }
}

template <typename T>
void deleteTree(Node<T> *root)
{
    if (!root)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    cout << "DELETED: " << root->data << endl;
    delete root;
}

template <typename T>
int calculateHeight(Node<T> *root)
{
    if (!root)
        return 0;

    return 1 + max(calculateHeight(root->left), calculateHeight(root->right));
}

template <typename T>
void drawTree(Node<T> *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node<T> *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i)
        {
            Node<T> *currentNode = q.front();
            q.pop();

            cout << currentNode->data << " ";

            if (currentNode->left != nullptr)
            {
                q.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                q.push(currentNode->right);
            }
        }
        cout << endl;
    }
}
#endif