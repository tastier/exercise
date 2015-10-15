void
PrintLots( List L, List P)
{ 
	Position pos_P = P->Next;
	Position pos_L = L->Next;
	int th_L = 1;

	while( pos_P != NULL && pos_L != NULL ) { 
		pos_L = find( pos_L, pos_P->Element - th_L );
		th_L = pos_P->Element;

		pos_P = pos_P->Next;
		printf( " The %dth element of L is %d\n", th_L, pos_L->Element);
	}
}

Position
find( Position p, int n)
{ 
	while( n-- )
		p = p->Next;
	return p;
}
