#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
};

void inOrder(Node* root)
{
    if(root)
    {
        cout << root->data << " ";
        inOrder(root->left);
        inOrder(root->right);
    }
}

void DFS(Node *root)
{
    stack<Node*> stk;
    if(root) stk.push(root);
    else return;

    while(!stk.empty())
    {
        Node* curr = stk.top();
        stk.pop();

        cout << curr->data << " ";

        if(curr->right) stk.push(curr->right);
        if(curr->left) stk.push(curr->left);
    }
}

void BFS(Node* root)
{
    queue<Node*> q;
    if(root) q.push(root);
    else return;

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

bool treeIncludes(Node* root, int data)
{
    queue<Node*> q;
    if(root) q.push(root);
    else return false;

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        if(curr->data == data) return true;

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    return false;
}

int treeSum(Node* root)
{
    if(!root) return 0;

    return root->data + treeSum(root->left) + treeSum(root->right);
}

int treeMin(Node* root)
{
    if(!root) return INT8_MAX;

    int leftMin = treeMin(root->left);
    int rightMin = treeMin(root->right);

    return min(root->data, min(leftMin, rightMin));
}

int maxPathSum(Node* root)
{
    if(!root) return 0;
    int leftSum = maxPathSum(root->left);
    int rightSum = maxPathSum(root->right);

    return root->data + max(leftSum, rightSum);
}

int treeDiameter(Node* root)
{
    if(!root) return 0;
    int leftDiameter = treeDiameter(root->left);
    int rightDiameter = treeDiameter(root->right);

    return 1 + max(leftDiameter, rightDiameter);
}

bool checkPathSum(Node* root, int sum)
{
    if(!root && sum != 0) return false;
    if(!root && sum == 0) return true;

    sum -= root->data;
    
    return checkPathSum(root->left, sum) || checkPathSum(root->right, sum);
}

Node* LCA(Node* root, Node* A, Node* B)
{
    if(!root) return root;
    if(root == A || root == B) return root;

    Node* left = LCA(root->left, A, B);
    Node* right = LCA(root->right, A, B);

    if(left && right) return root;
    else return (left ? left : right);
}

void mirrorTree(Node* root)
{
    if(!root) return;
    mirrorTree(root->left);
    mirrorTree(root->right);

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void zigzagTraversal(Node* root)
{
    stack<Node*> stk1;
    stack<Node*> stk2;
    int order = 0;
    stk1.push(root);

    while(!stk1.empty() || !stk2.empty())
    {
        Node* temp;
        if(!order)
        {
            while(!stk1.empty())
            {
                temp = stk1.top();
                stk1.pop();
                cout << temp->data << " ";
                if(temp->left) stk2.push(temp->left);
                if(temp->right) stk2.push(temp->right);
            }
            order = 1;
        }
        else
        {
            while(!stk2.empty())
            {
                temp = stk2.top();
                stk2.pop();
                cout << temp->data << " ";
                if(temp->right) stk1.push(temp->right);
                if(temp->left) stk1.push(temp->left);
            }
            order = 0;
        }


    }
}

bool isIsomorphic(Node* root1, Node* root2)
{
    if(!root1 && !root2) return 1;
    if(!root1 || !root2) return 0;

    bool leftSubtree = isIsomorphic(root1->left, root2->left);
    bool rightSubtree = isIsomorphic(root1->right, root2->right);

    return leftSubtree && rightSubtree;
}

int main()
{
    Node* A = new Node();
    Node* B = new Node();
    Node* C = new Node();
    Node* D = new Node();
    Node* E = new Node();
    Node* F = new Node();
    Node* G = new Node();
    Node* H = new Node();

    A->data = 1;
    A->left = B;
    A->right = C;

    B->data = 2;
    B->left = D;
    B->right = E;

    C->data = 3;
    C->left = F;
    C->right = G;

    D->data = 4;
    D->left = NULL;
    D->right = NULL;

    E->data = 5;
    D->left = NULL;
    D->right = NULL;

    F->data = 6;
    F->left = NULL;
    F->right = NULL;

    G->data = 7;
    G->left = NULL;
    G->right = NULL;

    Node* I = new Node();
    Node* J = new Node();
    Node* K = new Node();

    I->data = 2;
    I->left = J;
    I->right = K;

    J->data = 3;
    J->left = NULL;
    J->right = NULL;

    K->data = 4;
    K->left = NULL;
    K->right = NULL;

    cout << isIsomorphic(A, A);
    cout << endl;
    return 0;
}