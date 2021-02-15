/* ������� 8

	������: ��-011
	������: ������ ���������

	task8.cpp ��������� ������� ����� ����� ��������� ������������� ������
	���� ����� � �� ������ "�������", ��� ��� �� ������ � �������� ������ ���� ������� ������� */

// �������� ����������� ��� ������ � ������-������� ������ ����������
#include <iostream>
// �������� ���������� ��� ������ � ��������������� ���������
// � ������ ��������� ������������ ��� ���������� ������ �����
#include <cmath>
// ����� ���� �������� �������� �� ���������� � std �������
using namespace std;

// �������� ������� ���������
int main()
{
	// ���������� ��������� ���������
	setlocale(LC_ALL, "Russian");

	// ������������ ������� ��� �������� ��������� ���������
	enum Months { January = 1, Febreuary, March, April, May, June, July, August, September, October, November, December };

	// ���������� ����������
	int day1, month1, year1, totalDays1 = 0;
	int day2, month2, year2, totalDays2 = 0;
	long totalDayDiff;

	// ����� ���������� ������ �� �����
	cout << "���������� ������� (� ����) ����� ����� ���������� ������";

	// ������ �� ���� ������ � ����������
	cout << "\n��������������� ������� ��� ����� ����� ������ ���� (���� -> ����� -> ���):\n";
	cin >> day1 >> month1 >> year1;
	cout << "\n��������������� ������� ��� ����� ����� ������ ���� (���� -> ����� -> ���):\n";
	cin >> day2 >> month2 >> year2;

	// ���������� ������ ���������� ���� ����� ���

	// ������ ����
	// � ������ ���������� ���� ��������� �������� ���
	totalDays1 += day1;

	// ���������� ����, ��������� �� ������� ������ � ���� ����
	switch (month1)
	{
	case January:
		break;
	case Febreuary:
		totalDays1 += 31;
		break;
	case March:
		totalDays1 += 59;
		break;
	case April:
		totalDays1 += 90;
		break;
	case May:
		totalDays1 += 120;
		break;
	case June:
		totalDays1 += 151;
		break;
	case July:
		totalDays1 += 181;
		break;
	case August:
		totalDays1 += 212;
		break;
	case September:
		totalDays1 += 243;
		break;
	case October:
		totalDays1 += 273;
		break;
	case November:
		totalDays1 += 304;
		break;
	case December:
		totalDays1 += 334;
	default:
		cout << "\n������� ������������ ������.";
		return 0;
	}

	// ����� ���������� ���� � ����� = ���������� ��� * 365 + ���������� ��������� ���������� ���
	totalDays1 += year1 * 365 + (year1 / 4);


	// ������ ����
	// � ������ ���������� ���� ��������� �������� ���
	totalDays2 += day2;

	// ���������� ����, ��������� �� ������� ������ � ���� ����
	switch (month2)
	{
	case January:
		break;
	case Febreuary:
		totalDays2 += 31;
		break;
	case March:
		totalDays2 += 59;
		break;
	case April:
		totalDays2 += 90;
		break;
	case May:
		totalDays2 += 120;
		break;
	case June:
		totalDays2 += 151;
		break;
	case July:
		totalDays2 += 181;
		break;
	case August:
		totalDays2 += 212;
		break;
	case September:
		totalDays2 += 243;
		break;
	case October:
		totalDays2 += 273;
		break;
	case November:
		totalDays2 += 304;
		break;
	case December:
		totalDays2 += 334;
	default:
		cout << "\n������� ������������ ������.";
		return 0;
	}

	// ����� ���������� ���� � ����� = ���������� ��� * 365 + ���������� ��������� ���������� ���
	totalDays2 += year2 * 365 + (year2 / 4);

	// ������� ����� ������ ����� ������ ������� ������ ���������� ����
	totalDayDiff = abs(totalDays2 - totalDays1);

	// ����� ���������� �� �����
	cout << "\n������� ����� ��������� ������ (� ����) : " << totalDayDiff << endl;

	// ����� ���������
	system("pause");
	// ���������� ��������� ���������� ���������
	return 0;
}