#pragma once

#include <stdexcept>
#include <iostream>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class Matrix{
private:
	int rows, columns;
	E** matrix;

public:
	Matrix(int rows, int columns) {
		if (rows <= 0 || columns <= 0)
			throw runtime_error("Filas y columnas deben ser positivas ");
		this->rows = rows;
		this->columns = columns;
		matrix = new E* [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new E[columns];
		}
	}
	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	E getValue(int row, int column) {
		if (row < 0 || row >= rows)
			throw runtime_error("fila invalida");
		if (column < 0 || column >= columns)
			throw runtime_error("columna invalida");
		return matrix[row][column];
	}

	void setValue(int row, int column, E value) {
		if (row < 0 || row >= rows)
			throw runtime_error("fila invalida");
		if (column < 0 || column >= columns)
			throw runtime_error("columna invalida");
		matrix[row][column] = value;
	}

	int getRows() {
		return rows;
	}

	int getColumns() {
		return columns;
	}

	void setAll(E value) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i][j] = value;
			}
		}
	}

	void transpose() {
		Matrix<E> temp(columns, rows);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temp.setValue(j, i, matrix[i][j]);
			}
		}

		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;

		matrix = temp.matrix;
		int tempFilas = rows;
		rows = columns;
		columns = tempFilas;

		temp.matrix = nullptr;
		temp.rows = 0;
		temp.columns = 0;
	}

	void addRow(E value) {
		Matrix<E> temp(rows + 1, columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temp.setValue(i, j, matrix[i][j]);
			}
		}
		for (int j = 0; j < columns; j++) {
			temp.setValue(rows, j, value);
		}
		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;

		matrix = temp.matrix;
		rows = rows + 1;

		temp.matrix = nullptr;
		temp.rows = 0;
		temp.columns = 0;
	}

	void addColumn(E value) {
		transpose();
		addRow(value);
		transpose();
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << "|" << matrix[i][j] << "|";
			}
			cout << endl;
		}
	}
};

