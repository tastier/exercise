#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1(10, 45);
	cout << "size:" << v1.size() << endl;
	for(auto it = v1.cbegin(); it != v1.cend(); ++it)
		cout << *it << endl;
	return 0;
}
