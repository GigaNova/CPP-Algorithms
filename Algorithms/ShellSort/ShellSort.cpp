#include "ShellSort.h"

void ShellSort::Sort(std::vector<int>& _unsortedVector)
{
	for (int i = floor(_unsortedVector.size() / 3); true; i /= 3)
	{
		if (i == 0) i = 1;

		for (int j = i; j < _unsortedVector.size(); ++j)
		{
			int k = 0;
			while (j - k >= i && _unsortedVector[j - k]<_unsortedVector[j - i - k]) {
				int temp = _unsortedVector[j - k];
				_unsortedVector[j - k] = _unsortedVector[j - i - k];
				_unsortedVector[j - i - k] = temp;
				k += i;
			}
		}

		if (i == 1) break;
	}
}
