#include "search_tree.h"

using namespace std;

int main( ) 
{ 
	search_tree tree;
	int i;
	cout << "input tree node: ";
	while( cin >> i ) {
		if( i == -1 )
			break;
		tree.insert_node( i ) ;
	}
	tree.print() ; // return const search_tree but tree is not const
	cout << "tree depth is: " << tree.get_depth() << endl << endl << endl;

	cout << "delete node is:";
	while( cin >> i ) { 
		if( i == -1 )
			break;
		tree.delete_node( i ) ;
		tree.print() ;
		cout << "tree depth is: " << tree.get_depth() << endl;
		cout << endl << endl;
		cout << "delete node is:";
	} 

	cout << endl;
	tree.prefix() ;
	tree.infix() ;
	tree.postfix() ;


	cout << endl << "invert the tree" << endl;
	tree.invert().print( ) ;

	return 0;
}


