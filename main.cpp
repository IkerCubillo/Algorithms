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

	Punto* a1 = new Punto[9];
    a1[0] = p1; a1[1] = p2; a1[2] = p3;
	a1[3] = p4; a1[4] = p5; a1[5] = p6;
	a1[6] = p7; a1[7] = p8; a1[8] = p9;


	Cluster* cl1 = new Cluster("Cluster 1", Punto(0,0));
	Cluster* cl2 = new Cluster("Cluster 2", Punto(19,19));
	Cluster* cl3 = new Cluster("Cluster 3", Punto(23,23));

	Cluster* aCl1 = new Cluster[3];
    aCl1[0] = *cl1; aCl1[1] = *cl2; aCl1[2] = *cl3;

	KMeans km1 = {9, a1, 3, aCl1};

	km1.imprimir();

	km1.asignacionPuntos();

	km1.imprimir();

	// Punto* a2 = new Punto[3];
    // a2[0] = p1; a2[1] = p2; a2[2] = p3;

	// km1.getArrayClusters()[0].setArrayPuntos(a2, 3);

	// km1.imprimir();

	// km1.getArrayClusters()[0].anyadirPunto(p9);

	// km1.imprimir();

	return 0;
}

