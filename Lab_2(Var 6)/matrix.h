#pragma once

#include "vector.h"
#include <iostream>

class Matrix {
public:

	// ================================== ������������/����������	
	Matrix(Vector& val);

	virtual~Matrix(void);

	// ========================================== �������/�������

	void setAt(size_t i, size_t j, int Num);
	double at(size_t i, size_t j);


	// ========================================== ����� ��������� 2-� ������ ������ � ��������� ��� �����
public:
	void makeArray2D();
	void printArray2D();


private:
	// ���������� 2-� ������� ������� � ��� �� ����� ����������� ������� ��� ������ � ���
	size_t ROWS_;
	size_t COLS_;
	double** Array2D;
	Vector& var_;
};