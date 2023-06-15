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

}

KMeans::~KMeans()
{

}


int KMeans::getNumPuntos() const
{

}

Punto* KMeans::getArrayPuntos() const
{

}

int KMeans::getK() const
{

}

Cluster* KMeans::getArrayClusters() const
{

}

void KMeans::imprimir()
{
    for (int i = 0; i < this->k; i++)
    {
        arrayClusters[i].imprimir();
    }
    
}