#include <iostream>
#include <string>
#include "Alumno.h"
#include "Curso.h"
#include "Inscripcion.h"

using namespace std;

//LISTAS PRINCIPALES
Alumno* listaAlumnos = nullptr;
Curso* listaCursos = nullptr;
Inscripcion* listaInscripciones = nullptr;

//FUNCION AUXILIAR
Alumno* buscarAlumno(string id) {
    Alumno* temp = listaAlumnos;
    while (temp != nullptr) {
        if (temp->id == id) return temp;
        temp = temp->siguiente;
    }
    return nullptr;
}

Curso* buscarCurso(string codigo) {
    Curso* temp = listaCursos;
    while (temp != nullptr) {
        if (temp->codigo == codigo) return temp;
        temp = temp->siguiente;
    }
    return nullptr;
}

Inscripcion* buscarInscripcion(string idAlumno, string codigoCurso) {
    Inscripcion* temp = listaInscripciones;
    while (temp != nullptr) {
        if (temp->idAlumno == idAlumno && temp->codigoCurso == codigoCurso) return temp;
        temp = temp->siguiente;
    }
    return nullptr;
}

// Funcion principal de mi clase Main
void registrarAlumno() {
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

void registrarCurso() {
    string codigo, nombre, carrera, profesor;
    int maximo;
    cout << "Codigo Curso: "; cin >> codigo;
    cout << "Nombre: "; cin >> nombre;
    cout << "Maximo de estudiantes: "; cin >> maximo;
    cout << "Carrera: "; cin >> carrera;
    cout << "Profesor: "; cin >> profesor;

    Curso* nuevo = new Curso(codigo, nombre, maximo, carrera, profesor);
    nuevo->siguiente = listaCursos;
    listaCursos = nuevo;

    cout << "Curso registrado.\n";
}

void inscribirAlumno() {
    string idAlumno, codigoCurso;
    cout << "ID Alumno: "; cin >> idAlumno;
    cout << "Codigo Curso: "; cin >> codigoCurso;

    if (!buscarAlumno(idAlumno)) {
        cout << "Alumno no encontrado en este curso.\n";
        return;
    }
    if (!buscarCurso(codigoCurso)) {
        cout << "Curso inexistente.\n";
        return;
    }
    if (buscarInscripcion(idAlumno, codigoCurso)) {
        cout << "Alumno ya encontrado inscrito en este curso actualmente.\n";
        return;
    }

    Inscripcion* nueva = new Inscripcion(idAlumno, codigoCurso);
    nueva->siguiente = listaInscripciones;
    listaInscripciones = nueva;

    cout << "Alumno inscrito en el curso.\n";
}

void agregarNota() {
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
    Nota* nueva = new Nota(nota);
    nueva->siguiente = ins->notas;
    ins->notas = nueva;

    cout << "Nota agregada.\n";
}

void mostrarReportes() {
    cout << "\n----- LISTA DE ALUMNOS -----\n";
    Alumno* a = listaAlumnos;
    while (a != nullptr) {
        cout << "ID: " << a->id << " | " << a->nombre << " " << a->apellido 
             << " | Carrera: " << a->carrera << " | Ingreso: " << a->fechaIngreso << "\n";
        a = a->siguiente;
    }

    cout << "\n----- LISTADO DE CURSOS -----\n";
    Curso* c = listaCursos;
    while (c != nullptr) {
        cout << "Codigo: " << c->codigo << " | " << c->nombre 
             << " | Docente: " << c->profesor 
             << " | Max: " << c->maximoEstudiantes << "\n";
        c = c->siguiente;
    }

    cout << "\n----- INSCRIPCIONES DISPONIBLES -----\n";
    Inscripcion* i = listaInscripciones;
    while (i != nullptr) {
        cout << "Alumno: " << i->idAlumno << " -> Curso: " << i->codigoCurso << " | Notas: ";
        Nota* n = i->notas;
        while (n != nullptr) {
            cout << n->valor << " ";
            n = n->siguiente;
        }
        cout << "\n";
        i = i->siguiente;
    }
}

// Desplegar mi menu principal
int main() {
    int opcion;
    do {
        cout << "\n----- MENU PRINCIPAL -----\n";
        cout << "1. Registrar Alumno\n";
        cout << "2. Registrar Curso\n";
        cout << "3. Inscribir Alumno en Curso\n";
        cout << "4. Agregar Nota\n";
        cout << "5. Mostrar Reportes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarAlumno(); break;
            case 2: registrarCurso(); break;
            case 3: inscribirAlumno(); break;
            case 4: agregarNota(); break;
            case 5: mostrarReportes(); break;
            case 0: cout << "Saliendo\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);

    return 0;
}
