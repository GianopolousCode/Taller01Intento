#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <string>
#include "Nota.h"
using std::string;

class Inscripcion {
public:
    string idAlumno;    // referencia al Alumno
    string codigoCurso; // referencia al Curso
    Nota* notas;        // lista enlazada de notas

    Inscripcion* siguiente;

    Inscripcion(const string& idAlumno_, const string& codigoCurso_)
        : idAlumno(idAlumno_), codigoCurso(codigoCurso_), notas(nullptr), siguiente(nullptr) {}
};

#endif // INSCRIPCION_H
