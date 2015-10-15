//single
void
swap( Position beforeP, List L)
{ 
	Position P = beforeP->Next;
	Position afterP = P->Next;

	beforeP->Next = afterP;
	P->Next = afterP->Next;
	afterP->Next = P;
	 
}

//double
void
swap( Position P, List L) 
{ 
	Position BeforeP = P->Prev;
	Position AfterP = P->Next;

	P->Next = AfterP->Next;
	AfterP->Next->Prev = P;

	AfterP->Next = P;
	P->Prev = AfterP;

	BeforeP->Next = AfterP;
	AfterP->Prev = BeforeP;
}

