#include "Curso.h"
#include <iostream>
using namespace std;

Curso::Curso(string codigo_, string nombre_, int maxEstudiantes_,
             string carrera_, string profesor_)
    : codigo(codigo_), nombre(nombre_), maximoEstudiantes(maxEstudiantes_),
      carrera(carrera_), profesor(profesor_), siguiente(nullptr) {}

void Curso::mostrar() {
    cout << "Codigo: " << codigo
         << " | " << nombre
         << " | Docente: " << profesor
         << " | Max: " << maximoEstudiantes << "\n";
}
