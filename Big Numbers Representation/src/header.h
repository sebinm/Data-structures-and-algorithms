#pragma once

typedef short Atom; // tip predefinit

// Preliminarii
struct Nod {
	Atom data;
	Nod* succ;
	Nod* pred;
};
struct LDL
{
	Nod* first;
	Nod* last;
	int lungime;
	bool sign;
};

// Functii

void InsertFata(LDL& cap, int n);
void CreateList(LDL& list, unsigned long long number, bool sign = true);
void afisareLista(LDL cap, short order = 0);
void afisareDus(LDL);
void afisareIntors(LDL);
bool inserareElement(LDL& list, int poz, int elem);
void errorMessage();
bool citireNumar(unsigned long long& nr);
bool stergereElement(LDL& list, int poz = 1);
void golireLista(LDL& list);

// Functii intermediare pt comparare (subpunctul d)
void winnerMessage(short nr);
bool signCheckWinner(const LDL& nrMare1, const LDL& nrMare2);
bool lengthCheckWinner(const LDL& nrMare1, const LDL& nrMare2);
bool valueCheckWinner(const LDL& nrMare1, const LDL& nrMare2);

void comparNrMari(const LDL& nrMare1, const LDL& nrMare2);


// Functii intermediare pt adunarea a 2 numere foarte mari (subpunctul e)

LDL adunareNrMari(const LDL& nrMare1, const LDL& nrMare2);