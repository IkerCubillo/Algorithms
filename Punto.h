#ifndef PUNTO_H_
#define PUNTO_H_

class Punto
{	
	int x, y;

public:
	Punto();
	Punto(int x, int y);
	Punto(const Punto &punto);
	~Punto();

	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);

	float distancia(Punto &p);

	void imprimir();

	Punto operator+ (const Punto& p)const;
	Punto operator- (const Punto& p)const;

    Punto& operator+= (const Punto& p);
    Punto& operator-= (const Punto& p);

    Punto operator/ (int divisor)const;

	Punto& operator= (const Punto& p);
};

#endif /* PUNTO_H_ */
