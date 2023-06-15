#ifndef KMEANS_H_
#define KMEANS_H_

#include "Cluster.h"

class KMeans
{
	int numPuntos;
    Punto* arrayPuntos;
    int k;
    Cluster* arrayClusters;

    bool modificado;

public:
	KMeans();
	KMeans(int numPuntos, Punto* arrayPuntos, int k, Cluster* arrayClusters);
	KMeans(const KMeans &km);
	~KMeans();

	int getNumPuntos() const;
    Punto* getArrayPuntos() const;
	int getK() const;
    Cluster* getArrayClusters() const;
    bool getModificado() const;

    void asignacionPuntos();
    void centroidReCalculation();

    void imprimir();
};

#endif /* KMEANS_H_ */
