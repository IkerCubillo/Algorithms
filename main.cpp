#include "Kmeans.h"

#include <iostream>
using namespace std;

//g++ *.cpp -o Algorithms.exe

#include <fstream>
#include <sstream>
#include <string>
#include <cstring>


//Función para leer el archivo CSV y crear un array de punteros a Punto
Punto* leerArchivoCSV(const std::string& nombreArchivo, int& numPuntos)
{
    std::ifstream archivo(nombreArchivo);
    std::string linea;
    numPuntos = 0;

    // Contar el número de líneas/puntos en el archivo
    while (std::getline(archivo, linea))
    {
        numPuntos++;
    }

    // Volver a abrir el archivo para leer los puntos
    archivo.clear();
    archivo.seekg(0);

    // Crear el array de punteros a Punto
    Punto* puntos = new Punto[numPuntos];

    int indice = 0;
    while (std::getline(archivo, linea))
    {
        std::istringstream iss(linea);
        std::string token;

        // Obtener la coordenada X
        std::getline(iss, token, ',');
        int x = std::stoi(token);

        // Obtener la coordenada Y
        std::getline(iss, token, ',');
        int y = std::stoi(token);

        // Crear un nuevo objeto Punto y asignarlo al array de punteros
        Punto punto = {x,y};
        puntos[indice] = punto;

        indice++;
    }
	for (int i = 0; i < 100; i++)
	{
		puntos[i].imprimir();
	}
	

    archivo.close();

    return puntos;
}

void leerConfiguracion(const char* archivo, int* numPuntos, char* direccion, int* numClusters) {
    std::ifstream config(archivo);
    if (!config) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(config, linea)) {
        if (linea.find("Number of points:") != std::string::npos) {
            std::string valor = linea.substr(linea.find(":") + 1);
            *numPuntos = std::stoi(valor);
        }
        else if (linea.find("Data csv name:") != std::string::npos) {
            std::string valor = linea.substr(linea.find(":") + 1);
            std::strcpy(direccion, valor.c_str());
        }
        else if (linea.find("Number of clusters:") != std::string::npos) {
            std::string valor = linea.substr(linea.find(":") + 1);
            *numClusters = std::stoi(valor);
        }
    }

    config.close();
}

int main() {
    int numPuntos;
    char direccion[100];
    int numClusters;

    leerConfiguracion("config.txt", &numPuntos, direccion, &numClusters);

	Punto* a1 = new Punto[numPuntos];

	a1 = leerArchivoCSV(direccion, numPuntos);

	// Punto p1 = {1, 0};
	// Punto p2 = {2, 0};
	// Punto p3 = {3, 0};

	// Punto p4 = {7, 0};
	// Punto p5 = {8, 0};
	// Punto p6 = {9, 0};

	// Punto p7 = {11, 0};
	// Punto p8 = {12, 0};
	// Punto p9 = {13, 0};

	
    // a1[0] = p1; a1[1] = p2; a1[2] = p3;
	// a1[3] = p4; a1[4] = p5; a1[5] = p6;
	// a1[6] = p7; a1[7] = p8; a1[8] = p9;

	// Punto* a1 = new Punto[100];
	// int* num;
	// *num = 100;
	// cout << "finciona" << endl;
	// //a1 = leerArchivoCSV("puntos.csv", *num);

cout << "sigue" << endl;

	Cluster* cl1 = new Cluster("Cluster 1", Punto(50,50));
	Cluster* cl2 = new Cluster("Cluster 2", Punto(0,0));
	Cluster* cl3 = new Cluster("Cluster 3", Punto(-50,-50));

	Cluster* aCl1 = new Cluster[3];
    aCl1[0] = *cl1; aCl1[1] = *cl2; aCl1[2] = *cl3;

	KMeans km1 = {numPuntos, a1, numClusters, aCl1};

	while (km1.getModificado() == true)
	{
		km1.asignacionPuntos();
		km1.centroidReCalculation();
	}

	cout << "\nAlgoritmo Kmeans finalizado, imprimiendo resultados...";
	km1.imprimir();
	

	return 0;
}

