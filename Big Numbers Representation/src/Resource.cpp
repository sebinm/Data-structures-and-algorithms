#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>

#define playerOne 1
#define plyerTwo 2


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;

#include "header.h"


void InsertFata(LDL& list, int val)
{
	Nod* p = new Nod;
	p->data = val;
	if (!(list.first && list.last))
	{
		p->pred = p->succ = list.first;
		list.first = list.last = p;
	}
	else
	{
		p->pred = NULL;
		p->succ = list.first;
		list.first->pred = p;
		list.first = p;
	}
}

void CreateList(LDL& list, unsigned long long number, bool sign)
{
	// sign = true results that the number is positive 1*number
	// sign = false results the number is negative (-1)*number

	list.sign = sign;
	list.lungime = 0;

	while (number != 0)
	{
		InsertFata(list, number % 1000);
		number /= 1000;
		list.lungime++;
	}
}

void afisareDus(LDL list)
{
	while (list.first != NULL)
	{
		std::cout << list.first->data << " ";
		list.first = list.first->succ;
	}
	cout << endl;
}
void afisareIntors(LDL list)
{
	while (list.last != NULL)
	{
		std::cout << list.last->data << " ";
		list.last = list.last->pred;
	}
	cout << endl;
}

void afisareLista(LDL member, short order)
{
	//	0 -> afisare dus-intors
	//	1 -> afisare dus
	// -1 -> afisare intos

	if (order != 0 && order != 1 && order != -1)
	{
		cout << "Optiune invalida" << endl;
		exit(EXIT_FAILURE);
	}

	cout << endl;

	switch (order)
	{
	case 0:
		afisareDus(member);
		afisareIntors(member);
		break;
	case 1:
		afisareDus(member);
		break;
	case -1:
		afisareIntors(member);
		break;
	default:
		break;
	}
}
bool inserareElement(LDL& list, int poz, int elem)
{
	Nod* p = list.first;
	Nod* q = new Nod;
	q->data = elem;

	int k = 1;

	while (p != NULL && k < poz - 1)
	{
		p = p->succ;
		++k;
	}
	if (p != NULL)
	{
		q->succ = p->succ;
		(p->succ)->pred = q;
		q->pred = p;
		p->succ = q;
	}
	return p != NULL;
}
void errorMessage()
{
	cout << "Pozitie invalida." << endl;
}

bool citireNumar(unsigned long long& nr)
{
	bool sign;

	cout << "Introduceti numarul fara semn (maxim 18 cifre): ";
	cin >> nr;

	cout << "Introduceti semnul: (1-pozitiv | 0-negativ) ";
	cin >> sign;

	return sign;
}

bool stergereElement(LDL& list, int poz)
{
	Nod* p = list.first;
	Nod* victima = NULL;
	int k = 1;

	list.lungime--;

	while (p != NULL && k < poz - 1)
	{
		p = p->succ;
		++k;
	}
	if (p != NULL)
	{
		victima = p->succ;
		p->succ = p->succ->succ;
		(p->succ)->pred = p;

		delete victima;
	}
	return p != NULL;
}
void golireLista(LDL& list)
{
	while (list.lungime != 0)
	{
		stergereElement(list, list.lungime);
	}
}
void winnerMessage(short nr)
{
	cout << "Numarul " << nr << " este mai mare." << endl << endl;
}
bool signCheckWinner(const LDL& nrMare1, const LDL& nrMare2)
{
	if (nrMare1.sign == true && nrMare2.sign == false)
	{
		winnerMessage(playerOne);
		return true;
	}
	else if (nrMare1.sign == false && nrMare2.sign == true)
	{
		winnerMessage(plyerTwo);
		return true;
	}
	return false;
}
bool lengthCheckWinner(const LDL& nrMare1, const LDL& nrMare2)
{
	if (nrMare1.lungime > nrMare2.lungime)
	{
		winnerMessage(playerOne);
		return true;
	}
	else if (nrMare1.lungime < nrMare2.lungime)
	{
		winnerMessage(plyerTwo);
		return true;
	}
	return false;
}
bool valueCheckWinner(const LDL& nrMare1, const LDL& nrMare2)
{
	Nod* p = nrMare1.first;
	Nod* q = nrMare2.first;

	while (p != NULL && q != NULL)
	{
		if (p->data > q->data)
		{
			winnerMessage(playerOne);
			return true;
		}
		else if (q->data > p->data)
		{
			winnerMessage(plyerTwo);
			return true;
		}
		p = p->succ;
		q = q->succ;
	}
	return false;
}
void comparNrMari(const LDL& nrMare1, const LDL& nrMare2)
{
	if (signCheckWinner(nrMare1, nrMare2))
	{
		return;
	}
	else if (lengthCheckWinner(nrMare1,nrMare2))
	{
		return;
	}
	else if (valueCheckWinner(nrMare1,nrMare2))
	{
		return;
	}
	else
	{
		cout << "Numerele sunt egale!" << endl << endl;
	}
}
LDL adunareNrMari(const LDL& nrMare1, const LDL& nrMare2)
{
	// Se presupune semnul pozitiv pentru ambele numere si aceasi lungime (pentru moment)

	LDL aux{};
	aux.sign = true;
	aux.first = NULL;
	aux.last = NULL;

	Nod* p = nrMare1.first;
	Nod* q = nrMare2.first;
	short sum;
	short transport = 0;

	while (p != NULL && q != NULL)
	{
		sum = p->data + q->data + transport;

		if (sum <= 999)
		{
			transport = 0;

			InsertFata(aux, sum);
			aux.lungime++;
		}
		else
		{
			transport = sum / 1000;
			sum %= 1000;

			InsertFata(aux, sum);
			aux.lungime++;
		}
		p = p->succ;
		q = q->succ;
	}

	while (p != NULL)
	{
		// Tratarea cazului cand numarul nrMare1 este
		sum = p->data;

		InsertFata(aux, sum);
		aux.lungime++;

		p = p->succ;
	}
	while (q != NULL)
	{
		sum = q->data;

		InsertFata(aux, sum);
		aux.lungime++;

		q = q->succ;
	}

	return aux;
}