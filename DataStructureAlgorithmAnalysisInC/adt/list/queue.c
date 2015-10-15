#include " queue.h"

#define MinQueueSize 5

struct QueueRecord { 
	int Capacity;
	int Size;
	int Front;
	int Rear;
	ElementType *Array;
};

int
IsEmpty( Queue Q )
{ 
	return Q->Size == 0;
}

int
IsFull( Queue Q )
{ 
	return Q->Size == Q->Capacity;
}

Queue CreateQueue( int MaxElements )
{ 
	Queue Q;

	if( MaxElements < MinQueueSize )
		Error( " Queue is too small");

	Q = malloc( sizeof( QueueRecord ) );
	if( Q == NULL )
		Error( " out of memory ");

	Q->Capacity = MaxElements;
	MakeEmpty( Q );	
	Q->Array = malloc( sizeof( ElementType ) * MaxElements );
	if( Q->Array == NULL )
		Error( " out of memory");

	return Q;
}

void
DisposeQueue( Queue Q )
{ 
	if( Q != NULL ) { 
		free( Q->Array );
		free( Q );
	}
	else
		Error( " ");
}

void
MakeEmpty( Queue Q )
{ 
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

void
Enqueue( ElementType X, Queue Q)
{ 
	if( IsFull( Q))
		Error( " queue is full");

	if( ++Q->Rear == Q->Capacity )
		Q->Rear = 0;

	Q->Array[ Q->Rear ] = X;
	++Q->Size;
} 

ElementType 
Front( Queue Q )
{ 
	if( Q != NULL && !IsEmpty( Q ) )
		return Q->Array[ Q->Front ];
}

void
Dequeue( Queue Q )
{ 
	if( IsEmpty( Q))
		Error( " empty");

	if( ++Q->Front == Q->Capacity )
		Q->Front = 0;

	--Q->Size;
}

