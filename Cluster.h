#ifndef CLUSTER_H_
#define CLUSTER_H_

#include "Punto.h"

class Cluster
{	
    char* nombre;

	Punto centroide;

	int numPuntos;
	Punto* arrayPuntos;

    Punto media;
    float varianza;

public:
	Cluster();
    Cluster(char* nombre, Punto centroide);
	Cluster(char* nombre, Punto centroide, int numPuntos, Punto* arrayPuntos);
	Cluster(const Cluster &cluster);
	~Cluster();

	char* getNombre() const;
    Punto getCentroide() const;
	int getNumPuntos() const;
	Punto* getArrayPuntos() const;
    Punto getMedia() const;
	float getVarianza() const;

	void setNombre(char* nombre);
	void setCentroide(Punto centroide);
	void setNumPuntos(int numPuntos);
	void setArrayPuntos(Punto* arrayPuntos);
    
	void calcMedia();

    void calcVarianza();

	void imprimir();
};

#endif /* CLUSTER_H_ */
