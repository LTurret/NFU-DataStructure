# Questions

手刻容器

## Source code

### [hw6.cpp](./hw6.cpp)

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Polynomial;
class Term {
    friend Polynomial;
    private:
        int expo;
        int coef;
};

class Polynomial {
    public:
        Polynomial();
        void show_poly();
        void new_term(const int expo, const int coef);
        int solve(const int x);
    private:
        Term *term_array;
        int capacity;
        int terms;
        int show_terms();
        void expand_capacity(const int capacity, const Term *term_array);
};

Polynomial::Polynomial():capacity(1), terms(0) {
    term_array = new Term[capacity];
}

inline void Polynomial::show_poly() {
    for (int i = 0; i < terms; i++) {
        cout << term_array[i].coef << "x^" << term_array[i].expo << ", ";
    }
    cout << endl;
}

inline int Polynomial::show_terms() {
    return this -> terms;
}

inline int Polynomial::solve(const int x) {
    int result = 0;
    for (int i = 0; i < terms; i++) {
        result += pow(x, term_array[i].expo) * this -> term_array[i].coef;
    }
    return result;
}

inline void Polynomial::expand_capacity(const int capacity, const Term *term_array) {
    cout << "size reallocating..." << endl;
    
    this -> capacity *= 2;
    Term *dummy = new Term[capacity*2];

    for (int i = 0; i < capacity; i++) {
        dummy[i] = term_array[i];
    }

    term_array = dummy;
    delete []dummy;
}

inline void Polynomial::new_term(const int coef, const int expo) {
    if (terms == capacity) {
        expand_capacity(capacity, term_array);
    }

    Term new_term;
    new_term.expo = expo;
    new_term.coef = coef;

    cout << "new term: " << coef << "x^" << expo << ". terms: " << this -> terms+1 << endl;

    term_array[terms] = new_term;
    terms++;
}

int main() {
    Polynomial poly;
    poly.new_term(3, 4);
    poly.new_term(-5, 3);
    poly.new_term(2, 1);
    poly.new_term(-7, 0);
    poly.show_poly();
    cout << poly.solve(0) << endl;
}
```

```console
$ g++ main.cpp -O2
$ ./a.out
new term: 3x^4. terms: 1
size reallocating...
new term: -5x^3. terms: 2
size reallocating...
new term: 2x^1. terms: 3
new term: -7x^0. terms: 4
3x^4, -5x^3, 2x^1, -7x^0,
-7
```
