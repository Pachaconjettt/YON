#include <iostream>
using namespace std;

int main() {
	cout << "\t\t\t\t\tFiguras en C++\n";
	
	int filas;
	cout << "\nIngrese el numero de filas de la figura: ";
	cin >> filas;
	
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < filas; j++) {
			if (i == 0 || j == 0 || i == filas - 1 || j == filas - 1) {
				cout << "* ";
			} else {
				cout << "  "; 
			}
		}
		cout << endl;
	}
	return 0;
}

