#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int dum = a;
    a = b;
    b = dum;
}

void copy(int *begin, int *end, int *result) {
    for (int i = 0; i < (end - begin); i++) {
        result[i] = *(begin + i);
    }
}

int main() {
    int a = 1;
    int b = 5;
    cout << "--SWAP--" << endl;
    cout << "before swap: "
         << "a=" << a << ", b=" << b << endl;
    swap(a, b);
    cout << "after swap: "
         << "a=" << a << ", b=" << b << endl;

    cout << endl;
    cout << "--COPY--" << endl;

    int arr[] = {2, 8, 5, 9, 2};
    int *cp = new int[sizeof(arr) / sizeof(int)];
    copy(begin(arr), end(arr), cp);

    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
        cout << cp[i] << " ";
    }

    delete[] cp;

    return 0;
}
