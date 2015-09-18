#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include "quote.h"

class basket {

public:
	void add_item(const std::shared_ptr<quote> &);
	void add_item(const quote &);
//	void add_item(const bulk_quote &);
	double total_receipt(std::ostream &os) const;

private:
	static bool compare(const std::shared_ptr<quote> &lhs,
						const std::shared_ptr<quote> &rhs)
	{ return lhs->isbn() < rhs->isbn(); }

	std::multiset<std::shared_ptr<quote>, decltype(compare) *>
		items{compare};
};




#endif
