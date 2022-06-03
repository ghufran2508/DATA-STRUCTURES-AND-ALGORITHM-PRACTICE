#pragma once
#include<iostream>
#include<string>

using namespace std;

class term
{
    int coef; // coefficient
    int exp; // exponent
public:
    term();
    void set(int c, int e);
    int getCoef(int e);
    int getExp();
    void show();
    void input();
};

class polynomial
{
    int terms;
    term* Terms;
    int size;
public:
    polynomial();
    polynomial(const polynomial& p2);
    ~polynomial();

    void resize();

    int getTerms();
    void show();
    void addTerm(int c, int e);
    void addPolynomial(polynomial p2);
    void dist(int m, int e = 0); // multiply a term with a polynomial
    void dist(term any);
    polynomial multiply(polynomial p2);  // or times()
    int eval(int x);
    int getCoef();
    int getDegree();
    void reorder();
    void setTerm(int e, int c);// (set coefficient of given exponent)
    string tostring();
    void input();

    polynomial& operator=(const polynomial& p2);
    polynomial operator+(const polynomial& p2);
    polynomial operator-(const polynomial& p2);
    polynomial operator+( term& p2);
    polynomial operator-( term& p2);
    polynomial operator*(const polynomial& p2);
    polynomial operator*( term& p2);
};