#pragma once

#include <iostream>
#include <cmath>

class Vector {
public:

	// ================================== ������������/����������
	Vector();
	Vector(const Vector& vector);

	virtual~Vector();

	// ========================================== �������/�������

	double* getArray1D() const;
	const size_t getLength() const;
	double& operator [](unsigned int index) const;


	// ========================================== ������������� � ����� ����������� �������

public:
	void initializeArray1D();
	void printArray1D() const;

	// ========================================== ���������/���������

	Vector& operator ++();
	Vector& operator --();
	Vector operator ++(int value);
	Vector operator --(int value);

private:
	// ���������� ����������� �������
	size_t length_;
	double* Array1D_;
	static double PI_;
};