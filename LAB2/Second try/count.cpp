#include <iostream>
#include <algorithm>
#include <string>



using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;


void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// Algoritmi de sortare

int bubbleSort(int arr[], int n)
{
	unsigned int cont = 0;
	int i, j;
	for (i = 0; i < n - 1; ++i)
	{
		cont += 2;
		for (j = 0; j < n - i - 1; ++j)
		{
			cont += 2;
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				cont += 5;
			}
			cont += 3;
		}
	}
	cont += 2;
	return cont;
}

int selectionSort(int arr[], int n)
{
	unsigned int cont = 0;
	int i, j, min_idx;

	for (i = 0; i < n - 1; ++i)
	{
		cont += 2;
		min_idx = i;
		++cont;
		for (j = i + 1; j < n; j++)
		{
			cont += 2;
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
				++cont;
			}
			cont += 3;
		}
		if (min_idx != i)
		{
			swap(&arr[min_idx], &arr[i]);
			cont += 5;
		}
		++cont;
	}
	cont += 2;

	return cont;
}

int insertionsort(int arr[], int n)
{
	unsigned int cont = 0;

	int i, key, j;
	for (i = 1; i < n; i++)
	{
		cont += 2;

		key = arr[i];
		j = i - 1;

		cont += 2;

		while (j >= 0 && arr[j] > key)
		{
			cont += 4;
			arr[j + 1] = arr[j];
			j = j - 1;
			cont += 4;
		}
		arr[j + 1] = key;
		++cont;
	}
	++cont;
	return cont;
}

// Algoritmi de cautare

bool BruteForce_search(int A[], int n, int elem, int& cont)
{
	int i = 1;
	cont = 0;
	++cont;
	while (i <= n)
	{
		++cont;

		cont += 2;
		if (A[i] == elem)
		{
			return true;
		}
		++i;
		++cont;
	}
	return false;
}
int binarySearch(int arr[], int l, int r, int x, int& cont)
{
	// cont = 0;
	++cont;
	if (r >= l)
	{

		int mid = l + (r - l) / 2;
		++cont;

		cont += 2;
		if (arr[mid] == x)
		{
			return mid;
		}

		cont += 2;
		if (arr[mid] > x)
		{
			return binarySearch(arr, l, mid - 1, x, cont);
		}

		return binarySearch(arr, mid + 1, r, x, cont);
	}
	return -1;
}