#include<iostream>
#include"Polynomial.h"
#include<math.h>

using namespace std;
//**********************************
//      TERM implementation...
//*********************************
term::term()
{
    this->coef = 0;
    this->exp = 0;
}

void term::set(int c, int e)
{
    this->coef = c;
    this->exp = (e >= 0) ? e : 0;
}

int term::getCoef(int e)
{
    if (this->exp == e)
    {
        return this->coef;
    }
    return 0;
}

int term::getExp()
{
    return this->exp;
}

void term::show()
{
    char sign;
    if (coef >= 0)
        sign = '+';
    else
    {
        cout << coef << "x^" << exp << " ";
        return;
    }
    cout << sign << coef << "x^" << exp << " ";
}

void term::input()
{
    int e, c;

    cout << "Enter exponent: ";
    cin >> e;

    while (e < 0)
    {
        cout << "Error!!!Polynomial cannot have a negative exponent." << endl;
        cout << "Enter exponent: ";
        cin >> e;
    }

    cout << "Enter Coefficient: ";
    cin >> c;

    this->exp = e;
    this->coef = c;
}

//****************************************
//      Polynomial Implementation...
//***************************************
polynomial::polynomial()
{
    this->terms = 0;
    this->size = 5;
    this->Terms = new term[size];
}

polynomial::polynomial(const polynomial& p2)
{
    terms = p2.terms;
    this->size = p2.size;
    Terms = new term[size];

    for (int i = 0; i < terms; i++)
    {
        this->Terms[i].set(p2.Terms[i].getCoef(p2.Terms[i].getExp()), p2.Terms[i].getExp());
    }
}

polynomial::~polynomial()
{
    delete[] Terms;
    Terms = NULL;
}

void polynomial::resize()
{
    term* newterms = new term[size];

    for (int i = 0; i < terms; i++)
    {
        newterms[i].set(this->Terms[i].getCoef(this->Terms[i].getExp()), this->Terms[i].getExp());
    }

    delete[] Terms;
    Terms = new term[size * 2];

    for (int i = 0; i < terms; i++)
    {
        this->Terms[i].set(newterms[i].getCoef(newterms[i].getExp()), newterms[i].getExp());
    }
    size *= 2;

    delete[] newterms;
    newterms = NULL;
}

int polynomial::getTerms()
{
    return this->terms;
}

void polynomial::show()
{
    for (int i = 0; i < terms; i++)
    {
        Terms[i].show();
    }
    cout << endl;
}

//add a new term or add the term already exist...
void polynomial::addTerm(int c, int e)
{
    if (terms == size - 1)
        resize();

    bool exist = false;

    if (e < 0)
    {
        return;
    }

    for (int i = 0; i < getTerms(); i++)
    {
        if (Terms[i].getExp() == e)
        {
            exist = true;
            Terms[i].set(Terms[i].getCoef(e) + c, e);
            break;
        }
    }

    if (!exist)
    {
        Terms[terms].set(c, e);
        terms++;
    }
}

void polynomial::addPolynomial(polynomial p2)
{
    for (int i = 0; i < p2.terms; i++)
    {
        this->addTerm(p2.Terms[i].getCoef(p2.Terms[i].getExp()), p2.Terms[i].getExp());
    }
}

void polynomial::dist(int m, int e)
{
    for (int i = 0; i < getTerms(); i++)
    {
        int value = (this->Terms[i].getCoef(this->Terms[i].getExp()) * m);
        //this->addTerm(value, e);
        this->Terms[i].set(value, e + this->Terms[i].getExp());
    }
}

void polynomial::dist(term any)
{
    dist(any.getCoef(any.getExp()), any.getExp());
}

int polynomial::getDegree()
{
    int max_degree = 0;
    for (int i = 0; i < terms; i++)
    {
        if (this->Terms[i].getExp() > max_degree)
        {
            max_degree = this->Terms[i].getExp();
        }
    }

    return max_degree;
}

polynomial polynomial::multiply(polynomial p2)
{
    polynomial p3mul;

    for (int i = 0; i < getTerms(); i++)
    {
        for (int j = 0; j < p2.getTerms(); j++)
        {
            p3mul.addTerm(this->Terms[i].getCoef(this->Terms[i].getExp()) * p2.Terms[j].getCoef(p2.Terms[j].getExp()), this->Terms[i].getExp() + p2.Terms[j].getExp());
        }
    }

    return p3mul;
}

int polynomial::eval(int x)
{
    int evaluate = 0;

    for (int i = 0; i < getTerms(); i++)
    {
        evaluate += (pow(x, this->Terms[i].getExp()) * this->Terms[i].getCoef(this->Terms[i].getExp()));
    }

    return evaluate;
}

int polynomial::getCoef()
{
    int e;
    cout << "Enter exponent: ";
    cin >> e;

    for (int i = 0; i < getTerms(); i++)
    {
        if (this->Terms[i].getCoef(e))
        {
            return this->Terms[i].getCoef(e);
        }
    }

    return 0;
}

