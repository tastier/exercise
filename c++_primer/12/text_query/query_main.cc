#include "text_query.h"

using namespace std;
int main(int argc, char **argv)
{
	ifstream infile;
	infile.open(argv[1]);
	text_query tq(infile);
	string word;
	while(1) {
		cout << "input word: ";
		cin >> word;
		if(word == "q")
			break;
//		print(cout, tq.query(word)) << endl;
		cout << tq.query(word) << endl;
	}

	return 0;
}
