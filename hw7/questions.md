# Questions

手刻容器 - 堆疊

## Source code

### [hw7.cpp](./hw7.cpp)

```cpp
#include <iostream>

using namespace std;

template <class T> class Stack {
  public:
    Stack();
    void push(T item);
    void pop();
    bool is_empty();
    T &Top() const;

  private:
    int capacity;
    int top;
    void extend();
    T *stack_array;
};

template <class T> Stack<T>::Stack() : capacity(2), top(0) {
    stack_array = new T[capacity];
};

template <class T> inline void Stack<T>::push(T item) {
    if (top >= capacity)
        extend();
    stack_array[top++] = item;
};

template <class T> inline void Stack<T>::pop() {
    if (is_empty())
        throw "Stack is empty";
    stack_array[--top].~T();
}

template <class T> T &Stack<T>::Top() const { return stack_array[top - 1]; }

template <class T> bool Stack<T>::is_empty() { return (top == 0); }

template <class T> void Stack<T>::extend() {
    int new_size = capacity * 2;
    T *temp = new T[new_size];
    copy(stack_array, stack_array + capacity, temp);
    delete[] stack_array;
    stack_array = temp;
}

int main() {
    Stack<int> s1;
    s1.push(2);
    s1.push(4);
    s1.push(8);
    s1.push(16);
    cout << s1.Top();
}
```

```console
$ g++ main.cpp -O2
$ ./a.out
16
```
