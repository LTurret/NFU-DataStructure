#include <iostream>

using namespace std;

class ChainNode;
class Chain {
   public:
    Chain() { first = 0; };
    ChainNode *first;
};

class ChainNode {
   public:
    ChainNode(int data = 0) : next(0) { this->data = data; };
    int data;
    ChainNode *next;
};

int main() {
    ChainNode n1(21);
    cout << n1.data;
}
