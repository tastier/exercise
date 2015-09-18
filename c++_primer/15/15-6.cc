#include "quote.h"

using namespace std;

int main()
{
	quote q("asd", 10);
	bulk_quote bq("qwe", 20);

	print_total(cout, q, 10);
	print_total(cout, bq, 10);
	double ret = print_total(cout, bq, 50);
	return 0;
}
