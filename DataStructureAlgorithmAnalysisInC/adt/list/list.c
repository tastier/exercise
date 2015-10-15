#include "list.h"
#include <stdlib.h>

struct Node {
	ElementType Element;
	Position Next;
};

List MakeEmpty(List L)
{
	if( L != NULL)
		DeleteList( L );
	L = malloc( sizeof( struct Node ) );
	if( L == NULL )
		Error("out of space\n");
	L->Next = NULL;
	return L;
}

void DeleteList(List L)
{
	Position P, tmp;

	P = L->Next;
	free( L );
	L = NULL;
	while( P != NULL ) {
		tmp = P->Next;
		free(P);
		P = tmp;
	}
}

int IsEmpty( List L )
{
	if(L->Next == NULL)
		printf("empty list\n");
	return 1;
}

int IsLast( Position P, List L)
{
	return P->Next == NULL;
}

Position Find( ElementType X, List L)
{
/*	Position now = L;
	
	if(L->Next == NULL)
		return NULL;

	while(now->Next != NULL) {
		if( now->Next->Element != X)
			now = now->Next;
		else
			return now->Next;
	}
	return NULL; */
	Position P = L->Next;
	while(P != NULL && P->Element != X)
		P = P->Next;
	return P;
}

void Delete( ElementType X, List L)
{
	Position P = FindPrevious(X, L);
	Position tmp = P->Next;
	if(!IsLast(P, L)) {
		P->Next = P->Next->Next;
		free(tmp);
	}
	//if P is the last, do nothing
}

//if X is not found, P is the last position
Position FindPrevious(ElementType X, List L)
{
	Position P = L;
	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}

void Insert( ElementType X, List L, Position P)
{
	Position tmp = (Position)malloc( sizeof(struct Node));
	if(tmp == NULL)
		Error("out of space\n");
	tmp->Element = X;
	tmp->Next = P->Next;
	P->Next = tmp;
}

