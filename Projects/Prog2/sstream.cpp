
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	int x;
	float f;
	string s = "3.7", u;

	istringstream is(s);
	is >> x >> f;
	
	cout << x << " " << f << endl;

	ostringstream os (s, ios::out | ios::ate);
	os << 77 << hex << 77 << endl;
	cout << os.str() << endl;
	cout << s << endl;

	istringstream t("Howdy Folks!");
	t >> s >> u;

	cout << s << " " << u << endl;
	return 0;
}
