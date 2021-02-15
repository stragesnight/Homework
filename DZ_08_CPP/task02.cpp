/* ������� 2

	������: ��-011
	������: ������ ���������

	task02.cpp ���������� ��������� ��������������� ������ ����� �� ��� (���. � ����. ������� � ����� � ��������� ���������). */
// ���������� ��� ������ � ������-������� ������
#include <iostream>
// ���������� ������ ��� ��������� ������� � srand()
#include <stdlib.h>
// ���������� ������ ��� ��������� ���������� �������
#include <time.h>

// ����� ���� �������� �������� �� ���������� � std �������
using namespace std;

// �������� ������� ���������
int main()
{
	// ���������� ��������� ���������
	setlocale(LC_ALL, "Russian");
	// ��������� ��� ������� ��������� ������ ��� ����� ������������ ������ �����
	srand(time(NULL));

	float income[12];
	int rangeFrom = 0, rangeTo = 0;

	// ����� ���������� ������
	cout << "= ���������� ���������� ����� �� ���. =\n";
	cout << "\n��������������� ������� ����� ����� �� 12 ������� \n(������� 0 ��� ���������� ������� ���������� �������) : ";

	cin >> income[0];
	if (income[0] == 0)
	{
		// ���������� ��������� ������� ��������� ��������
		for (int i = 0; i < 12; i++)
			income[i] = rand() % 999 + 1;
	}
	else
	{
		// �������� ������
		for (int i = 1; i < 12; i++)
			cin >> income[i];
	}

	// �������� ��������� � ��������� � ���, ��� ����� ������
	do
	{
		cout << "\n������� �������� �������� (�� .. , �� .. ������������): ";
		cin >> rangeFrom >> rangeTo;

		if (rangeFrom == rangeTo)
			cout << "\n������� ��� ������ ������!";

	} while (rangeFrom == rangeTo);

	// ���� ������ ������� ��������� ���� �������...
	if (rangeFrom > rangeTo)
	{
		// ����������� �������� ��� ������������ ������ ���������
		float tmp = rangeFrom;
		rangeFrom = rangeTo;
		rangeTo = tmp;
	}

	int indexMin = 0, indexMax = 0;
	// �������� ������� ������������ � ������������� �������� � ���������
	for (int i = rangeFrom; i < rangeTo; i++)
	{
		if (income[i] > income[indexMax] || i == rangeFrom)
			indexMax = i;
		else if (income[i] < income[indexMin] || i == rangeFrom)
			indexMin = i;
	}

	system("cls");

	cout << "|| ���������� ������� �� " << rangeFrom << "-�� �� " << rangeTo << "-�� ������ ||\n\n";

	for (int i = 0; i < 12; i++)
		cout << "|  " << income[i] << "\t";

	cout << "|\n";

	// ���� ����������� ��������� ������
	bool flagDraw = false;

	for (int i = 1; i <= 12; i++)
	{
		if (i == rangeFrom)
		{
			cout << "\\_______";
			flagDraw = true;
		}
		else if (i == rangeTo)
		{
			cout << "________/";
			flagDraw = false;
		}
		else if (flagDraw) cout << "________";
		else cout << "\t";
	}

	cout << "\n\n\t������������ ����� � ��������� ����� �������� �� " << indexMax + 1 << "-� �����. ����� ������: " << income[indexMax];
	cout << "\n\t����������� ����� � ��������� ����� �������� �� " << indexMin + 1 << "-� �����. ����� ������: " << income[indexMin];

	cout << "\n\n";

	// ����� ���������
	system("pause");
	// ���������� ��������� ���������� ���������
	return 0;
}
