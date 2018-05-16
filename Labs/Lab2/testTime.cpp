#include "time.h"
#include <iostream>
using namespace std;

int main()
{
	Time myTime(9, 30, 0);
	myTime.Write();
	myTime.WriteAmPm();

	myTime.Set(8, 0, 0);
	myTime.Write();
	myTime.Mealtime();

	Time Schedule[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		Schedule[i].Set(11, 0, 0);
		Schedule[i].WriteAmPm();
	}

	return 0;
}
	


