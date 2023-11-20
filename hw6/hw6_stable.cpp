#include <bits/stdc++.h>
using namespace std;

class Polynomial;
class Term
{
    friend Polynomial;
    friend ostream &operator<<(ostream &os, const Polynomial &p);

private:
    float coef; //?Y??
    int term;   //???��
};

class Polynomial
{
    friend ostream &operator<<(ostream &os, const Polynomial &p);

private:
    Term *termArray;
    int capacity; //????j?p
    int terms;    //?D?s????q
public:
    Polynomial();                                        //??c?l
    float Eval(float f);                                 //?D??
    void NewTerm(const float newCoef, const int newExp); //?s?W?D?s??
};

Polynomial::Polynomial() : capacity(2), terms(0)
{
    termArray = new Term[capacity];
}

void Polynomial::NewTerm(const float newCoef, const int newExp)
{
    // ???????????s?t?m???
    if (terms == capacity)
    {
        capacity *= 2;
        Term *temp = new Term[capacity];
        copy(termArray, termArray + terms, temp);
        delete[] termArray;
        termArray = temp;
    }
    termArray[terms].coef = newCoef;
    termArray[terms++].term = newExp;
}

float Polynomial::Eval(float f)
{
    float sum = 0.0;
    for (int i = 0; i < terms; i++)
    {
        Term curr = termArray[i];
        sum += curr.coef * pow(f, curr.term);
    }
    return sum;
}

ostream &operator<<(ostream &os, const Polynomial &p)
{
    for (int i = 0; i < p.terms; i++)
    {
        if (p.termArray[i].term == 0)
        {
            os << p.termArray[i].coef;
            continue;
        }
        if (i == p.terms - 1)
        {
            os << p.termArray[i].coef << "X^" << p.termArray[i].term;
        }
        else
        {
            os << p.termArray[i].coef << "X^" << p.termArray[i].term << "+";
        }
    }

    return os;
}

int main()
{
    Polynomial poly;

    poly.NewTerm(2, 8);
    poly.NewTerm(2, 7);
    poly.NewTerm(2, 6);
    poly.NewTerm(2, 5);
    poly.NewTerm(2, 4);
    poly.NewTerm(2, 3);
    poly.NewTerm(2, 2);
    poly.NewTerm(2, 1);
    poly.NewTerm(2, 0);

    cout << poly << endl;
    cout << poly.Eval(2) << endl;
    return 0;
}
