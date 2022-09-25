#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//
#include <iostream>
#include "vector.h"
#include "matrix.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	// Создания объекта одномерного массива и вывод его на экран
	Vector Zet;
	Zet.printArray1D();

	// Создания объекта 2-х мерного массива (на осноме одномерного массива) и вывод его на экран
	Matrix Bob(Zet);
	Bob.printArray2D();

	cout << "\nПрисвоем значение для переменной (1,1) : 10\n";
	Bob.setAt(1, 1, 10);
	Bob.printArray2D();

	cout << "\nИнкремент Zet\n";
	++Zet;
	Zet.printArray1D();

	cout << "\nПеременная на (1,2) : " << Bob.at(1, 2) << "\n";

	cout << "\nОбявление одномерное массива и присвоение ему посфексного значение Zet\n";
	Vector Bomb = Zet++;
	Bomb.printArray1D();

	cout << "\nZet\n";
	Zet.printArray1D();

	return 0;
}