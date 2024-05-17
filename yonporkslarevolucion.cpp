#include <iostream>
using namespace std;

const float pi = 3.1415;
class Contaminacion{
    private:
    float altura;
    float radio;
    float pesoOriginal;
    float pesoSeco;
    public:
    Contaminacion(float altura, float radio, float pesoOriginal, float pesoSeco){
    this->altura = altura;
    this->radio = radio;
    this->pesoOriginal = pesoOriginal;
    this->pesoSeco = pesoSeco;
    }
    Contaminacion(){
        altura = 0;
        radio = 0;
        pesoOriginal = 0;
        pesoSeco = 0;
    }
    ~Contaminacion(){

    }
    float getAltura(){
        return altura;
    }
    void setAltura(int a){
        altura = a;
    }
    float getRadio(){
        return radio;
    }
    void setRadio(float r){
        radio = r;
    }
    float getPesoOriginal(){
        return pesoOriginal;
    }
    void setPesoOriginal(float po){
        pesoOriginal = po;
    }
    float getPesoSeco(){
        return pesoSeco;
    }
    void setPesoSeco(float ps){
        pesoSeco = ps;
    }
    float VolumenTronco(){
        float volumen;
        volumen = pi * radio*radio*altura;
        return volumen;
    }
    float ContenidoHumedad(){
        float ContenidoH;
        ContenidoH = (pesoOriginal - pesoSeco * 100 )/ pesoSeco;
        return ContenidoH;
    }
    Contaminacion Igual(Contaminacion copia){
        copia = *this;
        return copia;
    }
    Contaminacion cambio(Contaminacion temp, Contaminacion otro){
        temp = *this;
        otro = temp;
        temp = otro;
    }
};
int main(int argc, char const *argv[])
{
Contaminacion conta1(50,1,1000,8);
Contaminacion conta2 ; 
float a,r,po,ps;
cout<<"El volumen del tronco es de :"<<conta1.VolumenTronco()<<endl<<endl;
cout<<"Contenido Humedad :"<<conta1.ContenidoHumedad()<<""<<"%"<<endl<<endl;
cout<<endl<<endl;
cout<<"Ingrese valor de altura :"<<endl;
cin>>a;
conta2.setAltura(a);
cout<<"Ingrese valor de radio :"<<endl;
cin>>r;
conta2.setRadio(r);
cout<<"Ingrese valor de peso original :"<<endl;
cin>>po;
conta2.setPesoOriginal(po);
cout<<"Ingrese el valor de peso seco :"<<endl;
cin>>ps;
conta2.setPesoSeco(ps);
cout<<"El volumen del tronco es de :"<<conta2.VolumenTronco()<<endl<<endl;
cout<<"Contenido Humedad :"<<conta2.ContenidoHumedad()<<""<<"%"<<endl<<endl;
conta1.Igual(conta2);
    return 0;
}

