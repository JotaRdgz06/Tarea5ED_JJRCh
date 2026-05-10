#include <iostream>
#include "Matrix.h"

using std::cout;
using std::endl;

int main() {
    Matrix<int>* matriz = new Matrix<int>(2, 5);

    for (int i = 0; i < matriz->getRows(); i++) {
        for (int j = 0; j < matriz->getColumns(); j++) {
            matriz->setValue(i, j, i + j);
        }
    }

    matriz->print();

    cout << endl;

    matriz->transpose();

    matriz->print();

    cout << endl;

    matriz->removeRow(0);

    matriz->print();

	cout << endl;

	matriz->removeColumn(0);

	matriz->print();

    delete matriz;
    return 0;
}