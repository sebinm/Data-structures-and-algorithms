#pragma once

typedef int Atom;

struct Nod {
	Atom data;
	Nod *stg, *drt;
};

// Initializari
Nod* init();
Nod* CreareNod(Atom value);

// Functii recursive
namespace recursion
{
	
	Nod* minNode(Nod* q);
	void deleteRoot(Nod*& p);
	void deleteNode(Nod*& p, Atom value);
	bool test(Nod* p);

	void InserareBTS(Nod*& root, Atom value);
	bool cautareNod(Nod* p, Atom cautat);
}

// Functii iterative
namespace iterativ
{
	void InserareBTS(Nod*& root, Atom value);
	bool cautareNod(Nod* p, Atom cautat);
}


// Afisari
void inordine(Nod*);
void preordine(Nod* p);
void postordine(Nod* p);