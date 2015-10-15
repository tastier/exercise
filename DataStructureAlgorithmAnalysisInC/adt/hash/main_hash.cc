#include "hashsep.h"
#include <iostream>

using namespace std;

int main( ) 
{ 
	hash_table<string> map;
	int i;
	string s;
	cout << "input map key :" << endl;
	while( cin >> s ) { 
		if( i == -1 )
			break;
		map.insert_key( s ) ;
		map.print() ;
	}
//	map.print() ;

	cout << "input delete map key:";
	while( cin >> s ) { 
		if( i == -1 )
			break;
		map.delete_key( s ) ;
		map.print() ;
		cout << "input delete map key:";
	} 
	cin >> s;
	cout << map.find_key( s ) << endl;

	return 0;
}

