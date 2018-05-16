#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include "stack.h"

using namespace std;

bool isOperand(char ch);
bool isOperator(char ch);
bool openParenthesis(char ch);
bool closeParenthesis(char ch);
bool higherPrecedence(char ch, char top);
string InfixPostfix(string postfix);

int main()
{
	string postfix;
	ifstream infile("infix.dat");
	getline(infile, postfix);
	postfix = InfixPostfix(postfix);
	cout << postfix << endl;
}

bool isOperand(char ch)
{
	if(ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}

bool isOperator(char ch)
{
	if((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'))
		return true;
	else
		return false;
}

bool openParenthesis(char ch)
{
	if(ch == '(')
		return true;
	else
		return false;
}

bool closeParenthesis(char ch)
{
	if(ch == ')')
		return true;
	else
		return false;
}

bool higherPrecedence(char ch, char top)
{
	if(top == ch)
		return true;
	if((top == '*') || (top == '/'))
		return true;
	if((top == '+') || (top == '-'))
		if((ch == '+') || (ch == '-'))
			return true;
	if(top == '(')
		return false;
	return false;	
}

string InfixPostfix(string postfix)
{
	stack<char> myStack;
	string S;

	for (int i = 0; i < postfix.length(); i++)
	{
		if(S[i] == ' ')
			continue;
		else if(isOperator(S[i]))
		{
			while(!myStack.isEmpty() && openParenthesis(myStack.top() == false) && higherPrecedence(myStack.top(), S[i]) == true)
			{
				S = S + myStack.top();
				myStack.pop();
			}
			myStack.push(S[i]);
		}

		else if(isOperand(postfix[i]))
		{
			S = S + myStack.top();
		}

		else if(closeParenthesis(S[i]) == true)
		{
			myStack.push(S[i]);
		}

		else if(openParenthesis(S[i]) == true)
		{
			while( !myStack.isEmpty() && openParenthesis(myStack.top()) == false)
			{
				S = S + myStack.top();
				myStack.pop();
			}
			myStack.pop();
		}
	}

	while(!myStack.isEmpty())
	{
		S = S + myStack.top();
		myStack.pop();
	}

	return S;
}	
