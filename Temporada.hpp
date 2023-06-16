# pragma once 
# include <iostream>


class Temporada {
	private:
		int numero;
	public:
		Temporada();
		Temporada(int);
		std::vector<Episodio> Episodios;
};