#ifndef SISTEMA_H
#define SISTEMA_H

#include "Alumno.h"
#include "Curso.h"
#include "Inscripcion.h"

class Sistema {
private:
    Alumno* listaAlumnos;
    Curso* listaCursos;
    Inscripcion* listaInscripciones;

public:
    Sistema();

    Alumno* buscarAlumno(string id);
    Curso* buscarCurso(string codigo);
    Inscripcion* buscarInscripcion(string idAlumno, string codigoCurso);

    void registrarAlumno();
    void registrarCurso();
    void inscribirAlumno();
    void agregarNota();
    void mostrarReportes();
    void buscarAlumnoManual();
};

#endif // SISTEMA_H
