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
		int getValor(){
			return valor;
		}
			void setValor(int n){
				valor = n;
			}
				~Numero(){
				}
				
				bool esPar(){
					return valor % 2 == 0;
				}
					
					void cambiaSigno(){
						valor = -valor;
					}
						
						bool binario(){
							int numero = valor, digito;
							bool esBinario = true;
							while(numero > 0 && esBinario){
								digito = numero%10;
								numero/=10;
								esBinario = digito == 1 || digito == 0;
							}
							return esBinario;		
						}
							
							bool monotono(){
								int digito, digitoUno, digitoDos = -1;
								int numero = valor;
								bool esMonotono = true;
								digitoUno = numero%10;
								numero/=10;
								while(numero > 0 && esMonotono){
									digito = numero%10;
									numero/=10;
									if(digito != digitoUno && digitoDos == -1)
										digitoDos = digito;
									esMonotono = digito == digitoUno || digito == digitoDos;
								}
								return esMonotono;		
							}
								
								bool monotonoEstricto(){
									int n = valor;
									bool esMonotono = true;
									int digito, primero, segundo = -1;
									primero = n%10;
									n/=10;
									while(n > 0 && esMonotono){
										digito = n%10;
										if(digito != primero && segundo == -1)
											segundo = digito;
										if(digito != primero && digito != segundo)
											esMonotono = false;
										n/=10;
									}
									esMonotono = esMonotono && segundo != -1;
									return esMonotono;
								}
									
									Numero opuesto(){
										Numero opuestoAditivo;
										opuestoAditivo.valor = -valor;
										return opuestoAditivo;
									}
										
										bool igualV0(Numero elOtro){
											if(valor == elOtro.valor)
												return true;
											else
												return false;
										}
											bool igual(Numero elOtro){
												return valor == elOtro.valor;
											}
												bool igualV1(Numero elOtro){
													return valor == elOtro.getValor();
												}
													bool igualV2(Numero elOtro){
														return this->valor == elOtro.getValor();
													}
														
														Numero suma(Numero elOtro){
															Numero laSuma;
															laSuma.valor = valor + elOtro.valor;
															return laSuma;
														}
															Numero mayor(Numero elOtro){
																if(valor > elOtro.valor)
																	return *this; //devuelve el objeto propio
																else
																	return elOtro;
															}
																
																void mayorMenor(Numero elOtro, Numero &mayor, Numero &menor){
																	if(valor > elOtro.valor){
																		mayor.valor = valor;
																		menor.valor = elOtro.valor;
																	}else{
																		mayor.valor = elOtro.valor;
																		menor.valor = valor;
																	}			
																}
																	
																	void mayorMenorV1(Numero elOtro, Numero &mayor, Numero &menor){
																		if(valor > elOtro.valor){
																			mayor = *this;
																			menor = elOtro;
																		}else{
																			mayor = elOtro;
																			menor = *this;
																		}			
																	}
																		
																		void aritmeticas(Numero elOtro, Numero &suma, Numero &resta, Numero &multiplicacion, Numero &division){
																			suma.valor = valor + elOtro.valor;
																			resta.valor = valor - elOtro.valor;
																			multiplicacion.valor = valor * elOtro.valor;
																			division.valor = valor / elOtro.valor;
																		}			
																			
																			void intercambiaV0(Numero &elOtro){
																				int temporal;
																				temporal = valor;
																				valor = elOtro.valor;
																				elOtro.valor = temporal;
																			}
																				void intercambia(Numero &elOtro){
																					Numero temporal;
																					temporal = *this;
																					*this = elOtro;
																					elOtro= temporal;
																				}
};

int main(int argc, char *argv[]) {
	
	Numero numero1, elMayor, elMenor;
	Numero laSuma,laResta, laMultiplicacion, laDivision;
	cout<<"valor: "<<numero1.getValor()<<endl<<endl;
	numero1.setValor(7);
	cout<<"valor: "<<numero1.getValor()<<endl;
	cout<<"Par: "<<numero1.esPar()<<endl;
	numero1.cambiaSigno();
	cout<<"Le cambia el signo: "<<numero1.getValor()<<endl<<endl;
	numero1.setValor(2222);
	cout<<"valor: "<<numero1.getValor()<<endl;
	cout<<"Binario: "<<numero1.binario()<<endl;
	cout<<"Mon?tono: "<<numero1.monotono()<<endl;
	cout<<"Mon?tono Estricto: "<<numero1.monotonoEstricto()<<endl<<endl;
	numero1.setValor(11010);
	cout<<"valor: "<<numero1.getValor()<<endl;
	cout<<"Binario: "<<numero1.binario()<<endl;
	cout<<"Mon?tono: "<<numero1.monotono()<<endl;
	cout<<"Mon?tono Estricto: "<<numero1.monotonoEstricto()<<endl<<endl;
	
	Numero numero2(5);
	cout<<"numero2.valor: "<<numero2.getValor()<<endl;
	cout<<"Par: "<<numero2.esPar()<<endl;
	cout<<"Opuesto del numero2: "<<numero2.opuesto().getValor()<<endl<<endl;
	
	cout<<"N?mero 1: "<<numero1.getValor()<<endl;
	numero2.setValor(120);
	cout<<"N?mero 2: "<<numero2.getValor()<<endl;
	cout<<"Los n?meros son iguales: "<<numero1.igual(numero2)<<endl;
	cout<<"Los n?meros son iguales: "<<numero2.igual(numero1)<<endl;
	cout<<"Suma: "<<numero1.suma(numero2).getValor()<<endl;
	cout<<"Mayor: "<<numero1.mayor(numero2).getValor()<<endl<<endl;
	numero1.mayorMenor(numero2, elMayor, elMenor);
	cout<<"El Mayor: "<<elMayor.getValor()<<endl<<"El Menor: "<<elMenor.getValor()<<endl<<endl;
	numero1.mayorMenorV1(numero2, elMayor, elMenor);
	cout<<"El Mayor: "<<elMayor.getValor()<<endl<<"El Menor: "<<elMenor.getValor()<<endl<<endl;
	
	cout<<"numero1.valor: "<<numero1.getValor()<<endl;	
	cout<<"numero2.valor: "<<numero2.getValor()<<endl;
	numero1.intercambia(numero2);
	cout<<"numero1.intercambia(numero2);"<<endl;
	cout<<"numero1.valor: "<<numero1.getValor()<<endl;	
	cout<<"numero2.valor: "<<numero2.getValor()<<endl<<endl;
	
	numero1.setValor(6);
	numero2.setValor(2);
	numero1.aritmeticas(numero2,laSuma,laResta, laMultiplicacion, laDivision);
	cout<<"Operando 1: "<<numero1.getValor()<<endl;
	cout<<"Operando 2: "<<numero2.getValor()<<endl;
	cout<<"Suma: "<<laSuma.getValor()<<endl;
	cout<<"Resta: "<<laResta.getValor()<<endl;
	cout<<"Multiplicacion: "<<laMultiplicacion.getValor()<<endl;
	cout<<"Division: "<<laDivision.getValor()<<endl<<endl;
	
	numero2.aritmeticas(numero1,laSuma,laResta, laMultiplicacion, laDivision);
	cout<<"Operando 1: "<<numero2.getValor()<<endl;
	cout<<"Operando 2: "<<numero1.getValor()<<endl;
	cout<<"Suma: "<<laSuma.getValor()<<endl;
	cout<<"Resta: "<<laResta.getValor()<<endl;
	cout<<"Multiplicacion: "<<laMultiplicacion.getValor()<<endl;
	cout<<"Division: "<<laDivision.getValor()<<endl;
	
	return 0;
}
