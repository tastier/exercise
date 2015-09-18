#include"my_strblob.h"
using namespace std;

int main()
{
	strblob b1;
	{
		strblob b2 ({"ab", "cd", "ef"});
		b1 = b2;
		b2.push_back("123");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << "	" << b1.back() << endl;

	const strblob b3 = b1;
	cout << b3.front() << "	" << b3.back() << endl;
//	b3.front() = "diao";
//	cout << b3.front() << endl;

	return 0;
}

