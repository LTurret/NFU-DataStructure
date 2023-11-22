#include <iostream>

using namespace std;

void selection_sort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        int ptr = i;

        while (ptr) {
            if (arr[ptr] < arr[ptr - 1]) {
                int dum = arr[ptr];
                arr[ptr] = arr[ptr - 1];
                arr[ptr - 1] = dum;
            }
            ptr--;
        }
    }
}

int main() {
    while (true) {
        int len;
        cin >> len;

        if (!len)
            return 0;

        int arr[len];
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }

        selection_sort(arr, len);

        for (int i = 1; i <= len; i++) {
            cout << i;
            if (i != len) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}