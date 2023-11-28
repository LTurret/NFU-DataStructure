# Questions

遞迴

[Notion 版](https://lturret.notion.site/Ackermann-s-function-hw-report-52a060a8c00b428ab059bf6e3702f671?pvs=4)

## Source code

> [!NOTE]
> 以下 code 已成功實作
> 詳細解題報告請至 Notion 版裡

### [hw5-1.cpp](./hw5-1.cpp)

```cpp
#include <iostream>

using namespace std;

int ack(int m, int n) {
    while (m) {
        if (n == 0) {
            return ack(m - 1, 1);
        } else {
            return ack(m - 1, ack(m, n - 1));
        }
        m--;
    }
    return n + 1;
}

int main(void) {
    cout << ack(0, 0) << endl;
    cout << ack(0, 1) << endl;
    cout << ack(1, 0) << endl;
    cout << ack(1, 1) << endl;
    cout << ack(2, 1) << endl;
    cout << ack(3, 1) << endl;
}
```

```console
$ g++ main.cpp -O2
$ ./a.out
1
2
2
3
5
13
```
