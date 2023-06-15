#include "Kmeans.h"

#include <iostream>
using namespace std;

//g++ *.cpp -o Algorithms.exe
int main(void)
{
	Punto p1 = {1, 0};
	Punto p2 = {2, 0};
	Punto p3 = {3, 0};

	Punto p4 = {7, 0};
	Punto p5 = {8, 0};
	Punto p6 = {9, 0};

	Punto p7 = {11, 0};
	Punto p8 = {12, 0};
	Punto p9 = {13, 0};

	Punto* a1 = new Punto[9];
    a1[0] = p1; a1[1] = p2; a1[2] = p3;
	a1[3] = p4; a1[4] = p5; a1[5] = p6;
	a1[6] = p7; a1[7] = p8; a1[8] = p9;


	Cluster* cl1 = new Cluster("Cluster 1", Punto(1,0));
	Cluster* cl2 = new Cluster("Cluster 2", Punto(4,0));
	Cluster* cl3 = new Cluster("Cluster 3", Punto(15,0));

	Cluster* aCl1 = new Cluster[3];
    aCl1[0] = *cl1; aCl1[1] = *cl2; aCl1[2] = *cl3;

	KMeans km1 = {9, a1, 3, aCl1};

	// cout << " Media cluster 1 ";
	// cl1->getMedia().imprimir();

	// cl1->setArrayPuntos(a1,9);

	// cl1->imprimir();

	// cl1->calcMedia();

	// cout << " Media cluster 1 ";
	// cl1->getMedia().imprimir();

	while (km1.getModificado() == true)
	{
		km1.asignacionPuntos();
		km1.centroidReCalculation();
	}
	
	km1.imprimir();

	return 0;
}

