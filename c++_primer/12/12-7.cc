#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> make_vec(void)
{
	return make_shared<vector<int>>();
}

void wr_vec(shared_ptr<vector<int>> pv)
{
	int i;
	while(cin >> i)
		pv->push_back(i);
}

void print_vec(shared_ptr<vector<int>> pv)
{
	for( auto i : *pv)
		cout << i << " ";
	cout << endl;
}

int main()
{
	shared_ptr<vector<int>> pv = make_vec();
	wr_vec(pv);
	print_vec(pv);
	return(0);
}
