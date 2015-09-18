#include <vector>
#include <memory>
#include <iostream>
#include "quote.h"
using namespace std;
int main()
{
	int sum = 0;
	vector<shared_ptr<quote>> vec;
	vec.push_back(make_shared<bulk_quote>("asd", 10, 10, 0.8));
	vec.push_back(make_shared<quote>("qwe", 50));
	for (auto &item : vec) {
		sum += item->net_price(20);
	}
	cout << sum << endl;

	return 0;
}
