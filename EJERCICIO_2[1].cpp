#include <iostream>
#include <sstream>
using namespace std;

class Pedido {
    private:
    int identificador;
    char tipo;
    int platos;
    int bebidas;

    public:

    Pedido() {
        identificador = 0;
        tipo = ' ';
        platos = 0;
        bebidas = 0;
    }
    Pedido(int i, char t, int p, int b) {
        identificador = i;
        tipo = t;
        platos = p;
        bebidas = b;
    }

    ~Pedido() {
    }

    void setIdentificador(int i) {
        identificador = i;
    }
    int getIdentificador() {
        return identificador;
    }
    void setTipo(char t) {
        tipo = t;
    }
    char getTipo() {
        return tipo;
    }
    void setPlatos(int p) {
        platos = p;
    }
    int getPlatos() {
        return platos;
    }
    void setBedidas(int b) {
        bebidas = b;
    }
    int getBebidas() {
        return bebidas;
    }

    float getDescuento(){
        if (platos >= 10) return 0.15;
        else if (platos < 10 && platos >= 7 ) return 0.1;
        else if (platos < 7 && platos >= 5) return 0.05;
        else return 0.01;
    }

    float getPrecio(){
        float precio;
        switch (tipo){
            case 'D':
                precio = platos * 2500;
                break;
            case 'A':
                precio = platos * 3500 + bebidas * 1000;
                break;
            case 'C':
                precio = platos * 4500 + (bebidas - platos) * 1000;
                break;
            default:
                precio = 0.0;
        }

        return precio;
    }
    
    string toStringFactura(){
        stringstream s;
        s << "******** FACTURA ********" << endl;
        s << "Pedido:               " << identificador << endl;
        s << "Tipo:                 " << tipo << endl;
        s << "Platos:               " << platos << endl;
        s << "Bebidas:              " << bebidas << endl;
        s << "Total del pedido:     " << getPrecio() << endl;
        s << "Porcentaje descuento: " << getDescuento() * 100  << "%" << endl;
        s << "Precio del pedido:    " << getPrecio() - (getPrecio() * getDescuento()) << endl;

        return s.str();
    }
};

int main(int argc, char *argv[]) {
    bool corriendo = true;
    int pedidos = 1;
    while (corriendo){
        system("cls");
        cout << "BIENVENIDO A MIPEDIDO" << endl;  
        cout << "1. Ingresar un pedido" << endl;
        cout << "2. Salir" << endl;
        cout << "Su seleccion: ";

        int opcion;
        cin >> opcion;

        char tipo;
        int platos;
        int bebidas;

        switch (opcion){
        case 1:
            cout << "Digite el tipo de pedido (D: Desayuno, A: Almuerzo, C: Cena): ";
            cin >> tipo;
            cout << "Digite la cantidad de platos: ";
            cin >> platos;
            cout << "Digite la cantidad de bebidas: ";
            cin >> bebidas;

            cout << Pedido(pedidos, tipo, platos, bebidas).toStringFactura() <<  endl;
            pedidos ++;
            system("pause");
            break;
        
        case 2:
            corriendo = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            system("pause");
            break;
        }
        

        

        

        
    }
    
    return 0;
}