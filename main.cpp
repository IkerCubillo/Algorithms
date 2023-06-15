#include "Kmeans.h"

#include <iostream>
using namespace std;

//g++ *.cpp -o Algorithms.exe
int main(void)
{
	Punto p1 = {10, 10};
	Punto p2 = {11, 11};
	Punto p3 = {12, 12};

	Punto p4 = {20, 20};
	Punto p5 = {21, 21};
	Punto p6 = {22, 22};

	Punto p7 = {30, 30};
	Punto p8 = {31, 31};
	Punto p9 = {32, 32};

	Punto* a1 = new Punto[3];
    a1[0] = p1; a1[1] = p2; a1[2] = p3;

	p1.imprimir();
	a1[1].imprimir();

	return 0;
}