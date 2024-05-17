#include <iostream>
#include <sstream>
#define salarioHora 6000;
using namespace std;

class Empleado{
    private:
    string nombre;
    int cedula;
    char categoria;
    int horas;

    public:

    Empleado(){
        nombre = "";
        cedula = 0;
        categoria = ' ';
        horas = 0;
    }
    Empleado(string n, int ced, char c, int h){
        nombre = n;
        cedula = ced;
        categoria = c;
        horas = h;
    }

    ~Empleado(){
    }

    string getNombre(){
        return nombre; 
    }
    void setNombre(string n){
        nombre = n;
    }
    int getCedula(){
        return cedula;
    }
    void setCedula(int c){
        cedula = c;
    }
    char getCategoria(){
        return categoria;
    }
    void setCategoria(char c){
        categoria = c;
    }
    int getHoras(){
        return horas;
    }
    void setHoras(int h){
        horas = h;
    }

    string toString(){
        stringstream s;
        s << "Información de este empleado: " << endl;
        s << "Nombre: " << nombre << endl;
        s << "Cedula: " << cedula << endl;
        s << "Categoria: " << categoria << endl;
        s << "Horas: " << horas << endl;
        s << endl;
        s << "Incentivo: " << incentivo() << endl;
        s << "Deducción CCSS: " << deduccionCCSS() << endl;
        s << "Salario Bruto: " << salarioBruto() << endl;
        s << "Salario Neto: " << salarioNeto() << endl;

        return s.str();
    }

    float incentivo(){
        switch (categoria){
            case 'e':
                return 0.05;
                break;
            case 'b':
                return 0.03;
                break;
            case 'r':
                return 0.01;
                break;
            default:
                return 0;
        }
    }

    float deduccionCCSS(){
        return salarioBruto() * 0.28;
    }

    float salarioBruto(){
        return horas * salarioHora;
    }

    float salarioNeto(){
        return salarioBruto() + (salarioBruto() * incentivo()) - deduccionCCSS();
    }
};

int main(int argc, char *argv[]) {
    

    bool corriendo = true;
    while (corriendo){
        system("cls");
        cout << "Bienvenido al programa de empleados." << endl;
        cout << "1- Ingresar un empleado." << endl;
        cout << "2- Salir." << endl;
        cout << "Su seleccion: ";

        int opcion;
        cin >> opcion;

        Empleado e;
        string nombre;
        int cedula;
        char categoria;
        int horas;

        switch (opcion){
            case 1:
                cout << "Digite el nombre del empleado: ";
                cin >> nombre;
                e.setNombre(nombre);
                cout << "Digite la cedula del empleado: ";
                cin >> cedula;
                e.setCedula(cedula);
                cout << "Digite la categoria del empleado (e: excelente, b: bueno, r: regular, p: prueba): ";
                cin >> categoria;
                e.setCategoria(categoria);
                cout << "Digite las horas trabajadas por el empleado: ";
                cin >> horas;
                e.setHoras(horas);
                cout << e.toString();
                system("pause");
                break;
            case 2:
                corriendo = false;
                break;
            default:
                cout << "Opcion no valida." << endl;
                system("pause");
        }
    }
    return 0;
}