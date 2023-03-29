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



void InsertFata(Nod*& cap, int val)
{
	Nod* p;
	p = new Nod;
	p->data = val;
	p->succ = cap;
	cap = p;
}
void CreateList(Nod*& cap)
{
	int n;
	cout << "introduceti valori (0- termina)!"
		<< endl;
	cin >> n;
	while (n)
	{
		InsertFata(cap, n);
		cin >> n;
	}
}
void afisareLista(Nod* cap)
{
	Nod* p = cap;

	while (p != NULL)
	{
		std::cout << p->data << " ";
		p = p->succ;
	}
	cout << endl;
}
bool CautareNr(Nod* cap, int elem)
{
	Nod* p = cap;

	while (p != NULL)
	{
		if (p->data == elem)
		{
			return true;
		}
		p = p->succ;
	}
	return false;
}
void inserareElem(Nod*& cap, int elem, int poz)
{
	Nod* p = cap;
	Nod* q = new Nod;
	q->data = elem;

	int  k = 1;

	while (p != NULL && k < poz - 1)
	{
		p = p->succ;
		++k;
	}
	if (p != NULL)
	{
		q->succ = p->succ;
		p->succ = q;
	}
}
void stergereElement(Nod*& cap, int poz)
{
	Nod* p = cap;
	Nod* victima = NULL;
	int k = 1;

	while (p != NULL && k < poz - 1)
	{
		p = p->succ;
		++k;
	}
	if (p != 0)
	{
		victima = p->succ;
		p->succ = p->succ->succ;

		delete victima;
	}
}
bool afisareElement(Nod*& cap, int poz)
{
	Nod* p = cap;
	Nod* aux = cap;

	while (aux!= NULL && poz > 0)
	{
		aux = aux->succ;
		--poz;
	}
	while (aux != NULL)
	{
		aux = aux->succ;
		p = p->succ;
	}
	if (p != NULL)
	{
		cout << "Element: " << p->data << endl;
		return true;
	}
	return false;
}
void afisareDusIntors(Nod* cap)
{
	if (cap != NULL)
	{
		cout << cap->data << " ";
		afisareDusIntors(cap->succ);
		cout << cap->data << " ";
	}
}
void afisareMijloc(Nod* cap)
{
	Nod* p = cap;
	Nod* q = cap;

	while (q != NULL && q->succ != NULL)
	{
		q = q->succ->succ;
		p = p->succ;
	}
	//if (p)
	//{
	//	cout << p->data << endl;
	//}
	cout << (p ? p->data: -1) << endl;
}
void inversareLegaturi(Nod*& cap)
{
	Nod* aux = 0;
	Nod* p = cap;
	Nod* q = cap->succ;

	do {
		// interschimbare
		p->succ = aux; 
		aux = p;
		p = q;

		q = q->succ;
	} while (q != NULL);

	p->succ = aux;
	cap = p;
}

// Task 2
void uniuneListe(Nod*& first, Nod*& second)
{
	Nod* p = first;

	while (p->succ != NULL)
	{
		p = p->succ;
	}
	p->succ = second;

	afisareLista(first);
}
void interclasareListe(Nod* first, Nod* second) {
	Nod* p = first;
	Nod* q = second;
	Nod* aux1;
	Nod* aux2;

	while (p != NULL && q != NULL) 
	{
		aux1 = p->succ;
		aux2 = q->succ;

		p->succ = q;
		q->succ = aux1;
		
		p = aux1;
		q = aux2;
	}
	afisareLista(first);
}