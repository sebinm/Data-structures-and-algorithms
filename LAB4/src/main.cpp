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
	LDL listaDubla{};
	listaDubla.first = NULL;
	listaDubla.last = NULL;
	// 1
	// a
	CreateList(listaDubla);
	// b
	afisareLista(listaDubla);

	// c
	int pozElementNou = -1, n = -1;
	cout << endl << "Unde doriti sa se insereze un element? Si care este elementul?" << endl;
	cin >> pozElementNou;
	cin >> n;
	
	inserareElement(listaDubla, pozElementNou, n) ? afisareLista(listaDubla) : errorMessage();

	// d
	int pozVictima = -1;
	cout << endl << "Elementul de pe ce pozitie dori a fi sters?" << endl;
	cin >> pozVictima;

	stergereElement(listaDubla,pozVictima) ? afisareLista(listaDubla) : errorMessage();

	// 2

	int whatYouWish;
	cout << "Doresti o uniune de liste sau o interclasare? ( 1-uniune | 2-interclasare ): ";
	cin >> whatYouWish;


	LDL listaDublaSecunda{};
	listaDublaSecunda.first = NULL;
	listaDublaSecunda.last = NULL;

	cout << "Elemente pentru lista a doua: ";
	CreateList(listaDublaSecunda);


	switch (whatYouWish)
	{
	case 1:
		uniuneListe(listaDubla,listaDublaSecunda);
		afisareLista(listaDubla);
		break;
	case 2:
		interclasareListe(listaDubla,listaDublaSecunda);
		afisareLista(listaDubla);
	default:
		break;
	}

 	return 0;
}