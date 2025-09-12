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

    Curso* siguiente;

    Curso(string codigo_, string nombre_, int maxEstudiantes_,
          string carrera_, string profesor_);

    void mostrar();
};

#endif // CURSO_H
