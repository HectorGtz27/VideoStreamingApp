#include "Video.hpp"
#include "Episodio.hpp"
#include "Pelicula.hpp"
#include "Temporada.hpp"
#include "Serie.hpp"
#include <string>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include <iostream>
#include <sstream>
#include <string>

using json = nlohmann::json;

int main()
{
    try {
        std::ifstream ifs("/workspaces/vs-03/Videos.json");
        json jf = json::parse(ifs);

        // crear una list de peliculas inicialmente vacia
        std::vector<Pelicula *> peliculas;
        std::vector<Serie *> series;

        for(auto& pelicula : jf["Peliculas"]){
            std::vector<float> elementos;
            for (auto& calificacion : pelicula["Calificaciones"]) {
                elementos.push_back(calificacion);
            }
            Pelicula* tempPelicula = new Pelicula(pelicula["Id"], pelicula["Nombre"], pelicula["Duracion"], pelicula["Genero"], elementos);
            peliculas.push_back(tempPelicula);
        }

        for(auto& serie : jf["Series"]){
            std::string id = serie["Id"];
            std::string nombreSerie = serie["Nombre"];
            Serie *tempSerie = new Serie(id, nombreSerie);

            for(auto& temporada : serie["Temporada"]){
                std::string temporadaId = temporada["Id"];
                Temporada *tempTemporada = new Temporada(temporadaId);

                for(auto& episodio : temporada["Episodios"]){
                    std::vector<float> elementos;
                    for (auto& calificacion : episodio["Calificaciones"]) {
                        elementos.push_back(calificacion);
                    }

                    Episodio *tempEpisodio = new Episodio(episodio["Id"], episodio["Nombre"], episodio["Duracion"], episodio["Genero"], elementos);
                    tempTemporada->SetEpisodio(tempEpisodio);
                }
                tempSerie->AddTemporada(tempTemporada);
            }

            series.push_back(tempSerie);
        }

    // int opcion;

    int opcion;
    char nombre[MAX_NAME_LEN];

    do
    {
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

        std::string nombre;
        float calificacion;
        // Procesar la opción seleccionada
        switch (opcion)
        {
        case 1:
            std::cout << "Ha seleccionado la Opción 1." << std::endl;
            // Código para la opción 1
            // Iterate over each element in the vector
            for (const auto &pelicula : peliculas)
            {
                pelicula->Print();
                pelicula->MostrarCalificaciones();
            }

            for (const auto &serie : series)
            {
                for (auto temporada : serie->GetTemporadas())
                {
                    Temporada *tempTemporada = temporada;
                    for (auto episodio : tempTemporada->GetEpisodios())
                    {
                        Episodio *tempEpisodio = episodio;
                        tempEpisodio->Print();
                        tempEpisodio->MostrarCalificaciones();
                    }
                }
            }
            break;
        case 2:
            std::cout << "Ha seleccionado la Opción 2." << std::endl;
            // Código para la opción 1
            std::cout << "Que video quieres buscar: ";
            std::cin.ignore(); // Ignorar el carácter de nueva línea pendiente
            std::getline(std::cin, nombre);
            // Iterate over each element in the vector
            for (const auto &pelicula : peliculas)
            {
                if (pelicula->GetNombre() == nombre)
                {
                    pelicula->Print();
                    pelicula->MostrarCalificaciones();
                }
            }

            for (const auto &serie : series)
            {
                for (auto temporada : serie->GetTemporadas())
                {
                    Temporada *tempTemporada = temporada;
                    for (auto episodio : tempTemporada->GetEpisodios())
                    {
                        if (episodio->GetNombre() == nombre)
                        {
                            episodio->Print();
                            episodio->MostrarCalificaciones();
                        }
                    }
                }
            }
            break;
        case 3:
            std::cout << "Ha seleccionado la Opción 3." << std::endl;
            for (const auto &pelicula : peliculas)
            {
                pelicula->Print();
                pelicula->MostrarCalificaciones();
            }
            break;
        case 4:
            std::cout << "Ha seleccionado la Opción 4." << std::endl;
            std::cout << "Que serie quieres buscar: ";
            std::cin.ignore(); // Ignorar el carácter de nueva línea pendiente
            std::getline(std::cin, nombre);
            std::cout << "Con que calificacion de episodio quieres encontrar: ";
            std::cin >> calificacion;
            for (const auto &serie : series)
            {
                if (serie->nombre == nombre)
                {
                    for (auto temporada : serie->GetTemporadas())
                    {
                        Temporada *tempTemporada = temporada;
                        for (auto episodio : tempTemporada->GetEpisodios())
                        {
                            if (episodio->GetCalificacion() == calificacion)
                            {
                                episodio->Print();
                                episodio->MostrarCalificaciones();
                            }
                        }
                    }
                }
            }
            break;
        case 5:
            std::cout << "Ha seleccionado la Opción 5." << std::endl;
            // Código para la opción 1
            std::cout << "Que genero quieres buscar: ";
            std::cin.ignore(); // Ignorar el carácter de nueva línea pendiente
            std::getline(std::cin, nombre);
            // Iterate over each element in the vector
            for (const auto &pelicula : peliculas)
            {
                if (pelicula->GetGenero() == nombre)
                {
                    pelicula->Print();
                    pelicula->MostrarCalificaciones();
                }
            }

            for (const auto &serie : series)
            {
                for (auto temporada : serie->GetTemporadas())
                {
                    Temporada *tempTemporada = temporada;
                    for (auto episodio : tempTemporada->GetEpisodios())
                    {
                        if (episodio->GetGenero() == nombre)
                        {
                            episodio->Print();
                            episodio->MostrarCalificaciones();
                        }
                    }
                }
            }
            break;
        case 6:
            std::cout << "Ha seleccionado la Opción 6." << std::endl;
            // Código para la opción 1
            std::cout << "Que video quieres calificar: ";
            std::cin.ignore(); // Ignorar el carácter de nueva línea pendiente
            std::getline(std::cin, nombre);
            // Iterate over each element in the vector
            for (const auto &pelicula : peliculas)
            {

                Video *tempVideo = pelicula;
                if (tempVideo->GetNombre() == nombre)
                {
                    tempVideo->Print();
                    std::cout << "Agregar una nueva calificacion: ";
                    std::cin >> calificacion;
                    tempVideo->SetCalificacion(calificacion);
                    std::cout << "Nuevo Promedio de la pelicula es: ";
                    tempVideo->MostrarCalificaciones();
                     std::cout << tempVideo->GetCalificacion() << std::endl;
                }
            }

            for (const auto &serie : series)
            {
                for (auto temporada : serie->GetTemporadas())
                {
                    Temporada *tempTemporada = temporada;
                    for (auto episodio : tempTemporada->GetEpisodios())
                    {
                        Video *tempVideo = episodio;
                        if (tempVideo->GetNombre() == nombre)
                        {
                            tempVideo->Print();
                            std::cout << "Agregar una nueva calificacion: ";
                            std::cin >> calificacion;
                            tempVideo->SetCalificacion(calificacion);
                            std::cout << "Nuevo Promedio de la pelicula es: ";
                            tempVideo->MostrarCalificaciones();
                            std::cout << tempVideo->GetCalificacion() << std::endl;
                        }
                    }
                }
            }
            break;
        default:
        {
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
            break;
        }
        }
    } while (opcion != 4);

    } catch (const std::exception& e) {
        std::cerr << "Error al procesar el archivo JSON: " << e.what() << std::endl;
    }


    return 0;
}
