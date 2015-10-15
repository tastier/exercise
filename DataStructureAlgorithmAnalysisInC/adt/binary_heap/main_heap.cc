#include "binary_heap.h"
using namespace std;
int main ( ) 
{
	binary_heap<int> bh;
	int i;
	while( cin >> i) { 
		if( i == 0 ) 
			break;
		bh.insert( i) ;
	} 
	bh.print() ;

	cout << bh.find_min() << endl;
	bh.delete_min() ;
	cout << bh.find_min() << endl;
	bh.print() ;
	
	return 0;
} 
