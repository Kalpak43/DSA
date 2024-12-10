#include <iostream>
using namespace std;

int swap(int a, int b) {
    int temp = a;
    int c = temp;
    a = b;
    b = temp;

    return 0;
}

int main() {
    int a = 1, b = 2;
    swap(a, b);

    return 0;
}