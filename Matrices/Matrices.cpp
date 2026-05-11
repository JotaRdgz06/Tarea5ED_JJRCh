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
					do {
						cout << "Ingrese la fila: ";
						cin >> filaObtener;
						if (cin.fail() || filaObtener <= 0 || filaObtener > matriz->getRows()) {
							cout << "Error: Valor ingresado fuera de rango, ingrese un valor 1 y "
								<< matriz->getRows();
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (cin.fail() || filaObtener <= 0 || filaObtener > matriz->getRows());
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					do {
						cout << "Ingrese la columna: ";
						cin >> columnObtener;
						if (cin.fail() || columnObtener <= 0 || columnObtener > matriz->getColumns()) {
							cout << "Error: Valor ingresado fuera de rango, ingrese un valor 1 y "
								<< matriz->getColumns();
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (cin.fail() || columnObtener <= 0 || columnObtener > matriz->getColumns());
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << endl;
					cout << "El valor en la fila " << filaObtener << " y columna " << columnObtener << " es: ";
					cout << matriz->getValue(filaObtener - 1, columnObtener - 1);
					cout << endl;
					break;
				case 3:
					int filaBuscar, columnBuscar, valorInsert;
					do {
						cout << "Ingrese la fila: ";
						cin >> filaBuscar;
						if (cin.fail() || filaBuscar <= 0 || filaBuscar > matriz->getRows()) {
							cout << "Error: Ingrese un valor entre 1 y " << matriz->getRows() << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (cin.fail() || filaBuscar <= 0 || filaBuscar > matriz->getRows());
					do {
						cout << "Ingrese la columna: ";
						cin >> columnBuscar;
						if (cin.fail() || columnBuscar <= 0 || columnBuscar > matriz->getColumns()) {
							cout << "Error: Ingrese un valor entre 1 y " << matriz->getColumns() << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (cin.fail() || columnBuscar <= 0 || columnBuscar > matriz->getColumns());
					do {
						cout << "Ingrese el valor a insertar: ";
						cin >> valorInsert;
						if (cin.fail()) {
							cout << "Error: Ingrese un numero valido" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (cin.fail());
					matriz->setValue(filaBuscar - 1, columnBuscar - 1, valorInsert);
					cout << "Se ha insertado el valor " << valorInsert << " en la fila " << filaBuscar << " y columna " << columnBuscar << endl;
					break;
				case 4:
					cout << endl << "actualmente hay " << matriz->getRows() << " filas"
						<< endl << endl;
					break;
				case 5:
					cout << endl << "actualmente hay " << matriz->getColumns() << " columnas"
						<< endl << endl;
					break;
				case 6:
					int valorAll;
					do {
						cout << "Ingrese el valor a establecer en toda la matriz: ";
						cin >> valorAll;
						if (valorAll < 0) {
							cout << "Error: Ingrese un numero mayor o igual a 0" << endl;
						}
					} while (valorAll < 0);
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
					do {
						cout << "Ingrese el valor a establecer en la nueva fila: ";
						cin >> valorRow;
						if (valorRow < 0) {
							cout << "Error: Ingrese un valor mayor o igual a 0";
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (valorRow < 0);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					matriz->addRow(valorRow);
					cout << "Se ha añadido una nueva fila con el valor " << valorRow << endl;
					break;
				case 9:
					int valorColumn;
					do {
						cout << "Ingrese el valor a establecer en la nueva columna: ";
						cin >> valorColumn;
						if (valorColumn < 0) {
							cout << "Error: Ingrese un valor mayor o igual a 0";
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (valorColumn < 0);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					matriz->addColumn(valorColumn);
					cout << "Se ha añadido una nueva columna con el valor " << valorColumn << endl;
					cout << endl;
					break;
				case 10:
					int valorRemoveR;
					do {
						cout << "Ingrese el numero de la fila que desea eliminar entre 1 y " << matriz->getRows() << ": ";
						cin >> valorRemoveR;
						if (cin.fail() || valorRemoveR < 0 || valorRemoveR >= matriz->getRows()) {
							cout << "Error: Ingrese un valor mayor o igual a 0 y menor a " << matriz->getRows();
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (cin.fail() || valorRemoveR < 0 || valorRemoveR >= matriz->getRows());
					matriz->removeRow(valorRemoveR - 1);
					cout << "Se ha eliminado la fila " << valorRemoveR << endl << endl;
					break;
				case 11:
					int valorRemoveC;
					do {
						cout << "Ingrese el numero de la columna que desea eliminar entre 1 y " << matriz->getColumns() << ": ";
						cin >> valorRemoveC;
						if (cin.fail() || valorRemoveC < 0 || valorRemoveC >= matriz->getColumns()) {
							cout << "Error: Ingrese un valor mayor o igual a 0 y menor a " << matriz->getColumns();
							cout << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (cin.fail() || valorRemoveC < 0 || valorRemoveC >= matriz->getColumns());
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					matriz->removeColumn(valorRemoveC - 1);
					cout << "Se ha eliminado la columna " << valorRemoveC << endl;
					break;
				case 12:
					srand(time(0));
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