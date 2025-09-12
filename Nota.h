#ifndef NOTA_H
#define NOTA_H

class Nota {
public:
    double valor;
    Nota* siguiente;

    Nota(double valor_) : valor(valor_), siguiente(nullptr) {}
};

#endif // NOTA_H
