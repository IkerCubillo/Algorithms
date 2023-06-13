#ifndef PUNTO_H_
#define PUNTO_H_

class Punto
{	
	char* nombre;
	int x, y;

public:
	Punto();
	Punto(int x, int y);
	Punto(const char* nombre, int x, int y);
	Punto(const Punto &punto);
	~Punto();

	char* getNombre() const;
	int getX() const;
	int getY() const;

	void setNombre(char* nombre);
	void setX(int x);
	void setY(int y);

	float distancia(Punto &p);

	void imprimir();
};

#endif /* PUNTO_H_ */
