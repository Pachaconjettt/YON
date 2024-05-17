#include <iostream>
#include <sstream>
using namespace std;
class Estudiante{
private:
    string id;
    string name;
    int fechaNacimiento[3];
    int anoIngreso;
    int grupoEIF200;
    float calificaciones[20];
public:
    string getId(){
        return id;
    }
    void setId(string cedula){
        id = cedula;
    }
    string getName(){
        return name;
    }
    string setName(string nombre){
        name = nombre;
        return name;
    }
    int getFechaNacimiento(int diaMesAno){
        return fechaNacimiento[diaMesAno];
    }
    void setFechaNacimiento(int dia, int mes,int ano){
        fechaNacimiento[0] = dia;
        fechaNacimiento[1] = mes;
        fechaNacimiento[2] = ano;
    }
    int getAnoIngreso(){
        return anoIngreso;
    }
    void setAnoIngreso(int anoInicio){
        anoIngreso = anoInicio;
    }
    int getGrupoEIF200(){
        return grupoEIF200;
    }
    void setGrupoEIF200(int grupo){
        grupoEIF200 = grupo;
    }
    float getCalificaciones(int prueba){
        return calificaciones[prueba - 1];
    }
    void setCalificaciones(int prueba,float nota){
        calificaciones[prueba - 1] = nota;
    }
    float promedio3Calificaciones(){
        return (calificaciones[0]+calificaciones[1]+calificaciones[2])/ 3.0 ;
    }
    Estudiante(){
        id = "0000000000";
        name = "Desconocido";
        fechaNacimiento[0] = 0;
        fechaNacimiento[1] = 0;
        fechaNacimiento[2] = 0;
        anoIngreso = 0;
        grupoEIF200 = 0;
        for (int i=0;i<20;i++)
        calificaciones[i] = -1;
    }
    Estudiante(string cedula,string nombre,int diaN, int mesN, int anoN, int anoInicio, int grupo){
        id = cedula;
        name = nombre;
        fechaNacimiento[0] = diaN;
        fechaNacimiento[1] = mesN;
        fechaNacimiento[2] = anoN;
        anoIngreso = anoInicio;
        grupoEIF200 = grupo;
        for (int i=0;i<20;i++)
        calificaciones[i] = -1;
    }
    string mostrar(){
        stringstream s;
        s<<"Identificacion:"<<id<<endl;
        s<<"Nombre:"<< name <<endl;
        s<<"Fecha de Nacimiento:"<< fechaNacimiento[0]<< "/" << fechaNacimiento[1]<< "/"<< fechaNacimiento[3]<< endl;
        s<<"Año de Ingreso:"<< anoIngreso<< endl;
        s<<"Grupo:" << grupoEIF200<<endl;
        return s.str();

    }
    float promedio5Calificaciones(){
        return (calificaciones[0]+calificaciones[1]+calificaciones[2]+calificaciones[3]+calificaciones[4])/ 5.0 ;
    }
    float promedioCalificaciones(){
        int sumaCalifiaciones= 0;
        int calificacionesValidas = 0;
        for(int i = 0; i<=20;i++){
            sumaCalifiaciones += calificaciones[i];
            if (calificaciones[i]>0)
            calificacionesValidas++;
        }
        return sumaCalifiaciones/calificacionesValidas;
    }
    int getCalificacionesValidas(){
        int calificacionesValidas = 0;
        for(int i = 0; i<=20;i++){
            if(calificaciones[i]>0)
            calificacionesValidas++;
        }
        return calificacionesValidas;
    }
    bool aprobo(){
        bool pass = false;
        if(promedioCalificaciones() >= 7)
            pass = true;
        return pass;
    }
    bool apruebaConCurva10pct(){
        bool pass = false;
        int curva = (promedio5Calificaciones() * 0.1) +  promedioCalificaciones();
        if(curva>= 7)
            pass = true;
        return pass;
    }
    bool apruebaConCurva(int porcentaje){
        bool pass = false;
        int curva = (promedio5Calificaciones() * porcentaje) +  promedioCalificaciones();
        if(curva>= 7)
            pass = true;
        return pass;
    }
   string provinciaNacimiento (){
    char numero = id[1];
	if (numero == '1'){
		return "San Jose";}
	else 
        if (numero == '2'){
		return "Alajuela";}
	    else
            if (numero == '3'){
		        return "Cartago";}
	        else 
                if (numero == '4') {
		            return "Heredia";}
	            else 
                    if (numero == '5'){
		                return "Guanacaste";}
	                else 
                        if (numero == '6'){
		                    return "Puntarenas";}
	                    else 
                            if (numero == '7'){
		                        return "Limon";}
	                        else 
		                        return "Error";

    }
    int annosCumplidos(){
        int total=0;
        total += 2023-fechaNacimiento[2];
        if(fechaNacimiento[0] <= 14 && fechaNacimiento[1] <= 4)
            total += 1;
        return total;
    }
    ~Estudiante(){}
};


