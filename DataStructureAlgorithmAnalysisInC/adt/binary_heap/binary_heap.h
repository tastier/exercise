#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>
#include <vector>
#include <string>

template <typename T>
class binary_heap { 
private:
	static const int MIN_SIZE = 13;
public:
	binary_heap( int c = MIN_SIZE) : capacity( c ) , size( 0 ) 
	{ 
		pt = new T[capacity + 1]( ) ; // 数组第一个元素pt[0]不使用，保证堆的结构性
	}
	~binary_heap( ) 
	{ 
		delete [] pt;
	}
	
	binary_heap<T>& insert( T t ) ;
	binary_heap<T>& delete_min( ) ;
	void print( ) const;
	T find_min( ) const
	{
		if( !is_empty( ) ) 	
			return pt[1] ;
	}
	bool is_full( ) const
	{ 
		return size == capacity;
	}
	bool is_empty( ) const
	{ 
		return size == 0;
	}
	void make_empty( ) 
	{ 
		size = 0;
	}

private:
	T *pt;
	int capacity;
	int size;
} ;

template <typename T>
binary_heap<T>& binary_heap<T>::insert( T t ) 
{ 
	if( is_full( ) ) { 
		std::cout << "the binary_heap is full" << std::endl;
		return *this;
	}
	int i = ++size; // i记录空穴的位置
	// i >1 处理初始size=0和空穴上滤到根处的情况
	// 没有处理插入相同元素的情况，堆中的元素可重复
	while( i > 1 && pt[ i / 2 ] > t ) { 
		pt[ i ] = pt[ i / 2 ];
		i = i / 2;
	}
	pt[ i ] = t;
	return *this;
}

template <typename T>
binary_heap<T>& binary_heap<T>::delete_min( ) 
{ 
	if( is_empty( ) ) { 
		std::cout << "the binary_heap is empty" << std::endl;
		return *this;
	}

	T tmp = pt[ size-- ] ;
/*	
//	my code
	int i = 1; // i记录空穴的位置
	//注意边界条件 i * 2 <= size ;
	while( ( i * 2 <= size ) && ( tmp > pt[ i * 2 ] || tmp > pt[ i * 2 + 1 ] ) ) { 
		if( pt[ i * 2 ] < pt[ i * 2 +1 ] ) { 
			pt[ i ] = pt[ i * 2 ] ;
			i = i * 2;
		} 
		else { 
			pt[ i ] = pt[ i * 2 + 1 ] ;
			i = i * 2 + 1;
		}
	}
	pt[ i ] = tmp;
*/
	int child;
	int i;
	for( i = 1; i * 2 <= size; i = child ) { 
		child = i * 2;
		//find the small child
		if( child != size && pt[ child ] > pt[ child + 1 ] ) 
			++child;

		if( tmp > pt[ child ] ) 
			pt[ i ] = pt[ child ] ;
		else
			break;
	}
	pt[ i ] = tmp;
	return *this;
}

template <typename T>
void binary_heap<T>::print( ) const
{ 
	for( int i = 1; i <= size; ++i ) { 
		std::cout << pt[ i ] << "  ";
	}
	std::cout << std::endl;
}

#endif
