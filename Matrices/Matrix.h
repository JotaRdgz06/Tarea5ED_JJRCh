#pragma once

#include <stdexcept>

using std::runtime_error;

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

	E setValue(int row, int column, E value) {
		if (row < 0 || row >= rows)
			throw runtime_error("fila invalida");
		if (column < 0 || column >= columns)
			throw runtime_error("columna invalida");
		matrix[row][column] = value;
		return value;
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
};

