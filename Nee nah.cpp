#include <iostream>
using namespace std;

class Numero { 
private:
    int valor;
public:
    Numero() {
        valor = 0;
    }
    Numero(int n){
        valor = n;
    }
    int getValor(){
        return valor;
    }
    void setValor(int n){
        valor = n;
    }
    bool esPar(){
        return valor % 2 == 0;
    }
    int cambiaSigno(){
        valor = valor * -1;
        return valor;
    }
    bool esBinario(){
        int numero = valor , digito ; 
        bool esBinario = true;
        while ( numero > 0 && esBinario) {
            digito = numero % 10 ;
            numero /= 10;
            esBinario = digito == 1 || digito == 0;
        }
        return esBinario;
    }
    bool esMonotono() {
        int digito, digitoUno, digitoDos = -1 ;
        int numero = valor; 
        bool esMonotono = true;
        digitoUno = numero % 10;
        numero /= 10;
        while (numero > 0 && esMonotono){
            digito = numero % 10;
            numero /=10;
           } if (digito != digitoUno && digitoDos == -1) { 
        digitoDos = digito ; 
        esMonotono = digito == digitoUno  || digito == digitoDos ;
        
            }
            return esMonotono; 
        }
         bool esMonotonoEstricto() {
        int digito, digitoUno, digitoDos = -1 ;
        int numero = valor ; 
        bool esMonotonoEstricto = true;
        digitoUno = numero % 10;
        numero /= 10;
        while (numero > 0 && esMonotonoEstricto){
            digito = numero % 10;
            numero /= 10;
           } if (digito = digitoUno && digitoDos == -1) { 
        digitoDos == digito ; 
        esMonotonoEstricto = digito == digitoUno  && digito == digitoDos ;
    }
    return esMonotonoEstricto;
         }
         bool esIgual(Numero elOtro){
            return this -> valor == elOtro.getValor(); 
         }
         int opuesto(){
            return this -> valor = valor * -1;
         }
    int esSuma(Numero elOtro){
        return this->valor = valor + elOtro.getValor();
    }
    int esMayor(Numero elOtro){
        if(this->valor > elOtro.getValor()){
        return this->valor;
        }else{
            return elOtro.getValor();
        
        
        }
    }
    int esMayorMenor(Numero elOtro, Numero &mayor, Numero &menor){
        if(this->valor > elOtro.getValor()){
        mayor.valor = this->valor;
        menor.valor = elOtro.getValor();
        }else{
     mayor.valor = elOtro.getValor();
     menor.valor = this->valor; 
        }
        
    }
  	void esAritmetica(Numero elOtro, Numero &suma, Numero &resta, Numero &multiplicacion, Numero &division){
		suma.valor = valor + elOtro.valor;
		resta.valor = valor - elOtro.valor;
		multiplicacion.valor = valor * elOtro.valor;
		division.valor = valor / elOtro.valor;
    }
    int esIntercambio(Numero elOtro){
return this->valor = elOtro.valor;
    }
};

int main() {
    Numero num;
    Numero num1, num2, mayor , menor;
    Numero suma , resta , multiplicacion, division ;

    int n;
    int r;
    cout<<" Digite un numero : " <<endl;
    cin >> n; 
    num.setValor(n);
    cout << num.getValor() << " " << (num.esPar() ? "es par" : "no es par") << endl;
    cout <<"el numero con cambio de signo es : "<< num.cambiaSigno() << endl;
     cout << "Digite un numero : "<<endl;
    cin >> n;
    num.setValor(n);
    cout << " Es binario? " << (num.esBinario() ? " Es binario" : "No es binario ") << endl;

cout<<"digite un numero : " << endl;
cin >>n;
num.setValor(n);
cout<< " Es monotono? " << (num.esMonotono()? "Es monotono" : "No es monotono") << endl;
cout<< "Es monotono estricto? " << (num.esMonotonoEstricto() ? "Es monotono estricto" : " No es monotono estricto") << endl;

cout<<"Digite 2 numero : " <<endl;
cin>>n;
cin>>r;
num1.setValor(n);
num2.setValor(r);
cout<<"Los numeros son iguales?  " <<(num1.esIgual(num2)?"Es igual" : "No es igual") <<endl;
cout<< "Los numeros son iguales? " << (num2.esIgual(num1)?"Es igual" : "No es igual") <<endl;

cout<<"Digite un numero : "<<endl;
cin>>n;
num.setValor(n);
cout<<"El valor opuesto es : " << num.opuesto() << endl; 

cout<<"Digite 2 Numeros" <<endl;
cin>>n; 
cin>>r;
num1.setValor(n);
num2.setValor(r);
cout << "La suma de los digitos es: " <<num1.esSuma(num2)<<endl; 

cout<<"Digite 2 Numeros : " <<endl;
cin>>n; 
cin>>r;
num1.setValor(n);
num2.setValor(r);
cout<<"El numero mayor es : "<<num1.esMayor(num2)<<endl;

cout<<"Digite 2 Numeros : " <<endl;
cin>>n; 
cin>>r;
num1.setValor(n);
num2.setValor(r);
num1.esMayorMenor(num2,mayor,menor);
cout<<" El mayor es :" << mayor.getValor() <<" El menor es : "<< menor.getValor() <<endl;

cout<<"Digite 2 Numeros : " <<endl;
cin>>n; 
cin>>r;
num1.setValor(n);
num2.setValor(r);
num1.esAritmetica(num2, suma , resta, multiplicacion , division );
cout<<" La suma de los 2 numeros :" << suma.getValor() <<" La resta : "<< resta.getValor()<< "La multiplicacion : "<< multiplicacion.getValor()<< "La division : "<< division.getValor() <<endl;
cout<<"los digitos : " << num1.getValor() << " " <<"Y"<< " " << num2.getValor() << "se intercambian y es :" <<endl;
num1.esIntercambio(num2);
cout<<"El intercambio queda asi :  "<<endl;
cout<<num1.getValor()<<endl;
cout<<num2.getValor()<<endl;
    return 0;
}