#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Video.hpp"

Video::Video() {
    // Constructor por defecto
}

Video::Video( std::string id, std::string nombre,  std::string duracion, std::string genero, std::vector<float> calificaciones) {
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificaciones = calificaciones;
}
//Coloca las calificaciones en el vector
void Video::SetCalificacion(float calificacion) {
    calificaciones.push_back(calificacion);
}

//Obtiene el promedio de las calificaciones
float Video::GetCalificacion() {
    int suma = 0;

    // Iterar sobre el vector y sumar los valores
    for (int num : calificaciones) {
        suma += num;
    }

    // Calcular el promedio
    float promedio = static_cast<float>(suma) / calificaciones.size();

    return promedio;
}

std::string Video::GetNombre() {
 return this->nombre;
}

std::string Video::GetGenero() {
 return this->genero;
}

// void Video::MostrarCalificaciones(){
//     std::cout << "Calificaciones: " << std::endl;
//     for (int i = 0; i < calificaciones.size(); i++) {
//         std::cout << calificaciones[i] << std::endl;
//     }
// }

std::ostream& operator<<(std::ostream& os, const Video& video) {
    os << "Calificaciones: " << std::endl;
    for (int i = 0; i < video.calificaciones.size(); i++) {
        os << video.calificaciones[i] << std::endl;
    }
    return os;
}









