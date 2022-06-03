#include<iostream>
#include"Polynomial.h"

using namespace std;

int main()
{
	polynomial p1, p2, p3;
	cout << "Polynomial p1 input:" << endl;
	p1.input();
	cout << "Polynomial p2 input:" << endl;
	p2.input();
	p1.setTerm(3, 10); // exponent, coef

	cout << "\nP1 = ";
	p1.show();
	cout << "\nP2 = ";
	p2.show();

	term t1;
	cout << "Term t1 input: " << endl;
	t1.input();

	cout << "p1 eval(10): " << p1.eval(10) << endl;
	//p2.show();

	cout << "\nP3 = P1 + t1 = ";
	 p3 = p1 + t1;
	 p3.show();
	 t1.set(4,2); // exponent, coef
	 cout << "\nP3 = P1 - t1 = ";
	 p3 = p1 - t1;

	 p3.show();

	 cout << "\nP3 = P1 + P2 = ";
	 p3 = p1 + p2;
	 p3.show();
	 p3 = p1 * t1;
	 cout << "\nP3 = P1 * t1 = ";
	 p3.show();
	 cout << "\nP3 = P2 * P1 = ";
	 p3 = p2 * p1;
	 p3.show(); 

	return 0;
}

