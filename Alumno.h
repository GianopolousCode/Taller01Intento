#pragma once
#include <iostream>
using namespace std;

class Alumno {
public:
    string id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

    Alumno* siguiente;

    Alumno(string id_, string nombre_, string apellido_,
           string carrera_, string fechaIngreso_);

    void mostrar();
};
