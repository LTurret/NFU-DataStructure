#include <iostream>

using namespace std;

int ack(int m, int n) {
    while (m) {
        if (n == 0) { 
            return ack(m-1, 1);
        } else {
            return ack(m-1, ack(m,n-1));
        }
        m--;
    }
    return n+1;
}

int main(void) {
    cout << ack(0, 0) << endl;
    cout << ack(0, 1) << endl;
    cout << ack(1, 0) << endl;
    cout << ack(1, 1) << endl;
    cout << ack(2, 1) << endl;
    cout << ack(3, 1) << endl;
}