void polynomial::reorder()
{
    for (int i = 0; i < getTerms(); i++)
    {
        for (int j = i + 1; j < getTerms(); j++)
        {
            if (this->Terms[j].getExp() > this->Terms[i].getExp())
            {
                int tempexp = this->Terms[j].getExp();
                int tempcoef = this->Terms[j].getCoef(tempexp);
                this->Terms[j].set(this->Terms[i].getCoef(this->Terms[i].getExp()), this->Terms[i].getExp());
                this->Terms[i].set(tempcoef, tempexp);
            }
        }
    }
}

void polynomial::setTerm(int e, int c)
{
    for (int i = 0; i < terms; i++)
    {
        if (this->Terms[i].getExp() == e)
        {
            this->Terms[i].set(c, e);
            return;
        }
    }

    Terms[terms].set(c, e);
    terms++;
}

string polynomial::tostring()
{
    string polynomial = "";

    for (int i = 0; i < getTerms(); i++)
    {
        int coeff;
        int expo;
        char sign;

        coeff = this->Terms[i].getCoef(this->Terms[i].getExp());
        expo = this->Terms[i].getExp();
        if (coeff > 0)
        {
            sign = '+';
            polynomial += (sign + to_string(coeff));
        }
        else
        {
            polynomial += to_string(coeff);
        }

        polynomial += "x^";
        polynomial += (to_string(expo) + ' ');

    }

    return polynomial;
}

void polynomial::input()
{
    int check = 1;

    do
    {
        int e, c;
        bool exist = false;

        cout << "Enter exponent: ";
        cin >> e;

        while (e < 0)
        {
            cout << "Error!!!Polynomial cannot have a negative exponent." << endl;
            cout << "Enter exponent: ";
            cin >> e;
        }

        cout << "Enter Coefficient: ";
        cin >> c;

        for (int i = 0; i < terms; i++)
        {
            if (this->Terms[i].getExp() == e)
            {
                this->Terms[i].set(c, e);
                exist = true;
                break;
            }
        }

        if (!exist)
        {
            this->Terms[terms].set(c, e);
            terms++;
        }

        cout << "\nEnter 1 to input again...";
        cin >> check;

    } while (check == 1);
}

polynomial& polynomial::operator=(const polynomial& p2)
{  
    this->terms = p2.terms;
    this->size = p2.size;
    this->Terms = new term[size];

    for (int i = 0; i < p2.terms; i++)
    {
        this->Terms[i].set(p2.Terms[i].getCoef(p2.Terms[i].getExp()), p2.Terms[i].getExp());
    }

    return *this;
}

polynomial polynomial::operator+(const polynomial& p2)
{
    polynomial sump(*this);

    for (int i = 0; i < p2.terms; i++)
    {
        sump.addTerm(p2.Terms[i].getCoef(p2.Terms[i].getExp()), p2.Terms[i].getExp());
    }

    return sump;
}

polynomial polynomial::operator+(term& p2)
{
    polynomial sump(*this);

    sump.addTerm(p2.getCoef(p2.getExp()), p2.getExp());

    return sump;
}

polynomial polynomial::operator-(const polynomial& p2)
{
    polynomial diff(*this);

    for (int i = 0; i < p2.terms; i++)
    {
        if (p2.Terms[i].getExp() == this->Terms[i].getExp())
        {
            int sub = this->Terms[i].getCoef(this->Terms[i].getExp()) - p2.Terms[i].getCoef(p2.Terms[i].getExp());
            diff.Terms[i].set(sub, this->Terms[i].getExp());
        }
        else
        {
            diff.addTerm(p2.Terms[i].getCoef(p2.Terms[i].getExp()), p2.Terms[i].getExp());
        }
    }
    
    return diff;
}

polynomial polynomial::operator-(term& p2)
{
    polynomial diff(*this);

    for (int i = 0; i < diff.getTerms(); i++)
    {
        if (diff.Terms[i].getExp() == p2.getExp())
        {
            diff.Terms[i].set(diff.Terms[i].getCoef(diff.Terms[i].getExp()) - p2.getCoef(p2.getExp()) , p2.getExp());
        }
    }

    return diff;
}

polynomial polynomial::operator*(const polynomial& p2)
{
    polynomial p3mul;

    for (int i = 0; i < getTerms(); i++)
    {
        for (int j = 0; j < p2.terms; j++)
        {
            p3mul.addTerm(this->Terms[i].getCoef(this->Terms[i].getExp()) * p2.Terms[j].getCoef(p2.Terms[j].getExp()), this->Terms[i].getExp() + p2.Terms[j].getExp());
        }
    }

    return p3mul;
}

polynomial polynomial::operator*(term& p2)
{
    polynomial p3(*this);

    p3.dist(p2);

    return p3;
}