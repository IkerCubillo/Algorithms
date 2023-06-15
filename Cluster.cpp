#include "Cluster.h"
#include <math.h>

#include <string.h>
#include <iostream>
using namespace std;

Cluster::Cluster()
{
    this->nombre = NULL;

	this->centroide = Punto(0,0);

	this->numPuntos = 0;
	this->arrayPuntos = NULL;

    this->media = Punto(0,0);
    this->varianza = 0;
}

Cluster::Cluster(const char* nombre, Punto centroide)
{
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);

    this->centroide = centroide;

    this->numPuntos = 0;
	this->arrayPuntos = NULL;

    this->media = Punto(0,0);
    this->varianza = 0;
}

Cluster::Cluster(const char* nombre, Punto centroide, int numPuntos, Punto* arrayPuntos)
{
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);

    this->centroide = centroide;

    this->numPuntos = numPuntos;

    this->arrayPuntos = arrayPuntos;
    

    calcMedia();
    calcVarianza();
}

Cluster::Cluster(const Cluster &cluster)
{
    this->nombre = new char[strlen(cluster.nombre)+1];
    strcpy(this->nombre, cluster.nombre);

    this->centroide = cluster.centroide;

    this->numPuntos = cluster.numPuntos;

    this->arrayPuntos = cluster.arrayPuntos;

    this->media = cluster.media;
    this->varianza = cluster.varianza;
}

Cluster::~Cluster()
{
    delete[] nombre;
    delete[] arrayPuntos;
}


char* Cluster::getNombre() const
{
    return this->nombre;
}

Punto Cluster::getCentroide() const
{
    return this->centroide;
}

int Cluster::getNumPuntos() const
{
    return this->numPuntos;
}

Punto* Cluster::getArrayPuntos() const
{
    return this->arrayPuntos;
}

Punto Cluster::getMedia() const
{
    return this->media;
}

float Cluster::getVarianza() const
{
    return this->varianza;
}


void Cluster::setNombre(char* nombre)
{
    delete[] nombre;
    
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Cluster::setCentroide(Punto centroide)
{
    this->centroide = centroide;
}

void Cluster::setNumPuntos(int numPuntos)
{
    this->numPuntos = numPuntos;
}

void Cluster::setArrayPuntos(Punto* arrayPuntos, int numPuntos)
{
    this->arrayPuntos = arrayPuntos;
    this->numPuntos = numPuntos;
}


void Cluster::anyadirPunto(Punto nPunto)
{   
    Punto* arrayAntiguo = new Punto[this->numPuntos];

    setNumPuntos(this->numPuntos + 1);    

    for (int i = 0; i < this->numPuntos - 1; i++)
    {
        arrayAntiguo[i] = this->arrayPuntos[i];
    }

    delete[] this->arrayPuntos;

    this->arrayPuntos = new Punto[this->numPuntos];

    for (int i = 0; i < this->numPuntos - 1; i++)
    {
        this->arrayPuntos[i] = arrayAntiguo[i];
    }

    this->arrayPuntos[this->numPuntos - 1] = nPunto;

    delete[] arrayAntiguo;
}   

void Cluster::calcMedia()
{
    Punto media = {0,0};

    for (int i = 0; i < this->numPuntos; i++)
    {
        media += this->arrayPuntos[i];
    }

    media = media/this->numPuntos; 

    this->media = media;
}


void Cluster::calcVarianza()
{
    float var = 0;
    float varx = 0;
    float vary = 0;

    for (int i = 0; i < this->numPuntos; i++)
    {
        varx += pow(arrayPuntos->getX()-media.getX(),2);
        vary += pow(arrayPuntos->getY()-media.getY(),2);
    }

    varx = varx/numPuntos;
    vary = vary/numPuntos;

    this->varianza = varx + vary;
}


void Cluster::imprimir()
{   
    cout << "\nNombre: " << this->nombre << endl;

    cout << "Centroide: ";
    this->centroide.imprimir();

    if (numPuntos >0 )
    {
        cout << "Puntos: " << endl;

        for (int i = 0; i < this->numPuntos; i++)
        {
            arrayPuntos[i].imprimir();
        }
    } else {cout << "Sin Puntos" << endl;}
    
      
}
