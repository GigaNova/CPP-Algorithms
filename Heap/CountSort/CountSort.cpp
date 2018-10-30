#include "CountSort.h"
#include <algorithm>
#include <iostream>

void CountSort::Sort(std::vector<int>& _unsortedVector)
{
	int max = *std::max_element(_unsortedVector.begin(), _unsortedVector.end()) + 1;
	int* count = new int[max];

	std::fill(count, count + max, 0);

	for(int i : _unsortedVector)
	{
		count[i] += 1;
	}

	for (int j = 1; j < max; ++j)
	{
		count[j] = count[j - 1] + count[j];
	}

	for (int k = max - 1; k >= 0; --k)
	{
		count[k] = k - 1 < 0 ? 0 : count[k - 1];
	}

	std::vector<int> newvector;
	newvector.resize(max);

	for (int l = 0; l < _unsortedVector.size(); ++l)
	{
		int value = _unsortedVector[l];
		int index = count[value];
		newvector[index] = value;
		count[value] += 1;
	}

	newvector.resize(max - 1);
	_unsortedVector = std::vector<int>(newvector);
}
