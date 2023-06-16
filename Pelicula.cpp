#pragma once

#include "Video.hpp"
#include "Pelicula.hpp"
#include <fstream>
#include <iostream>


Pelicula::Pelicula() : Video(){
        // Constructor por defecto
        this->idPelicula = 0;
        this->nombre = "";
        this->duracion = 0;
        this->genero = "";
        this->calificacion = 0;
}

//Hazme un constructor por parámetros
Pelicula::Pelicula(int idPelicula, std::string nombre, float duracion, std::string genero, float calificacion) : Video(idPelicula, nombre, duracion, genero, calificacion){
        this->idPelicula = idPelicula;
        this->nombre = nombre;
        this->duracion = duracion;
        this->genero = genero;
        this->calificacion = calificacion;
}

//creame mostrarCalificaciones
std::string Pelicula::mostrarCalificaciones(){
        std::string calificaciones = "";
        for (int i = 0; i < this->calificaciones.size(); i++){
                calificaciones += std::to_string(this->calificaciones[i]) + "\n";
        }
        return calificaciones;
}
    
Pelicula::~Pelicula(){
        // Destructor
}