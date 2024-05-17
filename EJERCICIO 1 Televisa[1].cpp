#include <iostream>
#include <sstream>
using namespace std;

class Televisor{
    private:
    float precio;
    int codigo;
    int fabricacion;
    char loteGama;

    public:
    Televisor(){
        precio = 0.0;
        codigo = 0;
        fabricacion = 0;
        loteGama = ' ';
    }
    Televisor(float p, int c, int f, char l){
        precio = p;
        codigo = c;
        fabricacion = f;
        loteGama = l;
    }

    ~Televisor(){}

    void setPrecio(float p){
        precio = p;
    }
    float getPrecio(){
        return precio;
    }
    void setCodigo(int c){
        codigo = c;
    }
    int getCodigo(){
        return codigo;
    }
    void setFabricacion(int f){
        fabricacion = f;
    }
    int getFabricacion(){
        return fabricacion;
    }
    void setLoteGama(char l){
        loteGama = l;
    }
    char getLoteGama(){
        return loteGama;
    }

    string toString(){
        stringstream s;
        s << "Codigo:          " << codigo << endl;
        s << "Precio:          $" << precio << endl;
        s << "Fabricacion:     " << fabricacion << endl;
        s << "Lote Gama:       " << loteGama << endl;
        s << "Precio de venta: $" << precioVenta() << endl;

        return s.str();
    }

    float precioVenta(){
        float precioNuevo = precio;
        precioNuevo += precio * 0.3;

        int edad = 2024;
        if (edad - 2 <= fabricacion) 
            precioNuevo += precio * 0.05;
        if (loteGama == 'A')
            precioNuevo += precio * 0.15;
        if (codigo < 0)
            precioNuevo -= precio * 0.25;
        
        return precioNuevo;
    }
};

int main(int argc, char *argv[]) {
    Televisor t1;
    t1.setPrecio(46761);
    t1.setCodigo(1234);
    t1.setFabricacion(2019);
    t1.setLoteGama('A');

    Televisor t2(30000, -3422, 2020, 'B');
    Televisor t3(11965, 5678, 2017, 'M');
    Televisor t4(13584, 8765, 2016, 'M');
    Televisor t5(1052, 9876, 2015, 'A');

    cout << t1.toString() << endl;
    cout << t2.toString() << endl;
    cout << t3.toString() << endl;
    cout << t4.toString() << endl;
    cout << t5.toString() << endl;


    return 0;
}