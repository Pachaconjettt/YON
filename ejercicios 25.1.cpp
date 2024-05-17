#include <iostream>
using namespace std;

int sumadivisores( int n ) {
	int suma = 0 ;
	for ( int i= 1 ; i <= n / 2  ; ++i) {
		if ( n % i == 0 ) {
			suma += i;
		}
	}
	return suma ;
}

int main(int argc, char *argv[]) {
	int yonpork ;
	
	cout<< " ingrese un numero entero : " ;
	cin>> yonpork ;
	
	int suma = sumadivisores(yonpork) ;
	
	cout << " el numero " << yonpork << ", sus divisores suman : " << suma << endl;
	return 0;
}

