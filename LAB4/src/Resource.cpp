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

void CreateList(LDL& list)
{
	int n;
	cout << "introduceti valori (0- termina)!"<< endl;
	cin >> n;
	while (n)
	{
		InsertFata(list, n);
		cin >> n;
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

	if(order !=0 && order != 1 && order != -1)
	{
		cout << "Optiune invalida" << endl;
		exit(EXIT_FAILURE);
	}
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
bool stergereElement(LDL& list, int poz)
{
	Nod* p = list.first;
	Nod* victima = NULL;
	int k = 1;

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
void uniuneListe(LDL& list1, LDL& list2)
{
	Nod* p = list1.last;
	Nod* q = list2.first;

	p->succ = q;
	q->pred = p;
}
void interclasareListe(LDL& list1, LDL& list2)
{
	Nod* p = list1.first;
	Nod* q = list2.first;
	Nod* aux1 = p->succ;
	Nod* aux2 = q->succ;

	while (aux1 != NULL && aux2 != NULL)
	{
		p->succ = q;
		q->pred = p;

		q->succ = aux1;
		aux1->pred = q;

		q = aux2;
		p = aux1;

		aux1 = aux1->succ;
		aux2 = aux2->succ;
	}
	if (aux1 == NULL && aux2)
	{
		p->succ = q;
		q->pred = p;
	}
	if (aux2 == NULL && aux1)
	{
		p->succ = q;
		q->pred = p;

		q->succ = aux1;
		aux1->pred = q;
	}
}