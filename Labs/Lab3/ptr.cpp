#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
using namespace std;

struct RecType
{
	int age;
	float weight;
	char gender;
};
int main()
{
	cout << endl;
	int num = 5;
	int *intPtr = NULL;
//	intPtr = &num;
	*intPtr = *intPtr * 10;
	cout << "intPtr points to : ";
	cout << setw(37) << *intPtr << endl;

	RecType *recPtr;
	recPtr = new RecType;
	recPtr -> age = 25;
	recPtr -> weight = 190;
	recPtr -> gender = 'M';
	(*recPtr).age = (*recPtr).age + 5;
	cout << "Three Fields Pointed to By recPtr : ";
	cout << setw(20) << (*recPtr).age << " " << (*recPtr).weight << " " << (*recPtr).gender << endl;
	delete recPtr;
	recPtr = NULL;

	char *strPtr = new char [50];
	strcpy (strPtr, "Operating Systems");
	cout << "strPtr points to : ";
	cout << setw(52) << strPtr << endl;

	int lowerCount = 0;
        for(int i = 0; i < strlen(strPtr); i++)
	{
		if ( islower( *(strPtr + i) ))
		{
			lowerCount++;
                }
        }
	cout << "LowerCase Letters Pointed to By strPtr : ";
	cout << setw(15) << lowerCount << endl;

	strPtr += 10;
	cout << "Printing strPtr after adding 10 : ";
	cout << setw(27) << *&strPtr << endl;
	cout << endl;

	return 0;
}	
