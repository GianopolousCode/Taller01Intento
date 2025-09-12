#include "Inscripcion.h"
#include <iostream>
using namespace std;

Inscripcion::Inscripcion(string idAlumno_, string codigoCurso_)
    : idAlumno(idAlumno_), codigoCurso(codigoCurso_), notas(nullptr), siguiente(nullptr) {}

void Inscripcion::agregarNota(double valor) {
    Nota* nueva = new Nota(valor);
    nueva->siguiente = notas;
    notas = nueva;
}

void Inscripcion::mostrar() {
    cout << "Alumno: " << idAlumno << " -> Curso: " << codigoCurso << " | Notas: ";
    Nota* temp = notas;
    while (temp != nullptr) {
        temp->mostrar();
        temp = temp->siguiente;
    }
    cout << "\n";
}
