#include <iostream>
#include "Sistema.h"
using namespace std;

int main() {
    Sistema sistema;
    int opcion;

    do {
        cout << "\n----- MENU PRINCIPAL -----\n";
        cout << "1. Registrar Alumno\n";
        cout << "2. Registrar Curso\n";
        cout << "3. Inscribir Alumno en Curso\n";
        cout << "4. Agregar Nota\n";
        cout << "5. Mostrar Reportes\n";
        cout << "6. Buscar Alumno\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: sistema.registrarAlumno(); break;
            case 2: sistema.registrarCurso(); break;
            case 3: sistema.inscribirAlumno(); break;
            case 4: sistema.agregarNota(); break;
            case 5: sistema.mostrarReportes(); break;
            case 6: sistema.buscarAlumnoManual(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);

    return 0;
}