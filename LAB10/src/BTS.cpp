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

#include "ArboriBinariDeCautare.h"

Nod* init()
{
	return NULL;
}
Nod* CreareNod(Atom value)
{
	Nod* p = new Nod;
	p->data = value;

	p->drt = init();
	p->stg = init();

	return p;
}
namespace recursion
{

	void InserareBTS(Nod*& root, Atom value)
	{
		if (root == NULL)
		{
			root = CreareNod(value);
		}
		else if (value < root->data)
		{
			recursion::InserareBTS(root->stg, value);
		}
		else if (value > root->data)
		{
			recursion::InserareBTS(root->drt, value);
		}
	}
	bool test(Nod* p)
	{
		return p == NULL;
	}
	bool cautareNod(Nod* p, Atom cautat)
	{
		if (p == NULL)
		{
			return false;
		}


		if(p->data == cautat)
		{
			return true;
		}
		else if (p->data < cautat)
		{
			return recursion::cautareNod(p->drt, cautat);
		}
		else
		{
			return recursion::cautareNod(p->stg, cautat);
		}
	}
	Nod* minNode(Nod* q)
	{
		Nod* aux = q;

		while (aux->stg != NULL)
		{
			aux = aux->stg;
		}
		return aux;
	}
	void deleteRoot(Nod*& p)
	{
		if (test(p))
		{
			return;
		}


		if (p->stg == NULL && p->drt == NULL)
		{
			delete p;
		}
		else if (p->stg == NULL)
		{
			Nod* aux = p->drt;
			delete p;
			p = aux;
		}
		else if (p->drt == NULL)
		{
			Nod* aux = p->stg;
			delete p;
			p = aux;
		}
		else
		{
			Nod* aux = recursion::minNode(p->drt);
			std::swap(p->data, aux->data);
			delete aux;
		}
	}
	void deleteNode(Nod*& p, Atom value)
	{
		if (p == NULL)
		{
			cout << "Element de negasit!" << endl;
			return;
		}
		
		if (value < p->data)
		{
			recursion::deleteNode(p->stg, value);
		}
		else if (value > p->data)
		{
			recursion::deleteNode(p->drt, value);
		}
		else
		{
			recursion::deleteRoot(p);
		}
	}
}
void inordine(Nod* p)
{
	if (p)
	{
		 // S-R-D
		inordine(p->stg);
		cout << p->data << " ";
		inordine(p->drt);
	}
}
void preordine(Nod* p)
{
	if (p)
	{
		// R-S-D
		cout << p->data << " ";
		preordine(p->stg);
		preordine(p->drt);
	}
}
void postordine(Nod* p)
{
	if (p)
	{
		// S-D-R
		postordine(p->stg);
		postordine(p->drt);
		cout << p->data << " ";
	}
}
namespace iterativ
{
	bool cautareNod(Nod* p, Atom cautat)
	{
		while (p != NULL)
		{
			if (p->data == cautat)
			{
				return true;
			}
			else if (cautat > p->data)
			{
				p = p->drt;
			}
			else
			{
				p = p->stg;
			}
		}
	}
	void InserareBTS(Nod*& root, Atom value)
	{
		Nod* aux = CreareNod(value);

		if (root == NULL)
		{
			root = aux;
			return;
		}

		Nod* p = root;

		while (true)
		{
			if (value == p->data)
			{
				return;
			}
			else if (value < p->data)
			{
				if (p->stg == NULL)
				{
					p->stg = aux;
					return;
				}
				else
				{
					p = p->stg;
				}
			}
			else
			{
				if (p->drt == NULL)
				{
					p->drt = aux;
					return;
				}
				else
				{
					p = p->drt;
				}
			}
		}

	}
}