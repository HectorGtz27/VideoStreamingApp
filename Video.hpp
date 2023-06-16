#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Video {
protected:
    std::string id;
    std::string nombre;
    std::string duracion;
    std::string genero;
    std::vector<float> calificaciones;

public:
    Video();
    Video( std::string id, std::string nombre,  std::string duracion, std::string genero,  std::vector<float> calificaciones);

    void SetCalificacion(float calificacion);
    float GetCalificacion();
    void MostrarCalificaciones() const;
    virtual void Print() = 0;
    std::string GetNombre();
    std::string GetGenero();
    
    friend std::ostream& operator<<(std::ostream& os, const Video& video);

};


