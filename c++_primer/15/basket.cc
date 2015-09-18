#include "basket.h"

using namespace std;

void basket::add_item(const shared_ptr<quote> &ptr)
{
	items.insert(ptr);
}

void basket::add_item(const quote &obj)
{
//	items.insert(make_shared<quote>(obj)); // obj是一个对象
	items.insert(shared_ptr<quote>(obj.clone())); //obj.clone()是指针
}

/*
void basket::add_item(const bulk_quote &obj)
{
//	cout << "add bulk_quote" << endl;
	items.insert(make_shared<bulk_quote>(obj));
}
*/

double basket::total_receipt(ostream &os) const
{
	double ret = 0;
	for(auto iter = items.cbegin(); iter != items.cend(); 
			iter = items.upper_bound(*iter)) {
		ret += print_total(os, **iter, items.count(*iter));
	}
	os << "total receipt : " << ret << endl;
	return ret;
}
