#include "stackli.h"
#include <stdlib.h>
struct Node {
	ElementType Element;
	PtrToNode Next;
}

int IsEmpty( Stack S )
{
	return S->Next == NULL;
}

Stack CreateStack( void )
{
	Stack S;
	S = malloc( sizeof( struct Node ) );
	if( S == NULL )
		Error("out of space\n");
	S->Next = NULL;
	return S;
}

void MakeEmpty( Stack S )
{
	if( S == NULL )
		Error("use CreateStack first\n");
	else
		while( !IsEmpty(S) )
			Pop(S);
}

void Push( ElementType X, Stack S)
{
	PtrToNode P;

	P = malloc( sizeof( struct Node));
	if( P == NULL )
		Error("out of space\n");
	else {
		P->Element = X;
		P->Next = S->Next;
		S->Next = P;
	}
}

ElementType Top( Stack S )
{
	if( !IsEmpty( S ) )
		return S->Next->Element;
	else
		Error("Stack is empty");
}

void Pop( Stack S )
{
	PtrToNode tmp;
	if( !IsEmpty(S) ) {
		tmp = S->Next;
		S->Next = tmp->Next;
		free(tmp);
	}
	else
		Error("Stack is empty");
}

