#pragma once

struct Nod {
	int data;
	Nod* succ;
};

void InsertFata(Nod*& cap, int val);
void CreateList(Nod*& cap);
void afisareLista(Nod* cap);
bool CautareNr(Nod* cap, int elem);
void inserareElem(Nod*& cap, int elem, int poz);
void stergereElement(Nod*& cap, int poz);
bool afisareElement(Nod*& cap, int poz);
void afisareDusIntors(Nod* cap);
void afisareMijloc(Nod* cap);
void inversareLegaturi(Nod*& cap);
void uniuneListe(Nod*& first, Nod*& second);
void interclasareListe(Nod* list1, Nod* list2);