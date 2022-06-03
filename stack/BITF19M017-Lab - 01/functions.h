#pragma once
#include<iostream>
#include<string>
#include"Stack.h"

using namespace std;
//check the infix expression for brackets.
//if expression is false it would return false.
bool isValid(string s)
{
	Stack<char> mystack;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '[' || s[i] == '{' || s[i] == '(')
		{
			mystack.push(s[i]);
		}
		else if (s[i] == ']' || s[i] == '}' || s[i] == ')')
		{
			if (mystack.isEmpty())
			{
				return false;
			}

			char latestbracket = mystack.pop();

			if (latestbracket == '(' && s[i] != ')')
			{
				return false;
			}
			if (latestbracket == '{' && s[i] != '}')
			{
				return false;
			}
			if (latestbracket == '[' && s[i] != ']')
			{
				return false;
			}
		}
	}

	if (mystack.isEmpty())
		return true;
	else {
		return false;
	}
}

bool isOperand(char character)
{
	if (character >= 'A' && character <= 'Z')
		return true;
	if (character >= 'a' && character <= 'z')
		return true;
	if (character >= '0' && character <= '9')
		return true;

	return false;
}

bool isOperator(char character)
{
	if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^')
	{
		return true;
	}
	return false;
}

int operatorPrecedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;

	return 0;
}

string infix_postfix(string infix)
{
	string postfix = "";
	string op;

	Stack<char> opstack;

	if (isValid(infix))
	{
		for (int i = 0; i < infix.size(); i++)
		{
			if (infix[i] == ' ')	continue;

			if (isOperand(infix[i]))
			{
				postfix += infix[i];
			}
			else if (isOperator(infix[i]))
			{
				if (opstack.isEmpty())
				{
					opstack.push(infix[i]);
				}
				else
				{
					op = opstack.pop();

					while (operatorPrecedence(op[0]) >= operatorPrecedence(infix[i]))
					{
						postfix += op;

						if (opstack.isEmpty()) break;

						op = opstack.pop();
					}

					if (operatorPrecedence(op[0]) < operatorPrecedence(infix[i]))
						opstack.push(op[0]);

					opstack.push(infix[i]);
				}

			}
			else if (infix[i] == '(')
			{
				opstack.push(infix[i]);
			}
			else if (infix[i] == ')')
			{
				while (1)
				{
					op = opstack.pop();
					if (op[0] == '(')   break;
					else			    postfix += op;
				}
			}
		}

		while (!opstack.isEmpty())
			postfix += opstack.pop();
	}
	else
	{
		cout << "[+]NOT A VALID EXPRESSION!!!!" << endl;
	}
	return postfix;
}

int calculateop(int num1, int num2, char op)
{
	if (op == '+')
	{
		return num1 + num2;
	}
	if (op == '-')
	{
		return num1 - num2;
	}
	if (op == '*')
	{
		return num1 * num2;
	}
	if (op == '/')
	{
		return num1 / num2;
	}
	if (op == '^')
	{
		int count = num2;
		while (count > 0)
		{
			num1 *= num1;
			count--;
		}
		return num1;
	}
	return 0;
}

int evaluate(string postfix)
{
	Stack<int> numstack;
	int value = 0;

	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			numstack.push(postfix[i] - '0');
		}
		else if (isOperator(postfix[i]))
		{
			int num2 = numstack.pop();
			int num1 = numstack.pop();
			
			numstack.push(calculateop(num1, num2, postfix[i]));

		}
	}
	value = numstack.pop();
	return value;
}