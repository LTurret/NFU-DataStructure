# Questions

字母排序

> [!WARNING]
> 這裡還沒辦法完全照大小排序，必須實作

## Source code

> [!NOTE]
> 以下 code 已成功實作

### [hw4.cpp](./hw4.cpp)

```cpp
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
```

```console
$ g++ hw4.cpp -O2
$ ./a.out
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 3 2
1 4 2 3
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 3 1
2 4 1 3
3 2 1 4
3 2 4 1
3 1 2 4
3 1 4 2
3 4 1 2
3 4 2 1
4 2 3 1
4 2 1 3
4 3 2 1
4 3 1 2
4 1 3 2
4 1 2 3
```
