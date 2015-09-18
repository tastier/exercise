#include "query.h"

using namespace std;

int main(int argc, char **argv)
{
	ifstream infile;
	infile.open(argv[1]);
	text_query tq(infile);
//	query q = query("fiery") & query("bird") | query("wind");
//	query q = query("he") & query("her");
	query q = ~query("is");

	query_result result = q.eval(tq);
	cout << q.rep() << endl;
	cout << result << endl;

	return 0;
}
