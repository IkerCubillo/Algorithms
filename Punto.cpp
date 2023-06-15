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
    this->x = punto.x;
	this->y = punto.y;
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

Punto Punto::operator- (const Punto& p)const
{
    int x = this->getX()-p.getX();
    int y = this->getY()-p.getY();

    Punto resultado (x, y);

    return resultado;
}
	
Punto& Punto::operator+= (const Punto& p)
{   
    this->setX(this->getX()+p.getX());
    this->setY(this->getY()+p.getY());

    return *this;
}

Punto& Punto::operator-= (const Punto& p)
{   
    this->setX(this->getX()-p.getX());
    this->setY(this->getY()-p.getY());

    return *this;
}

Punto Punto::operator/ (int divisor)const
{
    int x = (this->getX()/divisor);
    int y = (this->getY()/divisor);

    Punto resultado (x, y);
    
    return resultado;
}

Punto& Punto::operator= (const Punto& p)
{
	this->x = p.x;
	this->y = p.y;

    return *this;
}

bool Punto::operator== (const Punto& p)const
{
    return (this->x == p.x) && (this->y == p.y);
}

bool Punto::operator!= (const Punto& p)const
{
    return !(*this == p);
}