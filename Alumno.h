#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
using std::string;

class Alumno {
public:
    string id;        
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

    Alumno* siguiente; // Aqui debe ir mi lista enlazada para la clase Alumno

    Alumno(const string& id_, const string& nombre_, const string& apellido_,
           const string& carrera_, const string& fechaIngreso_)
        : id(id_), nombre(nombre_), apellido(apellido_), carrera(carrera_),
          fechaIngreso(fechaIngreso_), siguiente(nullptr) {}
};

#endif // ALUMNO_H
