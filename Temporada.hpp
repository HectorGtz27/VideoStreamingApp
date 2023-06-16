# pragma once 
# include <iostream>
# include "Episodio.hpp"

class Temporada {
	private:
		std::string numero;
		std::vector<Episodio*> Episodios;
	public:
		Temporada();
		Temporada(std::string numero);
		void SetEpisodios(std::vector<Episodio*> episodios);
		//Para agregalo al vector es como el setCalificacion
	    void SetEpisodio(Episodio* episodio);
		std::vector<Episodio*> GetEpisodios();
		std::string GetId();
};