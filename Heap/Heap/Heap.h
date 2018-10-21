#pragma once
#include <vector>
#include <iostream>

//Min-Max Heap implementation
template <class T>
class Heap
{
public:
	Heap()
	{
		array.resize(1);
		size = 0;
		max = 1;
	}

	~Heap()
	{
	}

	void insert(T _item)
	{
		if (size >= max)
		{
			max += 1;
			array.resize(max);
		}

		array[size] = _item;
		siftup(size);
		size++;
	}

	T deletemin()
	{
		//Get min item
		T item = array[0];
		//Size decreases
		--size;
		--max;
		//Rotate most right item to the beginning
		std::rotate(array.begin(), array.begin() + 1, array.end());
		//Shrink the array
		array.resize(max);
		//Re-heapify
		if (size > 0)
		{
			siftdown(0);
		}
		//Return item
		return item;
	}

	void heapify(std::vector<T> _array)
	{
		array = _array;
		max = size = _array.size();

		int index = 1;
		while (index < max)
		{
			siftup(index);
			index += 1;
		}
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < pow(2, i) && j + pow(2, i) < size; j++)
			{
				auto index = j + (int)pow(2, i) - 1;
				std::cout << array[index] << " ";
			}
			std::cout << std::endl;
		}
	}

private:
	int findleaf(int _index)
	{
		int j = _index;
		while (right(j) <= size)
		{
			if (array[right(j)] > array[left(j)])
			{
				j = right(j);
			}
			else
			{
				j = left(j);
			}
		}

		if (left(j) <= max)
		{
			j = left(j);
		}
		return j;
	}

	void siftup(int _index)
	{
		int index = _index;
		while (index != 0)
		{
			int parentIndex = parent(index);
			if (array[index] < array[parentIndex])
			{
				T temp = array[index];
				array[index] = array[parentIndex];
				array[parentIndex] = temp;

				index = parentIndex;
			}
			else
			{
				break;
			}
		}
	}

	void siftdown(int _index)
	{
		int minindex = 0;
		int leftchild = left(_index);
		int rightchild = right(_index);
		if (rightchild >= size)
		{
			if (leftchild >= size)
				return;
			minindex = leftchild;
		}
		else
		{
			minindex = findleaf(_index);
		}

		if (array[_index] > array[minindex])
		{
			T tmp = array[minindex];
			array[minindex] = array[_index];
			array[_index] = tmp;
			siftdown(minindex);
		}
	}

	//-1 for zero based heap
	int parent(int _index)
	{
		return (_index - 1) / 2;
	}

	//+1 for zero based heap
	int left(int _index)
	{
		return 2 * _index + 1;
	}

	//+2 for zero based heap
	int right(int _index)
	{
		return (2 * _index) + 2;
	}

	int size;
	int max;
	std::vector<T> array;
};

