#include "Punto.h"
#include <math.h>

#include <string.h>
#include <iostream>
using namespace std;

Punto::Punto()
{	
	this->nombre = NULL;
	this->x = 0;
	this->y = 0;
}

Punto::Punto(int x, int y)
{
	this->nombre = NULL;
	this->x = x;
	this->y = y;
}


Punto::Punto(char* nombre, int x, int y)
{	
	this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);

	this->x = x;
	this->y = y;
}

Punto::Punto(const Punto &punto)
{
    this->nombre = new char[strlen(punto.nombre)+1];
    strcpy(this->nombre, punto.nombre);

	this->x = x;
	this->y = y;
}

Punto::~Punto()
{
	delete[] this->nombre;
}


char* Punto::getNombre() const
{
	return this->nombre;
}

int Punto::getX() const
{
	return this->x;
}

int Punto::getY() const
{
	return this->y;
}


void Punto::setNombre(char* nombre)
{
	delete[] this->nombre;
	this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Punto::setX(int x)
{
	this->x = x;
}

void Punto::setY(int y)
{
	this->y = y;
}


float Punto::distancia(Punto p)
{
	return sqrt(((p.x - this->x)*(p.x - this->x)) + ((p.y - this->y)*(p.y - this->y)));
}

void Punto::imprimir()
{
	cout << this->nombre << " (" << this->x << ", " << this->y << ")" << endl;
}