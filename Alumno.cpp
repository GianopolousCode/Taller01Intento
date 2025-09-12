#include "Alumno.h"
#include <iostream>
using namespace std;

Alumno::Alumno(string id_, string nombre_, string apellido_,
               string carrera_, string fechaIngreso_)
    : id(id_), nombre(nombre_), apellido(apellido_), carrera(carrera_),
      fechaIngreso(fechaIngreso_), siguiente(nullptr) {}

void Alumno::mostrar() {
    cout << "ID: " << id << " | " << nombre << " " << apellido
         << " | Carrera: " << carrera
         << " | Ingreso: " << fechaIngreso << "\n";
}
