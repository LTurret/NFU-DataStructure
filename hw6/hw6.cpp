#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;
using namespace std::chrono;

class Polynomial;
class Term {
    friend Polynomial;
    friend ostream &operator<<(ostream &os, const Polynomial &polynomial);
    friend istream &operator>>(istream &in, Polynomial &polynomial);

  private:
    float coef;
    int exp;
};

class Polynomial {
    friend ostream &operator<<(ostream &os, const Polynomial &polynomial);
    friend istream &operator>>(istream &in, Polynomial &polynomial);

  public:
    Polynomial();
    Polynomial Add(Polynomial polynomial);
    Polynomial Mult(Polynomial polynomial);
    float Eval(const float parameter);

  private:
    Term *term_array;
    int capacity;
    int terms;
};

ostream &operator<<(ostream &os, const Polynomial &polynomial) {
    for (int i = 0; i < polynomial.terms; i++) {
        if (polynomial.term_array[i].coef != 0) {
            os << "(" << polynomial.term_array[i].coef << ", " << polynomial.term_array[i].exp << ")";
        }
    }
    return os;
}

istream &operator>>(istream &in, Polynomial &polynomial) {
    float coef;
    int exp;

    in >> coef >> exp;

    if (polynomial.terms == polynomial.capacity) {
        int new_size = polynomial.capacity * 2;
        Term *temp = new Term[new_size];
        copy(polynomial.term_array, polynomial.term_array + polynomial.terms, temp);
        polynomial.capacity = new_size;
        delete[] polynomial.term_array;
        polynomial.term_array = temp;
    }

    polynomial.term_array[polynomial.terms].coef = coef;
    polynomial.term_array[polynomial.terms++].exp = exp;

    return in;
}

Polynomial::Polynomial() : capacity(4), terms(0) { term_array = new Term[capacity]; }

Polynomial Polynomial::Add(Polynomial polynomial) {
    Polynomial result;
    int p1 = 0, p2 = 0;
    while ((p1 <= this->terms) && (p2 <= polynomial.terms)) {
        float coef;
        int exp;
        if ((this->term_array[p1].exp) == (polynomial.term_array[p2].exp)) {
            coef = this->term_array[p1].coef + polynomial.term_array[p2].coef;
            exp = this->term_array[p1].exp;
            p1++, p2++;
        } else if ((this->term_array[p1].exp) > (polynomial.term_array[p2].exp)) {
            coef = this->term_array[p1].coef;
            exp = this->term_array[p1].exp;
            p1++;
        } else {
            coef = polynomial.term_array[p2].coef;
            exp = polynomial.term_array[p2].exp;
            p2++;
        }
        if (result.terms == result.capacity) {
            int new_size = result.capacity * 2;
            Term *temp_array = new Term[new_size];
            copy(result.term_array, result.term_array + result.terms, temp_array);
            result.capacity = new_size;
            delete[] result.term_array;
            result.term_array = temp_array;
        }
        result.term_array[result.terms].coef = coef;
        result.term_array[result.terms++].exp = exp;
    }
    return result;
}

Polynomial Polynomial::Mult(Polynomial polynomial) {
    Polynomial result;
    result.term_array = new Term[this->capacity * polynomial.capacity];
    int maximun = polynomial.term_array[0].exp + this->term_array[0].exp;
    for (int i = maximun; i >= 0; i--) {
        result.term_array[result.terms].coef = 0;
        result.term_array[result.terms++].exp = i;
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
    float result = 0.0;
    for (int i = 0; i < terms; i++) {
        result += term_array[i].coef * pow(parameter, term_array[i].exp);
    }
    return result;
}

int main() {
    Polynomial p1, p2;
    int c1, c2, x = 5;
    cout << "determin c1: ";
    cin >> c1;
    cout << "p1: ";
    for (int i = 0; i < c1; i++) {
        cin >> p1;
    }
    cout << p1 << endl;

    cout << "determin c2: ";
    cin >> c2;
    cout << "p2: ";
    for (int i = 0; i < c2; i++) {
        cin >> p2;
    }

    cout << p2 << endl;

    // p1.new_term(2, 2);
    // p1.new_term(3, 1);
    // p1.new_term(-2, 0);

    // p2.new_term(4, 3);
    // p2.new_term(12, 2);
    // p2.new_term(3, 1);

    cout << endl << "p1: " << p1 << ", p2: " << p2 << endl << endl;

    auto start = high_resolution_clock::now();
    cout << "Add: " << p1.Add(p2) << endl;
    cout << "Mult: " << p1.Mult(p2) << endl;

    cout << "f(x), x=";
    // cin >> x;
    cout << "Eval: " << p1.Eval(x) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " ms" << endl;
}
