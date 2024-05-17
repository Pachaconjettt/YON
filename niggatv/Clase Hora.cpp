#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Hora{
    private:
    int horas, minutos, segundos;

    public:
    Hora(int horas, int minutos, int segundos){
        this -> horas = horas;
        this -> minutos = minutos;
        this -> segundos = segundos;
    }
    Hora(){
        horas = 0;
        minutos = 0;
        segundos = 0;
    }
    ~Hora(){

    }

    int getHoras(){
        return horas;
    }
    void setHoras(int emma){
        horas = emma;
    }
    int getMinutos(){
        return minutos;
    }
    void setMinutos(int dario){
        minutos = dario;
    }
    int getSegundos(){
        return segundos;
    }
    void setSegundos(int kaleb){
        segundos = kaleb;
    }

    string muestraHora24Hrs(){
        stringstream s;
        s << setfill('0') << setw(2) << horas;
        s << ":";
        s << setfill('0') << setw(2) << minutos;
        s << ":";
        s << setfill('0') << setw(2) << segundos;
        return s.str();
    }

    string muestraHora12Hrs(){
        stringstream s;
        if (horas > 12){
            s << setfill('0') << setw(2) << horas - 12;
        } else if (horas == 0){
            s << 12;
        }else {
            s << setfill('0') << setw(2) << horas;
        }
        s << ":";
        s << setfill('0') << setw(2) << minutos;
        s << ":";
        s << setfill('0') << setw(2) << segundos;
        if (horas >= 12)
            s << " P.M.";
        else 
            s << " A.M.";
        return s.str();
    }

    //Agregue un 12 horas pero sin usar ningún if
    
    void avanza(){
        segundos ++;
        if (segundos > 59){
            minutos ++;
            segundos = 0;
        }
        if (minutos > 59){
            horas ++;
            minutos = 0;
        }
        if (horas > 23){
            horas = 0;
        }
    }

    void retrocede(){
        segundos --;
        if (segundos < 0){
            segundos = 59;
            minutos --;
        }
        if (minutos < 0){
            minutos = 59;
            horas --;
        }
        if (horas < 0){
            horas = 23;
        }
    }

    Hora mayor(Hora otra) {
        if (horas > otra.horas) {
            return *this;
        } else if (horas < otra.horas) {
            return otra;
        } else {
            if (minutos > otra.minutos) {
                return *this;
            } else if (minutos < otra.minutos) {
                return otra;
            } else {
                if (segundos > otra.segundos) {
                    return *this;
                } else {
                    return otra;
                }
            }
        }
    }

    void sumaHoras(Hora otra){
        segundos += otra.segundos;
    
        if (segundos > 59){
            minutos += segundos / 60;
            segundos = segundos % 60;
        }
    
        minutos += otra.minutos;
        if (minutos > 59){
            horas += minutos / 60;
            minutos = minutos % 60;
        }
    
        horas += otra.horas;
        if (horas > 23){
            horas = horas % 24;
        }
    }

    void intercambia(Hora& otra){
        Hora temp = otra;
        otra = *this;
        *this = temp;
    }
};

int main(int argc, char *argv[]) {
    Hora hora1(13,45,56);
    Hora hora2(14,16,20);

    cout << "Hora 1:" << endl;
    cout << hora1.muestraHora12Hrs() << endl << endl;
    cout << hora1.muestraHora24Hrs() << endl << endl;

    cout << "Hora 2:" << endl;
    cout << hora2.muestraHora12Hrs() << endl << endl;
    cout << hora2.muestraHora24Hrs() << endl << endl;

    hora1.avanza();
    cout << "Hora 1:" << endl;
    cout << hora1.muestraHora24Hrs() << endl << endl;

    hora2.retrocede();
    cout << "Hora 2:" << endl;
    cout << hora2.muestraHora12Hrs() << endl << endl;

    Hora mayor1 = hora1.mayor(hora2);
    cout << "Mayor entre hora1 y hora2:" << endl;
    cout << mayor1.muestraHora12Hrs() << endl << endl;
    cout << mayor1.muestraHora24Hrs() << endl << endl;

    hora1.sumaHoras(hora2);
    cout << "Hora 1:" << endl;
    cout << hora1.muestraHora12Hrs() << endl << endl;
    cout << hora1.muestraHora24Hrs() << endl << endl;

    hora1.intercambia(hora2);
    cout << "Hora 1:" << endl;
    cout << hora1.muestraHora24Hrs() << endl << endl;
    cout << "Hora 2:" << endl;
    cout << hora2.muestraHora12Hrs() << endl << endl;

    return 0;
}