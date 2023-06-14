#include "Punto.h"
#include <math.h>

#include <string.h>
#include <iostream>
using namespace std;

Punto::Punto()
{	
	this->x = 0;
	this->y = 0;
}

Punto::Punto(int x, int y)
{
	this->x = x;
	this->y = y;
}

Punto::Punto(const Punto &punto)
{
    this->x = x;
	this->y = y;
}

Punto::~Punto()
{
}


int Punto::getX() const
{
	return this->x;
}

int Punto::getY() const
{
	return this->y;
}


void Punto::setX(int x)
{
	this->x = x;
}

void Punto::setY(int y)
{
	this->y = y;
}


float Punto::distancia(Punto &p)
{
	this->imprimir();
	p.imprimir();
	return sqrt(((p.x - this->x)*(p.x - this->x)) + ((p.y - this->y)*(p.y - this->y)));
}

void Punto::imprimir()
{
	cout << "(" << this->x << ", " << this->y << ")" << endl;
}


Punto Punto::operator+ (const Punto& p)const
{
    int x = this->getX()+p.getX();
    int y = this->getY()+p.getY();

    Punto resultado (x, y);

    return resultado;
}

Punto Punto::operator+ (const Punto& p)const;
	Punto Punto::operator- (const Punto& p)const;
	
    Punto& Punto::operator+= (const Punto& p);
    Punto& Punto::operator-= (const Punto& p);

Punto& Punto::operator/ (int divisor)const
{
    this->x = this->x/divisor;
    this->x = this->x/divisor;

}

Punto& Punto::operator= (const Punto& p)
{
    delete[] this->nombre;
    this->nombre = new char[strlen(p.nombre)+1];
    strcpy(this->nombre, p.nombre);

	this->x = x;
	this->y = y;
}

Punto3D& Punto3D::operator+= (const Punto3D& p)
{
    this->setX(this->getX()+p.getX());
    this->setY(this->getY()+p.getY());
    this->setZ(this->getZ()+p.getZ());

     return *this;
}

Punto3D Punto3D::operator* (const Punto3D& punto2)const
{
    int x = this->getX()*punto2.getX();
    int y = this->getY()*punto2.getY();
    int z = this->getZ()*punto2.getZ();

    Punto3D resultado (x, y, z);

    return resultado;
}

Punto3D& Punto3D::operator* (int escalar)const
{
    int x = (this->getX()*escalar);
    int y = (this->getY()*escalar);
    int z = (this->getZ()*escalar);

    Punto3D resultado (x, y, z);
    
    return resultado;
}