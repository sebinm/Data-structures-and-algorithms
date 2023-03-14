#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;
using std::swap;
using std::setw;
using std::setfill;
using std::left;

#include "count.h"
#include "nonCount.h"
#include "AlgorithmTest.h"


int nameIndex(int i)
{
	int j = 0;

	if (i == 0)
	{
		j = 1;
	}
	else if (i == 4)
	{
		j = 2;
	}
	else if (i == 8)
	{
		j = 3;
	}
	else if (i == 12)
	{
		j = 4;
	}
	else if (i == 16)
	{
		j = 5;
	}
	else {
		j = 0;
	}
	return j;
}
int numberCase(int i)
{
	int n = 10000;
	if (i % 4 == 0)
	{
		n = 10;
	}
	else if (i % 4 == 1)
	{
		n = 100;
	}
	else if (i % 4 == 2)
	{
		n = 1000;
	}
	return n;
}

void TimeStatisticsPrint(unsigned long long* ms, unsigned long long* us)
{
	string algorithmName[] = {
		" ",
		"BubbleSort",
		"SelectionSort",
		"InsertionSort",
		"BruteForce",
		"BinarySearch"
	};

	cout << left << setw(10) << "Algorithm name: " << left << setw(5) << "N: " << left
		<< setw(8) << "Time in ms: " << left << setw(10) << "Time in us: " << endl;

	for (int i = 0; i < 20; ++i)
	{
		cout << " "<<left << setw(10) << algorithmName[nameIndex(i)] << " "
			<< left << setw(5) << numberCase(i) << " "
			<< left << setw(8) << ms[i] << " "
			<< left << setw(10) << us[i]
			<< endl;
	}
}

void GeneralTime()
{
	unsigned long long timpms[20];
	unsigned long long timpus[20];

	masuarareBubleSort(timpms, timpus);


	masuarareSelectionSort(timpms + 4, timpus + 4);

	masuarareInsertionSort(timpms + 8, timpus + 8);

	masuarareBruteForce(timpms + 12, timpus + 12);

	masuarareBinarySearch(timpms + 16, timpus + 16);


	TimeStatisticsPrint(timpms, timpus);

	//delete[] timpms;
	//delete[] timpus;

}