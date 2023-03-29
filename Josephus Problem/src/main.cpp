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
	int n, k;

	cout << "Numarul de membrii din joc: ";
	cin >> n;
	cout << "Pasul de excludere: ";
	cin >> k;

	Nod* JosephsList = NULL;
	Nod* blackList = NULL;

	CreateList(JosephsList, n);

	cout << "Lista: " << endl;
	afisareLista(JosephsList);

	cout << "Pariu pe: "; 
	showSomething(JosephsList, winner(n, k));

	
	if (!JosephsGame(JosephsList, blackList, k))
	{
		errorMessage();
	}

	cout << "Rezultat: ";
	afisareLista(JosephsList);

	cout << "Preliminarii: ";
	afisareLista(blackList);



	return 0;
}