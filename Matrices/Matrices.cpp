#include <iostream>
#include <stdexcept>
#include <string>
#include <random>
#include "Matrix.h"

using std::cout;
using std::endl;
using std::runtime_error;
using std::string;
using std::getline;
using std::stoi;
using std::cin;

string menuOpciones() {
	string result;
	result = "Elija una de las opciones: \n\n";
	result += "1. Mostrar el contendio de la matriz\n";
	result += "2. Obtener valor\n";
	result += "3. Establecer valor\n";
	result += "4. Obtener fila\n";
	result += "5. Obtener columna\n";
	result += "6. Establecer todas\n";
	result += "7. Transponer matriz\n";
	result += "8. Añadir fila\n";
	result += "9. Añadir columna\n";
	result += "10. Eliminar fila\n";
	result += "11. Eliminar columna\n";
	result += "12. Llenar aleatorio\n";
	result += "13. Salir\n";
	return result;
}

int main() {
	setlocale(LC_ALL, "es_ES.UTF-8");
	try {
		int filas, columnas;
		cout << "Ingrese la cantidad de filas: ";
		cin >> filas;

		if (filas <= 0) {
			throw runtime_error("La cantidad de filas debe ser un numero positivo");
		}

		cout << "Ingrese la cantidad de columnas: ";
		cin >> columnas;

		if (columnas <= 0) {
			throw runtime_error("La cantidad de columnas debe ser un numero positivo");
		}

		cout << endl;

		Matrix<int>* matriz = new Matrix<int>(filas, columnas);

		for (int i = 0; i < matriz->getRows(); i++) {
			for (int j = 0; j < matriz->getColumns(); j++) {
				matriz->setValue(i, j, 0);
			}
		}

		int opcion;
		do {
			cout << menuOpciones() << endl;
			cout << "Ingrese su opcion: ";
			cin >> opcion;
			if (opcion < 1 || opcion > 13) {
				throw runtime_error("Opcion invalida, intente de nuevo");
				cin.clear();
			}
			try {
				switch (opcion) {
				case 1:
					matriz->print();
					break;
				case 2:
					int filaObtener, columnObtener;
					cout << "Ingrese la fila: ";
					cin >> filaObtener;
					cout << "Ingrese la columna: ";
					cin >> columnObtener;
					cout << matriz->getValue(filaObtener - 1, columnObtener - 1);
					break;
				case 3:
					int filaBuscar, columnBuscar, valorInsert;
					cout << "Ingrese la fila: ";
					cin >> filaBuscar;
					cout << "Ingrese la columna: ";
					cin >> columnBuscar;
					cout << "Ingrese el valor a insertar: ";
					cin >> valorInsert;
					matriz->setValue(filaBuscar - 1, columnBuscar - 1, valorInsert);
					break;
				case 4:
					matriz->getRows();
					break;
				case 5:
					matriz->getColumns();
					break;
				case 6:
					int valorAll;
					cout << "Ingrese el valor a establecer en toda la matriz: ";
					cin >> valorAll;
					matriz->setAll(valorAll);
					break;
				case 7:
					matriz->transpose();
					break;
				case 8:
					int valorRow;
					cout << "Ingrese el valor a establecer en la nueva fila: ";
					cin >> valorRow;
					matriz->addRow(valorRow);
					break;
				case 9:
					int valorColumn;
					cout << "Ingrese el valor a establecer en la nueva columna: ";
					cin >> valorColumn;
					matriz->addColumn(valorColumn);
					break;
				case 10:
					int valorRemoveR;
					cout << "Ingrese el numero de la fila que desea eliminar: ";
					cin >> valorRemoveR;
					matriz->removeRow(valorRemoveR - 1);
					break;
				case 11:
					int valorRemoveC;
					cout << "Ingrese el numero de la columna que desea eliminar: ";
					cin >> valorRemoveC;
					matriz->removeColumn(valorRemoveC - 1);
					break;
				case 12:
					for (int i = 0; i < matriz->getRows(); i++) {
						for (int j = 0; j < matriz->getColumns(); j++) {
							matriz->setValue(i, j, rand() % 100);
						}
					}
					break;
				}
			}
			catch (runtime_error& e) {
				cout << "Error: " << e.what() << endl;
			}
		} while (opcion != 13);

		delete matriz;
	}catch (runtime_error& e) {
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}