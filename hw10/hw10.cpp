#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

class Polynomial;
class Node {
    friend Polynomial;
    friend istream &operator>>(istream &is, Polynomial &poly);
    friend ostream &operator<<(ostream &os, Polynomial &poly);

   public:
    Node(int coef = 0, int exp = -1, Node *link = nullptr) {
        this->coef = coef;
        this->exp = exp;
        this->link = link;
    }

   private:
    int coef;
    int exp;
    Node *link;
};

class Polynomial {
    friend Node;
    friend istream &operator>>(istream &is, Polynomial &poly);
    friend ostream &operator<<(ostream &os, Polynomial &poly);

   public:
    Polynomial() {
        head = new Node();
        head->link = head;
    };
    float Evaluate(float x) const;

   private:
    Node *head;
};

istream &operator>>(istream &is, Polynomial &poly) {
    int n;
    is >> n;
    if (n == 0) throw "Polynomial cannot has 0 term.";
    Node *tail = nullptr;
    for (int i = 0; i < n; i++) {
        int coef, exp;
        is >> coef >> exp;
        if (exp < 0) throw "Exponent cannot assign less than 0.";
        if (poly.head->link == poly.head) {
            tail = new Node(coef, exp, poly.head);
            poly.head->link = tail;
        } else {
            tail->link = new Node(coef, exp, poly.head);
            tail = tail->link;
        }
    }
    return is;
};

ostream &operator<<(ostream &os, Polynomial &poly) {
    Node *ptr = poly.head;
    while (ptr->link != poly.head) {
        ptr = ptr->link;
        if (abs(ptr->coef) > 1 || ptr->exp == 0) os << abs(ptr->coef);
        if (ptr->exp != 0) os << "x^" << ptr->exp;
        if (ptr->link != poly.head) {
            if (ptr->link->coef > 0) {
                os << " + ";

            } else {
                os << " - ";
            }
        }
    }
    return os;
};

float Polynomial::Evaluate(float x) const {
    float sum;
    Node *ptr = this->head;
    while (ptr->link != this->head) {
        ptr = ptr->link;
        sum += ptr->coef * pow(x, ptr->exp);
    }
    return sum;
};

int main() {
    Polynomial poly;
    cin >> poly;
    cout << poly;
}