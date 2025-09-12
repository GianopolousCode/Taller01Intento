#include "Sistema.h"
#include <iostream>
using namespace std;

Sistema::Sistema() : listaAlumnos(nullptr), listaCursos(nullptr), listaInscripciones(nullptr) {}

Alumno* Sistema::buscarAlumno(string id) {
    Alumno* temp = listaAlumnos;
    while (temp != nullptr) {
        if (temp->id == id) return temp;
        temp = temp->siguiente;
    }
    return nullptr;
}

Curso* Sistema::buscarCurso(string codigo) {
    Curso* temp = listaCursos;
    while (temp != nullptr) {
        if (temp->codigo == codigo) return temp;
        temp = temp->siguiente;
    }
    return nullptr;
}

Inscripcion* Sistema::buscarInscripcion(string idAlumno, string codigoCurso) {
    Inscripcion* temp = listaInscripciones;
    while (temp != nullptr) {
        if (temp->idAlumno == idAlumno && temp->codigoCurso == codigoCurso) return temp;
        temp = temp->siguiente;
    }
    return nullptr;
}

void Sistema::registrarAlumno() {
    string id, nombre, apellido, carrera, fecha;
    cout << "ID Alumno: "; cin >> id;
    cout << "Nombre: "; cin >> nombre;
    cout << "Apellido: "; cin >> apellido;
    cout << "Carrera: "; cin >> carrera;
    cout << "Fecha ingreso: "; cin >> fecha;

    Alumno* nuevo = new Alumno(id, nombre, apellido, carrera, fecha);
    nuevo->siguiente = listaAlumnos;
    listaAlumnos = nuevo;

    cout << "Alumno registrado.\n";
}

void Sistema::registrarCurso() {
    string codigo, nombre, carrera, profesor;
    int maximo;
    cout << "Codigo Curso: "; cin >> codigo;
    cout << "Nombre asignatura: "; cin >> nombre;
    cout << "Maximo de estudiantes: "; cin >> maximo;
    cout << "Carrera: "; cin >> carrera;
    cout << "Profesor: "; cin >> profesor;

    Curso* nuevo = new Curso(codigo, nombre, maximo, carrera, profesor);
    nuevo->siguiente = listaCursos;
    listaCursos = nuevo;

    cout << "Curso registrado.\n";
}

void Sistema::buscarAlumnoManual()
{
    string id = "";
    cout << "Ingrese ID: ";
    cin >> id;
    cout << endl;

    Alumno* temp = listaAlumnos;
    
    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Alumno con ID encontrado: " << temp -> nombre << " " << temp -> apellido << endl;
            return;
        }
        temp = temp->siguiente;
    }
    
    cout <<"Alumno no encontrado." << endl;
    
}

void Sistema::inscribirAlumno() {
    string idAlumno, codigoCurso;
    cout << "ID Alumno: "; cin >> idAlumno;
    cout << "Codigo Curso: "; cin >> codigoCurso;

    if (!buscarAlumno(idAlumno)) {
        cout << "Alumno no encontrado.\n";
        return;
    }
    if (!buscarCurso(codigoCurso)) {
        cout << "Curso inexistente.\n";
        return;
    }
    if (buscarInscripcion(idAlumno, codigoCurso)) {
        cout << "Alumno ya inscrito en este curso.\n";
        return;
    }

    Inscripcion* nueva = new Inscripcion(idAlumno, codigoCurso);
    nueva->siguiente = listaInscripciones;
    listaInscripciones = nueva;

    cout << "Alumno inscrito en el curso.\n";
}

void Sistema::agregarNota() {
    string idAlumno, codigoCurso;
    double nota;
    cout << "ID Alumno: "; cin >> idAlumno;
    cout << "Codigo Curso: "; cin >> codigoCurso;

    Inscripcion* ins = buscarInscripcion(idAlumno, codigoCurso);
    if (!ins) {
        cout << "Inscripcion no encontrada.\n";
        return;
    }

    cout << "Nota: "; cin >> nota;
    ins->agregarNota(nota);

    cout << "Nota agregada.\n";
}

void Sistema::mostrarReportes() {
    cout << "\n----- LISTA DE ALUMNOS -----\n";
    Alumno* a = listaAlumnos;
    while (a != nullptr) {
        a->mostrar();
        a = a->siguiente;
    }

    cout << "\n----- LISTADO DE CURSOS -----\n";
    Curso* c = listaCursos;
    while (c != nullptr) {
        c->mostrar();
        c = c->siguiente;
    }

    cout << "\n----- INSCRIPCIONES -----\n";
    Inscripcion* i = listaInscripciones;
    while (i != nullptr) {
        i->mostrar();
        i = i->siguiente;
    }
}
