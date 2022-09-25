#include <iostream>
#include <iomanip>
#include "matrix.h"
// ==================== ������������ / ���������� =======================

Matrix::Matrix(Vector& var): var_(var) {
	ROWS_ = 4;
	COLS_ = 4;
	Array2D = new double* [ROWS_];
	makeArray2D();
}

Matrix::~Matrix() {
	for (int i = 0; i < ROWS_; ++i)
		delete* (Array2D + i);                            

	delete Array2D;                                       
	std::cout << "\nDestructor : matrix Removed!";
}

// ==================== ������� / ������� =======================

// �� ������� 
void Matrix::setAt(size_t i, size_t j, int Num) {
	Array2D[i][j] = Num;
}

double Matrix::at(size_t i, size_t j) {
	return Array2D[i][j];
}


// ====================== ��������� =============================


//����� ��������� 2-� ������ ������ (���� �� ������� ����)
void Matrix::makeArray2D()
{
	for (size_t i = 0; i < ROWS_; ++i)
		*(Array2D + i) = new double[COLS_] {};          

	for (unsigned int i = 0; i < ROWS_; ++i)         
	{
		*(*(Array2D + i) + 0) = 0;                 
		for (size_t j = 1; j < COLS_; ++j)     
		{
			*(*(Array2D + i) + j) = *(var_.getArray1D() + i * COLS_ + j);         
			*(*(Array2D + i) + 0) += *(*(Array2D + i) + j);           
		}
	}                               
}

// ����� ������� �� �������
void Matrix::printArray2D() {
	std::cout << "\n" << std::setfill(' ') << std::setw(41) << "=>\n";                                             //���������� ���������� � ����������� ������� � �������

	for (size_t i = 0; i < ROWS_; ++i)                             //���������� �� �������
	{
		std::cout << "\n";                                                   //������� �� ��������� ������
		for (size_t j = 0; j < COLS_; ++j)
		{
			if (i == 0 && j == 0)
				std::cout << "[" << std::setfill(' ') << std::setw(9) << *(*(Array2D + i) + j); //����� ������� �������� ������ ������ (��-�� ���������� ������)
			else
				std::cout << std::setfill(' ') << std::setw(10) << *(*(Array2D + i) + j);      //����� ���� ��-�� �������
		}
	}
	std::cout << "  ]\n";                                                    //����������� ������
}