#include<memory>
using namespace std;
int main()
{
	unique_ptr<int> up(new int(10)), up2;
	up2 = up;
	
	return 0;
}
