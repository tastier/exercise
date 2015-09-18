#include "sales_data.h"

using namespace std;

int main()
{
	sales_data item1("123456"), item2{"123456", 20, 100};

	cout << item1 << endl << item2 << endl;

	sales_data &item3 = item1.combine(item2);//item3是item1的引用
	cout << item1 << "  " << item3 << endl;
	
	int i = item1.combine(item2, 1);
//	cout << i << endl; 
//	cin >> item1;
	cout << item1 << "	" << item3 << endl;

	sales_data item4(cin);
	cout << "item4 = " <<  item4<<endl;

//	string s("asd");
//	item4.combine(s);


	return 0;
	
}
