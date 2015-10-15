#ifndef _SEARCH_TREE_H
#define _SEARCH_TREE_H

#include <iostream>
#include <string>

typedef int element_type;
struct tree_node { 
	element_type element;
	struct tree_node *left;
	struct tree_node *right;
};
typedef struct tree_node* node;

//AVL tree can inherit search_tree
class search_tree { 
public:
	search_tree( ) : root( nullptr ) { } ;
	search_tree( struct tree_node *t) : root( t ) { } ;
	virtual ~search_tree( ) { 
		destroy( root );
	}

	//	interface
	virtual search_tree& insert_node( const element_type ) ;
	virtual search_tree& delete_node( const element_type );
	search_tree& invert( ) ;
	
	node find( const int x ) const;
	node find_min( ) const;
	node find_max( ) const;
	int get_depth( ) const; // tree depth

	const search_tree& print( ) const ;
	const search_tree& prefix( ) const;
	const search_tree& infix( ) const;
	const search_tree& postfix( ) const;

protected:
	virtual node insert_node( const element_type, node );
	virtual node delete_node( const element_type, node );

private:
	struct tree_node *root;

	//	iteration
	void destroy( node );
	void invert( node n ) ;

	node find( const element_type, node ) const;
	node find_max( node ) const;
	node find_min( node ) const;
	int get_depth( node n ) const;

	void print( node n, const std::string, int ) const;
	void prefix( node n ) const;
	void infix( node n ) const;
	void postfix( node n ) const;
};

#endif
