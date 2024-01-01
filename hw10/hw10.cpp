#include <chrono>
#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;
using namespace std::chrono;

class Polynomial;
class Node {
    friend Polynomial;
    friend istream &operator>>(istream &is, Polynomial &poly);
    friend ostream &operator<<(ostream &os, Polynomial &poly);

   public:
    // 多項式節點的建構函式
    Node(int coef = 0, int exp = -1, Node *link = nullptr) {
        this->coef = coef;
        this->exp = exp;
        this->link = link;
    }

   private:
    int coef;    // 系數
    int exp;     // 指數
    Node *link;  // 指向下一個節點的指標
};

class Polynomial {
    friend Node;
    friend istream &operator>>(istream &is, Polynomial &poly);
    friend ostream &operator<<(ostream &os, Polynomial &poly);

   public:
    // 多項式的頭節點
    inline Polynomial() {
        head = new Node();
        head->link = head;
    };

    Polynomial(const Polynomial &poly);
    ~Polynomial();
    Polynomial &operator=(const Polynomial &poly) {
        if (this != &poly) {
            // 在複製之前必須先釋放內存
            if (dump == nullptr) {
                dump = new Node();
                dump->link = dump;
            }

            Node *ptr = head;
            while (ptr->link != head) {
                ptr = ptr->link;
            }
            ptr->link = dump;
            dump->link = ptr;
            head->link = head;

            // 開始複製
            ptr = poly.head;
            Node *tail = new Node();

            if (ptr->link != poly.head) head->link = tail;

            while (ptr->link != poly.head) {
                ptr = ptr->link;
                tail->link = new Node(ptr->coef, ptr->exp, head);
                tail = tail->link;
            }
        }
        return *this;
    };

    // 多載加法運算子
    Polynomial operator+(const Polynomial &poly) const {
        Polynomial result;
        Node *p1 = this->head->link;
        Node *p2 = poly.head->link;
        Node *p3 = result.head;

        while (p1 != this->head || p2 != poly.head) {
            if (p2 == poly.head || (p1 != this->head && p1->exp > p2->exp)) {
                p3->link = new Node(p1->coef, p1->exp, result.head);
                p3 = p3->link;
                p1 = p1->link;
            } else if (p1 == this->head || (p2 != poly.head && p1->exp < p2->exp)) {
                p3->link = new Node(p2->coef, p2->exp, result.head);
                p3 = p3->link;
                p2 = p2->link;
            } else {
                int coef = p1->coef + p2->coef;
                if (coef) p3->link = new Node(coef, p1->exp, result.head);
                p3 = p3->link;
                p1 = p1->link;
                p2 = p2->link;
            }
        }

        return result;
    };

    // 多載減法運算子
    Polynomial operator-(const Polynomial &poly) const {
        Polynomial result;
        Node *p1 = this->head->link;
        Node *p2 = poly.head->link;
        Node *p3 = result.head;

        while (p1 != this->head || p2 != poly.head) {
            if (p2 == poly.head || (p1 != this->head && p1->exp > p2->exp)) {
                p3->link = new Node(p1->coef, p1->exp, result.head);
                p3 = p3->link;
                p1 = p1->link;
            } else if (p1 == this->head || (p2 != poly.head && p1->exp < p2->exp)) {
                p3->link = new Node(p2->coef, p2->exp, result.head);
                p3 = p3->link;
                p2 = p2->link;
            } else {
                int coef = p1->coef - p2->coef;
                if (coef) p3->link = new Node(coef, p1->exp, result.head);
                p3 = p3->link;
                p1 = p1->link;
                p2 = p2->link;
            }
        }

        return result;
    };

    // 多載乘法運算子
    Polynomial operator*(const Polynomial &poly) const {
        Polynomial result;
        Node *p1 = this->head->link;

        while (p1 != this->head) {
            Node *p2 = poly.head->link;
            while (p2 != poly.head) {
                int coef = p1->coef * p2->coef;
                int exp = p1->exp + p2->exp;
                Node *p3 = result.head;
                while (true) {
                    if (p3->link == result.head || p3->link->exp < exp) {
                        p3->link = new Node(coef, exp, p3->link);
                        break;
                    } else if (p3->link->exp == exp) {
                        p3->link->coef += coef;
                        if (p3->link->coef == 0) {
                            Node *temp = p3->link;
                            p3->link = temp->link;
                            delete temp;
                        }
                        break;
                    }
                    p3 = p3->link;
                }
                p2 = p2->link;
            }
            p1 = p1->link;
        }

        return result;
    };

    // 計算多項式在給定x值時的值
    float Evaluate(float x) const;

   private:
    Node *head;  // 指向多項式的頭節點
    Node *dump;  // 用於臨時存儲的節點，用於賦值運算子的實現
};

// 多載輸入運算子
istream &operator>>(istream &is, Polynomial &poly) {
    cout << "Start creating your polynomial." << endl << "Determin n-th terms: ";
    int n;
    is >> n;
    if (n == 0) throw "Polynomial cannot has 0 term.";
    Node *tail = nullptr;
    for (int i = 0; i < n; i++) {
        int coef, exp;
        cout << "Enter term (coef, exp): ";
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

// 多載輸出運算子
ostream &operator<<(ostream &os, Polynomial &poly) {
    Node *ptr = poly.head;
    while (ptr->link != poly.head) {
        ptr = ptr->link;
        if (abs(ptr->coef) > 1 || ptr->exp == 0) os << abs(ptr->coef);
        if (ptr->exp > 0) os << "x^" << ptr->exp;
        if (ptr->link != poly.head && ptr->coef > 0) {
            if (ptr->link->coef > 0) {
                os << " + ";

            } else {
                os << " - ";
            }
        }
    }
    return os;
};

// 複製建構函式實例
Polynomial::Polynomial(const Polynomial &poly) : dump(nullptr) {
    Node *ptr = poly.head;
    ptr = ptr->link;

    head = new Node();
    Node *tail = new Node(ptr->coef, ptr->exp, head);
    head->link = tail;

    while (ptr->link != poly.head) {
        ptr = ptr->link;
        tail->link = new Node(ptr->coef, ptr->exp, head);
        tail = tail->link;
    }
};

// 解構函式實例
Polynomial::~Polynomial() {
    Node *ptr = head;
    while (ptr != head) {
        Node *next = ptr->link;
        delete ptr;
        ptr = next;
    }
    delete head;
}

// 計算多項式在給定x值時的值
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
    Polynomial p1, p2, p3;
    cin >> p1;
    cin >> p2;
    auto start = high_resolution_clock::now();
    cout << "p1 and p2 are: " << endl;
    cout << p1 << endl << p2 << endl << endl;

    cout << "Testing Copy() :" << endl;
    Polynomial p4(p2);
    cout << "Polynomial p4(p2) = " << p4 << endl << endl;

    cout << "Testing = :" << endl;
    Polynomial p5;
    p5 = p1;
    cout << "p3 = p1 = " << p3 << endl << endl;

    cout << "Testing - :" << endl;
    p3 = p1 * p2;
    cout << p3 << endl << endl;

    cout << "Testing * :" << endl;
    p3 = p1 * p2;
    cout << p3 << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " ms" << endl;
}
