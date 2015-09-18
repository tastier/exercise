#include "basket.h"
#include "quote.h"

using namespace std;
int main()
{
	shared_ptr<quote> ptr = make_shared<quote>("asd", 10);
	quote obj1("asd", 10);
	bulk_quote obj2("qwe", 10, 5, 0.8);
	basket obj;

	//以下add_item会调用虚函数clone()
	obj.add_item(obj1);
	for(size_t i = 0; i < 5; ++i)
		obj.add_item(obj2);
	obj.add_item(obj1);
	//不调用虚函数，成员函数重载
	obj.add_item(ptr);
	//调用虚函数net_price()
	obj.total_receipt(cout);

	return 0;
}
