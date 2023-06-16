# pragma once 
# include <iostream>
# include "Temporada.hpp"
# include <vector>
# include "Episodio.hpp"
Temporada::Temporada(){}

Temporada::Temporada(std::string numero)
{
	this -> numero = numero;
}

void Temporada::SetEpisodios(std::vector<Episodio*> episodios)
{
	this->Episodios = episodios;
}

std::vector<Episodio*> Temporada::GetEpisodios()
{
	return this->Episodios;
}

std::string Temporada::GetId(){
	return this->numero;
}

void Temporada::SetEpisodio(Episodio* episodio){
	this->Episodios.push_back(episodio);
}


