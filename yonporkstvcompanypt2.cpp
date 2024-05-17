#include <iostream>
#include <sstream>
using namespace std;

class Emprendimiento{
    private: 
    int salario;
    int horas;
    int cedula;
    string empleado;
    char incentivo;
    public: 
    Emprendimiento(int salario,int horas, int cedula , string empleado, char incentivo ){
        this->salario = salario;
        this-> horas = horas;
        this-> cedula = cedula;
        this -> empleado = empleado;
        this -> incentivo = incentivo;
    }
    Emprendimiento(){
        salario = 6000;
        horas = 0;
        cedula = 0;
        empleado = " ";
        incentivo = ' ';
    }
    int getSalario(){
        return salario;
    }
    void setSalario(int plata){
        salario = plata;
    }
    int getHoras(){
        return horas;
    }
    void setHoras(int horascr){
        horas = horascr;
    }
    int getCedula(){
        return cedula;
    }
    void setCedula(int id){
        cedula = id;
    }
    string getEmpleado(){
        return empleado;
    }
    void setEmpleado(string chambero){
        empleado = chambero;
    }
    char getIncentivo(){
        return incentivo;
    }
    void setIncentivo(char ince){
        incentivo = ince;
    }
    int SalarioBruto(){
        return horas * salario;
    }
    double esIncentivo(){
    float incentivopapu;
    incentivopapu = SalarioBruto();
     switch(incentivo){
        case 'e': return incentivopapu * 0.05;break;
        case 'b': return incentivopapu * 0.03;break;
        case 'r': return incentivopapu * 0.01;break;
        case 'p': return 0 ;break;
        default : cout <<"ERROR DE SELECCION "<<endl;
     }
    }
    float DeduccionCCSS(){
        return SalarioBruto() * 0.28;
    }
    float esSalarioNeto(){
        return SalarioBruto() + esIncentivo() - DeduccionCCSS();
    }
    string ToString(){
    stringstream s;
    s<<"\t\t\t\t******INFORMACION EMPLEADO******"<<endl<<endl; 
    s<<"\tEMPLEADO :"<<getEmpleado()<<endl<<endl;
    s<<"\tCEDULA :"<<getCedula()<<endl<<endl;
    s<<"\tHORAS TRABAJADAS :"<<getHoras()<<endl<<endl;
    s<<"\tSALARIO BASE :"<<getSalario()<<endl<<endl;
    s<<"\tSALARIO BRUTO :"<<SalarioBruto()<<endl<<endl;
    s<<"\tINCENTIVO :"<<esIncentivo()<<endl<<endl;
    s<<"\tDEDUCCION DEL CCSS :"<<DeduccionCCSS()<<endl<<endl;
    s<<"\tSALARIO NETO :"<<esSalarioNeto()<<endl<<endl;
    return s.str();
 }
};
int main(int argc, char const *argv[])
{
Emprendimiento empr1(6000,80,113880873,"Johnatan",'e');
Emprendimiento sinpr;
int horascr,plata,id;
string chambero;
char ince;
cout<<"INGRESE SU NOMBRE :"<<endl<<endl;
cin>>chambero;
sinpr.setEmpleado(chambero);
cout<<"INGRESE SU CEDULA :"<<endl<<endl;
cin>>id;
sinpr.setCedula(id);
cout<<"INGRESE LAS HORAS TRABAJADAS :"<<endl<<endl;
cin>>horascr;
sinpr.setHoras(horascr);
cout<<"INGRESE SU SALARIO BASE :"<<endl<<endl;
cin>>plata; 
sinpr.setSalario(plata);
cout<<"INGRESE EL NIVEL DE INCENTIVO QUE LE HAN DADO :";
cin>>ince;
sinpr.setIncentivo(ince);
cout<<sinpr.ToString()<<endl<<endl;
cout<<empr1.ToString()<<endl<<endl;
    return 0;
}
