#include "quote.h"

using namespace std;

double print_total(std::ostream &os, const quote &q, std::size_t n)
{
	double ret = q.net_price(n);
	os << q.isbn() << " : " << ret << std::endl;
	return ret;
}

double bulk_quote::net_price(std::size_t n) const
{
	std::cout << "bulk_quote.net_price	" <<std::endl;
	if(n >= quantity)
		return n * price * discount;
	else
		return n * price;
}

double lim_quote::net_price(std::size_t n) const
{
	if(n <= quantity)
		return n * price * discount;
	else
		return n * price;
}
