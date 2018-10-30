// CountSort.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>
#include "ShellSort.h"

void fillvector(std::vector<int>& _vector, int _size)
{
	_vector.resize(_size);
	for (int i = 0; i < _size; ++i)
	{
		_vector[i] = (_size - i);
	}
}

void benchmark(std::vector<int>& _vector)
{
	auto c0 = std::chrono::high_resolution_clock::now();
	ShellSort::Sort(_vector);
	auto c1 = std::chrono::high_resolution_clock::now();

	std::cout << std::fixed;
	std::cout << _vector.size() << " Elements took " << std::chrono::duration<double>(c1 - c0).count() << " seconds... " << std::endl;
}

int main()
{
	std::vector<int> unsorted_small;
	std::vector<int> unsorted_medium;
	std::vector<int> unsorted_large;
	std::vector<int> unsorted_huge;

	fillvector(unsorted_small, 10);
	fillvector(unsorted_medium, 1000);
	fillvector(unsorted_large, 100000);
	fillvector(unsorted_huge, 10000000);

	benchmark(unsorted_small);
	benchmark(unsorted_medium);
	benchmark(unsorted_large);
	benchmark(unsorted_huge);

	getchar();
	return 0;
}
