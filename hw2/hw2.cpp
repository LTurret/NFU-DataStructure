#include <iostream>

using namespace std;

void intersection_sort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while (i > -1 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int len;
    while (cin >> len) {
        int *arr;
        arr = new int[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }
        intersection_sort(arr, len);
        for (int i = 0; i < len; i++) {
            cout << arr[i];
            if (i != len - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}