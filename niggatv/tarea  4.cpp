#include <iostream>
#include <sstream>
using namespace std;

class Envio{
    private:
    char tipoCliente;
    float peso;
    char tipoEnvio;

    public:
    Envio(){
        tipoCliente = ' ';
        peso = 0.0;
        tipoEnvio = ' ';
    }
    Envio(char tC, float p, char tE){
        tipoCliente = tC;
        peso = p;
        tipoEnvio = tE;
    }
    ~Envio(){}

    void setTipoCliente(char tC){
        tipoCliente = tC;
    }
    char getTipoCliente(){
        return tipoCliente;
    }
    void setPeso(float p){
        peso = p;
    }
    float getPeso(){
        return peso;
    }
    void setTipoEnvio(char tE){
        tipoEnvio = tE;
    }
    char getTipoEnvio(){
        return tipoEnvio;
    }

    float costoEnvio(){
        float precio = 0.0;

        //Precio inicial
        if (peso < 500)
            precio += 1;
        else if (peso >= 500 && peso < 1000)
            precio += 2;
        else if (peso >= 1000 && peso < 2000)
            precio += 5;
        else 
            precio += 20;
        
        //Adicional envio internacional
        if (tipoEnvio == 'I')
            precio += precio * 0.3;
        
        //Descuentos
        switch (tipoCliente){
        case 'E':
            precio -= precio * 0.07;
            break;
        case 'G':
            precio -= precio * 0.05;
            break;
        }

        //Impuestos
        if (tipoCliente != 'G')
            precio += precio * 0.15;
        if (tipoEnvio == 'I')
            precio += precio * 0.1;
        
        return precio;
    }

    string toString(){
        stringstream s;
        s << "Tipo de cliente: " << tipoCliente << endl;
        s << "Peso: " << peso << endl;
        s << "Tipo de envio: " << tipoEnvio << endl;
        s << "Costo de envio: $" << costoEnvio() << endl;

        return s.str();
    }
};

int main(int argc, char *argv[]) {
    bool corriendo = true;
    while (corriendo){
        system("cls");
        cout << "Comercio electronico" << endl;  
        cout << "1. Registrar envio" << endl;
        cout << "2. Salir" << endl;
        cout << "Su seleccion: ";

        int opcion;
        cin >> opcion;

        char tipoCliente;
        float peso;
        char tipoEnvio;

        switch (opcion){
        case 1:
            cout << "Digite el tipo de cliente (E- Ecologico, G- Gobierno, F- Fisico): ";
            cin >> tipoCliente;
            cout << "Digite el peso del paquete en gramos: ";
            cin >> peso;
            cout << "Digite el tipo de envio (N- Nacional, I- Internacional): ";
            cin >> tipoEnvio;

            cout << Envio(tipoCliente, peso, tipoEnvio).toString() << endl;

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