# pragma once 
# include <iostream>
# include <string>
# include "Temporada.hpp"
class Serie{
	private:
		int id;
	public:
		Serie();
		Serie(int id, std::string);
	    //std::vector<Temporada> *Temporadas;
		std::vector<Temporada> Temporadas;
		std::string nombre;
};