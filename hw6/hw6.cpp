#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>

using namespace std;

class Polynomial;
class Term {
    friend Polynomial;
    friend ostream &operator<<(ostream &os, const Polynomial &polynomial);

  private:
    float coef;
    int exp;
};

class Polynomial {
    friend ostream &operator<<(ostream &os, const Polynomial &polynomial);

  public:
    Polynomial();
    Polynomial Add(Polynomial polynomial);
    Polynomial Mult(Polynomial polynomial);
    float Eval(const float parameter);
    void new_term(const float coef, const int exp);

  private:
    Term *term_array;
    int capacity;
    int terms;
};

ostream &operator<<(ostream &os, const Polynomial &polynomial) {
    for (int i = 0; i < polynomial.terms; i++) {
        os << "(" << polynomial.term_array[i].coef << ", " << polynomial.term_array[i].exp << ")";
    }
    return os;
}

Polynomial::Polynomial() : capacity(1), terms(0) { term_array = new Term[capacity]; }

Polynomial Polynomial::Add(Polynomial polynomial) {
    Polynomial result;
    int p1 = 0, p2 = 0;
    while ((p1 <= this->terms) && (p2 <= polynomial.terms)) {
        if ((this->term_array[p1].exp) == (polynomial.term_array[p2].exp)) {
            result.new_term((this->term_array[p1].coef + polynomial.term_array[p2].coef), this->term_array[p1].exp);
            p1++, p2++;
        } else if ((this->term_array[p1].exp) > (polynomial.term_array[p2].exp)) {
            result.new_term((this->term_array[p1].exp), (this->term_array[p1].exp));
            p1++;
        } else {
            result.new_term((polynomial.term_array[p2].coef), (polynomial.term_array[p2].exp));
            p2++;
        }
    }
    return result;
}

Polynomial Polynomial::Mult(Polynomial polynomial) {
    Polynomial result;
    int maximun = polynomial.term_array[0].exp + this->term_array[0].exp;
    for (int i = maximun; i >= 0; i--) {
        result.new_term(0, i);
    }
    for (int i = 0; i < this->terms; i++) {
        for (int j = 0; j < polynomial.terms; j++) {
            int curr = this->term_array[i].exp + polynomial.term_array[j].exp;
            result.term_array[maximun - curr].coef += (this->term_array[i].coef * polynomial.term_array[j].coef);
        }
    }
    return result;
}

float Polynomial::Eval(const float parameter) {
    // remember do not just leave a blank variable, it will cause chaos.
    float result = 0.0;
    for (int i = 0; i < terms; i++) {
        result += term_array[i].coef * pow(parameter, term_array[i].exp);
    }
    return result;
}

void Polynomial::new_term(const float coef, const int exp) {
    if (terms == capacity) {
        int new_size = capacity * 2;
        Term *temp_array = new Term[new_size];
        copy(term_array, term_array + terms, temp_array);
        capacity = new_size;
        delete[] term_array;
        term_array = temp_array;
    }

    term_array[terms].coef = coef;
    term_array[terms++].exp = exp;
}

int main() {
    Polynomial p1, p2;
    p1.new_term(2, 2);
    p1.new_term(3, 1);
    p1.new_term(-2, 0);

    p2.new_term(4, 3);
    p2.new_term(12, 2);
    p2.new_term(3, 1);
    cout << "p1: " << p1 << ", p2: " << p2 << endl;
    cout << p1.Eval(3) << endl;

    cout << p1.Add(p2) << endl;

    cout << p1.Mult(p2) << endl;
}
