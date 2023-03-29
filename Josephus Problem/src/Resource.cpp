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
void errorMessage()
{
	cout << "Lista vida sau inexistenta." << endl;
	exit(EXIT_FAILURE);
}
void CreateList(Nod*& cap, int count)
{
	if (count <= 0)
	{
		errorMessage();
	}
	int n;
	cout << "introduceti valori: " << endl;

	while (--count)
	{
		cin >> n;
		InsertFata(cap, n);
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
bool JosephsGame(Nod*& list, Nod*& blackList, int k)
{
	Nod* aux = NULL;

	if (list == NULL || k <= 0)
	{
		return false;
	}

	while (list != list->succ)
	{
		int i = 1;

		while (i < k)
		{
			aux = list;
			list = list->succ;
			++i;
		}
		donareElement(list, blackList, aux);
	}
	return true;
}
void donareElement(Nod*& list, Nod*& blackList, Nod*& aux)
{
	InsertFata(blackList, list->data);
	aux->succ = list->succ;
	delete list;
	list = aux->succ;
}
int winner(int n, int k) 
{
	//if (n == 1) 
	//{
	//	return 1;
	//}
	//else 
	//{
	//	return (winner(n - 1, k) + k - 1) % n + 1;
	//}
    int pos = 0;
    for (int i = 2; i <= n; i++) {
        pos = (pos + k) % i;
    }
    return pos + 1;
}
void showSomething(Nod* cap, int n)
{
	while (n > 1)
	{
		cap = cap->succ;
		--n;
	}
	cout << cap->data <<endl;
}