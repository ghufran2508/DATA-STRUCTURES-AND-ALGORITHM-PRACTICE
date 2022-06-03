#include<iostream>
#include"Stack.h"
#include<string>
#include"functions.h"

using namespace std;

int main()
{
	string expression;
	string postfix;

	cout << "Please Enter infix expression: ";
	getline(cin, expression);
	// 8+9*7-(6/2+5)*(6+4) -> 71 - (8) * (10) -> 71 - 80 - > -9
	// 897*+62/5+64+*-
	
	postfix = infix_postfix(expression);
	cout << "Postfix Expression: " << postfix << endl;

	int evaluating = evaluate(postfix);

	cout << "After Evaluating: " << evaluating << endl;

	return 0;
}