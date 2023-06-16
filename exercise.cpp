#include "Video.hpp"
#include "Episodio.hpp"
#include "Pelicula.hpp"
#include "Serie.hpp"
#include <string>
#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

int main() 
{
    // crear una list de peliculas inicialmente vacia
    std::vector<Pelicula*> peliculas;
    std::vector<Serie*> series;

    std::vector<float> calificaciones5 = {5, 5, 5};
    std::vector<float> calificaciones4 = {4, 4, 4};

    // crea un objeto de tipo Pelicula
    Pelicula *pelicula1 = new Pelicula("4321", "Titanic", "180", "Drama", calificaciones5);
    Pelicula *pelicula2 = new Pelicula("2323", "Titanic 2", "180", "Drama", calificaciones4);

    peliculas.push_back(pelicula1);
    peliculas.push_back(pelicula2);

    //crea objectos de tipo Episodio
    Episodio *episodio1 = new Episodio("0001", "Winter is coming", "60", "Drama", calificaciones5);
    Episodio *episodio2 = new Episodio("0002", "The Kingsroad", "60", "Drama", calificaciones4);
    Episodio *episodio3 = new Episodio("0003", "The Kingsroad", "50", "Drama", calificaciones4);

    //crea objectos de tipo Temporada
    Temporada *temporada1 = new Temporada(1);
    std::vector<Episodio*> episodios;
    episodios.push_back(episodio1);
    episodios.push_back(episodio2);
    episodios.push_back(episodio3);

    temporada1->Episodios = episodios;

    temporada1->Episodios.push_back(episodio1);
    temporada1->Episodios.push_back(episodio2);
    temporada1->Episodios.push_back(episodio3);



    //crea un objeto tipo serie
    Serie *serie1 = new Serie(1, "Game of Thrones");
    Serie *serie1 = new Serie(1, "Game of Thrones");


    // int opcion;

      int opcion;

    do {
        // Mostrar el menú
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Mostrar sus videos con sus calificaciones" << std::endl;
        std::cout << "2. Buscar video por nombre" << std::endl;
        std::cout << "3. Mostrar películas con calificaciones" << std::endl;
        std::cout << "4. Mostrar episodios de cierta serie con cierta calificación" << std::endl;
        std::cout << "5. Mostrar videos de cierto género" << std::endl;
        std::cout << "6. Ingresar el título del video para agregar una calificación" << std::endl;

        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        // Procesar la opción seleccionada
        switch (opcion) {
            case 1:  std::cout << "Ha seleccionado la Opción 1." << std::endl;
                // Código para la opción 1
                    // Iterate over each element in the vector
                for (const auto& pelicula : peliculas) {
                    pelicula->Print();
                    pelicula->MostrarCalificaciones();
                }

                for (const auto& serie : series) {
                    for (auto temporada : serie->Temporadas) {
                        Temporada *tempTemporada = &temporada;
                        for (auto episodio : tempTemporada->Episodios) {
                            Episodio *tempEpisodio = &episodio;
                            tempEpisodio->Print();
                            tempEpisodio->MostrarCalificaciones();
                        }
                    }
                }
                break;
            }
            case 2: {
                std::cout << "Ha seleccionado la Opción 2." << std::endl;
                // Código para la opción 2
                break;
            }
            case 3: {
                std::cout << "Ha seleccionado la Opción 3." << std::endl;
                // Código para la opción 3
                break;
            }
            case 4: {
                std::cout << "Ha seleccionado la Opción 4." << std::endl;
                // Código para la opción 4
                break;
            }
            case 5: {
                std::cout << "Ha seleccionado la Opción 5." << std::endl;
                // Código para la opción 5
                break;
            }
            case 6: {
                std::cout << "Ha seleccionado la Opción 6." << std::endl;
                // Código para la opción 6
                break;
            }
            default: {
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
            }
        }

        std::cout << std::endl;
    } while (opcion != 4);


    return 0;
    
}


