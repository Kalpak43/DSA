#include<iostream>
using namespace std;

string Reverse(int size, string s)
{
    if(size == 0)
    {
        return "";
    }

    return s[size-1] + Reverse(size-1, s);
}

bool checkPalindrome(string s)
{
    if(s.length() <= 1)
    {
        return true;
    }

    if(s[0] == s[s.length()-1])
    {
        return checkPalindrome(s.substr(1, s.length()-2));
    }

    return false;
}


int main()
{
    string s = "kayak";
    cout << checkPalindrome(s) << endl; 

    return 0;
}