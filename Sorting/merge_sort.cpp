#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right)
{

    vector<int> result;

    int leftSize = left.size(), rightSize = right.size();
    int leftI = 0, rightI = 0;

    while ((leftI < leftSize) and (rightI < rightSize))
    {
        if (left[leftI] < right[rightI])
        {
            result.push_back(left[leftI]);
            leftI++;
        }
        else
        {
            result.push_back(right[rightI]);
            rightI++;
        }
    }

    while (leftI != leftSize)
    {
        result.push_back(left[leftI]);
        leftI++;
    }

    while (rightI != rightSize)
    {
        result.push_back(right[rightI]);
        rightI++;
    }

    return result;
}

vector<int> merge_sort(vector<int> arr)
{
    int size = arr.size();

    if (size < 2)
        return arr;

    int mid = size / 2;

    vector<int> left = merge_sort(vector<int>(arr.begin(), arr.begin() + mid));
    vector<int> right = merge_sort(vector<int>(arr.begin() + mid, arr.end()));

    return merge(left, right);
}

int main()
{

    vector<int> arr{1, 2, 5, 3, 6, 8, 7};

    vector<int> arr2 = merge_sort(arr);

    for (auto x : arr2)
    {
        cout << x << "  ";
    }

    cout << endl;
    return 0;
}