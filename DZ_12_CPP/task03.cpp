/* ������� 3

	������: ��-011
	������: ������ ���������

	task03.cpp ������ ������� �������� ���� �������� ���, ��� �� �� ������ �������
	�������� ��� � �������� �������, ��������� ��������� � ���������� ����������. */
#include <iostream>		// ����-����� ������
#include <stdlib.h>		// ������ � srand()
#include <ctime>		// ������ � ���������� �������

using namespace std;

// ������ �������, ����������� ���������� ����������
const int SIZE = 10;

// ���������� �������, ����������� ���������� ��� ��������� �� int
// ����������� int[] � int* �����������
// �.�. ������ ���������� �������� ���������� �� ���� ������ �������
void swapArrays(int* a, int* b)
{
	cout << "\n\n������ ���������� ������� � �������������� ������ ������...\n";
	// ���������� ���������� �������
	int tmp[SIZE] = {};
	// ���������� ���������� ������� ���������� ��������� �������
	// �� ���������� �������� ������ � �������� ������� 
	// ��������� <������ ������� - 1> - i
	for (int i = 0; i < SIZE; i++)
		*(tmp + i) = *(a + (SIZE - 1 - i));

	// ��� ������� �������� �������...
	for (int i = 0; i < SIZE; i++)
	{
		// �������� ������� ������� ��������
		*(a + i) = *(b + i);
		// ��������� � ����������� ������� ������� ����� ��������� ������
		*(b + i) = *(tmp + i);
	}
}

// �������, ��������� ���������� ���� �������� �� �������
void coutArrays(int* a, int* b)
{
	cout << "\n������ 1 -  ";
	for (int i = 0; i < SIZE; i++)
		cout << *(a + i) << " ";
	cout << "\n������ 2 -  ";
	for (int i = 0; i < SIZE; i++)
		cout << *(b + i) << " ";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	// ���������� ���� ��������
	int arr1[SIZE] = {};
	int arr2[SIZE] = {};

	// ���������� �������� ��������� ����������
	for (int i = 0; i < SIZE; i++)
	{
		arr1[i] = i + 10;
		arr2[i] = rand() % 90 + 10;
	}

	// ������� ����������� ���������� �� �����
	coutArrays(arr1, arr2);
	// �������� �������� �������
	swapArrays(arr1, arr2);
	// ������� ���������� ����� ������
	coutArrays(arr1, arr2);

	// ���������� ���������
	cout << "\n\n";
	system("pause");
	return 0;
}