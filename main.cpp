#include <iostream>
#include <sstream>
#include "Fracao.h"
using namespace std;

// Fracao operator+(const Fracao& a, const Fracao& b);

// Fracao operator*(const Fracao &a, const Fracao &b){
Fracao operator*( Fracao &a,  Fracao &b){
    return Fracao(a.obtemNumerador()*b.obtemNumerador(), a.obtemDenominador()*b.obtemDenominador());
}

bool operator==(const Fracao &a,  const Fracao &b){
    if(a.obtemNumerador() == b.obtemNumerador() &&  a.obtemDenominador() == b.obtemDenominador())
        return true;
    return false;
}

ostream& operator<<(ostream& os,  const Fracao & f){
    os << f.obtemNumerador() << '/' << f.obtemDenominador() << endl;
    return os;
}

void Func(int n){
    cout << n << endl; // aparece 2
}

int main() {
    cout << "----- FT4_1::Operators Overloading ------" << endl;

    Fracao f0;
    Fracao f1{4};
    Fracao f2{6,2};

    cout << endl << " --- start ---" << endl;
    Fracao a{1,2};
    Fracao b{3};
    const Fracao c{3, 4};

// a = b * 4;
    //a = 4 * b;
    //cout << endl << "----- :: alinea a :: cout a, b, c -----" << endl;
    // visualizada pelos construtores

     cout << endl << "----- :: alinea b :: {a=b*c} -----" << endl;
     a = b * c;
     cout << "-- Res: a = b*c ---> " << a.obtemNumerador() << "/" << a.obtemDenominador() << endl;

    // O operador * como global permite converter int z em objeto Fracao e usar - o contrário não irá permitir caso o z esteja à esquerda de b
    // int z = 4;
    // cout << endl << "----- :: alinea b :: -----" << endl;
    // a = z * b;
    // cout << "-- Res: a = b*c ---> " << a.obtemNumerador() << "/" << a.obtemDenominador() << endl;

    cout << endl << "----- :: alinea c :: {a*b*c} -----" << endl;
    //a*b*c;
    Fracao z = a*b*c;
    cout << "-- Res: a*b*c ---> " << z.obtemNumerador() << "/" << z.obtemDenominador() <<  endl;

    cout << endl << "----- :: alinea d :: {a=b*4} -----" << endl;
    a = b * 4;
    cout << "-- Res: a=b*4 ---> " << a.obtemNumerador() << "/" << a.obtemDenominador() <<  endl;

    cout << endl << "----- :: alinea e :: {a=b*4 --- usando explicit} -----" << endl;
    // explicit - garante que os dados passados para a função ou construtor são do tipo declarado
    //a = b*4;
    //cout << "-- Res: a=b*4 ---> " << a.obtemNumerador() << "/" << a.obtemDenominador() <<  endl;

    cout << endl << "----- :: alinea f :: {cout << a} -----" << endl;
    a = 4*b;
    cout << "-- Res: a=b*4 ---> " << a.obtemNumerador() << "/" << a.obtemDenominador() <<  endl;

    cout << endl << "----- :: alinea g :: {cout << a} -----" << endl;
    cout << a;

    cout << endl << "----- :: alinea h :: {cout << a << b} -----" << endl;
    cout << a << b;

    cout << endl << "----- :: alinea i :: {a=b*4} -----" << endl;
    // devolve & e recebe const como referência

    cout << endl << "----- :: alinea j :: {a*=b} -----" << endl;
    a *= b;
    cout << a;

    cout << endl << "----- :: alinea k :: {a*=b*=c} -----" << endl;
    a *= b *= c; // a execução do operador é da direita para a esquerda --> a*= (b*=c)
    cout << a;

    cout << endl << "----- :: alinea l :: {a=b*4} -----" << endl;
    Fracao a1(1,2),b1(2,3),c1(3,4);
    (a1 *= b1) *= c1;
    cout << a1;
    // deverá aparecer 6/24

    cout << endl << "----- :: alinea m :: {++a; a++} -----" << endl;
    cout << ++a << endl;
    cout << a++;

    cout << endl << "----- :: alinea n :: {a=b*4} -----" << endl;
    const Fracao f(7,-3);
    Func(f);        //  é passado automaticamente o valor 7/3

    cout << endl << "----- :: alinea o :: {if(a==b)} -----" << endl;
    Fracao n{2, 1}, p{2};
    //if(a == b)
    if(n == p)
        cout << "----- :: Fracao a(n) e Fracao b(p) iguais -----" << endl;
    else
        cout << "----- :: Fracao a(n) e Fracao b(p) diferentes -----" << endl;


    cout << "--------- :: ---------" << endl;
    Fracao x(2,1),y(1,3),z1;
    cout << " z= " << z1 << endl;
    z1=x*y;
    cout << x << " * " << y << " = " << z1 << endl;
    //z1 = x/y;
    cout << x << " / " << y << " = " << z1 << endl;
    Fracao aa(2,-4),bb(2);
    cout << " a= " << aa << " b= " << bb << endl;
    aa *= bb;
    cout << "a *= b " << endl;
    cout << "a= " << aa << " b= " << bb << endl;

    //Fracao az (7, 4);

    cout << "--------- :: cin ---------" << endl;
    cin >> aa;
    cout << "--------- :: cin ---------" << endl;
    cout << aa;

    class String {
        int x;
    public:
        // explicit String(int n): x(n){};
        String(int n): x(n){};
        string printS(){
            ostringstream ss;
            ss << x;
            return ss.str();
        }
    };
    String mystring = 'X';
    cout << "----- :: explicit :: ------ " << mystring.printS() << endl;

    return 0;
}
