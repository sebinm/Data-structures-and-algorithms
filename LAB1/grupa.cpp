#include <iostream>
#include <algorithm>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::sort;

#include "student.h"
#include "grupa.h"


void InitGrupa(Grupa& gr)
{
	do
	{
		cout << "Numarul grupei: ";
		cin >> gr.id;
	} while (gr.id < 1); // se presupune ca nu exista grupe cu id-ul <= 0

	do
	{
		cout << endl << "Nr studenti: ";
		cin >> gr.nr;
	} while (gr.nr < 1);

	gr.tab = new Student[gr.nr];

	for (int i = 0; i < gr.nr; ++i)
	{
		cin.get();
		InitStudent(gr.tab[i]);
	}
}
void AfisGrupa(Grupa gr)
{
	cout << "Grupa " << gr.id << endl;
	cout << "Nr studenti: " << gr.nr << endl;
	cout << "Lisat studenti: " << endl;

	for (auto i = 0; i < gr.nr; ++i)
	{
		AfisStudent(gr.tab[i]);
		cout << endl;
	}
}
void StergeGrupa(Grupa& gr)
{
	for (auto i = 0; i < gr.nr; ++i)
	{
		StergeStudent(gr.tab[i]);
	}
	gr.id = -1;
	gr.nr = -1;
}
void CautStudent(Student st, Grupa gr)
{
	bool gasit = false;
	int i;
	for (i = 0; i < gr.nr; ++i)
	{
		if (!strcmp(st.nume, gr.tab[i].nume))
		{
			gasit = true;
			break;
		}
	}
	if (gasit)
	{
		cout << "Studentul " << gr.tab[i].nume << " gasit cu nota oficiala : " << gr.tab[i].nota << endl;
	}
	else
	{
		cout << "Studentul " << st.nume << " este de negasit in grupa " << gr.id << endl;
	}
}
void TopNote(Grupa gr)
{
	int* a = new int[gr.nr];

	for (auto i = 0; i < gr.nr; ++i)
	{
		a[i] = gr.tab[i].nota;
	}
	sort(a, a + gr.nr);

	cout << "Cea mai mica nota din grupa " << gr.id << " este: " << a[0] << endl << endl;
	cout << "Cea mai mare nota din grupa " << gr.id << " este: " << a[gr.nr - 1] << endl;

	delete[] a;
	a = 0;
}