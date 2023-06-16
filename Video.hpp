#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Video {
protected:
    int id;
    std::string nombre;
    float duracion;
    std::string genero;
    float calificacion;
    std::vector<float> calificaciones;
    
    // Ahorita nos preocupamos por el archivo
    std::ifstream fi{"input"};
    std::ofstream fo{"output"};

public:
    Video();
    Video(int id, std::string nombre, float duracion, std::string genero, float calificacion);

    void setCalificacion(float calificacion);
    float getCalificacion();
    virtual std::string mostrarCalificaciones() = 0;
    void print();
    void outMsg(std::string);
    void start();

};


