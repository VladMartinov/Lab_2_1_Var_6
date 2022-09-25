#pragma once

#include "vector.h"
#include <iostream>

class Matrix {
public:

	// ================================== конструкторы/деструктор	
	Matrix(Vector& val);

	virtual~Matrix(void);

	// ========================================== сеттеры/геттеры

	void setAt(size_t i, size_t j, int Num);
	double at(size_t i, size_t j);


	// ========================================== метод создающий 2-х мерный массив и выводящий его метод
public:
	void makeArray2D();
	void printArray2D();


private:
	// переменные 2-х мерного массива а так же класс одномерного массива для раьоты с ним
	size_t ROWS_;
	size_t COLS_;
	double** Array2D;
	Vector& var_;
};