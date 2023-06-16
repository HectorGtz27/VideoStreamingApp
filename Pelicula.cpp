#pragma once

#include "Video.hpp"
#include "Pelicula.hpp"
#include <fstream>
#include <iostream>


Pelicula::Pelicula() : Video(){
        // Constructor por defecto
        this->idPelicula = "";
        this->nombre = "";
        this->duracion = "";
        this->genero = "";
}

//Hazme un constructor por parámetros
Pelicula::Pelicula(std::string idPelicula, std::string nombre,  std::string duracion, std::string genero,  std::vector<float> calificaciones) : Video(idPelicula, nombre, duracion, genero, calificaciones){
        this->idPelicula = idPelicula;
        this->nombre = nombre;
        this->duracion = duracion;
        this->genero = genero;
        this->calificaciones = calificaciones;
}


void Pelicula::Print(){
        std::cout << "Pelicula: " << this->idPelicula << std::endl;
        std::cout << "Nombre: " << this->nombre << std::endl;
        std::cout << "Duracion: " << this->duracion << " min" << std::endl;
        std::cout << "Genero: " << this->genero << std::endl;
}
    
Pelicula::~Pelicula(){
        // Destructor
}