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
    
}

Punto* Cluster::getCentroide() const
{
    
}

int Cluster::getNumPuntos() const
{
    
}

Punto* Cluster::getArrayPuntos() const
{
    
}

float Cluster::getMedia() const
{
    
}

float Cluster::getVarianza() const
{
    
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

    
float Cluster::calcMedia()
{
    
}


float Cluster::calcVarianza()
{
    
}


void Cluster::imprimir()
{
    
}
