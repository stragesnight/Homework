/* ������� 6

	������: ��-011
	������: ������ ���������

	task06.cpp ������� �� ����� ����� ���� ��������� ����� � ��������� �� � �� �. */
// ���������� ��� ������ � ������-������� ������
#include <iostream>
// ���������� ������ ��� �������� "����"("��������� �����") ���������� ��������� �����
#include <stdlib.h>
// ���������� ��� ��������� ������� � ���������� �������
#include <time.h>

// ����� ���� �������� �������� �� ���������� � std �������
using namespace std;

// �������� ������� ���������
int main()
{
	// ���������� ��������� ���������
	setlocale(LC_ALL, "Ukrainian");
	// ��������� "����"("��������� �����") ���������� ��������� �����
	srand(time(NULL));

	int A, B;
	int summ = 0, currTemp;

	// ����� ���������� ������ �� ����� � ���� ������ � ����������
	cout << "\t����i�� �i�i ����� �i������� �i� � �� � (A<B): ";
	cin >> A >> B;

	cout << endl;

	for (int i = 1; i <= 5; i++)
	{
		// ��������� ����� � ��������� �� � �� �
		currTemp = rand() % (B - A) + A;
		summ += currTemp;

		cout << "\n\t����� " << i << " = " << currTemp;
	}

	cout << "\n\n\t���� ���� ����� �i� " << A << " �� " << B << " = " << summ << "\n\n\n";

	// ����� ���������
	system("pause");
	// ���������� ��������� ���������� ���������
	return 0;
}