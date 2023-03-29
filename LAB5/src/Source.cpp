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

#include "header.h"

//void swap(int& xp, int& yp)
//{
//	int temp = xp;
//	xp = yp;
//	yp = temp;
//}
void InsertFata(Nod*& cap, int val)
{
	Nod* p = new Nod;
	p->data = val;

	if (cap == NULL)
	{
		cap = p;
		p->succ = p;
	}
	else
	{
		p->succ = cap->succ;
		cap->succ = p;
		swap(cap->data, p->data);
	}
}
void CreateList(Nod*& cap)
{
	int n;
	cout << "introduceti valori (0- termina)!" << endl;
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
	do
	{
		std::cout << p->data << " ";
		p = p->succ;
	} while (p != cap);
	
	cout << endl;
}

void inversareLegaturi(Nod*& cap)
{
	Nod* aux = cap;
	Nod* p = cap->succ;
	Nod* q = cap->succ->succ;

	do {
		// interschimbare
		p->succ = aux;
		aux = p;
		p = q;

		q = q->succ;
	} while (q != cap);

	p->succ = aux;
	q->succ = p;
	cap = p;
}
void uniuneLista(Nod* first, Nod* second)
{
	Nod* p = first;
	Nod* q = second;

	while (p->succ != first)
	{
		p = p -> succ;
	}
	p->succ = second;

	while (q->succ != second)
	{
		q = q->succ;
	}
	q->succ = first;
}
void interclasareListe(Nod* first, Nod* second)
{
	Nod* p = first;
	Nod* q = second;
	Nod* aux1;
	Nod* aux2;

	while (p->succ != first && q->succ != second)
	{
		aux1 = p->succ;
		aux2 = q->succ;

		p->succ = q;
		q->succ = aux1;

		p = aux1;
		q = aux2;
	}
}