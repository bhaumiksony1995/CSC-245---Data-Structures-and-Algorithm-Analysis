#include <iostream>
using namespace std;

double convert(double value);
string sortArray(string array);

int main()
{
	double celsius;
	double fahrenheit;
    string array[3];
    array[1] = "programming";
    array[2] = "run";
    array[3] = "timmy";

    sortArray(array);

	cout << "Please enter Celsius value: ";
	cin >> celsius;

	fahrenheit = convert(celsius);

	cout << celsius << " degrees in Celsius is " << fahrenheit << " degrees in Fahrenheit" << endl;
}

string sort(array(string array)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i].length() > array[i+1].length())
        {
            array[i] == array[i+1];
        }
        else
        {
            array[i] = array[i];
        }
    }
}

double convert(double tmp)
{
	double fahrenheit = 1.8 * tmp + 32.0;
	return fahrenheit;
}
