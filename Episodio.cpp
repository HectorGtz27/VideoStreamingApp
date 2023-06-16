#pragma once

#include "Video.hpp"
#include "Episodio.hpp"
#include <fstream>
#include <iostream>

Episodio ::Episodio() : Video(){
        // Constructor por defecto
        this->idEpisodio = "";
        this->nombre = "";
        this->duracion = "";
        this->genero = "";
}

//Hazme un constructor por parámetros
Episodio::Episodio( std::string idEpisodio, std::string nombre,  std::string duracion, std::string genero,  std::vector<float> calificaciones) : Video(idEpisodio, nombre, duracion, genero, calificaciones){
        this->idEpisodio = idEpisodio;
        this->nombre = nombre;
        this->duracion = duracion;
        this->genero = genero;
        this->calificaciones = calificaciones;
}

void Episodio::Print(){
        std::cout << "Episodio: " << this->idEpisodio << std::endl;
        std::cout << "Nombre: " << this->nombre << std::endl;
        std::cout << "Duracion: " << this->duracion << " min" << std::endl;
        std::cout << "Genero: " << this->genero << std::endl;
}

Episodio::~Episodio(){
        // Destructor
}   


