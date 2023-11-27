#include <iostream>

using namespace std;

class Node {

  public:
    int data;
    Node *next;
};

class ChainNode {

  public:
    ChainNode(int data, ChainNode *next);
    void Create2();

  private:
    int data;
    Node *next;
};

ChainNode::ChainNode(int data = 0, ChainNode *next = 0) {
    data = data;
    next = next;
}

void ChainNode::Create2() {
    data = data;
    ChainNode *second = new ChainNode(10, 0);
    ChainNode first(20, second);
}

int main() {
    ChainNode first;
    first.Create2();
}
