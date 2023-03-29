#pragma once

struct Nod {
	int data;
	Nod* succ;
};

void errorMessage();
void InsertFata(Nod*& cap, int val);
void CreateList(Nod*& cap, int);
void afisareLista(Nod* cap);
bool JosephsGame(Nod*& list, Nod*& blackList, int k);
void donareElement(Nod*& list, Nod*& blackList, Nod*& aux);
int winner(int n, int k);
void showSomething(Nod* cap, int n);