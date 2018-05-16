#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int main()
{
	stack<int> myStack;
    	string input;
    	ifstream infile("infix.dat");
    	int op1, op2, result;

	cout << "Your expression is: " << input << endl;

    	while (!infile.eof())
   	{
        	getline(infile, input);
        	for (int i = 0; i < input.length(); i++)
        	{
			if (!isspace(input[i]))
				cout << "Token = " << input[i] << '\t';
		
			if (isdigit(input[i]))
			{
				cout << "Push " << input[i] << '\t' << endl;
				myStack.push(input[i]);
			}
            		if(input[i] == '+')
			{
				op1 = myStack.top();
				myStack.pop();
				op2 = myStack.top();
				myStack.pop();
				cout << "Pop " << op1 << '\t' << "Pop " << op2 << '\t' << "Push " << input[i];
                		myStack.push(op2 + op1);
				cout << "Push " << myStack.top() << '\t' << endl;
			}
            		if(input[i] == '-')
			{
                		op1 = myStack.top();
				myStack.pop();
                        	op2 = myStack.top();
				myStack.pop();
                        	cout << "Pop " << op1 << '\t' << "Pop " << op2 << '\t' << "Push " << input[i];
				myStack.push(op2 - op1);
				cout << "Push " << myStack.top() << '\t' << endl;
			}
 	           	if(input[i] == '*')
			{
                		op1 = myStack.top();
				myStack.pop();
                        	op2 = myStack.top();
				myStack.pop();
                        	cout << "Pop " << op1 << '\t' << "Pop " << op2 << '\t' << "Push " << input[i];
				myStack.push(op2 * op1);
				cout << "Push " << myStack.top() << '\t' << endl;
			}
            		if(input[i] == '/')
			{
				op1 = myStack.top();
				myStack.pop();
                        	op2 = myStack.top();
				myStack.pop();
                        	cout << "Pop " << op1 << '\t' << "Pop " << op2 << '\t' << "Push " << input[i];
                		myStack.push(op2 / op1);
				cout << "Push " << myStack.top() << '\t' << endl;
			}
        	}
	result = myStack.top();
	cout << "Value = " << result << endl;
    	}
	return 0;
}

