#include <iostream>

using namespace std;

class ChainNode {

  public:
    ChainNode(int data, ChainNode *next);
    void Create2();
    int data;
    ChainNode *next;
};

ChainNode::ChainNode(int data = 10, ChainNode *next = 0) {
    this->data = data;
    this->next = next;
}

void ChainNode::Create2() {
    ChainNode *second = new ChainNode(20, 0);
    next = second;
}

int main() {
    ChainNode head;
    cout << head.data << endl;

    head.Create2();
    head = *head.next;
    cout << head.data << endl;
}
