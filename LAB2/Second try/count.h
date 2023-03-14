#pragma once


// Algoritmi de sortare
void swap(int* xp, int* yp);
int bubbleSort(int arr[], int n);
int selectionSort(int arr[], int n);
int insertionsort(int arr[], int n);

// Algoritmi de cautare
bool BruteForce_search(int A[], int n, int elem, int& cont);
int binarySearch(int arr[], int l, int r, int x, int& cont);