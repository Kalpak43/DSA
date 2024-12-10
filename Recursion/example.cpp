#include <iostream>
#include <map>
using namespace std;


int countSpeakers(int n)
{
    if(n == 0) return 0;

    if(n % 2 == 0)
    {
        return 2 + countSpeakers(n-1);
    }
    else
    {
        return 1 + countSpeakers(n-1);
    }
}

int allSum(int n)
{
    if(n >= 0 && n < 10) return n;

    return n % 10 + allSum(n/10);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    cout << allSum(12345) << endl;

    return 0;
}