#include<iostream>
#include "Heap.h"

int main()
{
	std::vector<int> nonheap = { 5, 6, 7, 12, 17, 15, 100, -10, -190, 10, 20, 18 };
	Heap<int>* intheap = new Heap<int>();

	intheap->heapify(nonheap);
	intheap->print();
	intheap->deletemin();
	intheap->print();

	getchar();
	return 0;
}

