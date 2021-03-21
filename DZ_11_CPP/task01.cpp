/* ������� 1

	������: ��-011
	������: ������ ���������

	task01.cpp �������� ������������� ������� ��� ������ � ��������� */
#include <iostream>		// ����-����� ������
#include <algorithm>	// �������� �������� ����������
#include <stdlib.h>		// �������� srand
#include <ctime>		// ������������ ��� ������� ����� ���������

using namespace std;

// ���������� ������� ������� ���������� ����������
// *��������� �������� � ��� ��������� ����� ��������*
// **����� ������� ������� ������� ����� �����������**
const int SIZE = 3;


/////////////////////////////////////////////
// - ����������� ���� �������� ������ ���  //
//  ������ ���� ������ ��� �������� �����  //
/////////////////////////////////////////////


//////////////////    INT    ////////////////
void initMat(int in[SIZE * SIZE], int out[SIZE][SIZE])
{
	// �������������� ����������� �������
	// � ������� �������� SIZE
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			out[y][x] = in[y * SIZE + x];
}

void coutMat(int mat[SIZE][SIZE])
{
	cout << "\n - �������: \n\n";
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
			cout << mat[y][x] << "\t";

		cout << "\n\n";
	}

}

void minMaxMat(int mat[SIZE][SIZE])
{
	cout << "\n - ����������� � ������������ �������� �� ������� ���������: \n\n";

	int min = -1, max = -1;

	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			// ���� ������� ������� ��������� �� ������� ���������
			if (x == y)
			{
				cout << "|" << mat[y][x] << "|" << "\t";

				// ���� ������� ������� ������ ������������� ��� ������������ ������� ��� �� ����������
				if (mat[y][x] > max || max == -1)
					max = mat[y][x];
				// ���� ������� ������� ������ ������������ ��� ����������� ������� ��� �� ����������
				if (mat[y][x] < min || min == -1)
					min = mat[y][x];
			}
			else
				cout << " " << mat[y][x] << "\t";
		}

		cout << "\n\n";
	}

	cout << "\n����������� ������� �� ������� ��������� - " << min;
	cout << "\n������������ ������� �� ������� ��������� - " << max << "\n\n";
}

void sortMat(int mat[SIZE][SIZE])
{
	cout << "\n - ���������� �������...";

	for (int y = 0; y < SIZE; y++)
		// ���������� ��������� ���������� �� ���������� algorithm
		// �� ������ ������� �������� � ���� �� ������ ���������� ��������
		sort(&mat[y][0], &mat[y][SIZE]);

	coutMat(mat);
}

//////////////////  DOUBLE  ////////////////
void initMat(double in[SIZE * SIZE], double out[SIZE][SIZE])
{
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			out[y][x] = in[y * SIZE + x];
}

void coutMat(double mat[SIZE][SIZE])
{
	cout << "\n - �������: \n\n";
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
			cout << mat[y][x] << "\t";

		cout << "\n\n";
	}

}

void minMaxMat(double mat[SIZE][SIZE])
{
	cout << "\n - ����������� � ������������ �������� �� ������� ���������: \n\n";

	double min = -1, max = -1;

	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (x == y)
			{
				cout << "|" << mat[y][x] << "|" << "\t";

				if (mat[y][x] > max || max == -1)
					max = mat[y][x];
				if (mat[y][x] < min || min == -1)
					min = mat[y][x];
			}
			else
				cout << " " << mat[y][x] << "\t";
		}

		cout << "\n\n";
	}

	cout << "\n����������� ������� �� ������� ��������� - " << min;
	cout << "\n������������ ������� �� ������� ��������� - " << max << "\n\n";
}

void sortMat(double mat[SIZE][SIZE])
{
	cout << "\n - ���������� �������...";

	for (int y = 0; y < SIZE; y++)
		sort(&mat[y][0], &mat[y][SIZE]);

	coutMat(mat);
}

