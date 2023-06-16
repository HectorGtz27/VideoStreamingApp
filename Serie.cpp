# pragma once 
# include <iostream>
# include <string>
# include "Serie.hpp"

//hazme un constructor por defecto
Serie::Serie(){
		this->id = 0;
		this->nombre = "";
}

//creame el constructor por parámetros sin heredar de video
Serie::Serie(int id, std::string nombre){
		this->id = id;
		this->nombre = nombre;
}