int main() {
Estudiante e1;
e1.setName("yon");
e1.setId("119770043");
e1.setFechaNacimiento(1,7,2003);
e1.setCalificaciones(1,8.35);
e1.setCalificaciones(2,9.46);
e1.setCalificaciones(3,9.05);

cout<<"Nombre del Estudiante: "<<e1.getName()<<endl;
cout<<"Numero de cedula: "<<e1.getId()<<endl;
cout<<"Promedio de calificaciones en las 3 primeras pruebas: "<<e1.promedio3Calificaciones()<<endl;
cout<<"El promedio de calificaciones es:"<< e1.promedioCalificaciones()<<endl;
if(!e1.aprobo())
    cout<<"El estudiante no aprobo."<<endl;
else
    cout<<"El estudiante aprobo."<<endl;

cout<<endl;

Estudiante e2("1123456789", "Jorge",14,8,2000, 2023, 3);
e2.setCalificaciones(1,9.35);
e2.setCalificaciones(2,8.46);
e2.setCalificaciones(3,7.05);
e2.setCalificaciones(4,8.05);
e2.setCalificaciones(5,9.08);

cout<< "Nombre del Estudiante:"<< e2.getName()<< endl;
cout<< "Numero de cedula:"<< e2.getId()<<endl;
cout<<"Promedio de las 5 primeras pruebas:"<< e2.promedio5Calificaciones()<<endl;
cout<<"El promedio de calificaciones es:"<< e2.promedioCalificaciones()<<endl;
if(!e2.aprobo())
    cout<<"El estudiante no aprobo."<<endl;
else
    cout<<"El estudiante aprobo."<<endl;
if(!e2.apruebaConCurva(0.15))
    cout<<"El estudiante no aprueba con la curva."<<endl;
else
    cout<<"El estudiante aprueba con la curva."<<endl;

cout<<endl;

if(e1.apruebaConCurva(0.08) && e2.apruebaConCurva(0.08)){
    cout<<"Ambos estudiante aprueban el curso."<<endl;}
else {
    if(!e1.apruebaConCurva(0.08) && !e2.apruebaConCurva(0.08)){
        cout<<"Ambos estudiante reprueban el curso."<<endl;}
    else {
        if(e1.apruebaConCurva(0.08) && !e2.apruebaConCurva(0.08)){
            cout<< e1.getName() << " Aprueba el curso."<< endl;
            cout<< e2.getName() << " Reprueba el curso" << endl;
        }
        else
            if(!e1.apruebaConCurva(0.08) && e2.apruebaConCurva(0.08)){
                cout<< e1.getName() << " Reprueba el curso"<< endl;
                cout<< e2.getName() << " Aprueba el curso."<< endl;
            }}}

cout<<endl;

cout<< e1.getName() << " nacio en:"<< e1.provinciaNacimiento()<<endl;
cout<< e2.getName() << " nacio en:"<< e2.provinciaNacimiento()<<endl;

cout<<endl;

cout<< e1.getName() << " tiene una edad de "<< e1.annosCumplidos()<<" anos"<<endl;
cout<< e2.getName() << " tiene una edad de "<< e2.annosCumplidos()<<" anos"<<endl;

cout<<endl;

if(e1.annosCumplidos()>e2.annosCumplidos())
    cout<< e1.getName() << " es el mayor." << endl;
else
    cout<< e2.getName() << " es el mayor." << endl;
	return 0;
}