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

int main(void)
{
	Nod* root = init();
	Atom aux = 0;


	// a
	cout << "Introduceti valori pentru BTS (0-STOP)" << endl;
	cin >> aux;

	while (aux)
	{
		if (aux % 2 == 0)
		{
			// Folosim forma recursiva daca e par
			recursion::InserareBTS(root, aux);
		}
		else
		{
			// Si cea iterativa daca este impar
			iterativ::InserareBTS(root, aux);
		}
		cin >> aux;
	}

	// b
	cout << "\n\nInordine: " << endl;
	inordine(root);

	cout << "\n\nPreordine: " << endl;
	preordine(root);

	cout << "\n\nPostordine: " << endl;
	postordine(root);


	// c + d
	cout << "\n\nDoresti sa cauti o valoare in BTS? Daca da care ar fi aceea?  ";
	cin >> aux;
	
	if (recursion::cautareNod(root, aux) && iterativ::cautareNod(root, aux))
	{
		cout << "\nValoare gasita si stearsa" << endl << endl;

		recursion::deleteNode(root, aux);
		inordine(root);
	}
	else
	{
		cout << "\nValoare negasita" << endl;
	}

	

	return 0;
}