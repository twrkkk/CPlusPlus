#include <iostream>
const int SIZE = 5;

void BubbleSort(int* arr, int size)
{
	for (size_t i = 0; i < size - 2; i++)
	{
		for (size_t j = 0; j < size - 2 - i; j++)
		{
			if (arr[j + 1] < arr[j])
				std::swap(arr[j + 1], arr[j]);
		}
	}
}

void SelectionSort(int* arr, int size)
{
	for (size_t i = 0; i < size-1; i++)
	{
		int min = i;
		for (size_t j = i+1; j < size; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		if (i != min)
			std::swap(arr[i], arr[min]);
	}
}

void QuickSort(int* arr, int l, int r)
{
	int d = arr[r];
	int i = l;
	int j = r;

	do
	{
		while (arr[i] < d)
			++i;
		while (arr[j] > d)
			--j;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			++i; 
			--j;
		}
	} while (i <= j);
	if (j > l)
		QuickSort(arr, l, j);
	if (i < r)
		QuickSort(arr, i, r);
}

int main()
{
	int* arr = new int[SIZE]{7,3,4,1,9};
	//BubbleSort(arr, SIZE);
	//SelectionSort(arr, SIZE);
	QuickSort(arr, 0, SIZE - 1);
	for (size_t i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

