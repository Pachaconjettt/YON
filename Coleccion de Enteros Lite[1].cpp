#include <iostream>
#include <sstream>
using namespace std;
#define maximo 40

//Desafio E1
class ColeccionEnteros{
    private:
    int vector[maximo];
    int cantidad;
    int tamano;

    public:
    ColeccionEnteros(){
        for (int i = 0; i < maximo; i++){
            vector[i] = 0;
        }
        cantidad = 0;
        tamano = maximo;
    }
    ColeccionEnteros(int tamano){
        for (int i = 0; i < tamano; i++){
            vector[i] = 0;
        }
        cantidad = 0;
        this -> tamano = tamano;
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

    string toString(){
        stringstream s;
        s << "| ";
        for (int i = 0; i < cantidad; i++){
            s << vector[i] << " | ";
        }
        return s.str();
    }

    //Desafio E2
    int sumaPosicionesPares(){
        int suma = 0;
        for (int i = 0; i < cantidad; i++){
            if (i % 2 == 0){
                suma += vector[i];
            }
        }
        return suma;
    }
};

int main(int argc, char *argv[]) {
    ColeccionEnteros c1(3);

    c1.setVector(0,10);
    c1.setVector(1,20);
    c1.setVector(2,30);

    cout << c1.toString() << endl;
    cout << c1.sumaPosicionesPares() << endl;
}