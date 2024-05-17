#include <iostream> 
#include <sstream>
using namespace std;
class Vehiculo{
    private:
    int annio;
    int precioinicial;
    bool gps;
    int VIN;
    public:
    Vehiculo(int annio, int precioinicial, bool gps, int VIN){
        this->annio = annio;
        this->precioinicial = precioinicial;
        this->gps = gps;
        this->VIN = VIN;
    }
    int getAnnio(){
        return annio;
    }
    void setAnnio(int a){
        annio = a;
    }
    int getPrecioInicial(){
        return precioinicial;
    }
    void setPrecioInicial(int p){
        precioinicial = p;
    }
    bool getGPS(){
        return gps;
    }
    void setGPS(bool gps2){
        gps = gps2;
    }
    int getVIN(){
        return VIN;
    }
    void setVIN(int v){
        VIN = v;
    }
    string toString(){
        stringstream s;
        s<<"Annio "<<annio<<endl;
        s<<"Precio Inicial "<<precioinicial<<endl;
        s<<"Tiene gps(1:SI 0:NO) "<<gps<<endl;
        s<<"VIN "<<VIN<<endl;
        return s.str();
    }
    float AumentoGPS(){
        float gpsextra;
        if(gps == 1){
            gpsextra = precioinicial * 0.05;
        }else{
            gpsextra = 0;
        }
    return gpsextra;
    }
    float esDepreciacion(){
        float depren;
        if(annio < 2020){
            depren = precioinicial * 0.20;
        }
        else if(annio <= 2022){
            depren = precioinicial * 0.10;
        }
        else if(annio <= 2023){
            depren = precioinicial * 0.05;
        }else{
            depren = 0;
        }
        return depren;
    }
    float esSumaPrecio(){
        float sumayonpork;
        sumayonpork =(precioinicial + AumentoGPS())-esDepreciacion();
        return sumayonpork;
    }
    int escontinente(){
    int UltimoDigito;
    for (int i=0;i<VIN;i++){
        VIN = VIN % 10;
        UltimoDigito = VIN / 10;
    }
    switch (UltimoDigito){
        case 1:cout<<"America ";break;
        case 2:cout<<"Africa ";break;
        case 3:cout<<"Oceania ";break;
        case 4:cout<<"Asia ";break;
        case 5:cout<<"Europa ";break;
        default:cout<<"No existe"<<endl;
    }
    return UltimoDigito;
    }
    bool EsVerdadero(){
        int PrimerDigito;
        int DigitoSumas;
        VIN = VIN % 10;
        PrimerDigito = VIN /10;
        bool funciona;
        funciona = true;
        for(int i=1;i<VIN;i++){
            VIN = VIN % 10;
            DigitoSumas = VIN / 10;
            DigitoSumas += DigitoSumas;
        }
        DigitoSumas = DigitoSumas % 10;
        if(DigitoSumas == PrimerDigito){
            funciona = true;
        }else{
            funciona = false;
        }
        return funciona;
    }
    Vehiculo copia(Vehiculo copia2){
        Vehiculo copia = *this;
        return copia;
    }
    Vehiculo cambio(Vehiculo otro,Vehiculo temp){
        temp = *this;
        *this = otro;
        otro = temp;
    }
};
int main(int argc, char const *argv[])
{
    Vehiculo v1(2021,200000,1,1234567);
    Vehiculo v2(2023,300000,0,1234578);
    cout<<v1.toString()<<endl;
    cout<<v1.AumentoGPS()<<endl;
    cout<<v1.esDepreciacion()<<endl;
    cout<<v1.esSumaPrecio()<<endl;
    v1.cambio(v1);
    cout<<v1.toString()<<endl;
    cout<<v2.toString()<<endl;
    return 0;
}
