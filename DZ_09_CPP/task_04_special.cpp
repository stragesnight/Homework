/* ������� 4

	������: ��-011
	������: ������ ���������

	task04.cpp ��������� �������� ������������� ����� ����������� �������. */
// ���������� ��� ������ � ������-������� ������
#include <iostream>

// ����� ���� �������� �������� �� ���������� � std �������
using namespace std;

// �������� ������� ���������
int main()
{
	// ���������� ��������� ���������
	setlocale(LC_ALL, "Russian");
	
	const int SIZE_X = 6;
	const int SIZE_Y = 2;

	int init[SIZE_X][SIZE_Y];
	int fin[SIZE_X][SIZE_Y];

	int offsetX, offsetY;


	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			init[x][y] = rand() % 10;
			cout << init[x][y] << " ";
		}

		cout << endl;
	}

	cout << "������� ����� �� ���� X(����) � Y(�������): ";
	cin >> offsetX >> offsetY;

	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			int newX = x + offsetX;
			if (newX > SIZE_X - 1)
				newX -= SIZE_X;

			int newY = y + offsetY;
			if (newY > SIZE_Y - 1)
				newY -= SIZE_Y;

			fin[x][y] = init[newX][newY];
			cout << fin[x][y] << " ";
		}

		cout << endl;
	}

	// ����� ���������
	system("pause");
	// ���������� ��������� ���������� ���������
	return 0;
}
