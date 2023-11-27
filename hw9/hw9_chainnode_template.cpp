#include <iostream>

using namespace std;

template <class T>
class ChainNode {
   public:
    ChainNode(T data = 0, ChainNode *next = 0);
    void Create2();
    T data;
    ChainNode *next;
};

template <class T>
ChainNode<T>::ChainNode(T data, ChainNode *next) {
    this->data = data;
    this->next = next;
}

template <class T>
void ChainNode<T>::Create2() {
    ChainNode<int> *second = new ChainNode(10, 0);
    next = second;
}

int main() {
    ChainNode<int> head;
    cout << head.data << endl;

    head.Create2();
    head = *head.next;
    cout << head.data << endl;
}
