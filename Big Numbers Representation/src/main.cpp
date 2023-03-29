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

#include "header.h"

int main(void)
{
	unsigned long long compar1 = 141592653589793238; // 18 digits
	// unsigned long long compar2 = 718281828459045235; 
	unsigned long long compar3 = 718281;
	unsigned long long aux = 0;
	
	bool signAUX = citireNumar(aux);

	LDL test{}, billGates{}, suma{}, termen{};
	test.first = NULL;
	test.last = NULL;
	billGates.first = NULL;
	billGates.last = NULL;
	// LDL test si billGates ne folosesc pentru realizarea compararii

	CreateList(billGates, aux, signAUX);
	afisareLista(billGates, -1);

	cout << endl << endl;
	CreateList(test, compar1);
	afisareLista(test, -1);

	comparNrMari(test, billGates);

	
	suma.first = NULL;
	suma.last = NULL;
	termen.first = NULL;
	termen.last = NULL;
	// LDL suma si termen sunt utilizate pentru realizarea sumei
	
	// golireLista(test);
	// afisareLista(test);

	CreateList(termen, compar3);

	suma = adunareNrMari(termen, billGates);
	afisareLista(billGates, 1);
	afisareLista(termen, 1);
	afisareLista(suma, -1);

	cout << endl << endl;
	stergereElement(suma);
	afisareLista(test, 1);

	return 0;
}