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

void Video::setCalificacion(float calificacion) {
    miVector.push_back(calificacion);
}

float Video::getPromedioCalificaciones() {
  
}

void Video::mostrarVideo() {
    std::cout << "ID: " << id;
    std::cout << "Nombre: " << nombre;
    std::cout << "Duracion: " << duracion;
    std::cout << "Genero: " << genero;
    std::cout << "Calificacion: " << calificacion;
    std::cout << "Promedio de calificaciones: " << getPromedioCalificaciones() << std::endl;
}

void Video::outMsg(std::string msg) {
    fo << msg << std::endl;
}

void Video::start() {
    
}