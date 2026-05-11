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
using std::numeric_limits;
using std::streamsize;

string menuOpciones() {
	string result;
	result = "Elija una de las opciones: \n\n";
	result += "1. Mostrar el contendio de la matriz\n";
	result += "2. Obtener valor\n";
	result += "3. Establecer valor\n";
	result += "4. Obtener filas\n";
	result += "5. Obtener columnas\n";
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
	int filas, columnas;
	try {
		do {
			cout << "Ingrese la cantidad de filas: ";
			cin >> filas;

			if (filas <= 0) {
				cout << "Error: La cantidad de filas debe ser un numero positivo" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (filas <= 0);

		do {
			cout << "Ingrese la cantidad de columnas: ";
			cin >> columnas;

			if (columnas <= 0) {
				cout << "La cantidad de columnas debe ser un numero positivo" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (columnas <= 0);
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
				cout << "Error: Opcion invalida, intente de nuevo" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			try {
				switch (opcion) {
				case 1:
					matriz->print();
					cout << endl;
					break;
				case 2:
					int filaObtener, columnObtener;
					cout << "Ingrese la fila: ";
					cin >> filaObtener;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Ingrese la columna: ";
					cin >> columnObtener;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << endl;
					cout << "El valor en la fila " << filaObtener << " y columna " << columnObtener << " es: ";
					cout << matriz->getValue(filaObtener - 1, columnObtener - 1);
					cout << endl;
					break;
				case 3:
					int filaBuscar, columnBuscar, valorInsert;
					cout << "Ingrese la fila: ";
					cin >> filaBuscar;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Ingrese la columna: ";
					cin >> columnBuscar;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Ingrese el valor a insertar: ";
					cin >> valorInsert;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					matriz->setValue(filaBuscar - 1, columnBuscar - 1, valorInsert);
					cout << "Se ha insertado el valor " << valorInsert << " en la fila " << filaBuscar << " y columna " << columnBuscar << endl;
					break;
				case 4:
					cout << "actualmente hay " << matriz->getRows() << "filas";
					break;
				case 5:
					cout << "actualmente hay " << matriz->getColumns() << "columnas";
					break;
				case 6:
					int valorAll;
					cout << "Ingrese el valor a establecer en toda la matriz: ";
					cin >> valorAll;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					matriz->setAll(valorAll);
					cout << "Se ha establecido el valor " << valorAll << " en toda la matriz" << endl;
					break;
				case 7:
					matriz->transpose();
					cout << "Matriz transpuesta:" << endl;
					matriz->print();
					cout << endl;
					break;
				case 8:
					cout << endl;
					int valorRow;
					cout << "Ingrese el valor a establecer en la nueva fila: ";
					cin >> valorRow;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					matriz->addRow(valorRow);
					cout << "Se ha añadido una nueva fila con el valor " << valorRow << endl;
					break;
				case 9:
					int valorColumn;
					cout << "Ingrese el valor a establecer en la nueva columna: ";
					cin >> valorColumn;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					matriz->addColumn(valorColumn);
					cout << "Se ha añadido una nueva columna con el valor " << valorColumn << endl;
					cout << endl;
					break;
				case 10:
					int valorRemoveR;
					cout << "Ingrese el numero de la fila que desea eliminar: ";
					cin >> valorRemoveR;
					matriz->removeRow(valorRemoveR - 1);
					cout << "Se ha eliminado la fila " << valorRemoveR << endl << endl;
					break;
				case 11:
					int valorRemoveC;
					cout << "Ingrese el numero de la columna que desea eliminar: ";
					cin >> valorRemoveC;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					matriz->removeColumn(valorRemoveC - 1);
					cout << "Se ha eliminado la columna " << valorRemoveC << endl;
					break;
				case 12:
					for (int i = 0; i < matriz->getRows(); i++) {
						for (int j = 0; j < matriz->getColumns(); j++) {
							matriz->setValue(i, j, rand() % 100);
						}
					}
					cout << "Matriz llenada con valores aleatorios:" << endl;
					matriz->print();
					cout << endl;
					break;
				}
			}
			catch (runtime_error& e) {
				cout << "Error: " << e.what() << endl;
			}
		} while (opcion != 13);

		delete matriz;
	}
	catch (runtime_error& e) {
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}