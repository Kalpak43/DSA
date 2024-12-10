#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &arr, int begin = 0, int pivot = -1)
{

    int size = pivot - begin;

    if (size <= 0)
        return;

    int maxInd = -1;
    for (int i = begin; i < pivot; i++)
    {
        if (arr[i] < arr[pivot])
        {
            if ((arr[i] < arr[maxInd]) && (maxInd != -1))
            {
                swap(arr[i], arr[maxInd]);
                maxInd = i;
            }
        }
        else
        {
            if(maxInd == -1) {
                maxInd = i;
            } else {
                arr[i] > arr[maxInd] ? maxInd = i : maxInd = maxInd;
            }
        }
    }

    if(maxInd != -1) swap(arr[pivot], arr[maxInd]);

    maxInd == -1 ? quick_sort(arr, begin, pivot-1) : (quick_sort(arr, begin, maxInd-1), quick_sort(arr, maxInd + 1, size));
    
    return;
}

int main(int n, char** args)
{

    vector<int> arr{5, 1, 4, 2, 5, 3, 2};
    int size = arr.size();

    quick_sort(arr, 0, size - 1);

    for (auto x : arr)
    {
        cout << x << "    ";
    }

    cout << endl;
    return 0;
}