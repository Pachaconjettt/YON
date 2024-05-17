#include <iostream>
#include <sstream>
using namespace std;
class Envio{
    private:
    string nombre;
    int peso;
    char cliente;
    char tipoenvio;
    public:
    Envio(int peso, char cliente, char tipoenvio,string nombre){
        this->peso = peso;
        this->cliente = cliente;
        this->tipoenvio = tipoenvio;
        this->nombre = nombre;
    }
    Envio(){
        nombre="";
        peso = 0;
        cliente =' ';
        tipoenvio = ' ';

    }
    ~Envio(){
    }
    string muestraLogo(){
		stringstream s;
		s<<"****************************************"<<endl;
		s<<"*                                      *"<<endl;
		s<<"*    Sitio de Comercio Electronico     *"<<endl;
		s<<"*                                      *"<<endl;
		s<<"****************************************"<<endl<<endl;
		return s.str();
	}
    string getNombre(){
        return nombre;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    int getPeso(){
        return peso;
    }
    void setPeso(int p){
        peso = p;
    }
    char getCliente(){
        return cliente;
    }
    void setCliente(char c){
        cliente = c;
    }
    char getTipoEnvio(){
        return tipoenvio;
    }
    void setTipoEnvio(char t){
        tipoenvio = t;
    }
    int esPrecio(){
        int money;
        money = 0;
        if(peso<500){
            money = 1;
        }
        if (peso>=500 && peso<1000){
            money = 2;
        }
        if (peso>=1000 && peso<=2000){
            money = 5;
        }
        if (peso > 2000 ){
            money = 20;
        }
        return money;
    }
    float esEnvios(){
        int viaje;
        viaje = esPrecio();
        switch (tipoenvio){
       case 'N':return 0;break;
        case 'I':return viaje * 0.30;break;
        default:
        cout<<"OPCION INGRESADA ES INCORRECTA "<<endl;
        }
    }
    float esDescuento(){
        int Descuento;
        Descuento = esPrecio();
        switch (cliente){
        case 'E':return Descuento * 0.07;break;
        case 'G':return Descuento * 0.05;break;
        case 'F':return 0;
        default:
        cout<<"INGRESO UNA OPCION INCORRECTA "<<endl;
        }
    }
    float esIVA(){
        int precioiva;
        precioiva = esPrecio();
        switch (cliente){
        case 'F':return precioiva*0.15;break;
        case 'E':return precioiva*0.15;break;
        case 'G':return 0;break;
        }
    }
    float esAduana(){
        int precioadu;
        precioadu = esPrecio();
        switch (tipoenvio){
            case 'N':return 0;break;
            case 'I':return precioadu * 0.10;break;
        }
    }
    float EsMontoTotal(){
        return esPrecio()+esEnvios()+esIVA()+esAduana()-esDescuento();
    }
    string ToString(){
        stringstream s;
        s<<"\t\t\t\t~~~~~~INFORMACION PEDIDO~~~~~~"<<endl<<endl;
        s<<"NOMBRE DEL CLIENTE: "<<getNombre()<<endl<<endl;
        s<<"TIPO CLIENTE: "<<getCliente()<<endl<<endl;
        s<<"PESO DE ENVIO (GRAMOS): "<<getPeso()<<endl<<endl;
        s<<"TIPO DE ENVIO(NACIONAL,INTERNACIONAL):"<<getTipoEnvio()<<endl<<endl;
        s<<"PRECIO BASE DEL ENVIO: "<<esPrecio()<<"$"<<endl<<endl;
        s<<"PRECIO DEL ENVIO: "<<esEnvios()<<"$"<<endl<<endl;
        s<<"DESCUENTO DEL ENVIO: "<<esDescuento()<<"$"<<endl<<endl;
        s<<"IVA: "<<esIVA()<<"$"<<endl<<endl;
        s<<"ADUANA: "<<esAduana()<<"$"<<endl<<endl;
        s<<"MONTO TOTAL: "<<EsMontoTotal()<<"$"<<endl<<endl;
        return s.str();
    }
};
int main(int argc, char const *argv[])
{
string nombre;
int p,desea;
char c, t;
bool continuar;
Envio yon;
do{ 
system("CLS");
cout<<yon.muestraLogo();
cout<<"INGRESE SU NOMBRE :";
cin>>nombre;
yon.setNombre(nombre);
cout<<"INGRESE EL PESO DE SU ENVIO:";
cin>>p;
yon.setPeso(p);
cout<<"INGRESE QUE TIPO DE CLIENTE ES: ('G': Institucion del Gobierno., 'F': Persona Fisica., 'E': Organizacion Ecologista.) ";
cin>>c;
yon.setCliente(c);
cout<<"INGRESE EL TIPO DE ENVIO QUE QUIERE HACER: ('N' : Nacional, 'I': Internacional) ";
cin>>t;
yon.setTipoEnvio(t);
system("CLS");
cout<<yon.ToString()<<endl<<endl;
cout<<"DESEA HACER OTRO PEDIDO?(1: Si, 0: No) "<<endl;
cin>>desea;
continuar = desea == 1;
}while(continuar);  
return 0;
}
