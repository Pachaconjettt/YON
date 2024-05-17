#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
class Hora{
    private:
    int horas;
    int minutos;
    int segundos;
    public:
    Hora(int horas,int minutos,int segundos){
        this->horas = horas;
        this->minutos = minutos;
        this->segundos = segundos;
    }
    Hora(){
    horas = 0;
    minutos = 0;
    segundos = 0;
    }
    int getHoras(){
        return horas;
    }
    void setHoras(int h){
        horas = h;
    }
    int getMinutos(){
        return minutos;
    }
    void setMinutos(int m){
        minutos = m;
    }
    int getSegundos(){
        return segundos;
    }
    void setSegundos(int s){
        segundos = s;
    }
   string MuestraHora24hrs(){
    stringstream s;
    s<<setfill('0')<<setw(2)<<horas%24; 
    s<<":";
    s<<setfill('0')<<setw(2)<<minutos;
    s<<":";
    s<<setfill('0')<<setw(2)<<segundos;
    return s.str();  
   }
   string MuestraHora12hrs(){
    stringstream s;
    if(horas>12){
    s<<setfill('0')<<setw(2)<<horas-12;
    }else if(horas == 0){
    s<<12;
    }else{
    s<<setfill('0')<<setw(2)<<horas;  
    }
    s<<":";
    s<<setfill('0')<<setw(2)<<minutos;
    s<<":";
    s<<setfill('0')<<setw(2)<<segundos;
    if(horas >= 12){
        s << " P.M" <<endl; 
    }else{
        s << " A.M "<<endl;
        }
        return s.str();
    }
    void Avanza(){
    segundos++;
    if(segundos>59){
        segundos = 0;
        minutos ++;
    }if(minutos>59){
        minutos = 0;
        horas++;
    }
 }
 void Retroseco(){
    segundos--;
    if(segundos < 0){
        segundos = 59;
        minutos--;
    }if(minutos < 0){
        minutos = 59;
        horas--;
    }if(horas < 0) {
        horas = 23;
        }   
 }
 Hora esMayor(Hora otro){
    if(this->horas > otro.horas){
        return *this;
    }else if(this->horas < otro.horas){
        return otro;
    }else{
    }if (this->minutos > otro.minutos){
        return *this;
    }else if(this-> minutos <otro.minutos){
        return otro;
    }else{
    }if(this->segundos > otro.segundos){
        return *this;
    }else{
        return otro;
    }
 }
 void sumaHora(Hora otra){
    segundos += otra.segundos;
    if(segundos>59){
        minutos = segundos / 60;
        minutos = segundos % 60;
    }
    minutos += otra.minutos;
    if(minutos>59){
        horas = minutos / 60; 
        horas = minutos % 60;
    }
    horas += otra.horas;
    if(horas > 23){
        horas = horas % 24;
    }
 }
 void intercambia(Hora &otra){
    Hora temporal;
    temporal = otra;
    otra = *this;
    *this = temporal;
 }
};
int main(int argc, char const *argv[]){
Hora hr1;
Hora hr2(23,32,31);
int h,m,s,desea;
bool continuar;
do{
cout<<"\t\t\t\t~~~~~~~~INFORMACION HORA~~~~~~~~\t\t\t\t"<<endl<<endl<<endl;
cout<<"Ingrese la hora: ";
cin>>h;
hr1.setHoras(h);
cout<<"Ingrese los minutos: ";
cin>>m;
hr1.setMinutos(m);
cout<<"Ingrese los segundos: ";
cin>>s;
hr1.setSegundos(s);
cout<<endl<<endl;
cout<<"HORA EN FORMATO 24 Y 12 HORAS :"<<endl<<endl;
cout<<hr1.MuestraHora24hrs()<<endl<<endl;
cout<<hr1.MuestraHora12hrs()<<endl<<endl;
hr1.Avanza();
cout<<"HORA AVANZADA 1 SEGUNDO :"<<endl<<endl;
cout<<hr1.MuestraHora24hrs()<<endl<<endl;
hr1.Retroseco();
cout<<"HORA RETROCEDIDA 1 SEGUNDO :"<<endl<<endl;
cout<<hr1.MuestraHora12hrs()<<endl<<endl;
Hora mayor1 = hr1.esMayor(hr2);
cout<<"MAYOR ENTRE HORA 1 Y HORA 2 :"<<endl;
cout<<mayor1.MuestraHora12hrs()<<endl<<endl;
cout<<mayor1.MuestraHora24hrs()<<endl<<endl; 
hr1.sumaHora(hr2);
cout<<"HORA SUMADA ENTRE HORA 1 Y HORA 2 :"<<endl;
cout<<hr1.MuestraHora24hrs()<<endl<<endl;    
cout<<hr1.MuestraHora12hrs()<<endl<<endl;

cout<<hr1.MuestraHora24hrs()<<endl<<endl;
cout<<hr2.MuestraHora24hrs()<<endl<<endl;
hr1.intercambia(hr2);
cout<<"INTERCAMBIO DE VALORES ENTRE HORA 1 Y HORA 2 :"<<endl;
cout<<"HORA 1 :"<<hr1.MuestraHora24hrs()<<endl<<endl;
cout<<"HORA 2 :"<<hr2.MuestraHora24hrs()<<endl<<endl;
cout<<endl<<endl;
cout<<"Desea ingresar otra hora?(0:NO 1:SI)"<<endl;
cin>>desea;
continuar = desea == 1; 
}while(continuar);
    return 0;
}
