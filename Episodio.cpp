#pragma once

#include "Video.hpp"
#include "Episodio.hpp"
#include <fstream>
#include <iostream>

Episodio ::Episodio() : Video(){
        // Constructor por defecto
        this->idEpisodio = 0;
        this->nombre = "";
        this->duracion = 0;
        this->genero = "";
        this->calificacion = 0;
}

//Hazme un constructor por parámetros
Episodio::Episodio(int idEpisodio, std::string nombre, float duracion, std::string genero, float calificacion) : Video(idEpisodio, nombre, duracion, genero, calificacion){
        this->idEpisodio = idEpisodio;
        this->nombre = nombre;
        this->duracion = duracion;
        this->genero = genero;
        this->calificacion = calificacion;
}

//creame mostrarCalificaciones
std::string Episodio::mostrarCalificaciones(){
        std::string calificaciones = "";
        for (int i = 0; i < this->calificaciones.size(); i++){
                calificaciones += std::to_string(this->calificaciones[i]) + "\n";
        }
        return calificaciones;
}

Episodio::~Episodio(){
        // Destructor
}   


