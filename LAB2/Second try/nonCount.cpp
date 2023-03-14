#include <iostream>
#include <algorithm>
#include <string>



using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;

#include "nonCount.h"

void swap2(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Algoritmi de sortare

void bubbleSortN(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap2(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void selectionSortN(int arr[], int n)
{
    int i, j, min_idx;
    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in 
        // unsorted array 
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element 
        // with the first element 
        if (min_idx != i)
            swap2(&arr[min_idx], &arr[i]);
    }
}
void insertionSortN(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Algoritmi de cautare

bool BruteForce_searchN(int A[], int n, int elem)
{
    int i = 1;
    while (i <= n)
    {
        if (A[i] == elem)
        {
            return true;
        }
        ++i;
    }
    return false;
}

int binarySearchN(int array[], int x, int low, int high) {

    // Repeat until the pointers low and high meet each other
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}