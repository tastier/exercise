#include "quote.h"
using namespace std;
int main()
{
//	disc_quote a;
	quote a("asd", 50);
	cout << a.net_price(10) << endl;

	bulk_quote b("qwe", 50, 10, 0.8);
	cout << b.net_price(50) << endl;

	quote *p = new lim_quote("zxc", 10, 20, 0.8);
	cout << p->net_price(10) << endl; //动态绑定

	return 0;
}
