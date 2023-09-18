# Questions

為甚麼我不能在 `copy()` 內部 allocate 新的記憶體空間  
當變數 `cp` 離開 `copy()` 之後變數裡的資料全都被清除了

```cpp
#include <iostream>

using namespace std;

void copy(int *begin, int *end, int *result) {
    int len = end - begin;
    result = new int[len];

    for (int i=0; i<len; i++) {
        result[i] = *(begin + i);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *cp;
    copy(begin(arr), end(arr), cp);

    for (int i=0; i<5; i++) {
        cout << cp[i]; //發生益位或存取NULL
    }

    delete cp;
}
```

## Source code

> [!NOTE]
> 以下 code 已成功實作

### [hw1.cpp](./hw1.cpp)

```cpp
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
```
