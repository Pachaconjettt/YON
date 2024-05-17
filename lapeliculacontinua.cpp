#include <iostream>
using namespace std;

class Numero {
private:
    int valor;

public:
    void setValor(int n){
        valor = n;
    }

    int getValor(){
        return valor;
    }

    bool espar(){
        return valor % 2 == 0;
    }

    void cambiaSigno(){
        valor *= -1;
    }

    bool metodoBinario() {
        int n = valor;
        while (n != 0) {
            if (n % 10 > 1) {
                return false;
            }
            n /= 10;
        }
        return true;
    }

    bool monotono() {
        int n = valor / 10;
        int n1 = valor % 10;
        int n2 = -1;
        while (n > 0){
            int ultimo = n % 10;
            n /= 10;
            if (ultimo != n1){
                if (n2 != -1 && ultimo != n2){
                    return false;
                }
                if (n2 == -1){
                    n2 = ultimo;
                }
            }
        }
        return true;
    }

    bool monotonoEstricto() { 
        int n = valor ; 
        int ultimoDigito = n % 10;
        n /= 10;
        while (n > 0) { 
            int pork = n % 10;
            if (ultimoDigito != pork) {
                return false;
            }
            ultimoDigito = pork;
            n /= 10;
        }
        return true;
    }
    bool igual(const Numero& otroNumero){
return this -> valor == otroNumero.valor;
    }
};

int main() {
    Numero num;
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    num.setValor(n);
    cout << "El numero " << num.getValor() << " es par? " << (num.espar() ? "verdadero" : "falso") << endl;
    num.cambiaSigno();
    cout << "El numero despues de cambiar signo es: " << num.getValor() << endl;
    cin >> n;
    num.setValor(n);
    cout << "El numero " << num.getValor() << " es binario? " << (num.metodoBinario() ? "verdadero" : "falso") << endl;
    cin >> n;
    num.setValor(n);
    cout << "El numero " << num.getValor() << " es monotono? " << (num.monotono() ? "verdadero" : "falso") << endl;
    cout << "El numero " << num.getValor() << " es monotono estricto? " << (num.monotonoEstricto() ? "verdadero" : "falso") << endl;
    num.igual(num);
    cout << "el numero es igual a si mismo? " << (num.igual(num) ? "verdadero" : "falso") << endl;
    return 0;
}