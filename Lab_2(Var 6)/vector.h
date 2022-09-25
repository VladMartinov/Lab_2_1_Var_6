#pragma once

#include <iostream>
#include <cmath>

class Vector {
public:

	// ================================== конструкторы/деструктор
	Vector();
	Vector(const Vector& vector);

	virtual~Vector();

	// ========================================== сеттеры/геттеры

	double* getArray1D() const;
	const size_t getLength() const;
	double& operator [](unsigned int index) const;


	// ========================================== инициализация и вывод одномерного массива

public:
	void initializeArray1D();
	void printArray1D() const;

	// ========================================== инкремент/декремент

	Vector& operator ++();
	Vector& operator --();
	Vector operator ++(int value);
	Vector operator --(int value);

private:
	// Переменный одномерного массива
	size_t length_;
	double* Array1D_;
	static double PI_;
};