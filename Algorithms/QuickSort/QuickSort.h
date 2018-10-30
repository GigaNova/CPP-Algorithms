#pragma once
#include <vector>

class QuickSort
{
public:
	static void Sort(std::vector<int>& _unsortedVector);
	
private:
	static void quicksort(std::vector<int>& _vector, int _low, int _high);
	static int partition(std::vector<int>& _vector, int _low, int _high);
	static void swap(std::vector<int>& _vector, int _firstindex, int _secondindex);
};

