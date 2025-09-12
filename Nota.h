#ifndef NOTA_H
#define NOTA_H

class Nota {
public:
    double valor;
    Nota* siguiente;

    Nota(double valor_);
    void mostrar();
};

#endif // NOTA_H
