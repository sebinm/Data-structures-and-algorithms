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
	// Task 1 / A
	Nod* cap = NULL;
	CreateList(cap);

	// Task 1 / B
	afisareLista(cap);

	// Tak 1 / C
	int cautat;
	cout <<"Nr de cautat in lista: ";
	cin >> cautat;

	if (CautareNr(cap, cautat))
	{
		cout << endl << "Elementul " << cautat << " se regaseste in lista creata" << endl;
	}
	else
	{
		cout << endl << "Elementul " << cautat << " nu se regaseste in lista creata" << endl;
	}

	// Task 1 / D
	int pozitie;

	cout << endl << "Pe ce pozitie se doreste a fi inserat numarul?" << endl;
	cin >> pozitie;

	inserareElem(cap, cautat, pozitie);
	afisareLista(cap);

	// Task 1 / E


	cout << "Elementul de pe ce pozitie doriti a fi sters?" << endl;
	cin >> pozitie;

	stergereElement(cap, pozitie);
	afisareLista(cap);

	// Task 1 / F
	cout << "Doriti sa se afiseze elemntul de pe linia: " << endl;
	cin >> pozitie;

	if (!afisareElement(cap, pozitie))
	{
		cout << "Poztie invalida" << endl;
	}

	// Task 1 / G

	cout << "Lista dus intors: " << endl;
	afisareDusIntors(cap);

	// Task 1 / H

	cout << endl << endl << "Mijlocul listei: ";
	afisareMijloc(cap);


	// Task 1 / I
	cout << "Lista cu legaturi inversate: " << endl;
	inversareLegaturi(cap);
	afisareLista(cap);

	// Task 2

	cout << "Lista a doua: " << endl;
	Nod* second = NULL;
	CreateList(second);

	int whatYouWish;
	cout << "Doresti o uniune de liste sau o interclasare? ( 1-uniune | 2-interclasare ): ";
	cin >> whatYouWish;

	while (whatYouWish != 1 && whatYouWish != 2)
	{
		cin >> whatYouWish;
	}

	switch (whatYouWish)
	{
	case 1:
		uniuneListe(cap, second);
		break;
	case 2:
		interclasareListe(cap, second);
	default:
		break;
	}
	
	return 0;
}
