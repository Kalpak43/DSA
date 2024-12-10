#include <bits/stdc++.h>
using namespace std;

void insertAfterTop(stack<int> &st, int num)
{
    if (st.empty() || st.top() <= num)
    {
        st.push(num);
        return;
    }

    int top = st.top();
    st.pop();
    insertAfterTop(st, num);
    st.push(top);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();

    sortStack(st);

    insertAfterTop(st, top);
}

string infixToPostfix(string s)
{
    string res = "";
    stack<char> st;
    map<char, int> mp;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['+'] = 1;
    mp['-'] = 1;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')')
        {
            if (st.empty())
                st.push(s[i]);
            else
            {
                if (s[i] != ')' && s[i] != '(')
                {
                    while (!st.empty() && mp[s[i]] <= mp[st.top()])
                    {
                        res += st.top();
                        st.pop();
                    }

                    st.push(s[i]);
                }
                else
                {
                    if (s[i] == ')')
                    {
                        while (st.top() != '(')
                        {
                            res += st.top();
                            st.pop();
                        }

                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
            }
        }
        else
        {
            res += s[i];
        }
    }

    while (!st.empty())
    {
        /* code */
        res += st.top();
        st.pop();
    }

    return res;
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &v)
{
    sort(v.begin(), v.end());
    stack<vector<int>> st;
    st.push(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        vector<int> currentInterval = st.top();
        if (currentInterval[1] >= v[i][0])
        {
            vector<int> newInterval = {currentInterval[0], 0};
            currentInterval[1] <= v[i][1] ? newInterval[1] = v[i][1] : newInterval[1] = currentInterval[1];
            st.pop();
            st.push(newInterval);
        }
        else
        {
            st.push(v[i]);
        }
    }

    vector<vector<int>> newIntervals;
    while (!st.empty())
    {
        newIntervals.push_back(st.top());
        st.pop();
    }

    sort(newIntervals.begin(), newIntervals.end());

    return newIntervals;
}

long long maxArea(long long arr[], int n)
{
    stack<pair<int, long long>> st;
    long long res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(pair<int, long long>({i, arr[i]}));
            continue;
        }

        int index = -1;
        long long height = -1;

        while (!st.empty() && st.top().second > arr[i])
        {
            index = st.top().first;
            height = st.top().second;
            st.pop();
            res = max(res, (height * (i - index)));
        }

        if (index != -1)
        {
            st.push(pair<int, long long>({index, arr[i]}));
            index = -1;
            height = -1;
        }
        else
        {
            st.push(pair<int, long long>({i, arr[i]}));
        }
    }

    while (!st.empty())
    {
        int index = st.top().first;
        long long height = st.top().second;
        st.pop();
        res = max(res, (height * (n - index)));
    }

    return res;
}

int returnFullDay(vector<int> v)
{

    int res = 0;

    map<int, int> mp;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        int t = v[i] / 24;
        int req = t == 0 ? 24 : 24 * (t + 1) - v[i];

        if (mp.find(req) != mp.end())
        {
            res += mp[req];
        }
        else
        {
            mp[req]++;
        }
    }

    return res;
}

bool stackPermutation(vector<int> arr1, vector<int> arr2)
{

    int l = arr2.size();
    int j = 0;

    stack<int> st;

    for (int i = 0; i < l; i++)
    {
        st.push(arr1[i]);

        while (!st.empty() && (st.top() == arr2[j]))
        {
            st.pop();
            j++;
        }
    }

    if (st.empty() && j == l)
        return true;

    return false;
}

queue<int> interLeave(queue<int> &q)
{
    queue<int> temp;

    int half = q.size() / 2;

    while (half)
    {
        temp.push(q.front());
        q.pop();
        half--;
    }

    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();
    }

    return q;
}

int main()
{

    queue<int> v1;

    v1.push(11);
    v1.push(12);
    v1.push(13);
    v1.push(14);
    v1.push(15);
    v1.push(16);
    v1.push(17);
    v1.push(18);
    v1.push(19);
    v1.push(20);
    
    interLeave(v1);

    while (!v1.empty())
    {
        cout << v1.front() << "\t";
        v1.pop();
    }

    cout << endl;
    return 0;
}