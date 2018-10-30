#pragma once
#include <vector>

class OddEvenSort
{
public:
	static void Sort(std::vector<int>& _unsortedVector);

private:
	static void odd(std::vector<int>& _vector);
	static void even(std::vector<int>& _vector);
	static void swap(std::vector<int>& _vector, int _firstindex, int _secondindex);
};

