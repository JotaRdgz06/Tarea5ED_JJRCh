#include <iostream>
#include <stdexcept>
#include <string>
#include "Matrix.h"

using std::cout;
using std::endl;
using std::runtime_error;
using std::string;
using std::getline;
using std::stoi;
using std::cin;

int main() {
	int filas, columnas;
    cout << "Ingrese la cantidad de filas: ";
    cin >> filas;

	cout << "Ingrese la cantidad de columnas: ";
	cin >> columnas;

    Matrix<int>* matriz = new Matrix<int>(filas,columnas);

    for (int i = 0; i < matriz->getRows(); i++) {
        for (int j = 0; j < matriz->getColumns(); j++) {
            matriz->setValue(i, j, 0);
        }
    }

	int opcion;
	do {
		menuOpciones();
		cout << "Ingrese su opcion: ";
		cin >> opcion;
	} while (opcion != 13);

    delete matriz;
    return 0;
}

string menuOpciones() {
	cout << "Elija una de las opciones: " << endl;
    cout << endl;
	cout << "1. Mostrar el contendio de la matriz" << endl;
	cout << "2. Obtener valor" << endl;
	cout << "3. Establecer valor" << endl;
	cout << "4. Obtener fila" << endl;
    cout << "5. Obtener columna" << endl;
	cout << "6. Establecer todas" << endl;
	cout << "7. Transponer matriz" << endl;
	cout << "8. Añadir fila" << endl;
	cout << "9. Añadir columna" << endl;
	cout << "10. Eliminar fila" << endl;
	cout << "11. Eliminar columna" << endl;
	cout << "12. Llenar aleatorio" << endl;
	cout << "13. Salir" << endl;
	cout << endl;
}