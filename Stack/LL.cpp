#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
    Node *top = NULL;
public:

    void push(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = top;

        top = newNode;
    }

    int pop()
    {
        Node *temp = top;
        int data = temp->data;
        top = top->next;

        delete temp;

        return data;
    }

    int getTop()
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

// Check valid strings

// bool isValid(string s)
// {
//     Stack S;

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//         {
//             S.push(s[i]);
//         }
//         else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
//         {
//             if(S.isEmpty())
//             {
//                 return 0;
//             }
//             else if ((S.getTop() == '(' && s[i] == ')') || (S.getTop() == '[' && s[i] == ']') || (S.getTop() == '{' && s[i] == '}'))
//             {
//                 S.pop();
//             }
//             else 
//             {
//                 return 0;
//             }
//         }
//     }

//     if(S.isEmpty())
//     {
//         return 1;
//     }
//     else 
//     {
//         return 0;
//     }

// }

// infix to postfix

// int priority(char s)
// {
//     if(s == '(' || s == ')')
//     {
//         return 0;
//     }
//     else if(s == '+' || s == '-')
//     {
//         return 1;
//     }
//     else if(s == '*' || s == '/')
//     {
//         return 2;
//     }

//     return -1;
// }

// string inToPost(string s)
// {
//     Stack stk;
//     string output;
//     char x;
//     for(int i = 0; i < s.length(); i++)
//     {
//         if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')')
//         {
//             if(stk.isEmpty())
//             {
//                 stk.push(s[i]);
//             }
//             else if(s[i] == '(')
//             {
//                 stk.push(s[i]);
//             }
//             else if(s[i] == ')')
//             {
//                 while((x = stk.pop()) != '(')
//                 {
//                     output += x;
//                 }
//             }
//             else 
//             {
//                 while(!stk.isEmpty() && priority(stk.getTop()) >= priority(s[i]))
//                 {
//                     output += stk.pop();
//                 }
//                 stk.push(s[i]);
//             }
//         }
//         else 
//         {
//             output += s[i];
//         }
//     }

//     while(!stk.isEmpty())
//     {
//         output += stk.pop();
//     }

//     return output;
// }

// int operate(int a, int b, char op)
// {
//     switch (op)
//     {
//     case '+':
//         return a+b;
//         break;
//     case '-':
//         return a-b;
//         break;
//     case '*':
//         return a*b;
//         break;
//     case '/':
//         return a/b;
//         break;
//     default:
//         return 0;
//         break;
//     }
// }

// int postEvaluate(string s)
// {
//     Stack stk;

//     for(int i = 0; i < s.length(); i++)
//     {
//         if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
//         {
//             int a = stk.pop();
//             int b = stk.pop();
//             int result = operate(b, a, s[i]);
//             stk.push(result);
//         }
//         else
//         {
//             stk.push((int(s[i]) - 48));
//         }
//     }

//     return stk.pop();
// }

// int infixEvaluate(string s)
// {
//     Stack operand, opr;
//     char x;
//     int a, b, res;

//     for(int i = 0; i < s.length(); i++)
//     {
//         if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
//         {
//             if(!opr.isEmpty())
//             {
//                 while(!opr.isEmpty() && priority(opr.getTop()) >= priority(s[i]))
//                 {
//                     x = opr.pop();
//                     a = operand.pop();
//                     b = operand.pop();

//                     res = operate(b, a, x);
//                     operand.push(res);
//                 }
//             }

//             opr.push(s[i]);
//         }
//         else
//         {
//             operand.push((int(s[i]) - 48));
//         }
//     }

//     while(!opr.isEmpty())
//     {
//         a = operand.pop();
//         b = operand.pop();
//         x = opr.pop();
//         res = operate(b, a, x);
//         operand.push(res);
//     }

//     return operand.pop();
// }

int main()
{
    cout << infixEvaluate("2*3-1*4") << endl;
    return 0;
}