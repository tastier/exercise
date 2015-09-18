#include <iostream>
//#include <string>
using namespace std;

bool has_upper(const string &s)
{
	for (auto i : s){
		if(isupper(i))
			return true;		
	}
	return false;
}

void to_lower(string &s)
{
	for(auto &c : s){
		if(isupper(c))
			c = tolower(c);
	}
}

int main()
{
	string s("Hello World");
	cout << has_upper(s) << endl;
	
	to_lower(s);
	cout << s << endl;	

	return 0;
}
