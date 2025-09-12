#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <string>
#include "Nota.h"
using std::string;

class Inscripcion {
public:
    string idAlumno;
    string codigoCurso;
    Nota* notas;

    Inscripcion* siguiente;

    Inscripcion(string idAlumno_, string codigoCurso_);
    void agregarNota(double valor);
    void mostrar();
};

#endif // INSCRIPCION_H
