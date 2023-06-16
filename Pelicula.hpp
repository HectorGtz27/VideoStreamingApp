#pragma once

#include "Video.hpp"

class Pelicula : public Video {
    private:
        int idPelicula;
    public:
        Pelicula();
        Pelicula(int idPelicula, std::string nombre, float duracion, std::string genero, float calificacion);
        virtual ~Pelicula();
        std::string mostrarCalificaciones() override;


};