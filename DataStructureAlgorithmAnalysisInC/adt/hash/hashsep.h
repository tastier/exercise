#ifndef HASHSEP_H
#define HASHSEP_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

template <typename T>
class hash_table { 
private:
	struct list_node { 
		T key;
		std::shared_ptr<list_node> next;
	} ;
	static const int MIN_SIZE = 7;

public:
	hash_table( int size = MIN_SIZE ) : map_size( size ) 
	{
		//allocate list headers
		for( int i = 0; i < map_size; ++i ) { 
			std::shared_ptr<list_node> p( new list_node ) ;
			map.push_back( p );
			map[i]->next = nullptr;
		}
	} 
	
	hash_table<T>& insert_key( const T& key ) ;
	hash_table<T>& delete_key( const T& key ) ;

	std::shared_ptr<list_node> find_key( const T& key )  
	{ 
		int index = hash( key ) ;
		std::shared_ptr<list_node> p = map[index]->next;

		while( p != nullptr && p->key != key ) 
			p = p->next;
		return p;
	}
	
	int size( ) const
	{ 
		return map_size;
	}

	void print( ) const;

private:
	int map_size;
	std::vector< std::shared_ptr<list_node> > map;

	int hash( const int& key ) // hash function
	{ 
		return key % map_size;
	}

	int hash( const std::string& str ) 
	{ 
		int val = 0;
		for( int i = 0; i < str.size( ) ; ++i )
			val = ( val << 5 ) + str[i];
		return val % map_size;
	}
} ;

template <typename T>
inline hash_table<T>&
hash_table<T>::insert_key( const T& key )
{ 
	int index = hash( key ) ;
	std::shared_ptr<list_node> p;
	std::shared_ptr<list_node> tmp = map[index]->next;
//	if key is in hash, do nothing
	if( find_key( key ) ) 
		return *this;

//	no matter map[index]->next is nullptr or not

	p = std::make_shared<list_node>( ) ;
	p->key = key;
	p->next = map[index]->next;
	map[index]->next = p;
	return *this;
}

template <typename T>
inline hash_table<T>&
hash_table<T>::delete_key( const T& key ) 
{ 
	int index = hash( key ) ;
	std::shared_ptr<list_node> p = map[index] ;

	while( p->next ) { 
		if( p->next->key == key ) { 
			p->next = p->next->next;
			break;
		} 
		p = p->next;
	}
	return *this;
}

template <typename T>
inline void
hash_table<T>::print( ) const
{ 
	std::shared_ptr<list_node> p;

	for( int i = 0; i < map_size; ++i ) { 
		p = map[i]->next;
		std::cout << i << "th row: ";
		while( p != nullptr ) { 
			std::cout << p->key << "  ";
			p = p->next;
		}
		std::cout << std::endl;
	}
}

#endif
