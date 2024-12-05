#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

    ofstream outputBus;
    outputBus.open("README.txt");
    outputBus << "\n\t\tNombre de los autores: Gabriel A. Sanchez Rivera (num. de estudiante: 801-23-8372), Luis D. Figueroa Olmo(num. de estudiante: 401-20-2128) y Aidan.\n";
    outputBus << "\t\tSeccion: 002\n";
    outputBus << "\t\tDependencias requeridas para correr el juego : libreria limits(#include <limits>), string, iomanip.\n";
    outputBus << "\t\tComentarios: Las fichas que se le asignaran a los jugadores son 'X' y 'O'";
    outputBus.close();
}