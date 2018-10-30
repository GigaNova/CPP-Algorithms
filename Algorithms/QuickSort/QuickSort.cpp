#include "QuickSort.h"

void QuickSort::Sort(std::vector<int>& _unsortedVector)
{
	quicksort(_unsortedVector, 0, _unsortedVector.size() - 1);
}

void QuickSort::quicksort(std::vector<int>& _vector, int _low, int _high)
{
	if(_low < _high)
	{
		int pivot = partition(_vector, _low, _high);
		quicksort(_vector, _low, pivot - 1);
		quicksort(_vector, pivot + 1, _high);
	}
}

int QuickSort::partition(std::vector<int>& _vector, int _low, int _high)
{
	int pivot = _vector[_high];
	int index = _low;

	for (int i = _low; i <= _high - 1; ++i)
	{
		if(_vector[i] < pivot)
		{
			if(index != i)
			{
				swap(_vector, index, i);
			}
			++index;
		}
	}
	swap(_vector, index, _high);

	return index;
}

void QuickSort::swap(std::vector<int>& _vector, int _firstindex, int _secondindex)
{
	int temp = _vector[_firstindex];
	_vector[_firstindex] = _vector[_secondindex];
	_vector[_secondindex] = temp;
}
