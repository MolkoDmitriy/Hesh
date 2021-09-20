#include "List.h"

void genRandMas(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 20+1;
	}
}

void init(List*& ptr, int var) {
	ptr = new List;
	ptr->next = NULL;
	ptr->var = var;
}

void add(List*& ptr, int var) {
	if (ptr) {
		List* p;
		p = new List;
		p->var = ptr->var;
		p->next = ptr->next;
		ptr->var = var;
		ptr->next = p;
	}
	else
	{
		ptr = new List;
		ptr->next = NULL;
		ptr->var = var;
	}
}
void print_list(List* ptr) {
	while (ptr)
	{
		cout << ptr->var << " ";
		ptr = ptr->next;
	}
}

void FillInc(List*& ptr, int size)
{
	for (int i = size; i >0; i--)
	{
		add(ptr, i );
	}
}

