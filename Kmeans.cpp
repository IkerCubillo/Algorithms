#include "Kmeans.h"
#include <math.h>

#include <string.h>
#include <iostream>
using namespace std;

KMeans::KMeans()
{
    this->arrayClusters = NULL;
    this->arrayPuntos = NULL;
    this->k = 0;
    this->numPuntos = 0;
}

KMeans::KMeans(int numPuntos, Punto* arrayPuntos, int k, Cluster* arrayClusters)
{
    this->numPuntos = numPuntos;
    this->arrayPuntos = arrayPuntos;
    this->k = k;

    this->arrayClusters = arrayClusters;
}

KMeans::KMeans(const KMeans &km)
{
    this->numPuntos = km.numPuntos;
    this->arrayPuntos = km.arrayPuntos;
    this->k = km.k;

    this->arrayClusters = km.arrayClusters;
}

KMeans::~KMeans()
{
    delete[] arrayClusters;
    delete[] arrayPuntos;
}


int KMeans::getNumPuntos() const
{
    return this->numPuntos;
}

Punto* KMeans::getArrayPuntos() const
{
    return this->arrayPuntos;
}

int KMeans::getK() const
{
    return this->k;
}

Cluster* KMeans::getArrayClusters() const
{
    return this->arrayClusters;
}

void KMeans::asignacionPuntos()
{
    for (int i = 0; i < this->numPuntos; i++)
    {
        /* code */
    }
    
}

void KMeans::imprimir()
{
    for (int i = 0; i < this->k; i++)
    {
        arrayClusters[i].imprimir();
    }
    
}