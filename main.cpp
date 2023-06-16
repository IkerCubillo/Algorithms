#include "Kmeans.h"

#include <iostream>
#include <random>
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

int generarNumeroAleatorio(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

int main() {
	cout << "Iniciando programa..." << endl;

    int numPuntos;
    char direccion[100];
    int numClusters;

	cout << "\nLeyendo configuracion de programa..." << endl;

    leerConfiguracion("config.txt", &numPuntos, direccion, &numClusters);
	
	std::cout << "Numero de puntos: " << numPuntos << std::endl;
    std::cout << "Direccion del archivo: " << direccion << std::endl;
    std::cout << "Numero de clusters: " << numClusters << std::endl;

	Punto* a1 = new Punto[numPuntos];

	cout << "\nLeyendo archivo CSV y asignando puntos..." << endl;
	a1 = leerArchivoCSV(direccion, numPuntos);

	// char respuesta[4];
	// cout << "\nSi desea introducir manualmente los centroides de los clusters escriba YES" << endl;
	// cout << "Si desea que se introduzcan automaticamente los centroides de los clusters escriba NO" << endl;
	// cout << "Introduzca respuesta: ";
	// cin >> respuesta;


	// int maxX, maxY, minX, minY;
	// cout << "Escriba un valor maximo para la coordenada X de los centroides: ";
	// cin >> maxX;
	// cout << "Escriba un valor minimo para la coordenada X de los centroides: ";
	// cin >> minX;
	// cout << "Escriba un valor maximo para la coordenada Y de los centroides: ";
	// cin >> maxY;
	// cout << "Escriba un valor minimo para la coordenada Y de los centroides: ";
	// cin >> minY;
	
	// if (!strcmp(respuesta, "YES"))
	// {
		
	// }

	// int respuesta;
	// cout << "\nIniciando programa, presione una letra y enter para continuar: ";
	// cin >> respuesta;


	Cluster* aCl1 = new Cluster[numClusters];

	char respuesta[4];

	// do
	// {
	for (int i = 0; i < numClusters; i++)
	{	
		std::string clusterName = "Cluster " + std::to_string(i + 1);
    	Cluster* cl = new Cluster(clusterName.c_str(), Punto(generarNumeroAleatorio(-100, 100), generarNumeroAleatorio(-100, 100)));
    	aCl1[i] = *cl;
	}

	KMeans km1 = {numPuntos, a1, numClusters, aCl1};

	while (km1.getModificado() == true)
	{
		km1.asignacionPuntos();
		km1.centroidReCalculation();
	}

	cout << "\nAlgoritmo Kmeans finalizado, imprimiendo resultados...";
	km1.imprimir();
	
	float varianzaTotal = 0;
	cout << "\n---------------------------------\n" << endl; 
	for (int i = 0; i < numClusters; i++)
	{	
		km1.getArrayClusters()[i].calcVarianza();
		varianzaTotal += km1.getArrayClusters()[i].getVarianza();
		cout << "\n/////////////////////\n" << endl; 
		cout << "Nombre: " << km1.getArrayClusters()[i].getNombre() << endl;
		cout << "Numero de puntos: " << km1.getArrayClusters()[i].getNumPuntos() << endl;
		cout << "Centroide: "; km1.getArrayClusters()[i].getCentroide().imprimir();
		cout << "Varianza interna: " << km1.getArrayClusters()[i].getVarianza() << endl;
	}
	cout << "\nVarianza Total: " << varianzaTotal << endl;
	cout << "\n---------------------------------\n" << endl;

		
	// cout << "\nSi desea repetir el algoritmo escriba YES" << endl;
	// cout << "Si no lo desea, escriba cualquier respuesta" << endl;
	// cout << "Introduzca respuesta: ";
	// cin >> respuesta;

	for (int i = 0; i < numClusters; i++)
	{
		delete &km1.getArrayClusters()[i];
	}

	//} while (!strcmp(respuesta, "YES"));

	delete[] a1;

	cout << "FIN" << endl;

	return 0;
}