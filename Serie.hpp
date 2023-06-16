# pragma once 
# include <iostream>
# include "Temporada.hpp"
# include <vector>

class Serie{
	private:
		std::string id;
		std::vector<Temporada*> Temporadas;
	public:
		Serie();
		Serie(std::string id, std::string);
		void AddTemporada(Temporada* temporada);
	  	std::vector<Temporada*> GetTemporadas();
		std::string nombre;
};