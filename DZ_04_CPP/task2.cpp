/* ������� 2

	������: ��-011
	������: ������ ���������

	task2.cpp ������� �� ����� ������� �� �������� ������������� ���� ����� */

// �������� ����������� ��� ������ � ������-������� ������ ����������
#include <iostream>
// ����� ���� �������� �������� �� ���������� � std �������
using namespace std;

// �������� ������� ���������
int main()
{
	// ���������� ��������� ���������
	setlocale(LC_ALL, "Russian");

	// ���������� ����������
	float num1, num2;

	// ����� ���������� ������ �� �����
	cout << "������� 2 ����� � ��������� ������� ����� �� ��� ������";
	// ������ �� ���� ������ � ����������
	cout << "\n\n������: ";
	cin >> num1;
	cout << "������: ";
	cin >> num2;

	// ���� ����� �� �����...
	if (num1 != num2)
	{
		// ���� ������ ����� ������...
		if (num1 < num2)
			cout << endl << num1 << " ������, ��� " << num2 << endl;
		// � ���� ������...
		else
			cout << endl << num2 << " ������, ��� " << num1 << endl;
	}
	// ����� ������ � ������������ �������� ������
	else
		cout << endl << "���� ������� ��� ���������� �����." << endl;

	// ����� ���������
	system("pause");
	// ���������� ��������� ���������� ���������
	return 0;
}