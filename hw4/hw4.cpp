#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int dum = a;
    a = b;
    b = dum;
}

void perm(int *a, const int k, const int m) {
    if (k == m) {
        for (int i=0; i<=m; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        for (int i=k; i<=m; i++) {
            swap(a[k], a[i]);
            perm(a, k+1, m);
            swap(a[k], a[i]);
        }
    }
}

int main() {
    int a[4] = {1, 2, 3, 4};
    int k = 0;
    int m = 3;

    perm(a, k, m);
}
