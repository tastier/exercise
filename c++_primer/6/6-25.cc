#include <iostream>
using namespace std;
int main( int argc, char * argv[])
{
	string s;
	
	for(int i = 0; i < argc; ++i)
		s += argv[i];

	cout << s << endl;
	return 0;
}
