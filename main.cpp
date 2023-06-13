#include "Punto.h"

#include <iostream>
using namespace std;


int main(void)
{
	Punto p1 = {"p10", 10, 10};
	Punto p2 = {"p11", 11, 11};
	Punto p3 = {"p12", 12, 12};

	Punto p4 = {"p20", 20, 20};
	Punto p5 = {"p21", 21, 21};
	Punto p6 = {"p22", 22, 22};

	Punto p7 = {"p30", 30, 30};
	Punto p8 = {"p31", 31, 31};
	Punto p9 = {"p32", 32, 32};

	p1.imprimir();
	
	cout << p1.distancia(p2) << endl;

	return 0;
}
