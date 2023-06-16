#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Video.hpp"

Video::Video() {
    // Constructor por defecto
}

Video::Video(int id, std::string nombre, float duracion, std::string genero, float calificacion) {
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;
}
//Coloca las calificaciones en el vector
void Video::setCalificacion(float calificacion) {
    calificaciones.push_back(calificacion);
}

//Obtiene el promedio de las calificaciones
float Video::getCalificacion() {
    int suma = 0;

    // Iterar sobre el vector y sumar los valores
    for (int num : calificaciones) {
        suma += num;
    }

    // Calcular el promedio
    float promedio = static_cast<float>(suma) / calificaciones.size();

    return promedio;
}

void Video::print(){
    std::cout << "Id: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Duracion: " << duracion << std::endl;
    std::cout << "Genero: " << genero << std::endl;
    std::cout << "Calificacion: " << calificacion << std::endl;
}
void Video::outMsg(std::string msg) {
    fo << msg << std::endl;
}

void Video::start() {
    int opcion;

    do {
        // Mostrar el menú
        std::cout << "Bienvenido a YouUnity" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Mostrar catalogo: " << std::endl;
        std::cout << "2. Calificar Video: " << std::endl;
        std::cout << "3. Calificar Pelicula: " << std::endl;
        std::cout << "4. Calificar Episodio: " << std::endl;
        std::cout << "5. Salir " << std::endl;

        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        // Procesar la opción seleccionada
        switch (opcion) {
            case 1:
                std::cout << "Ha seleccionado la Opción 1." << std::endl;
                mostrarCalificaciones();
                break;
            case 2:
                std::cout << "Ha seleccionado la Opción 2." << std::endl;
                std::cout << "Ingresa el Id del video: " << std::endl;
                std::cin >> id;
                std::cout << "Ingresa la calificacion del video: " << std::endl;
                std::cin >> calificacion;
                setCalificacion(calificacion);
                break;
            case 3:
                std::cout << "Ha seleccionado la Opción 3." << std::endl;
                // Código para la opción 3
                break;
            case 4:
                std::cout << "Ha seleccionado la Opción 4." << std::endl;
                // Código para la opción 4
                break;
            case 5:
                std::cout << "Has salido de YouUnity" << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcion != 5);
}



