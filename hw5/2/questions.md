# Questions

遞迴

[Notion 版](https://lturret.notion.site/Supersets-function-hw-report-b1b9c6d9fe9848f59d0632af9c1142fd?pvs=4)

## Source code

> [!NOTE]
> 以下 code 已成功實作
> 詳細解題報告請至 Notion 版裡

### [hw5-2.cpp](./hw5-2.cpp)

```cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cout << ("請輸入集合元素總數：");
    cin >> n;

    // 產生宇集合 \mathbb{U}
    int u[n];

    // 初始化宇集合元素
    for (int i = 0; i < n; i++) {
        u[i] = i + 1;
    }

    // 設定長度，以bitwise實作
    /*
    00 00 00 01
    01 00 00 00 << 3
                 = 8
    */
    int len = (1 << n);

    // 格式化輸出
    cout << "S = {";

    // 遍歷n次，n \in |S|，|S| = 2^{|U|}
    for (int i = 0; i < (1 << n); i++) {
        cout << "(";
        for (int j = 0; j < i; j++) {
            if ((1 << j) & i) {
                cout << char(96 + u[j]);
            }
        }
        if (i == (1 << n) - 1) {
            cout << ")";
        } else {
            cout << "), ";
        }
    }
    cout << "}" << endl;
    // 完成輸出冪集合
}
```

```console
$ g++ main.cpp -O2
$ ./a.out
請輸入集合元素總數：4
S = {(), (a), (b), (ab), (c), (ac), (bc), (abc), (d), (ad), (bd), (abd), (cd), (acd), (bcd), (abcd)}
```
