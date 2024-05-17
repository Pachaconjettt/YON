#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Fraccion {
private: 
    int denominador; 
    int numerador; 

public:
    Fraccion() {
        denominador = 0;
        numerador = 0;	
    }

    Fraccion(int numerador, int denominador) {
        this->numerador = numerador;
        this->denominador = denominador;
    }

    int getNumerador() {
        return numerador;
    }

    void setNumerador(int a) {
        numerador = a;
    }

    int getDenominador() {
        return denominador;
    }	

    void setDenominador(int b) {
        denominador = b;
    }

    bool esPropia() {
        return numerador < denominador;
    }

    bool esUnitaria() {
        return numerador == denominador;
    }

    double esValorDecimal() {
        return static_cast<double>(numerador) / denominador;
    }

    Fraccion esMayor(Fraccion otro) {
        return esValorDecimal() > otro.esValorDecimal() ? *this : otro;
    }

    string esMostrar() {
        stringstream s;
        s << numerador << '/' << denominador;
        return s.str();
    }

    Fraccion esMultiplicacion(Fraccion otro) {
        return Fraccion(numerador * otro.numerador, denominador * otro.denominador);
    }

    Fraccion esDivision(Fraccion otro) {
        int NuevoNumerador = numerador * otro.denominador;
        int NuevoDenominador = denominador * otro.numerador;
        return Fraccion(NuevoNumerador, NuevoDenominador);
    }

    int esMcd(int a, int b) {
        while (b != 0) {
            int residuo = a % b;
            a = b;
            b = residuo;
        }
        return a;
    }

    int esMCM(int a, int b) { 
         int m = a * b;
    int mcd = esMcd(a, b);
    int mcm = m / mcd;
    return mcm;
    }

    Fraccion esSuma(Fraccion otro) {
        int nuevon = numerador * otro.denominador + denominador * otro.numerador;
        int nuevod = denominador * otro.denominador;
        return Fraccion(nuevon, nuevod);
    }

    Fraccion esResta(Fraccion otro) {
        int nuevon = numerador * otro.denominador - denominador * otro.numerador;
        int nuevod = denominador * otro.denominador;
        return Fraccion(nuevon, nuevod);
    }

    Fraccion esInversoAditivo() {
        int Inverso1 = -numerador;
        int Inverso2 = -denominador;
        int Resultado1 = Inverso1 + numerador;
        int Resultado2 = Inverso2 + denominador; 
        return Fraccion(Resultado1, Resultado2);
    }

    Fraccion esInversoMultiplicativo() {
        return Fraccion(denominador, numerador);
    }

    Fraccion esCanonica() {
		int yon1;
		int yon2;
        int mcd = esMcd(numerador, denominador);
		yon1 = numerador/mcd;
		yon2 =	denominador/mcd;
        return Fraccion(yon1,yon2);
    }
};

int main() {
    Fraccion conwork(6, 10);
    Fraccion num;
    int a, b;

    cout << "Ingrese el numerador y denominador para la primera fracción: ";
    cin >> a >> b;
    num.setNumerador(a);
    num.setDenominador(b);
    cout << num.getNumerador() << "/" << num.getDenominador() << " " << (num.esPropia() ? "es propia" : "No es propia") << endl << endl;

    cout << "Ingrese el numerador y denominador para la segunda fracción: ";
    cin >> a >> b;
    num.setNumerador(a);
    num.setDenominador(b);
    cout << num.getNumerador() << "/" << num.getDenominador() << " " << (num.esUnitaria() ? "Es unitaria" : "No es unitaria") << endl << endl;

    cout << "Ingrese el numerador y denominador para la tercera fracción: ";
    cin >> a >> b;
    num.setNumerador(a);
    num.setDenominador(b);
    cout << "El valor decimal es : " << num.esValorDecimal() << endl << endl;

    cout << "El mayor entre parametro : " << num.esValorDecimal() << "  y  " << " propio : " << conwork.esValorDecimal() << "  es  " << conwork.esMayor(num).esMostrar() << endl << endl;

    Fraccion resultado = conwork.esMultiplicacion(num);
    cout << "La multiplicacion es : " << resultado.esMostrar() << endl << endl;

    Fraccion resultado2 = conwork.esDivision(num);
    cout << "La division es : " << resultado2.esMostrar() << endl << endl;

    cout << "El mcd es : " << conwork.esMcd(num.getNumerador(), num.getDenominador()) << endl << endl;

    cout << "El mcm es : " << conwork.esMCM(num.getNumerador(), num.getDenominador()) << endl << endl;

    Fraccion resultado3 = conwork.esSuma(num);
    cout << "La suma es : " << resultado3.esMostrar() << endl << endl;

    Fraccion resultado4 = conwork.esResta(num);
    cout << "La resta es : " << resultado4.esMostrar() << endl << endl;

    Fraccion resultado5 = conwork.esInversoAditivo();
    cout << "El inverso aditivo es la suma de : " << -conwork.getNumerador() << " con el numerador : " << conwork.getNumerador() << " y " <<  -conwork.getDenominador()  << "con el denominador : " <<  conwork.getDenominador()  << " y resultado da : " << resultado5.esMostrar() << endl << endl;

    Fraccion resultado6 = conwork.esInversoMultiplicativo();
    cout << "El inverso multiplicativo de la fraccion propia que es: " << conwork.esMostrar() << " es: " << resultado6.esMostrar() << endl;

    Fraccion resultado7 = conwork.esCanonica();
    cout << "La forma canónica de la fracción propia es : " << resultado7.esMostrar() << endl << endl;

    return 0;
}
