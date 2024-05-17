#include <iostream>
using namespace std;

class Numero{
private:
int valor;

public:
    Numero(){
        valor = 0;
    }
    Numero(int n){
        valor = n;
    }
    ~Numero(){

    }
    void setValor(int n){
        valor = n;
    }
    int getValor(){
        return valor;
    }
    bool getCondicion(){
         return (valor%2 == 0);
    }
    int cambiaSigno(){
        return -valor;
    }
    bool binario() {
    int temp = valor;
    int digito;
    while (temp > 0) {
        digito = temp % 10;
        if (digito != 0 && digito != 1)
            return false;
        temp = temp / 10;
    }
    return true;
}

    
    bool monotono(){
        int digito1, digito2, digito;
        int temp = valor;
        digito1 = valor%10;
        temp = temp/10;
        while (temp > 0){
            digito = temp%10;
            temp = temp/10;
            if(digito != digito1){
                digito2 = digito;
            break;}
            else{
                return true;
            }
        }
        temp = valor;
        while(temp > 0){
            digito = temp%10;
            if(digito != digito1 && digito != digito2){
            return false;
            }
            temp = temp/10;
         
    }
    return true;
}
    bool monotonoEstricto(){
        int digito1,digito;
        digito1 = valor % 10;
        int temp = valor;
        if(monotono()){
        for(int i = 0; temp > 0;i++){
        digito = temp % 10;
        if(digito != digito1){
            return true;
        }
        temp = temp/10;
        }
        }
        else 
        return false;
return false;
}
    bool igual(Numero otro) {
    return (valor == otro.getValor());
}
Numero opuesto(){
    Numero new1 = -valor;
    cout<< "El valor de el opuesto es :"<< new1.getValor()<<endl;
    return new1;
}

Numero suma (Numero otro){
    Numero new1 = valor + otro.getValor();
    cout<< "El valor de la suma es :"<< new1.getValor()<<endl;
    return new1;
}
Numero mayor(Numero otro){
    if(valor > otro.getValor()){
        cout<< "El mayor es:"<< valor<<endl;
        return *this;}
    else
        if(otro.getValor()> valor){
            cout<< "El mayor es:"<< otro.getValor()<<endl;
            return otro;}
        else{
            if(otro.getValor() == valor)
            cout<< "Los numeros son iguales"<<endl;
            return *this;}
}
void arimetica (Numero &suma, Numero &resta, Numero &Multi, Numero &Divi, Numero otro){
    suma = otro.getValor() + valor;
    resta = otro.getValor() - valor;
    Multi = otro.getValor() * valor;
    Divi = otro.getValor() / valor;
}
void mayorMenor(Numero &mayor,Numero &menor, Numero otro){
    if(valor > otro.getValor()){
        mayor = *this;
        menor = otro;
    }
        else
            if(valor< otro.getValor())
            {
                mayor = otro;
                menor = *this;
            }
    }
void intercambiar(Numero otro){
    Numero aux;
    aux = *this;
    *this = otro;
    otro = aux;
}
};
int main(){

int n = 1212;
Numero num1;
num1.setValor(n);

cout<<num1.getValor()<<endl;
if(num1.getCondicion() == true){
    cout<<"Es un Numero Par\n";
}else{
    cout<<"Es un Numero Impar\n";
}
cout<<num1.cambiaSigno()<<endl;

if(!num1.binario())
    cout<< "No es binario"<< endl;
else 
    cout<< "Es binario"<< endl;

if(num1.monotono()){
    cout<<"Es monotono\n";
}else{
    cout<<"No es Monotono\n";
}
if(!num1.monotonoEstricto())
    cout<< "No es monotono estricto"<< endl;
else 
    cout<< "Es monotono estricto"<< endl;

int x = 1214;
Numero num2;

num2.setValor(x);

cout<<num2.getValor()<<"\n";
if(!num1.igual(num2)){
    cout<<"No son iguales\n";
}
else{
    cout<<"Son iguales\n";
}

num1.opuesto();

num1.suma(num2);

num1.mayor(num2);
Numero suma,resta,Multi,Divi;
num1.arimetica(suma,resta,Multi,Divi,num2);
cout<< suma.getValor()<<endl;
cout<< resta.getValor()<<endl;
cout<< Multi.getValor()<<endl;
cout<< Divi.getValor()<<endl;

Numero mayor,menor;
num1.mayorMenor(mayor,menor,num2);
cout<<"El mayor es:" << mayor.getValor()<<endl;
cout<< "El menor es:"<<menor.getValor()<<endl;


return 0;
}