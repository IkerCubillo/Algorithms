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

    this->modificado = true;
}

KMeans::KMeans(int numPuntos, Punto* arrayPuntos, int k, Cluster* arrayClusters)
{
    this->numPuntos = numPuntos;
    this->arrayPuntos = arrayPuntos;
    this->k = k;

    this->arrayClusters = arrayClusters;

    this->modificado = true;
}

KMeans::KMeans(const KMeans &km)
{
    this->numPuntos = km.numPuntos;
    this->arrayPuntos = km.arrayPuntos;
    this->k = km.k;

    this->arrayClusters = km.arrayClusters;

    this->modificado = true;
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

bool KMeans::getModificado() const
{
    return this->modificado;
}

void KMeans::asignacionPuntos()
{   
    for (int j = 0; j < this->k; j++)
    {   
        this->arrayClusters[j].setArrayPuntos(NULL, 0);
    }
    
    for (int i = 0; i < this->numPuntos; i++)
    {   
        
        float distMin = pow(10,36);
        int nearCluster = 0;

        for (int j = 0; j < this->k; j++)
        {   
            if (this->arrayClusters[j].getCentroide().distancia(arrayPuntos[i]) < distMin)
            {
                distMin = this->arrayClusters[j].getCentroide().distancia(arrayPuntos[i]);
                nearCluster = j;
            }            
        }
        cout << "Punto: " << i << " anyadido a Cluster: " << nearCluster << endl;
        this->arrayClusters[nearCluster].anyadirPunto(this->arrayPuntos[i]);
    }
}

void KMeans::centroidReCalculation()
{   
    this->modificado = false;
    cout << "Iniciando calculo nuevos centroides" << endl;

    for (int i = 0; i < this->k; i++)
    {   
        if (this->arrayClusters[i].getNumPuntos() > 0 )
        {
            this->arrayClusters[i].calcMedia();
            
            if (this->arrayClusters[i].getMedia() != this->arrayClusters[i].getCentroide())
            {
                this->arrayClusters[i].setCentroide(this->arrayClusters[i].getMedia());
                this->modificado = true;
            } 
        }        
    }
    cout << "Finalizado calculo nuevos centroides" << endl;
}

void KMeans::imprimir()
{
    for (int i = 0; i < this->k; i++)
    {
        arrayClusters[i].imprimir();
    }
    
}