# pragma once 
# include <iostream>
# include <string>
# include "Serie.hpp"

Serie::Serie(){}

Serie::Serie(int id, std::string nombre, float duracion, std::string genero, float calificacion)
{
	this -> id = id;
	this -> nombre = nombre;
	this -> duracion = duracion;
	this -> genero = genero;
	this -> calificacion = calificacion;
}
