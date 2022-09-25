#define _USE_MATH_DEFINES 
#include "vector.h"
#include <iostream>
#include <cmath>

// ==================== ������������ / ���������� =======================

Vector::Vector() {
	length_ = 16;
	Array1D_ = new double[length_];
	initializeArray1D();
}

// ����������� ����������� (�������� ������ ������� ������� � ����� � �� ������ ��� ������
Vector::Vector(const Vector& vector) {
	length_ = vector.length_;
	Array1D_ = new double[length_];

	for (int i = 0; i<length_; i++)
		Array1D_[i] = vector.Array1D_[i];
}

Vector::~Vector() {

	delete Array1D_;
	Array1D_ = NULL;
	std::cout << "\nDestructor : vector Removed!";

}

// ==================== ������� / ������� =======================

double* Vector::getArray1D() const {
	return Array1D_;
}

const size_t Vector::getLength() const {
	return length_;
}

double& Vector::operator [](unsigned int index) const {
	return Array1D_[index];
}


// ====================== ��������� =============================


// ������������� ������������ ������� �� �������
void Vector::initializeArray1D() {

	for (size_t i = 0; i < length_; ++i)
		*(Array1D_ + i) = i * exp(PI_ * i / 100);

}

// ����� ����������� �������
void Vector::printArray1D() const{
	std::cout << "\n[ ";

	for (size_t i = 0; i < length_; ++i)
		std::cout << *(Array1D_ + i) << "  ";

	std::cout << "]\n";
}

// ====================== ���������/��������� =============================

// ��������� ����������
Vector& Vector::operator ++() {
	for (size_t i = 0; i < length_; i++)
		Array1D_[i] = Array1D_[i] + 1;

	return *this;
}

// ��������� ����������
Vector& Vector::operator --() {
	for (size_t i = 0; i < length_; i++)
		Array1D_[i] = Array1D_[i] - 1;

	return *this;
}

// ��������� �����������
Vector Vector::operator ++(int value) {
	Vector temp(*this);
	for (size_t i = 0; i < temp.length_; i++)
		Array1D_[i] = Array1D_[i] + 1;

	return temp;
}

// ��������� �����������
Vector Vector::operator --(int value) {
	Vector temp = *this;
	for (size_t i = 0; i < temp.length_; i++)
		Array1D_[i] = Array1D_[i] - 1;

	return temp;
}

// ������� ����� ����������� � ���������� � ��� ��� ��� ��������� �������� ������� ���������� � ������ ������ ����� ���������� ������������/�������������
// � ����������� ��������, ������� �������� ����� ��������� ��������

// ���������� ����������� ����������
double Vector::PI_ = M_PI;