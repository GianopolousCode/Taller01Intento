#include "Nota.h"
#include <iostream>
using namespace std;

Nota::Nota(double valor_) : valor(valor_), siguiente(nullptr) {}

void Nota::mostrar() {
    cout << valor << " ";
}