#pragma once

struct Nod {
	int data;
	Nod* succ;
	Nod* pred;
};
struct LDL
{
	Nod* first;
	Nod* last;
};

// Functii
void InsertFata(LDL& cap, int n);
void CreateList(LDL& cap);
void afisareLista(LDL cap, short order = 0);
void afisareDus(LDL);
void afisareIntors(LDL);
bool inserareElement(LDL& list, int poz, int elem);
void errorMessage();
bool stergereElement(LDL& list, int poz);
void uniuneListe(LDL& list1, LDL& list2);
void interclasareListe(LDL& first, LDL& second);