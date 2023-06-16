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


