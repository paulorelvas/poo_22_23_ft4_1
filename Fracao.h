#include <iostream>
#include <cmath>

using namespace std;

#ifndef FT_4_1_FRACAO_H
#define FT_4_1_FRACAO_H

class Fracao {
private:
    unsigned int denominador {1};
    int numerador {0};
public:
    Fracao();
    //explicit Fracao(int n);  // --- alinea d
    Fracao(int n);
    Fracao(int n, int d);
    ~Fracao();

    // métodos membros
    void alteraNumerador(int valor);
    void alteraDenominador(int valor);
    // métodos membros constantes
    int obtemNumerador() const;
    int obtemDenominador() const;

    // operadores overloading
    //Fracao operator*(const Fracao &f);
    Fracao& operator*=(const Fracao &f);
    // bool operator==(const Fracao &a);
    // friend ostream& operator<<(ostream& os, const Fracao& f);
    friend istream& operator>>(istream& is, Fracao& f);

    Fracao& operator++(); // prefixo ---> ++a
    Fracao const operator++(int); // posfixo ---> a++
    operator int() const;
};
#endif //FT_4_1_FRACAO_H
