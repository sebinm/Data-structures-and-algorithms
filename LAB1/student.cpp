#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::sort;

#include "student.h"


void InitStudent(Student& st)
{
	char buffer[50];

	cout << "Nume: ";
	cin.get(buffer, 50);
	cin.get();

	size_t spatiu = strlen(buffer);

	st.nume = new char[spatiu + 1];
	strcpy_s(st.nume, spatiu+1, buffer);

	cout << "Nota: ";
	cin >> st.nota;

	//while (st.nota < 0 || st.nota > 10)
	//{
	//	cout << "Nota: ";
	//	cin >> st.nota;
	//}
}
void AfisStudent(Student st)
{
	cout << "Studentul cu numele: " << st.nume << endl;
	cout << "\tsi cu nota: " << st.nota << endl;
}
void StergeStudent(Student& st)
{
	delete st.nume;
	st.nume = 0;
	st.nota = -1;
}