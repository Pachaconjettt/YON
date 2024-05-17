#include <iostream>
#define mesActual 5
#define diaActual 12
using namespace std;

class ComeBien {
    private:
    string nombre;
    int dia;
    int mes;
    float cantidad;
    float costopxk;
    float temperatura;
    int anaquel;
    public : 
    string getNombre(){
        return nombre;
    }
    void setNombre(string name){
        nombre = name;
    }   
    int getDia(){
        return dia;
    }
    void setDia(int d){
        dia = d;
    }
    int getMes(){
       return mes; 
    }
    void setMes(int m){
        mes = m;
    }
    float getCantidad(){
        return cantidad;
    }
    void setCantidad(float c){
        cantidad = c;
    }
    float getCostoPorKilo(){
        return costopxk;
    }
    void setCostoPorKilo(float cpk){
        costopxk = cpk;
    }
    float getTemperatura(){
        return temperatura;
    }
    void setTemperatura(float t){
        temperatura = t;
    }
    int getAnaquel(){
        return anaquel;
    }
    void setAnaquel(int ana){
        anaquel = ana;
    }
    bool FueradeUso(){
        bool desuso = false;
    if(mes <= mesActual){
        if((mesActual - 1)*30+diaActual - (mes-1)*30+dia >= 90) 
        desuso = true;
    }else
    if((mes-1)*30+diaActual+360 - (mes-1)*30+dia >= 90)
    desuso = true;
    return desuso;
    }
    bool Anaquelft(int anaquelActual , float temperaturaActual){
        bool seDebeEliminar  = FueradeUso();
        if(anaquel != anaquelActual && temperaturaActual >= temperatura)
            seDebeEliminar = true;
            return seDebeEliminar;
        }
        float precioventa
};