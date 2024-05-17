#include <iostream>
#include <sstream>
using namespace std;
class Coleccion { 
    protected: 
string nombre[40];
int tamano;
int cantidad;
public: 
Coleccion(){
    cantidad = 0;
    tamano = 40;
    for (int i=0; i<tamano; i++){
        nombre[i] = " ";
     }
}
Coleccion(int n){
    cantidad = 0;
    tamano = n; 
    for (int i=0; i<tamano; i++)
    nombre[i]=" ";
}
~Coleccion(){}
string getNombre(int i){
    return nombre[i];
}
void setNombre(int i,string n){
    nombre[i] = n;
}
void AgregarElemento(string elem){
    if (cantidad < tamano){
        nombre [cantidad] = elem;
        cantidad += 1;
    }
}
string ToString(){
    stringstream s;
    for(int i=0;i<cantidad;i++){
        s<<"Personaje "<<i+1<<":";
        s<<nombre[i]<<endl;
    }
     return s.str();
}
string ConcatenaElementos(){
string hilera = "|";
for(int i=0;i<cantidad;i++)
hilera += nombre[i] + "|";
return hilera;
}
string Acrostico(){
    string acrostico = "";
    for(int i = 0; i < cantidad;i++){
        if(!nombre[i].empty()){
            acrostico += nombre[i][0];

        }
    }
    return acrostico;
}
string aMayusculas(string str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    return str;
}
void ConvertirNombresAMayusculas() {
    for (int i = 0; i < cantidad; i++)
        nombre[i] = aMayusculas(nombre[i]);
}
void AgregarColeccion(const Coleccion& otra) {
    for (int i = 0; i < otra.cantidad; i++) {
        AgregarElemento(otra.nombre[i]);
    }
}
};
class Coleccion2 : public Coleccion { 
    public:
    Coleccion2(int n) : Coleccion(n) {
    }   
};
int main(int argc, char const *argv[])
{
int desea;
bool continuar;
do{
/*
cout<<"\t\t\t\tEJEMPLO PROFE\t\t\t\t"<<endl;
Coleccion avengers(7);
avengers.AgregarElemento("Thanos");
avengers.AgregarElemento("Iron Man");
avengers.AgregarElemento("Captain America");
avengers.AgregarElemento("Thor");
cout<<avengers.getNombre(2)<<endl;
avengers.setNombre(2,"Tio conejo");
cout<<avengers.getNombre(2)<<endl;
cout<<avengers.ToString();
cout<<avengers.ConcatenaElementos()<<endl<<endl;
*/
cout<<"\t\t\t\tINTERFAZ USUARIO\t\t\t\t"<<endl<<endl;
cout<<"Cantidad de personajes que desea ingresar :";
int cuantos;
cin>>cuantos;
cin.ignore();
Coleccion avengers(cuantos);
for(int i=0; i<cuantos; i++){
cout<<"Ingrese el nombre del personaje "<<(i + 1)<<" : ";
string personaje;
getline(cin,personaje);
avengers.AgregarElemento(personaje);
Coleccion avengersMayusculas = avengers;
avengersMayusculas.ConvertirNombresAMayusculas();
cout <<avengersMayusculas.ToString()<<endl;
}
cout<<endl; 
cout<<avengers.ToString()<<endl;
cout<<avengers.ConcatenaElementos()<<endl<<endl;
cout<<avengers.Acrostico()<<endl<<endl<<endl;

cout<<"\t\t\t\tCOLECCION STAR WARS\t\t\t\t"<<endl<<endl;
cout<<"cantidad de personajes que desea ingresar : "<<endl;
int cuantos2;
cin>>cuantos2;
cin.ignore();
Coleccion2 StarWars(cuantos2);
for(int i=0; i<cuantos2; i++){
    cout<<"Ingrese el nombre del personaje "<<(i + 1)<<" : ";
    string personaje;
    getline (cin,personaje);
    StarWars.AgregarElemento(personaje);
    }
    cout<<endl;
    cout<<StarWars.ToString()<<endl;
    cout<<StarWars.ConcatenaElementos()<<endl;
    cout<<StarWars.Acrostico()<<endl<<endl;
    Coleccion avengersMayusculas = avengers;  
    avengersMayusculas.AgregarColeccion(StarWars); 
    cout << avengersMayusculas.ToString() << endl;  
cout<<endl<<endl;
cout<<"Desea continuar? presione 2 para no y 1 para si"<<endl;
cin>>desea;
continuar = desea == 1;
}while(continuar);
    return 0;
}
h