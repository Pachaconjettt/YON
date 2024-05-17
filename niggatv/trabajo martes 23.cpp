#include <iostream>
using namespace std;

class AhorroPlazo { 
private:
    int capitalInicial;
    int plazo; 
    int tipoInteres;

public:
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
    double tasaInteres(){
        double tasaInteres;   
        double capital = capitalInicial;
        if(tipoInteres == 1 ){
            switch(plazo){
                case 1: tasaInteres = 0.08 ;break;
                case 2: tasaInteres = 0.08; break;
                case 3: tasaInteres = 0.10; break;
                case 4: tasaInteres = 0.12; break;
                case 5: tasaInteres = 0.14; break;
                case 6: tasaInteres = 0.15; break;
                default: tasaInteres = 0.0; break;
            }
            return capitalInicial * tasaInteres;
        } 
        else if (tipoInteres == 2){
            for( int i = 0; i < plazo; i++){
                switch(plazo){
                    case 1: tasaInteres = 0.08 ;break;
                    case 2: tasaInteres = 0.08; break;
                    case 3: tasaInteres = 0.10; break;
                    case 4: tasaInteres = 0.12; break;
                    case 5: tasaInteres = 0.14; break;
                    case 6: tasaInteres = 0.15; break;
                    default: tasaInteres = 0.0; break;
                }
                capital += capital * tasaInteres; // Corrección aquí
            }
            return capital - capitalInicial; 
        }
    }
};

int main(int argc, char const *argv[])
{
    AhorroPlazo num;
    int n, r;
cin>>n;
cin>>r;
num.setCapitalInicial(n);
cout <<num.getCapitalInicial()<<num.tasaInteres()<<endl;
    return 0;
}