# Questions

## Improvement

> [!WARNING]
> 這演算法非常北爛，建議是重寫

請用真正的 ADT 寫齁，這啥小

## Source code

> [!NOTE]
> 以下 code 已成功實作

### [hw3.cpp](./hw3.cpp)

```cpp
#include <iostream>
using namespace std;

int BinarySearch(int *arr, int target, const int n)
{
    // Implement binary search
    int left, right, middle;
    left = 0;
    right = n - 1;
    for (int i = 0; i < 10000; i++)
    {
        middle = (left + right) / 2;

        if (arr[middle] == target)
        {
            return middle + 1;
        }

        if (target < arr[middle])
        {
            right = middle - 1;
        }
        else if (target > arr[middle])
        {
            left = middle + 1;
        }

        if (arr[middle] == target)
        {
            return middle + 1;
        }
    }
    return -1;
}

int main()
{
    while (true)
    {
        int input[2] = {};
        for (int i = 0; i < 2; i++)
        {
            cin >> input[i];
        }

        if (input[0] == 0)
            return 0;

        int arr[input[0]] = {};

        for (int i = 0; i < input[0]; i++)
        {
            cin >> arr[i];
        }

        cout << BinarySearch(arr, input[1], input[0]) << endl;
    }
}
```

```console
$ g++ ./hw3.cpp -O2
$ ./a.out
5 13
1 3 7 13 26
4
7 100
100 200 300 400 500 600 700
1
0 0
```
