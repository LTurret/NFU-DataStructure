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