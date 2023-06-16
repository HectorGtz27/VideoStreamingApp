#pragma once 

#include "Video.hpp"

class Episodio : public Video {
    private:
        int idEpisodio;
    public:
        Episodio();
        Episodio(int idEpisodio, std::string nombre, float duracion, std::string genero, float calificacion);
        virtual ~Episodio();
        std::string mostrarCalificaciones() override;
        
};

