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
#include "grupa.h"

int main(void)
{
	// cerinta 1
	Grupa a;
	InitGrupa(a);
	
	cout << "\n\nStudent cuatat: " << endl << endl;

	cin.get();
	Student b;
	InitStudent(b);

	// cerinta 2
	cout << "\n\n";
	CautStudent(b, a);

	// cerinta 3
	cout << "\n\n";
	TopNote(a);

	StergeGrupa(a);
	StergeStudent(b);

	return 0;
}