# pragma once 
# include <iostream>
# include <string>
# include "Serie.hpp"
# include "Temporada.hpp"
//hazme un constructor por defecto
Serie::Serie(){
		this->id = "";
		this->nombre = "";
}

//creame el constructor por parámetros sin heredar de video
Serie::Serie(std::string id, std::string nombre){
		this->id = id;
		this->nombre = nombre;
}

void Serie::AddTemporada(Temporada* temporada){
		this->Temporadas.push_back(temporada);
}

std::vector<Temporada*> Serie::GetTemporadas(){
		return this->Temporadas;
}



