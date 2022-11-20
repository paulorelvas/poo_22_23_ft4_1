#include "Fracao.h"

using namespace std;

// construtores
Fracao::Fracao(){
    cout << "Construtor por omissão: " << this->numerador << "/" <<  this->denominador << endl;
}
Fracao::Fracao(int n): numerador(n){
    cout << "Construtor " << this->numerador << "/" <<  this->denominador << endl;
}
Fracao::Fracao(int n, int d):numerador(n){

    if(d<0){
        denominador = -d;
    }else{
        denominador = d;
    }
    cout << "Construtor " << this->obtemNumerador() << "/" <<  this->obtemDenominador() << endl;
}
Fracao::~Fracao(){}

// métodos membros
void Fracao::alteraNumerador(int valor){
    numerador = valor;
}
void Fracao::alteraDenominador(int valor){
    denominador = valor;
}
// métodos membros constantes
int Fracao::obtemNumerador() const{
    return numerador;
}
int Fracao::obtemDenominador() const{
    if(denominador < 0){
        int den = denominador;
        den = -den;
        return den;
    }
    return denominador;
}

// ---- operadores overloading::ft4_1-b -------
/*Fracao Fracao::operator*(const Fracao &b){
    return Fracao(numerador*b.obtemNumerador(), denominador*b.obtemDenominador());
}*/

// ------- alínea f ---------------
/*
ostream& operator<<(ostream& os, const Fracao& f){
    os << f.obtemNumerador() << '/' << f.obtemDenominador() << endl;
    return os;
}
 */

// ---- operadores overloading::ft4_1-j -------
Fracao &Fracao::operator*=(const Fracao &b){
    numerador = numerador * b.numerador;
    denominador = denominador * b.denominador;
    return *this;
}

// ---- operadores overloading::ft4_1-m -------
Fracao &Fracao::operator++(){
    ++numerador;
    ++denominador;
    return *this;
}
Fracao const Fracao::operator++(int){
    Fracao tmp(*this);
    ++numerador;
    ++denominador;
    return tmp;
}

// versão membro
/*bool Fracao::operator==(const Fracao &a){
    return this->obtemNumerador() == a.obtemNumerador() && this->obtemDenominador() == a.obtemDenominador();
}*/

Fracao::operator int() const {
    return abs(this->obtemNumerador()/this->obtemDenominador());
}

istream& operator>>(istream& ist, Fracao& f){
    /*if(ist){
        f = Fracao(f.numerador, f.denominador);
    }*/

    ist >> f.numerador >> f.denominador;

    return ist;
}