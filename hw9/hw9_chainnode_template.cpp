#include <iostream>

using namespace std;

template <class T>
class ChainNode {
   public:
    ChainNode(T data = 0) : next(0) { this->data = data; };
    T data;
    ChainNode *next;
};

template <class T>
class Chain {
   public:
    Chain() { this->first = 0; };
    ChainNode<T> *first;
};

int main() {
    ChainNode<int> n1(21);
    cout << n1.data;
}
