#include <iostream>

using namespace std;

void swap(int& a, int& b) {
    int* dum = &a;
    a = b;
    b = *dum;
}

void copy(int* begin, int* end, int* result) {
    
    int len = end - begin;

    for (int i = 0; i < len; i++) {
        result[i] = *(begin + i);
    }
}

int main() {
    int a = 1;
    int b = 5;
    swap(a, b);

    int arr[] = { 2, 8, 5, 9, 2 };
    int* cp = new int[sizeof(arr) / sizeof(int)];
    copy(begin(arr), end(arr), cp);

    for (int i = 0; i < 5; i++) {
        cout << cp[i];
    }

    delete[] cp;

    return 0;
}
