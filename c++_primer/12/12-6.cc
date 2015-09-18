#include <iostream>
#include <vector>
//#include <memory>
using namespace std;

vector<int>* new_vec(void)
{
	return new vector<int>;
}

void wr_vec(vector<int> *pv, istream &in)
{
	int i;
	while(in >> i)
		pv->push_back(i);
}

void print_vec(vector<int> *pv, ostream &out)
{
	out << endl <<  "print vector" << endl;
	for(auto i : *pv)
		out << i << endl;
}

int main()
{
	vector<int> *pv = new_vec();

	wr_vec(pv, cin);
	print_vec(pv, cout);

	delete pv;
	pv = nullptr;

	return 0;
}
