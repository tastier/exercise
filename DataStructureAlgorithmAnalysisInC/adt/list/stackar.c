#include "stackar.h"
#include <stdlib.h>

#define EmptyTOS -1
#define MinStackSize 5

struct StackRecord {
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

int 
IsEmpty( Stack S )
{
	return S->TopOfStack == EmptyTOS;
}

int 
IsFull( Stack S )
{
	return S->TopOfStack == S->Capacity - 1;
}

Stack
CreateStack( int MaxElements )
{
	Stack S;
	
	if( MaxElements < MinStackSize )
		Error( " too small");

	S = malloc( sizeof( struct StackRecord ) );
	if( S == NULL )
		Error( " out of space ");
	
	S->Capacity = MaxElements;
	S->TopOfStack = -1;
	S->Array = malloc( sizeof( ElementType) * MaxElements );
	if( S->Array == NULL)
		Error( " out of space " );

	return S;
}

void
DisposeStack( Stack S )
{ 
	free( S->Array );
	free( S );
}

void 
MakeEmpty( Stack S )
{ 
	S->TopOfStack = EmptyTOS;
}

void
Push( ElementType X, Stack S)
{ 
	if( IsFull( S ) )
		Error( " Stack is full " );
	
	++S->TopOfStack;
	S->Array[ S->TopOfStack ] = X;
}

ElementType
Top( Stack S )
{ 
	if( IsEmpty( S ) )
		Error( " Empty");
	return S->Array[ S->TopOfStack ];
}

void
Pop( Stack S )
{ 
	if( IsEmpty( S ) )
		Error( " Stack is empty " );
	else	
		--S->TopOfStack;
}

ElementType
TopAndPop( Stack S )
{ 
	if( IsEmpty( S ) )
		Error( " empty " );
	else { 
		return S->Array[ S->TopOfStack-- ];
	}
}

