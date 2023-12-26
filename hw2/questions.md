# Questions

插入排序法

## Source code

> [!NOTE]
> 以下 code 已成功實作

### [hw2.cpp](./hw2.cpp)

```cpp
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int *arr;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        insertion_sort(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
```

```console
$ g++ ./hw2.cpp -O2
$ ./a.out
5
2 8 5 9 2
1 2 3 4 5
0
```
