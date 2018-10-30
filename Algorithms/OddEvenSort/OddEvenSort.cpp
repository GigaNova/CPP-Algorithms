#include "OddEvenSort.h"

void OddEvenSort::Sort(std::vector<int>& _unsortedVector)
{
	odd(_unsortedVector);
}

void OddEvenSort::odd(std::vector<int>& _vector)
{
	bool swapped = false;
	for (int i = 0; i + 1 < _vector.size(); i += 2)
	{
		if(_vector[i + 1] < _vector[i])
		{
			swap(_vector, i, i + 1);
			swapped = true;
		}
	}

	if (swapped) even(_vector);
}

void OddEvenSort::even(std::vector<int>& _vector)
{
	bool swapped = false;
	for (int i = 1; i + 1 < _vector.size() - 1; i += 2)
	{
		if (_vector[i + 1] < _vector[i])
		{
			swap(_vector, i, i + 1);
			swapped = true;
		}
	}

	if (swapped) odd(_vector);
}

void OddEvenSort::swap(std::vector<int>& _vector, int _firstindex, int _secondindex)
{
	int temp = _vector[_firstindex];
	_vector[_firstindex] = _vector[_secondindex];
	_vector[_secondindex] = temp;
}
