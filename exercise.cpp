#include <iostream>
#include "Video.hpp"
#include "Episodio.hpp"
#include "Pelicula.hpp"

int main() 
{
    // Crear objetos de las clases derivadas
    Pelicula pelicula(1, "Mi Pelicula", 120.5, "Drama", 4.5);
    Episodio episodio(2, "Mi Episodio", 30.0, "Comedia", 3.8);

    // Llamar a la función mostrarCalificaciones() a través de punteros o referencias de la clase base
    Video* ptrVideo1 = &pelicula;
    Video* ptrVideo2 = &episodio;

    std::cout << "Calificaciones de la Pelicula: " << ptrVideo1->mostrarCalificaciones() << std::endl;
    std::cout << "Calificaciones del Episodio: " << ptrVideo2->mostrarCalificaciones() << std::endl;

    return 0;
}