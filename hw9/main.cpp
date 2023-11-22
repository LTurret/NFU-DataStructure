#include <iostream>

using namespace std;

class Chain;
class Node {
    friend Chain;

  public:
    int value;
    int &link;
};

class Chain {
  public:
    void insert(int);
};

int main() {
    int a = 3;
    cout << &a;
}
