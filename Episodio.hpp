#pragma once 

#include "Video.hpp"

class Episodio : public Video {
    private:
         std::string idEpisodio;
    public:
        Episodio();
        Episodio( std::string idEpisodio, std::string nombre,  std::string duracion, std::string genero, std::vector<float> calificaciones);
        virtual ~Episodio();
        void Print() override;
        
};

