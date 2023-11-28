#include <iostream>

using namespace std;

template <class T>
class ChainNode {
   public:
    ChainNode(int data = 0, ChainNode<T> *next = 0) { this->data = data, this->next = next; };
    int data;
    ChainNode<T> *next;
};

template <class T>
class Chain {
   public:
    Chain() : first(0){};
    ~Chain();
    void insert(int index, T &element);
    void remove(int index);
    int index(T element);
    ChainNode<T> *first;
};

template <class T>
Chain<T>::~Chain() {
    while (first != NULL) {
        ChainNode<T> *next = first->next;
        delete first;
        first = next;
    }
}

template <class T>
void Chain<T>::insert(int index, T &element) {
    if (index < 0) throw "Bad insert index";

    if (index == 0) {
        first = new ChainNode<T>(element, first);
    } else {
        ChainNode<T> *curr = first;
        for (int i = 0; i < index - 1; i++) {
            if (curr = 0) throw "Bad insert index";
            curr = curr->next;
        }
        curr->next = new ChainNode<T>(element, curr->next);
    }
}

template <class T>
void Chain<T>::remove(int index) {
    if (first == 0) throw "Can't delete empty chain";

    ChainNode<T> *deleteNode;
    if (index == 0) {
        deleteNode = first;
        first = first->next;
    } else {
        ChainNode<T> *curr = first;
        for (int i; i < index - 1; i++) {
            if (curr == 0) throw "Bad deletion index";
            curr = curr->next;
        }
        deleteNode = curr->next;
        curr->next = curr->next->next;
    }
    delete deleteNode;
}

template <class T>
int Chain<T>::index(T element) {
    ChainNode<T> *curr = first;
    int i = 0;

    while (curr != 0 && curr->data != element) {
        curr = curr->next;
        i++;
    }

    return (curr == 0) ? i : -1;
}

int main() {
    Chain<int> head;
    int a = 15;
    int b = 20;
    int c = 25;

    head.insert(0, a);
    head.insert(0, b);
    head.insert(1, c);
    cout << head.first->data << endl;

    cout << head.index(15) << endl;
    cout << head.index(20) << endl;
    cout << head.index(25) << endl;

    head.remove(0);
    cout << "hi" << endl;
    cout << head.index(15) << endl;
    cout << head.index(20) << endl;
    cout << head.index(25) << endl;
}
