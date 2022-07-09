#include <iostream>
using namespace std;

#include "face.h"

void main()
{
	{
		Eyes eyes1;
		Eyes eyes2("green", 2);
		Eyes* eyes3 = new Eyes("brown");
		Eyes eyes4(eyes2);

		cout << "1) --------------------------------\n";

		Face p1(*eyes3, 15, 20);
		cout << "2) --------------------------------\n";

		Face p2(Eyes("gray"));
		cout << "3) --------------------------------\n";
		Face* p3 = new Face(eyes2);
		cout << "4) --------------------------------\n";
		Face p4(34, 0);
		cout << "5) --------------------------------\n";

		delete eyes3;
		delete p3;
		cout << "6) --------------------------------\n";

		// SHOW WHAT HAPPENS WHEN THERE IS NO DEFAULT C'TOR
		Eyes eyes[2];
		cout << "7) --------------------------------\n";
	}
	system("pause");
}

// NOTE FROM WHERE COMES EACH PRINT!!
