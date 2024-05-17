#include <iostream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Televisor { 
private:
    int annof;
    int ndelote;
    int preciocompra;
    int codigo;
    char claseop;
public: 
    int GeneradorCodigo(){
        int min = 1000;
        int max = 9999;
        codigo = rand() % (max - min + 1) + min;
        return codigo;
    }
    int getPrecio(){
        return preciocompra;
    }
    void setPrecio(int precio){
        preciocompra = precio; 
    }
    int getAnnos(){
        return annof;
    }
    void setAnnos(int anno){
        annof = anno;
    }
    int getLote(){
        return ndelote;
    }
    void setLote(int lote){
        ndelote = lote;
    }
    char getClase(){
        return claseop;
    }
    void setClase(char gama){
        claseop = gama;
    }
    string toStringTelevision(){
        stringstream s;
        s<<"\t\t\t\t TELEVISOR \t\t\t\t"<<endl;
        s<< "PRECIO INICIAL :" << getPrecio() <<endl;
        s<<"CODIGO :" << GeneradorCodigo()<<endl;
        s<<"AÑO DE FABRICACION :"<<getAnnos()<<endl;
        s<<"NUMERO DE LOTE :"<<getLote()<<endl;
        s<<"GAMA :" <<getClase()<<endl;
        s<<"PRECIO DE VENTA :"<<PrecioVenta()<<endl;
        return s.str();
    }   
 int PrecioVenta(){
    double loteb = preciocompra;
    loteb += preciocompra * 0.3;
    int anto = 2024;
    if (anto - 2 <= getAnnos()){ 
        loteb += preciocompra * 0.05;
    }if (getClase() == 'A') {
        loteb += preciocompra * 0.15;
    }
    if (ndelote < 0){
        loteb -= preciocompra * 0.55;                    
    }
    return loteb;
}
};

int main(int argc, char const *argv[])
{
    Televisor tv;
    int precio, anno , lote;
    char gama;

    cout << "\t\t BIENVENIDO A VENDEDORAS DE TELEVISORES COMPANY\t\t "<<endl;
    cout << "INGRESE EL PRECIO DE SU TELEVISOR :" <<endl<<endl;
    cin>>precio;
    tv.setPrecio(precio);
    cout <<"INGRESE EL YEAR DE FABRICACION :"<<endl<<endl;
    cin>>anno;
    tv.setAnnos(anno);
    cout<<"INGRESE EL NUMERO DE LOTE :"<<endl<<endl;
    cin>>lote;
    tv.setLote(lote);
    cout<<"INGRESE LA GAMA DEL TELEVISOR :"<<endl<<endl;
    cin>>gama;
    tv.setClase(gama);
    cout<<tv.toStringTelevision()<<endl<<endl;
    return 0;
}