#include <iostream>
#include <sstream> 
#define maximo 30
using namespace std;
class Coleccion{
    private:
    int vector[maximo];
    int cantidad; 
    int tamano;
    public:
    Coleccion(int n){
        cantidad = 0;
        tamano = n;
        for ( int i=0;i < tamano ; i++){
        vector[i] = 0;
        }
    }
    
    Coleccion(){
         cantidad = 0;
        tamano = 40;
        for (int i = 0; i < tamano ; i++){
        vector[i] = 0;
        }
    }
    ~Coleccion(){} 
    int getVector(int i){
        return vector[i];
    }
    void setVector(int i, int valorV){
        vector[i] = valorV;
        cantidad ++;
    }
    int getCantidad(){
        return cantidad;
    }
    void setCantidad(int c){
        cantidad = c;
    }
    int getTamano(){
        return tamano;
    }
    void setTamano(int t){
        tamano = t;
    }
    string toString(){
        stringstream s; 
        s<<"|";
        for(int i = 0; i < cantidad ; i++){
        s<< vector[i] << "|";
        }
        return s.str();
    }
    void agregarElemento(int elem){
        if(cantidad < tamano){
            vector[cantidad] = elem;
            cantidad = cantidad + 1;
        }
    }
    int sumaPosicionesPares(){
        int suma; 
        suma = 0;
        for(int i = 0; i < cantidad ; i++){
            if(i%2==0){
                suma += vector[i];
            }
        }
        return suma;
    }
    float promedioPosicionesImpares(){
        double posicion = 0;
        double contador = 0;
        for(int i = 0; i < cantidad ; i++){
        float yonporkgames = i%2;
        if(i%2 == 1){
            posicion += vector[i];
            contador++;
            contador = posicion / contador; 
         }
        }
        return contador;
    }
    int busca(int buscan){
        for(int i = 0; i < cantidad;i++){
        if(buscan == vector[i]){
            return i;       
        } 
        }
        return -1;
        }
    int aparicionesDe(int valor){
        int apariciones = 0;
        for(int i = 0; i < cantidad; i++){
            if (vector[i] == valor){
            apariciones++;
        
        }
        }
        return apariciones++;
        }
        void intercambia(Coleccion &otro){
           Coleccion temp = *this;
            *this = otro;
            otro = temp;
        }
        void intercambiaPosiciones(int pos1, int pos2){
        if(pos1 < cantidad && pos2 < cantidad){
        int temp = vector[pos1];
        vector[pos1] = vector[pos2];
        vector[pos2] = temp;      
        }
        }
        void eliminePosicion(int pos){
            if(pos < cantidad){
            for(int i = pos; i < cantidad - 1; i ++){
                vector[i] = vector [i + 1];
                    }
                    cantidad--;
                }   
            }
};
int main(int argc, char const *argv[])
{
bool continuar;
int desea,cuantos,elementos,busca,yon,cuantos2,elementos2,pos1, pos2,lista;
do{ 
    cout<<"Ingrese cuantos numeros quiere ingresar :"; 
    cin>>cuantos;
    Coleccion nu(cuantos);
    cout<<endl;
    for(int i=0; i<cuantos; i++){
    cout<<"Ingrese numeros"<<i+1<<":";
    cin>> elementos;
    nu.agregarElemento(elementos);
    }
    cout<<nu.toString()<<endl;
    cout<<"Suma de posiciones impares :"<<endl;
    cout<<nu.sumaPosicionesPares()<<endl;
    cout<<"El promedio de la suma de los numeros impares :"<<endl;
    cout<<nu.promedioPosicionesImpares()<<endl;
    cout<<"Ingrese el numero que quiere buscar en el array :"<<endl;
    cin>>busca;
    cout<<nu.busca(busca)<<endl;
    cout<<"Ingrese el numero que quiere saber cuantas veces aparece ."<<endl;
    cin>>yon;
    cout<<nu.aparicionesDe(yon)<<endl;
    cout<<"Ingrese el valor que quiere cambiar de la lista"<<endl;
    cin>>pos1;
    cout<<"Ingrese el valor donde lo quiere remplazar"<<endl;
    cin>>pos2;
    cout<<"Lista modificada :"<<endl;
    nu.intercambiaPosiciones(pos1,pos2);
    cout<<nu.toString()<<endl;
    cout<<"Ingrese el numero en la lista que desea eliminar"<<endl;
    cin>>lista;
    nu.eliminePosicion(lista);
    cout<<"Lista nueva"<<endl;
    cout<<nu.toString()<<endl;
    cout<<endl;
    cout<<"COLECCION DIFERENTE :"<<endl;
    cout<<"Ingrese cuantos numeros quiere ingresar :"; 
    cin>>cuantos2;
    Coleccion nu2(cuantos2);
    cout<<endl;
    for(int i=0; i<cuantos2; i++){
    cout<<"Ingrese numeros"<<i+1<<":";
    cin>> elementos2;
    nu2.agregarElemento(elementos2);
    }
    cout<<"listas originales :"<<endl;
    cout<<nu.toString()<<endl;
    cout<<nu2.toString()<<endl;
    nu.intercambia(nu2);
    cout<<"Listas intercambiadas :"<<endl;
    cout<<nu.toString()<<endl;
    cout<<nu2.toString()<<endl;
    cout<<endl<<endl;
    cout<<"Desea continuar (1:SI OTRO NUMERO : NO)";
    cin>>desea;
    continuar = desea == 1;
}while(continuar);
    return 0;
}
