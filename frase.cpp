#include <iostream>
using namespace std;
#define maximo 20

class Frase {
    private:
    char vector[maximo];
    int cantidad;
    int tamano;

    public:
    Frase(){
        for (int i = 0; i < maximo; i++){
            vector[i] = '-';
        }
        cantidad = 0;
        tamano = maximo;
    }

    Frase(int tam){
        for (int i = 0; i < tam; i++){
            vector[i] = '-';
        }
        cantidad = 0;
        tamano = tam; 
    }

    int getVector(int i){
        return vector[i];
    }

    void setVector(int i, char valor){
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

    string toString(){
        string s = "";
        for (int i = 0; i < cantidad; i++){
            s += vector[i];
        }
        return s;
    }

    void almacenaFrase(string hilera){
        for (int i = 0; i < hilera.length(); i++){
            vector[cantidad] = hilera[i];
            cantidad ++;
        }
    }
};

int main(int argc, char *argv[]) {
    Frase f1(30);
    f1.setVector(0, 'A');
    f1.setVector(1, 'B');
    f1.setVector(2, 'C');
    f1.setVector(3, '/');
    f1.almacenaFrase("Hola Mundo");

    cout << f1.toString() << endl;
    return 0;
}