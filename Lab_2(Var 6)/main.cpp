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

	// �������� ������� ����������� ������� � ����� ��� �� �����
	Vector Zet;
	Zet.printArray1D();

	// �������� ������� 2-� ������� ������� (�� ������ ����������� �������) � ����� ��� �� �����
	Matrix Bob(Zet);
	Bob.printArray2D();

	cout << "\n�������� �������� ��� ���������� (1,1) : 10\n";
	Bob.setAt(1, 1, 10);
	Bob.printArray2D();

	cout << "\n��������� Zet\n";
	++Zet;
	Zet.printArray1D();

	cout << "\n���������� �� (1,2) : " << Bob.at(1, 2) << "\n";

	cout << "\n��������� ���������� ������� � ���������� ��� ����������� �������� Zet\n";
	Vector Bomb = Zet++;
	Bomb.printArray1D();

	cout << "\nZet\n";
	Zet.printArray1D();

	return 0;
}