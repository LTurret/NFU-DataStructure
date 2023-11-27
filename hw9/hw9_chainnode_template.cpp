#include <iostream>

using namespace std;

template <typename T> class Node {

  public:
    T data;
    Node *next;
};

template <typename T> class ChainNode {

  public:
    ChainNode(int data, ChainNode *next);
    void Create2();

  private:
    T data;
    Node<T> *next;
};

template <typename T>
ChainNode<T>::ChainNode(int data = 0, ChainNode<T> *next = 0) {
    data = data;
    next = next;
}

template <typename T> void ChainNode<T>::Create2() {
    T = data;
    ChainNode *second = new ChainNode(10, 0);
    ChainNode first(20, second);
}

int main() {
    ChainNode<int> first;
    first.Create2();
}
