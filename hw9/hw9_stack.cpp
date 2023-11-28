#include <iostream>

using namespace std;

template <class T>
class ChainNode {
   public:
    ChainNode(T data = 0, ChainNode<T> *next = 0) : data(data), next(next) {}
    T data;
    ChainNode<T> *next;
};

template <class T>
class LinkedStack {
   public:
    LinkedStack() : top(0) {}
    ~LinkedStack();
    bool isEmpty() const { return top == 0; }
    T &Top() const;
    void Push(const T &item);
    void Pop();

   private:
    ChainNode<T> *top;
};

template <class T>
LinkedStack<T>::~LinkedStack() {
    while (top != NULL) {
        ChainNode<T> *nextNode = top->next;
        delete top;
        top = nextNode;
    }
}

template <class T>
T &LinkedStack<T>::Top() const {
    if (isEmpty()) throw "Stack is empty";
    return top->data;
}

template <class T>
void LinkedStack<T>::Push(const T &item) {
    top = new ChainNode<T>(item, top);
}

template <class T>
void LinkedStack<T>::Pop() {
    if (isEmpty()) throw "Stack is empty. Cannot delete.";
    ChainNode<T> *nextNode = top->next;
    delete top;
    top = nextNode;
}

int main() {
    LinkedStack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    cout << stack.Top() << endl;  // Output: 3
    stack.Pop();
    cout << stack.Top() << endl;  // Output: 2
    return 0;
}
