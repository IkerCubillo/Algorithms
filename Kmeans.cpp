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
    cout << "\nIniciando asignacion puntos a clusters..." << endl;
    
    for (int j = 0; j < this->k; j++) 
    {   
        cout << "\t--->" << "Vaciando " << this->getArrayClusters()[j].getNombre() << endl;
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
        cout << "\t--->" << "Punto " << i << " anyadido a  " << this->getArrayClusters()[nearCluster].getNombre() << endl;
        this->arrayClusters[nearCluster].anyadirPunto(this->arrayPuntos[i]);
    }
}

void KMeans::centroidReCalculation()
{   
    this->modificado = false;
    cout << "\nIniciando calculo nuevos centroides" << endl;

    for (int i = 0; i < this->k; i++)
    {   
        if (this->arrayClusters[i].getNumPuntos() > 0 )
        {
            this->arrayClusters[i].calcMedia();
            
            if (this->arrayClusters[i].getMedia() != this->arrayClusters[i].getCentroide())
            {
                this->arrayClusters[i].setCentroide(this->arrayClusters[i].getMedia());
                this->modificado = true;
                cout << "\t--->" << "Nuevo centroide de " << this->getArrayClusters()[i].getNombre() << ": ";
                this->getArrayClusters()[i].getCentroide().imprimir();
            } else {
                    cout << "\t--->" << this->getArrayClusters()[i].getNombre() << " mantiene centroide: ";
                    this->getArrayClusters()[i].getCentroide().imprimir();
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