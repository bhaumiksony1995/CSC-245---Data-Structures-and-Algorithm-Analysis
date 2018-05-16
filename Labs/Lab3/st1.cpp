#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void Initialize(vector<int> &v);
void Print (vector<int> v);
void Reverse (vector<int> &v);

int main()
{
	cout << endl;
	stack<string> s1, s2;
	s1.push("Hi there");
	s2.push("Hello there");
	s1.push("A");
	s2.push("a");
	
	if (s1 == s2)
		cout << "s1 == s2" << endl;
	else if (s1 < s2)
		cout << "s1 < s2" << endl;
	else if (s2 < s1)
		cout << "s2 < s1" << endl;

	vector<int> v;
	Initialize(v);
	cout << endl;
	Print(v);
	Reverse(v);
	Print(v);
	sort(v.begin(), v.end());
	Print(v);
}

void Initialize(vector<int> &v)
{
	for(int i = 1; i <= 5; i++)
	{
		int input;
		cout << "Please enter digit " << i << " : ";
		cin >> input;
		v.push_back(input);	
	}
}

void Print (vector<int> v)
{
	for (int i = 0; i < v.size();i++)
		cout << v[i] << " ";
	cout << endl;
}

void Reverse (vector<int> &v)
{
	stack<int> s;
	for (int i = 0; i < v.size(); i++)
		s.push(v[i]);

	for (int i = 0; i < v.size(); i++) 
	{
   		v[i] = s.top();
   		s.pop();
	}
}

