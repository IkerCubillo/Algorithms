#include "Cluster.h"
#include <math.h>

#include <string.h>
#include <iostream>
using namespace std;

Cluster::Cluster()
{
    this->nombre = NULL;

	this->centroide = NULL;

	this->numPuntos = 0;
	this->arrayPuntos = NULL;

    this->media = 0;
    this->varianza = 0;
}

Cluster::Cluster(char* nombre, Punto* centroide)
{
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);

    this->centroide = centroide;

    this->numPuntos = 0;
	this->arrayPuntos = NULL;

    this->media = 0;
    this->varianza = 0;
}

Cluster::Cluster(char* nombre, Punto* centroide, int numPuntos, Punto* arrayPuntos)
{
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);

    this->centroide = centroide;

    this->numPuntos = numPuntos;

    this->arrayPuntos = new Punto[this->numPuntos];
	for (int i=0;i<this->numPuntos;i++)
	{
		this->arrayPuntos[i] = arrayPuntos[i];
	}

    

    calcMedia();
    calcVarianza();
}

Cluster::Cluster(const Cluster &cluster)
{
    
}

Cluster::~Cluster()
{
    
}


char* Cluster::getNombre() const
{
    return this->nombre;
}

Punto* Cluster::getCentroide() const
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

float Cluster::getMedia() const
{
    return this->media;
}

float Cluster::getVarianza() const
{
    return this->varianza;
}


void Cluster::setNombre(char* nombre)
{
    
}

void Cluster::setCentroide(Punto* centroide)
{
    
}

void Cluster::setNumPuntos(int numPuntos)
{
    
}

void Cluster::setArrayPuntos(Punto* arrayPuntos)
{
    
}

    
void Cluster::calcMedia()
{
    float media = 0;

    for (int i = 0; i < this->numPuntos; i++)
    {
        media += this->centroide->distancia(arrayPuntos[i]);
    }

    media = 

    this->media = media;
}


void Cluster::calcVarianza()
{
    float var = 0;

    for (int i = 0; i < this->numPuntos; i++)
    {
        media += this->centroide->distancia(arrayPuntos[i]);
    }
    this->media = media;
}


void Cluster::imprimir()
{
    
}
