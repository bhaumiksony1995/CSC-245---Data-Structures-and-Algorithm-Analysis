#include <iostream>
using namespace std;
int main ()
{
	double x = 10;
	double y = 20; 
	double *ptr1;
	ptr1 = &x;
	double *ptr2; 
	ptr2 = &y;
	bool identvar (double ptr1, double ptr2)<< endl;
	bool identadd (double &ptr1, double &ptr2) << endl;
	return 0;
}

bool identvar (double *ptr1, double *ptr2)
{
	double *pointer1;
	double *pointer2;
	return (*(ptr1) == *(ptr2));
}

bool identadd (double &ptr1, double &ptr2)
{
	return (&ptr1 == &ptr2);
}
