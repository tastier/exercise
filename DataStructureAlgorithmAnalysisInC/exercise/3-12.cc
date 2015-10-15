//a
//Assuming L has a header
List
reverse_list( List L )
{ 
	struct Node * p, tmp;

	p = L->Next->Next;
	L->Next->Next = NULL;

	while( p != NULL ) { 
		tmp = p;
		p = p->Next;
		tmp->Next = L->Next;
		L->Next = tmp;
	} 
	return L;
}