//////////////////   CHAR   ////////////////
void initMat(char in[SIZE * SIZE], char out[SIZE][SIZE])
{
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			out[y][x] = in[y * SIZE + x];
}

void coutMat(char mat[SIZE][SIZE])
{
	cout << "\n - �������: \n\n";
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
			cout << mat[y][x] << "\t";

		cout << "\n\n";
	}

}

void minMaxMat(char mat[SIZE][SIZE])
{
	cout << "\n - ����������� � ������������ �������� �� ������� ���������: \n\n";

	char min = -1, max = -1;

	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (x == y)
			{
				cout << "|" << mat[y][x] << "|" << "\t";

				if (mat[y][x] > max || max == -1)
					max = mat[y][x];
				if (mat[y][x] < min || min == -1)
					min = mat[y][x];
			}
			else
				cout << " " << mat[y][x] << "\t";
		}

		cout << "\n\n";
	}

	cout << "\n����������� ������� �� ������� ��������� - " << min;
	cout << "\n������������ ������� �� ������� ��������� - " << max << "\n\n";
}

void sortMat(char mat[SIZE][SIZE])
{
	cout << "\n - ���������� �������...";

	for (int y = 0; y < SIZE; y++)
		sort(&mat[y][0], &mat[y][SIZE]);

	coutMat(mat);
}

// ���������� ��������� ���������� ������������ �����
double rnd()
{
	return ((rand() % 256) / 1.15);
}

int main()
{
	// ���������� ��������� ���������
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	// ������������ ��� �������� ������ � ��������� ����� ������
	enum dataType { INT = 1, DOUBLE, CHAR };

	int dataTypeIndex;
	int initRand;

	int inputINT[SIZE * SIZE] = {};
	double inputDOUBLE[SIZE * SIZE] = {};
	char inputCHAR[SIZE * SIZE] = {};

	cout << "��������� ���� ������:\n\t1 - int\n\t2 - double\n\t3 - char\n\n";
	cout << "������� �����, ��������������� ��������� ���� ������: ";
	cin >> dataTypeIndex;

	cout << "\n������� 0 ��� ����� ������ �������,\n\t��� ����� ������ ������� ��� ��������� ��������� - ";
	cin >> initRand;

	if (!initRand)
		cout << "\n��������������� ������� " << SIZE * SIZE << " ��������(-�) ���������� ���� ������: ";

	// ����� ���� ������ � ����������� �� ������ ������������
	switch (dataTypeIndex)
	{
	case INT:
		// ����������, ������� ����� ������������� ����� ��������� �������
		int matINT[SIZE][SIZE];

		// ���������� ������� �������� �������
		for (int i = 0; i < SIZE * SIZE; i++)
			if (initRand)
				inputINT[i] = rnd();
			else
				cin >> inputINT[i];

		// ����� ������ ������� �� ����������
		initMat(inputINT, matINT);
		coutMat(matINT);
		minMaxMat(matINT);
		sortMat(matINT);

		break;

	case DOUBLE:
		double matDOUBLE[SIZE][SIZE];

		for (int i = 0; i < SIZE * SIZE; i++)
			if (initRand)
				inputDOUBLE[i] = rnd();
			else
				cin >> inputDOUBLE[i];

		initMat(inputDOUBLE, matDOUBLE);
		coutMat(matDOUBLE);
		minMaxMat(matDOUBLE);
		sortMat(matDOUBLE);

		break;

	case CHAR:
		char matCHAR[SIZE][SIZE];

		for (int i = 0; i < SIZE * SIZE; i++)
			if (initRand)
				inputCHAR[i] = rnd();
			else
				cin >> inputCHAR[i];

		initMat(inputCHAR, matCHAR);
		coutMat(matCHAR);
		minMaxMat(matCHAR);
		sortMat(matCHAR);

		break;
	}

	// ���������� ������ ���������
	cout << "\n\n";
	system("pause");
	return 0;
}
