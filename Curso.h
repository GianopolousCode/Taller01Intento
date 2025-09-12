#ifndef CURSO_H
#define CURSO_H

#include <string>
using std::string;

class Curso {
public:
    string codigo;
    string nombre;
    int maximoEstudiantes;
    string carrera;
    string profesor;

    Curso* siguiente; // Aqui debe ir mi lista enlazada para la clase Curso

    Curso(const string& codigo_, const string& nombre_, int maxEstudiantes_,
          const string& carrera_, const string& profesor_)
        : codigo(codigo_), nombre(nombre_), maximoEstudiantes(maxEstudiantes_),
          carrera(carrera_), profesor(profesor_), siguiente(nullptr) {}
};

#endif // CURSO_H
