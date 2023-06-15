#include <iostream>
#include <fstream>
#include <random>

// Estructura para almacenar un punto
struct Punto
{
    int x;
    int y;
};

// Función para generar un número aleatorio en el rango especificado
int generarNumeroAleatorio(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

// Función para crear un archivo CSV con puntos aleatorios
void crearArchivoCSV(const std::string& nombreArchivo, int numPuntos)
{
    std::ofstream archivo(nombreArchivo);

    for (int i = 0; i < numPuntos; ++i)
    {
        int x = generarNumeroAleatorio(-100, 100);
        int y = generarNumeroAleatorio(-100, 100);

        archivo << x << "," << y << std::endl;
    }

    archivo.close();
}

int main()
{
    std::string nombreArchivo = "puntos.csv";
    int numPuntos = 100;

    crearArchivoCSV(nombreArchivo, numPuntos);

    std::cout << "Archivo CSV creado exitosamente: " << nombreArchivo << std::endl;

    return 0;
}
