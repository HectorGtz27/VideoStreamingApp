#pragma once

#include "Video.hpp"

class Pelicula : public Video {
    private:
         std::string idPelicula;
    public:
        Pelicula();
        Pelicula( std::string idPelicula, std::string nombre,  std::string duracion, std::string genero,  std::vector<float> calificaciones);
        virtual ~Pelicula();
        void Print() override;


};