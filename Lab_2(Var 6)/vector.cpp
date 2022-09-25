#define _USE_MATH_DEFINES 
#include "vector.h"
#include <iostream>
#include <cmath>

// ==================== КОНСТРУКТОРЫ / ДЕСТРУКТОР =======================

Vector::Vector() {
	length_ = 16;
	Array1D_ = new double[length_];
	initializeArray1D();
}

// Конструктор копирования (копирует каждый элемент массива в новый а не только его ссылку
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

// ==================== СЕТТЕРЫ / ГЕТТЕРЫ =======================

double* Vector::getArray1D() const {
	return Array1D_;
}

const size_t Vector::getLength() const {
	return length_;
}

double& Vector::operator [](unsigned int index) const {
	return Array1D_[index];
}


// ====================== ОСТАЛЬНОЕ =============================


// Инициализация одномерноего массива по заданию
void Vector::initializeArray1D() {

	for (size_t i = 0; i < length_; ++i)
		*(Array1D_ + i) = i * exp(PI_ * i / 100);

}

// Вывод одномерного массива
void Vector::printArray1D() const{
	std::cout << "\n[ ";

	for (size_t i = 0; i < length_; ++i)
		std::cout << *(Array1D_ + i) << "  ";

	std::cout << "]\n";
}

// ====================== Инкремент/Декремент =============================

// Инкремент префиксный
Vector& Vector::operator ++() {
	for (size_t i = 0; i < length_; i++)
		Array1D_[i] = Array1D_[i] + 1;

	return *this;
}

// Декремент префексный
Vector& Vector::operator --() {
	for (size_t i = 0; i < length_; i++)
		Array1D_[i] = Array1D_[i] - 1;

	return *this;
}

// Инкремент постфиксный
Vector Vector::operator ++(int value) {
	Vector temp(*this);
	for (size_t i = 0; i < temp.length_; i++)
		Array1D_[i] = Array1D_[i] + 1;

	return temp;
}

// Декремент постфиксный
Vector Vector::operator --(int value) {
	Vector temp = *this;
	for (size_t i = 0; i < temp.length_; i++)
		Array1D_[i] = Array1D_[i] - 1;

	return temp;
}

// Разница между постфиксным и префиксным в том что при префесном значение массива копируется в другой объект после выполнения инкремнтации/декрементации
// а постфиксный наоборот, сначало копирует потом выполняет операции

// Заполнение статической переменной
double Vector::PI_ = M_PI;