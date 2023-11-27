#include <iostream>

using namespace std;

class ChainNode {
   public:
    ChainNode(int data = 0, ChainNode *next = 0);
    void Create2();
    int data;
    ChainNode *next;
};

ChainNode::ChainNode(int data, ChainNode *next) {
    this->data = data;
    this->next = next;
}

void ChainNode::Create2() {
    ChainNode *second = new ChainNode(10, 0);
    next = second;
}

int main() {
    ChainNode head;
    cout << head.data << endl;

    head.Create2();
    head = *head.next;
    cout << head.data << endl;
}
