#include "search_tree.h"

using namespace std;

void
search_tree::destroy( struct tree_node *n )
{ 
	if( n != nullptr ) { 
		destroy( n->left );
		destroy( n->right);
		delete n;
		n = nullptr;
	}
	return;
}

node
search_tree::find( const int x ) const
{
	return find( x, root );
} 

node
search_tree::find( const element_type x, node n ) const
{ 
	if( n == nullptr )
		return nullptr;

	if( n->element == x )
		return n;
	else if( n->element > x)
		return find( x, n->left);
	else
		return find( x, n->right);
}

node
search_tree::find_min( ) const
{ 
	node p = root;

	if( p == nullptr )
		return nullptr;
	
	while( p->left != nullptr )
		p = p->left;

	return p;
}
node
search_tree::find_min( node n ) const
{ 
	if( n == nullptr ) 
		return nullptr;
	if( n->left == nullptr ) 
		return n;
	else
		return find_min( n->left ) ;
}


node
search_tree::find_max( ) const
{ 
	return find_max( root );	
}

node
search_tree::find_max( node n ) const
{ 
	if( n == nullptr )
		return nullptr;
	if( n->right == nullptr )
		return n;
	else 
		return find_max( n->right );
}

search_tree&
search_tree::insert_node( const element_type x )
{ 
	root = insert_node( x, root);
	return *this;
} 
node
search_tree::insert_node( const element_type x, node n )
{
	if( n == nullptr ) { 
		n = new tree_node;
		n->element = x;
		n->left = nullptr;
		n->right = nullptr;
	}
	else if( n->element > x )
		n->left = insert_node( x, n->left ) ;
	else if( n->element < x )
		n->right = insert_node( x, n->right ) ;
	//n->element == x, do nothing	
	return n;
}

search_tree&
search_tree::delete_node( const element_type x )
{ 
	root = delete_node( x, root );
	return *this;
}
node
search_tree::delete_node( const element_type x, node n )
{ 
	node p = nullptr;
	node tmp = nullptr;

	if( n == nullptr )
		return nullptr; // not find x
	else if( n->element > x )
		n->left = delete_node( x, n->left ) ;
	else if( n->element < x )
		n->right = delete_node( x, n->right ) ;
	else if( n-> element == x ) { 
		if( n->left == nullptr && n->right == nullptr ) { 
			delete n;
			return nullptr;
		}
		else if( n->left == nullptr && n->right != nullptr ) { 
			tmp = n->right;
			delete n;
			return tmp;
//			tmp = n;
//			n = n->right;
//			delete tmp;
		}
		else if( n->left != nullptr && n->right == nullptr ) { 
			tmp = n->left;
			delete n;
			return tmp;
		}
		else {
			tmp = find_min( n->right ) ;
			n->element = tmp->element;
			n->right = delete_node( tmp->element, n->right );
			return n;
		} 
	} 

	return n;
}


const search_tree&
search_tree::print( ) const
{ 
	print( root, "root", 0 ) ;
	return *this;
}
void
search_tree::print( node n, const string str, int depth ) const 
{
	int i = depth;
	if( n == nullptr ) 
		return ;

	while( i-- )
		cout << "\t" ;

	cout << str + ":" << n->element << endl;
	print( n->left, "left", depth + 1 ) ;
	print( n->right, "right", depth + 1 ) ;
}

const search_tree&
search_tree::prefix( ) const
{ 
	prefix( root ) ;
	cout << endl;
	return *this;
}
void
search_tree::prefix( node n ) const
{ 
	if( n == nullptr )
		return ;
	cout << n->element << "  ";
	prefix( n->left ) ;
	prefix( n->right ) ;
}

const search_tree&
search_tree::infix( ) const
{ 
	infix( root ) ;
	cout << endl;
	return *this;
}
void
search_tree::infix( node n ) const
{ 
	if( n == nullptr ) 
		return ;
	infix( n->left ) ;
	cout << n->element << "  ";
	infix( n->right ) ;
}

const search_tree&
search_tree::postfix( ) const
{ 
	postfix( root );
	cout << endl;
	return *this;
}
void
search_tree::postfix( node n ) const
{ 
	if( n == nullptr ) 
		return;
	postfix( n->left ) ;
	postfix( n->right ) ;
	cout << n->element << "  ";
}


search_tree&
search_tree::invert( ) 
{ 	
	invert( root ) ;
	return *this;
}
void
search_tree::invert( node n ) 
{ 
	node tmp;

	if( n == nullptr ) 
		return;
	tmp = n->left;
	n->left = n->right;
	n->right = tmp;
	invert( n->left ) ;
	invert( n->right ) ;
}


int
search_tree::get_depth( ) const
{ 
	return get_depth( root ) ;
}
int 
search_tree::get_depth( node n ) const
{ 
	int left_depth, right_depth;

	if( n == nullptr ) 
		return 0;
	else { 
		left_depth = get_depth( n->left ) + 1;
		right_depth = get_depth( n->right ) + 1;
	}
	return left_depth > right_depth ? left_depth : right_depth;
}

