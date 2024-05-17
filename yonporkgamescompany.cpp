#include <iostream>
using namespace std;
class CuentaBancaria { 
private :
int valor; 
int cliente;
float saldo;
float interesA;
int deposito;
public:
int getValor(){
return valor;
}
void setValor(int n){
    valor = n;
}
int getCliente(){
    return cliente;
}
void setCliente(int clientem){
 cliente = clientem;
}
float getSaldo(){
    return saldo;
}
void setSaldo(float saldomain){
    saldo = saldomain;
}
int esDepositar(){
deposito = deposito + saldo; 

}
};



int main(int argc, char const *argv[])
{
int n , clientem, deposito;
float saldomain;
  int menupork = 0;
  cout << "Ingrese un numero : " ;
  cin>>menupork;

  while(menupork != 7){
        cout << "\n\n\n\t\t\t\tMENU BANCO";
        cout<<"\n\n\n[1]-Crear Cuenta ";
        cout<<"\n\n\n[2]-Ver detalle de cuenta ";
        cout<<"\n\n\n[3]-Ver saldo ";
        cout<<"\n\n\n[4]-Depositar ";
        cout<<"\n\n\n[5]-Retirar ";
        cout<<"\n\n\n[6]-Calcular intereses ";
        cout<<"\n\n\n[7]-Salir";

    cout << "\nIngresa una opcion : ";
    cin>> menupork;
    switch(menupork){
        case 1:
        cout << "\n\n\nIngresa tu nombre y tus ganancias : ";break;
        case 2:
        cout << "\n\n\nTu detalle de la cuenta : ";break;
        case 3:
        cout << " \n\n\nTu saldo es de :  ";break;
        case 4:
        cout << " \n\n\nVas a depositar : ";break;
        case 5:
        cout << " \n\n\nVas a retirar : ";break;
        case 6:
        cout << " \n\n\nTu interes anual es de :  ";break;
        case 7:
        cout<< "\n\n\nSalio del programa con exito  ";break;
        default :
        cout << "\n\n\nIngreso una opcion equivocada  ";break;
    }
  }         

    return 0;
}
