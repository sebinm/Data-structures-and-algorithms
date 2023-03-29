#pragma once

struct Nod {
	int data;
	Nod* succ;
};

//void swap(int& xp, int& yp);
void InsertFata(Nod*& cap, int val);
void CreateList(Nod*& cap);
void afisareLista(Nod* cap);
void inversareLegaturi(Nod*& cap);
void uniuneLista(Nod* first, Nod* second);
void interclasareListe(Nod* first, Nod* second);