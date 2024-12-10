#include <bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> v, int n)
{
    stack<int> s;
    int max_area = INT_MIN;

    int tp;
    int i = 0;

    while (i < n)
    {
        int temp = 0;
        if (s.empty() || v[s.top()] <= v[i])
        {
            s.push(i++);
        }
        else
        {
            tp = s.top();
            s.pop();

            temp = v[tp] * (s.empty() ? i : i - s.top() - 1);

            if (temp > max_area)
            {
                max_area = temp;
            }
        }
    }

    while (!s.empty())
    {
        tp = s.top();
        s.pop();

        int temp = v[tp] * (s.empty() ? i : i - s.top() - 1);

        if (temp > max_area)
        {
            max_area = temp;
        }
    }

    return max_area;
}

int rect1(vector<vector<int>> v, int n, int m)
{
    vector<vector<int>> temp(n, vector<int>(m));
    int maxArea = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                temp[i][j] = j == 0 ? 1 : temp[i][j - 1] + 1;

                int width = temp[i][j];

                for (int k = i; k >= 0; k--)
                {
                    width = min(width, temp[k][j]);
                    maxArea = max(maxArea, width * (i - k + 1));
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

    return maxArea;
}

int findMaxValue(vector<vector<int>> &mat, int n)
{
    // Write your code here.
    int a = 0, b = 0;
    int c = n - 1, d = n - 1;

    int minN = mat[a][b];
    int maxN = mat[c][d];
    int res = INT_MIN;

    for (a = 0, c = n - 1; (c > a); a++, c--)
    {
        for (b = 0, d = n - 1; (d > b); b++, d--)
        {
            cout << a << " " << b << " - " << c << " " << d << endl;
        }
    }

    return res;
}

bool checkString(string s1, string s2, int ind, int n)
{
    for (int i = 0; i < n; i++, ind++)
    {
        if (s1[i] != s2[ind % n])
        {
            return false;
        }
    }

    return true;
}

void getFrequencies(vector<int> &v)
{
    // Write Your Code Here
    int n = v.size();
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }

    vector<int> res;
    int minFreq = INT_MAX, maxFreq = INT_MIN;
    int minRes, maxRes;

    for (auto x : mp)
    {
        if (x.second < minFreq)
        {
            minFreq = x.second;
            minRes = x.first;
        }
        else if (x.second == minFreq)
        {
            minRes = min(minRes, x.first);
        }

        if (x.second > maxFreq)
        {
            maxFreq = x.second;
            maxRes = x.first;
        }
        else if (x.second == maxFreq)
        {
            maxRes = min(maxRes, x.first);
        }
    }

    res.push_back(maxRes);
    res.push_back(minRes);

    for (auto x : res)
    {
        cout << x << "  ";
    }
    cout << endl;
}

void modifiedMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int j = 0; j < m; j++)
    {
        int colMax = INT_MIN;
        vector<int> negInd;

        for (int i = 0; i < n; i++)
        {
            colMax = max(colMax, matrix[i][j]);
            if (matrix[i][j] == -1)
            {
                negInd.push_back(i);
            }
        }

        for (auto x : negInd)
        {
            matrix[x][j] = colMax;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void findTwoElement(vector<int> arr, int n)
{
    // code here
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            res.push_back(i + 1);
        }
        else if (arr[arr[i] - 1] > 0)
        {
            arr[arr[i] - 1] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            res.push_back(i + 1);
    }

    for (auto x : res)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void fourSum(vector<int> &arr, int sum)
{
    // Your code goes here

    vector<vector<int>> res;

    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (auto x : arr)
        cout << x << " ";
    cout << endl;

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            for (int k = j + 2; k < n - 1; k += 2)
            {
                if (arr[i] + arr[j] + arr[k - 1] + arr[k] == sum)
                {
                    res.push_back(vector<int>{arr[i], arr[j], arr[k - 1], arr[k]});
                }

                if (arr[k + 1] < n)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[k + 1] == sum)
                    {
                        res.push_back(vector<int>{arr[i], arr[j], arr[k], arr[k + 1]});
                    }
                }
            }
        }
    }

    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

void FindMaxSum(vector<int> arr, int n)
{
    // Your code here
    int sum = 0;
    vector<int> sumArr(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            sumArr[i] = arr[i];
        }
        else if (i == 1)
        {
            sumArr[i] = max(sumArr[i - 1], arr[i]);
        }
        else
        {
            sumArr[i] = max(arr[i], arr[i] + sumArr[i - 2]);
        }
    }

    for (auto x : sumArr)
    {
        cout << x << "  ";
    }
    cout << endl;
}

long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    sort(arr, arr + n);
    long long count = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            long long temp = arr[i] + arr[k] + arr[j];
            if (temp >= sum)
            {
                k--;
            }
            else
            {
                count += (k - j);
                j++;
            }
        }
    }

    return count;
}

void ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // Write your code here.

    int newN = n;

    for (int j = 0; j < m; j++)
    {
        int index = -1;
        for (int i = 0; i < newN; i++)
        {
            if (arr1[i] > arr2[j])
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            arr1[newN] = arr2[j];
            newN += 1;
        }
        else
        {
            for (int k = n + m - 1; k > index; k--)
            {
                arr1[k] = arr1[k - 1];
            }
            arr1[index] = arr2[j];
            newN += 1;
        }
    }

    for (int i = 0; i < n + m; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}

void findSubarray(vector<long long int> &arr, int n)
{
    // code here
    map<long long, long long> mp;
    mp[0] = 1;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (mp.find(sum) != mp.end())
        {
            count += mp[sum];
        }

        mp[sum] += 1;
    }
    cout << count << endl;
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

Node *removeDuplicates(Node *head)
{
    // your code goes here
    if (!head)
        return head;

    map<int, int> mp;

    Node *p1 = head, *prev = NULL;

    while (p1 != NULL)
    {

        if (mp[p1->data] > 0)
        {
            prev->next = p1->next;
        }
        else
        {
            prev = prev->next;
        }

        p1 = p1->next;

        mp[p1->data]++;
    }

    while(head != NULL) {
        
    }
}

int main()
{
    vector<long long> arr{1, 0};
    productExceptSelf(arr, 2);

    return 0;
}