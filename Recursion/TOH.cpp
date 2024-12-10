#include<iostream>
using namespace std;

// Tower of hanoi

void TOH(int n, char source, char dest, char aux)
{
    if(n == 0)
    {
        return;
    }

    TOH(n-1, source, aux, dest);
    cout << "Disk " << n << " Moved from " << source << " to " << dest << endl;
    TOH(n-1, aux, dest, source);
}

int main()
{
    int n = 3;
    TOH(n, 'A', 'B', 'C');

    return 0;
}