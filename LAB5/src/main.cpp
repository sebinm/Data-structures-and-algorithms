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
	// 3
	Nod* list = NULL;
	CreateList(list);
	afisareLista(list);

	inversareLegaturi(list);
	afisareLista(list);



	// 5

	Nod* aux = NULL;

	int whatYouWish;
	cout << "Doresti o uniune de liste sau o interclasare? ( 1-uniune | 2-interclasare ): ";
	cin >> whatYouWish;


	cout << "Elemente pentru lista a doua: ";

	CreateList(aux);


	switch (whatYouWish)
	{
	case 1:
		uniuneLista(list, aux);
		afisareLista(list);
		break;
	case 2:
		interclasareListe(list, aux);
		afisareLista(list);
	default:
		break;
	}

	return 0;
}