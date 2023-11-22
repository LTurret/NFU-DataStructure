# Questions

手刻容器 - 佇列

## Source code

### [hw8.cpp](./hw8.cpp)

```cpp
#include <iostream>
#include <ostream>

using namespace std;

template <typename T> class Queue {
  public:
    Queue();
    void push(T);
    T pop();
    bool is_empty();
    bool is_full();

  private:
    int capacity;
    int size;
    int front;
    int rear;
    T *arr;
};

template <typename T>
Queue<T>::Queue() : capacity(5), front(0), rear(0), size(0) {
    arr = new T[capacity];
}

template <typename T> T Queue<T>::pop() {
    if (is_empty()) {
        throw "queue is empty";
    }
    size--;
    return arr[front++];
}

template <typename T> void Queue<T>::push(T data) {
    if (is_full()) {
        throw "queue is max";
    }
    arr[rear++ % capacity] = data;
    size++;
}

template <typename T> bool Queue<T>::is_empty() {
    return front == rear ? true : false;
}

template <typename T> bool Queue<T>::is_full() {
    return rear % capacity == front && size == capacity ? true : false;
}

int main() {
    Queue<int> q;
    cout << q.is_empty() << endl;
    q.push(1);
    cout << q.is_empty() << endl;
    q.pop();
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q.is_full() << endl;
}
```

```console
$ g++ main.cpp -O2
$ ./a.out
1
0
1
```
