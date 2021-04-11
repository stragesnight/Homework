/* ������� 3
	������: ��-011
	������: ������ ���������
	task03.cpp �������������� ������� � ������������ � ����������� �����. */

#include <iostream>
#include <windows.h>
#include <time.h>

// ������������� ������� ���������� ����������
//	arr   - ������� ��� �������������
//	sizeX - ������ �����
//	sizeY - ������ �������
void initMatrix(int** mat, int sizeX, int sizeY)
{
	// ������������� ����������� ������� ���������� ����������
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
			mat[x][y] = rand() % 10;
	}
}

// ����� ������� �� ����� � ������������ �����������
//	arr   - ������� ��� �������������
//	sizeX - ������ �����
//	sizeY - ������ �������
void drawMatrix(int** mat, int sizeX, int sizeY)
{
	// ��� ����� �������� ������� ��������� ������������ ����
	// ���� �������� ������������� ������������� ��������� ������ 
	// ������������ ��� ��������� �� ��, � ����� ����������� ��������� �������

	// ����� ������������ ��� � �� �����
	std::cout << "\n\t0 ";
	for (int i = 0; i < sizeX; i++)
		if (i == sizeX / 2)		// ���������� 'X' �� ������ �����
			if (sizeX % 2) std::cout << "- X -";
			else std::cout << "\b X ---"; // ����� ��� ������������, ���� ������ ����� - ������
		else
			std::cout << "----";
	std::cout << ">\n";

	// ����� ������� ����� �� �����
	std::cout << "\t| +";
	for (int i = 0; i < sizeX * 4 - 1; i++)
		std::cout << "-";
	std::cout << "+\n";

	for (int y = 0; y < sizeY; y++)
	{
		// ����� ������������ ��� Y �� �����
		if (y == sizeY / 2 && sizeY % 2)
			std::cout << "\tY ";
		else
			std::cout << "\t| ";

		// ����� ��������������� ��������
		for (int x = 0; x < sizeX; x++)
			std::cout << "| " << mat[x][y] << " ";

		// ������� �� ����� �����
		std::cout << "|\n";

		// ���� ������� ����� - ���������, �� ��������� �� �����
		if (y == sizeY - 1)
			break;

		// �����, ���������� "����������" �����
		if (y == sizeY / 2 - 1 && sizeY % 2 == 0)
			std::cout << "\tY |";
		else
			std::cout << "\t| |";
		for (int i = 0; i < sizeX * 4 - 1; i++)
			std::cout << "-";
		std::cout << "|\n";
	}

	// ����� ������ ����� �� �����, ��������� �������
	std::cout << "\tV +";
	for (int i = 0; i < sizeX * 4 - 1; i++)
		std::cout << "-";
	std::cout << "+\n";
}

// ����� ������� � ��������� �����������
//	arr     - ������ �� ������� ��� ������
//	sizeX   - ������ �����
//	sizeY   - ������ �������
//  amountX - ����� �� ��� X
//  amountY - ����� �� ��� Y
void shiftMatrinx(int**& mat, int sizeX, int sizeY, int amountX, int amountY)
{
	// ���������� ����� �������
	
	// - ����� ������� ��������� ��-�� �������������
	// ������ ������������ ��������� �������
	int** newMat = new int* [sizeX];	// ������� ������
	for (int i = 0; i < sizeX; i++)
		newMat[i] = new int[sizeY];		// ���������� ����������

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			int newX, newY;
			// ���������� ���������� ���������
			newX = (x + amountX + sizeX) % sizeX;
			if (amountY >= 0)
				newY = (y + amountY) % sizeY;

			// ����������� �� ������ ������� � ����� � ������ ������
			newMat[newX][newY] = mat[x][y];
		}
	}

	// ������������ ������������ ������ ������ �������
	for (int i = 0; i < sizeX; i++)
		delete[] mat[i];	// ���������� ����������
	delete[] mat;			// ������� ������


	// ���������� ����� ������� ������
	// ��� ��� ����������� ������� ���� �������� �� ������,
	// ������ ��� ��������� � "mat" ����� ����������� ��������� � ������ "newMat"
	mat = newMat;
}

int main()
{
	// ������������ ��������� �������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ������������� ��������� ���������
	srand(time(0));

	// ����� ���������� ������ �� �����
	std::cout << "\t-= ������� 3 =- \n - ���������� ������� {M x N} ���������� � � ����������� �����.\n";

	// ���������� ���������� ��� ��������� ����������� �������
	int sizeX = 4;
	int sizeY = 4;

	// ������ �� ���� ����������� �������
	std::cout << "\n������� ����������� ������� {x, y}: ";
	std::cin >> sizeX >> sizeY;

	// ���������� �������
	int** mat = new int* [sizeX];	// ������� ������
	for (int i = 0; i < sizeX; i++)
		mat[i] = new int[sizeY];	// ���������� ����������

	// ������������� ������� ���������� ����������
	initMatrix(mat, sizeX, sizeY);

	// ����������, ������������ ��� �������� ����� ����������� ���������
	bool shouldNotExit = true;
	while (shouldNotExit)
	{
		system("cls");
		// ����� ���������� ��������� ������� �� �����
		std::cout << "\t������� �� ������:";
		drawMatrix(mat, sizeX, sizeY);

		int shiftX, shiftY;
		std::cout << "\n������� ����� ������� {x, y}: ";
		std::cin >> shiftX >> shiftY;

		// ������������ ��������������� ������
		shiftMatrinx(mat, sizeX, sizeY, shiftX, shiftY);

		// ����� ���������� �������� �� �����
		std::cout << "\n\t������� ����� ������ { ";
		// ����� ����������� ������ � �������
		if (shiftX > 0) std::cout << "->, ";
		else if (shiftX < 0) std::cout << "<-, ";
		else std::cout << "-, ";

		if (shiftY > 0) std::cout << "v }:";
		else if (shiftY < 0) std::cout << "^ }:";
		else std::cout << "- }:";

		drawMatrix(mat, sizeX, sizeY);

		// �������� ����� � ����������� ������ ���������
		std::cout << "\n����������? (0 - ���, 1 - ��): ";
		std::cin >> shouldNotExit;
	}

	// ������������ ������������ ������
	for (int i = 0; i < sizeX; i++)
		delete[] mat[i];	// ���������� ����������
	delete[] mat;			// ������� ������

	// ����� � ���������� ���������
	std::cout << "\n\n������� ����� ������� ��� ������ �� ���������...";
	_getwch();		// ��������� ������ ������� � ����������
	return 0;
}
