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

    for (int i = 0; i < matriz->getRows(); i++) {
        for (int j = 0; j < matriz->getColumns(); j++) {
            cout << matriz->getValue(i, j) << "\t";
        }
        cout << endl;
	}

    matriz->transpose();

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 0; i < matriz->getRows(); i++) {
        for (int j = 0; j < matriz->getColumns(); j++) {
            cout << matriz->getValue(i, j) << "\t";
        }
        cout << endl;
    }


	delete matriz;

    return 0;
}