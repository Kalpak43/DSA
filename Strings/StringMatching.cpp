#include <bits/stdc++.h>

using namespace std;

bool matchNaive(string s1, string s2)
{
    // O(n*m)
    int n = s1.length();
    int m = s2.length();

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (s1[i + j] != s2[j])
            {
                break;
            }
        }

        if (j == m)
            return true;
    }

    return false;
}

int matchKMP(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<int> LPS(m, 0);
    int prevLPS = 0, i = 1;

    while (i < m)
    {
        if (s2[i] == s2[prevLPS])
        {
            LPS[i] = prevLPS + 1;
            prevLPS += 1;
            i++;
        }
        else
        {
            if (prevLPS == 0)
            {
                LPS[i] = 0;
                i++;
            }
            else
            {
                prevLPS = LPS[prevLPS - 1];
            }
        }
    }

    i = 0;
    int j = 0;

    while (i < n)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = LPS[j - 1];
            }
        }

        if (j == m)
        {
            return i - m;
        }
    }

    return -1;
}

string count(string s1)
{
    string res = "";

    char target = s1[0];
    int c = 1;

    for (int j = 1; j < s1.length(); j++)
    {
        if (s1[j] == target)
            c++;
        else
        {
            res += (to_string(c) + target);
            target = s1[j];
            c = 1;
        }
    }

    res += (to_string(c) + target);

    return res;
}

string say(int n)
{
    string res = "1";
    if (n == 1)
    {
        return res;
    }

    int i = 1;

    while (i < n)
    {
        res = count(res);
        i++;
    }

    return res;
}

string oddPalSubstr(string s)
{
    int n = s.length();

    int fi = 0, fj = 0;

    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        int k = i + 1;

        while (j >= 0 && k < n)
        {
            if (s[j] != s[k])
                break;
            j--;
            k++;
        }

        if (k - j - 1 > fj - fi + 1)
        {
            fi = j + 1;
            fj = k - 1;
        }
    }

    return s.substr(fi, fj + 1);
}

string evenPalSubstr(string s)
{
    int n = s.length();

    int fi = 0, fj = 0;

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 and s[i] == s[i + 1])
        {
            int j = i - 1;
            int k = i + 2;

            while (j >= 0 && k < n)
            {
                if (s[j] != s[k])
                    break;
                j--;
                k++;
            }

            if (k - j - 1 > fj - fi + 1)
            {
                fi = j + 1;
                fj = k - 1;
            }
        }
    }

    return s.substr(fi, fj + 1);
}

string palSubstr(string s)
{
    int n = s.length();

    int fi = 0, fj = 0;

    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        int k = i + 1;

        while (j >= 0 && k < n)
        {
            if (s[j] != s[k])
                break;
            j--;
            k++;
        }

        if (k - j - 1 > fj - fi + 1)
        {
            fi = j + 1;
            fj = k - 1;
        }

        if (i < n - 1 and s[i] == s[i + 1])
        {
            j = i - 1;
            k = i + 2;

            while (j >= 0 && k < n)
            {
                if (s[j] != s[k])
                    break;
                j--;
                k++;
            }

            if (k - j - 1 > fj - fi + 1)
            {
                fi = j + 1;
                fj = k - 1;
            }
        }
    }

    cout << fi << " " << fj << endl;

    string res = "";
    for (int i = fi; i <= fj; i++)
    {
        res += s[i];
    }

    return res;
}

void strSubSequence(string inp, string out)
{
    if (inp.empty())
    {
        cout << out << endl;
        return;
    }

    strSubSequence(inp.substr(1), out + inp[0]);

    strSubSequence(inp.substr(1), out);
}

// Longest Common Subsequence
int LCS(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                mat[i][j] += (mat[i + 1][j + 1] + 1);
            }
            else
            {
                mat[i][j] = max(mat[i + 1][j], mat[i][j + 1]);
            }
        }
    }

    return mat[0][0];
}

// Longest Recurring Subsequence
int LRS(string str)
{
    int n = str.length();

    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if ((str[i] == str[j]) and (i != j))
            {
                mat[i][j] += (mat[i + 1][j + 1] + 1);
            }
            else
            {
                mat[i][j] = max(mat[i + 1][j], mat[i][j + 1]);
            }
        }
    }

    return mat[0][0];
}

// Edit Distance : Extenstion on LCS
int editDistance (string s, string t) {
    int n = s.length();
    int m = t.length();

    if(n == 0) return m;
    if(m == 0) return n;

    vector<vector<int>> mat(n+1, vector<int> (m+1, 0));

    for(int i = 0; i < m; i++) {
        mat[n][i] = m - i;
    }

    for(int i = 0; i < n; i++) {
        mat[i][m] = n - i; 
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(s[i] == t[j]) {
                mat[i][j] = mat[i+1][j+1];
            }
            else {
                mat[i][j] = 1 + min(mat[i+1][j], min(mat[i][j+1], mat[i+1][j+1]));
            }
        }
    }

    return mat[0][0];
}


int editDistanceRecur(string s, string t) {
    int n = s.length();
    int m = t.length();

    if(n == 0) return m;
    if(m == 0) return n;

    vector<vector<int>> mat(n+1, vector<int> (m+1, 0));

    solve(s, t, mat);
}

int countSubStr(string s)
{
    int n = s.length();
    int count = 0;

    stack<char> st;
    st.push(s[0]);

    for (int i = 1; i < n; i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] == st.top())
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }

        if (st.empty())
            count++;
    }

    return count;
}

int maxSubStr(string str)
{
    // Write your code here
    int n = str.length();
    int count = 0;

    int target = str[0];
    int tempCount = 1;

    for (int i = 1; i < n; i++)
    {
        
    }

    return count == 0 ? -1 : count;
}

int main()
{

    string s1 = "1";
    string s2 = "baca";

    cout << editDistance("geek", "gesek") << endl;

    return 0;
}