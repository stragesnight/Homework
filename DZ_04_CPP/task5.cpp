/* ������� 5

	������: ��-011
	������: ������ ���������

	task5.cpp ��������� ����� �� �������� ������������� �����. ���� ���, �� ������� �� �� ����� � ������� ����������� */

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
	float grade1, grade2, grade3, grade4, grade5, averageGrade;

	// ����� ���������� ������ �� �����
	cout << "�������� ������� � ��������."
		<< "\n����������� ������� ���� ��� ������� - 4 �� 5."
		<< "\n����� ���������� ������ - 5.";

	// ������ �� ���� ������ � ����������
	cout << "\n\n������� ������ ������: ";
	cin >> grade1;
	cout << "������� ������ ������: ";
	cin >> grade2;
	cout << "������� ������ ������: ";
	cin >> grade3;
	cout << "������� ��������� ������: ";
	cin >> grade4;
	cout << "������� ����� ������: ";
	cin >> grade5;

	// ���������� �������� �����
	averageGrade = (grade1 + grade2 + grade3 + grade4 + grade5) / 5;

	// ����� ���������� �� �����
	cout << "\n\n������� ������: " << averageGrade << ".";
	// ���� ������� ���� ���� ������...
	if (averageGrade >= 4)
		cout << " ������ ������� � ��������";
	// �����...
	else 
		cout << " ������ �� ������� � ��������";

	cout << endl;

	// ����� ���������
	system("pause");
	// ���������� ��������� ���������� ���������
	return 0;
}