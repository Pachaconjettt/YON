#include <iostream>
#include <sstream>
using namespace std;
#define maximo 20

class Numero{
    private:
    int valor;

    public:
    Numero(){
        valor = 0;
    }
    Numero(int n){
        valor = n;
    }
    ~Numero(){}
    void setValor(int n){
        valor = n;
    }
    int getValor(){
        return valor;
    }

    //Desafio CN9
    Numero mayor(Numero otro){
        if (valor > otro.valor){
            return *this;
        } else {
            return otro;
        }
    }

    //Desafio N2
    Numero fibonacci(){
        int a = 0;
        int b = 1;
        int c;
        for (int i = 1; i < valor; i++){
            c = a + b;
            a = b;
            b = c;
        }

        return Numero(c);
    }

    //Desafio N5
    bool numeroFeliz(){
        int num = valor;
        while (num > 9){
            int num2 = 0;
            for (int i = num; i != 0; i /= 10 ){
                num2 += (i % 10) * (i % 10);
            }
            num = num2;
        }

        return num == 1;
    }

    //Desafio N6
    Numero siguienteNumeroFeliz(){
        int i = valor;
        bool encontrado = false;
        while (!encontrado){
            int num = i;
            while (num > 9){
                int num2 = 0;
                for (int i = num; i != 0; i /= 10 ){
                    num2 += (i % 10) * (i % 10);
                }
                num = num2;
            }

            if (num == 1){
                encontrado = true;
            } else {
                i++;
            }
        }

        return Numero(i);
    }
};

class Coleccion {
    private:
    int vector[maximo];
    int cantidad;
    int tamano;

    public:
    Coleccion(){
        for (int i = 0; i < maximo; i++){
            vector[i] = 0;
        }
        cantidad = 0;
        tamano = maximo;
    }
    Coleccion(int tam){
        for (int i = 0; i < tam; i++){
            vector[i] = 0;
        }
        cantidad = 0;
        tamano = tam;
    }
    int getVector(int i){
        return vector[i];
    }
    void setVector(int i, int valor){
        vector[i] = valor;
        cantidad ++;
    }
    int getCantidad(){
        return cantidad;
    }
    void setCantidad(int cantidad){
        this -> cantidad = cantidad;
    }
    int getTamano(){
        return tamano;
    }
    void setTamano(int tamano){
        this -> tamano = tamano;
    }

    void agregar(int n){
        if (cantidad < tamano){
            vector[cantidad] = n;
            cantidad++;
        }
    }

    string toString(){
        stringstream s;
        s << "| ";
        for (int i = 0; i < cantidad; i++){
            s << vector[i] << " | ";
        }
        return s.str();
    }

    //Desafio E12
    void fibonacci(int n){
        agregar(1);
        int a = 0;
        int b = 1;
        int c;
        for (int i = 0; i < n-1; i++){
            c = a + b;
            a = b;
            b = c;
            agregar(c);
        }
    }

    //Desafio E15.1
    Coleccion mask(Coleccion otra){
        Coleccion nueva;
        for (int i = 0; i < otra.cantidad && i < cantidad; i++){
            if (otra.vector[i] == 1){
                nueva.agregar(vector[i]);
            }
        }
        return nueva;
    }

    //Desafio E17
    void ulam(int n){
        int a = n;
        while (a != 1){
            if (n % 2 == 0){
                a /= 2;
            } else {
                a = a * 3 + 1;
            }
            agregar(a);
        }
    }
};

int main(int argc, char *argv[]) {
    cout << "Desafio CN9 -- Metodo mayor()" << endl;
    Numero n1(5);
    Numero n2(10);
    Numero n3 = n1.mayor(n2);
    cout << "El primer numero es " << n1.getValor() << endl;
    cout << "El segundo numero es " << n2.getValor() << endl;
    cout << "El mayor es " << n3.getValor() << endl;

    cout << endl << "Desafio N2 -- Metodo fibonacci()" << endl;
    Numero n4(5);
    Numero n5 = n4.fibonacci();
    cout << "El numero fibonacci numero " << n4.getValor() << " es " << n5.getValor() << endl;

    cout << endl << "Desafio E13 -- Metodo fibonacci() en coleccion" << endl;
    Coleccion c1(10);
    c1.fibonacci(10);
    cout << "Los primeros 10 numeros fibonacci son " << c1.toString() << endl;

    cout << endl << "Desafio E17 -- metodo ulam()" << endl;
    Coleccion c2(20);
    c2.ulam(5);
    cout << "La serie de ULAM partiendo del numero 5 es " << c2.toString() << endl;

    cout << endl << "Desafio N5 -- Metodo numeroFeliz()" << endl;
    Numero n6(19);
    cout << "El numero " << n6.getValor() << (n6.numeroFeliz() ? " es feliz" : " no es feliz") << endl;

    cout << endl << "Desafio N6 -- Metodo siguienteNumeroFeliz()" << endl;
    Numero n7(15);
    Numero n8 = n7.siguienteNumeroFeliz();
    cout << "El siguiente numero feliz despues de " << n7.getValor() << " es " << n8.getValor() << endl;

    cout << endl << "Desafio E15.1 -- Metodo mascara()" << endl;
    Coleccion c3(10);
    c3.agregar(5);
    c3.agregar(4);
    c3.agregar(7);
    c3.agregar(3);
    c3.agregar(9);
    Coleccion c4(10);
    c4.agregar(1);
    c4.agregar(1);
    c4.agregar(0);
    c4.agregar(0);
    c4.agregar(1);
    Coleccion c5 = c3.mask(c4);
    cout << "La mascara de la coleccion " << c3.toString() << " con " << c4.toString() << " es " << c5.toString() << endl;

    return 0;
}