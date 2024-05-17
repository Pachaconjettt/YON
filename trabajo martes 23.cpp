#include <iostream>
#include <sstream>
using namespace std;

class AhorroPlazo { 
private:
    int capitalInicial;
    int plazo; 
    int tipoInteres;

public:
  AhorroPlazo(){
        capitalInicial = 0;
        plazo = 0;
        tipoInteres = 0;
    }
    AhorroPlazo(float capital, int plazo, int interes){
        capitalInicial = capital;
        this->plazo = plazo;
        tipoInteres = interes;
    }
    int getCapitalInicial(){
        return capitalInicial;
    }
    void setCapitalInicial(int n){
        capitalInicial = n;
    }
    int getPlazo(){
        return plazo;
    }
    void setPlazo(int s){
        plazo = s;
    }
    int getTipoInteres(){
        return tipoInteres;
    }
    void setTipoInteres(int r){
        tipoInteres = r;
    }
    string toString(){
        stringstream s;
        s << "Capital inicial : " << capitalInicial <<endl;
        s << "plazo : " << plazo <<endl;
        s << "tipo de interes : " ;
        if (tipoInteres == 1){
            s << "simple" <<endl;
        }else{
            s << "compuesto" <<endl;
        }
        return s.str();
    }
    double tasaInteres(){
        double tasaInteres;   
            switch(plazo){
        case 1: tasaInteres = 0.08 ;break;
        case 2: tasaInteres = 0.09; break;
        case 3: tasaInteres = 0.10; break;
        case 4: tasaInteres = 0.12; break;
        case 5: tasaInteres = 0.14; break;
        case 6: tasaInteres = 0.15; break;
        default: tasaInteres = 0.0; break;
         
            }
            return tasaInteres ; 
    }
    float montoInteres(){
        float capital;
        if (tipoInteres == 1){
            return capitalInicial * tasaInteres();
        }
        else if (tipoInteres == 2){
            capital = 0;
            for (int i = 0; i < plazo ; i++){ 
                capital += (capitalInicial + capital) * tasaInteres();
            }
            return capital; 
        }
        return 0; 
    }
    int calcularMontoFinal (){
        int capital;
        if (tipoInteres == 1){
            return capitalInicial + montoInteres(); 
        }
        else if (tipoInteres == 2 ){
      return capitalInicial + montoInteres ();
        }   
    }   
};

int main() {
     AhorroPlazo ah1(100000,5,2);
    AhorroPlazo ah2;
    float n;
    int s, r;
cout<<"Ingresa el capital que tienes : " <<endl;
    cin >> n;
    cout<<"Ingrese el plazo que tuvo *de 1 a 6 annos maximo* : "<<endl;
    cin >> s;
    cout<<"Ingrese el tipo de interes que desea usar, el 1 o el 2?" <<endl;
    cin >> r;
    ah2.setCapitalInicial(n);
    ah2.setPlazo(s);
    ah2.setTipoInteres(r);

    cout << "Datos de la inversion 1: " << endl;
    cout << ah1.toString();
    cout << "Total a retirar: " << ah1.calcularMontoFinal() <<" "<< endl;

    cout << "Datos de la inversion 2: " << endl;
    cout << ah2.toString();
    cout << "Total a retirar: " << ah2.calcularMontoFinal() << " "<< endl;

if ( ah1.getCapitalInicial() == ah2.getCapitalInicial () && ah1.getPlazo() == ah2.getPlazo()){
    if (ah1.calcularMontoFinal() > ah2.calcularMontoFinal()){
        cout <<  "la inversion 1 es mayor que la 2" << endl;
    }else{
        cout<<" la inversion 2 es mayot que la 1" << endl;
}
}
    return 0;
}