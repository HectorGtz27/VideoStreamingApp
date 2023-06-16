#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Video {
private:
    int id;
    std::string nombre;
    float duracion;
    std::string genero;
    float calificacion;
    std::vector<float> miVector;

    std::ifstream fi{"input"};
    std::ofstream fo{"output"};

public:
    Video();
    Video(int id, std::string nombre, float duracion, std::string genero, float calificacion);

    void setCalificacion(float calificacion);
    float getPromedioCalificaciones();
    void mostrarVideo();
    void outMsg(std::string);
    void start();
};



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
    if (miVector.empty()) {
        return 0.0f; // Si no hay calificaciones, retorna 0
    }

    float sum = 0.0f;
    for (float calif : miVector) {
        sum += calif;
    }

    return sum / miVector.size();
}

void Video::mostrarVideo() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Duracion: " << duracion << std::endl;
    std::cout << "Genero: " << genero << std::endl;
    std::cout << "Calificacion: " << calificacion << std::endl;
    std::cout << "Promedio de calificaciones: " << getPromedioCalificaciones() << std::endl;
}

void Video::outMsg(std::string msg) {
    fo << msg << std::endl;
}

void Video::start() {
    
}