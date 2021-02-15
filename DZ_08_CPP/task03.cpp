/* ������� 3

	������: ��-011
	������: ������ ���������

	task03.cpp ���������� �������� ��� ���������� ������� � ������� ���������� �� �����. */
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

	float numbers[100];

	int n;
	int indexMin = -1, indexMax = -1;
	int indexFirstNegative = -1, indexLastNegative = -1;
	long float sumNegative = 0, multiplicationMinMax = 1, multiplicationEven = 1, sumMinMaxNegative = 0;

	// ����� ���������� ������
	cout << "��������� ��� ���������� ��������� �������� ��� ���������� �������.\n";

	// ���� ������ � �������� �� �����������
	do
	{
		cout << "������� ���������� ��������� ������� (1 - 100): ";
		cin >> n;

		if (n < 1 || n > 100)
			cout << "������� ���������� ������!\n\n";

	} while (!(n > 1 && n < 100));

	cout << "\n��������������� ������� �������� �������\n(������� 0 ��� ���������� ������� ���������� ����������): ";
	cin >> numbers[0];

	// ���� ������� ����� 0 - ��������� ������ ���������� ������������� �������
	if (numbers[0] == 0)
		for (int i = 0; i < n; i++)
			numbers[i] = rand() / 22.12 - 740.;
	// ����� - ������� ������ � ����������
	else
		for (int i = 1; i < n; i++)
			cin >> numbers[i];

	cout << "\n\n";

	// �������� �������� ������������� � ������������ �������� ��������� �������
	// � ����� ������� ������� � ���������� �������������� ��������
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] > numbers[indexMax] || i == 0)
			indexMax = i;
		else if (numbers[i] < numbers[indexMin] || i == 0)
			indexMin = i;

		if (numbers[i] < 0)
		{
			if (indexFirstNegative == -1)
				indexFirstNegative = i;

			indexLastNegative = i;
		}
	}


	for (int i = 0; i < n; i++)
	{
		// ��������� �������� �������� � ���������� ��� �������� ���������
		float curr = numbers[i];

		cout << curr << "\n";

		// �������� ������ ��� ������ �������...
		// ����� �������������
		if (curr < 0)
			sumNegative += curr;

		// ����� ��������� ����� ����������� � ������������ ���������
		if (indexMin < indexMax)
		{
			if (i > indexMin && i < indexMax)
				multiplicationMinMax *= curr;
		}
		else
			if (i < indexMin && i > indexMax)
				multiplicationMinMax *= curr;

		// ������������ ������
		if (i % 2 == 0)
			multiplicationEven *= curr;

		// ����� ��������� ����� ������ � ��������� �������������
		if (i > indexFirstNegative && i < indexLastNegative)
			sumMinMaxNegative += curr;
	}

	cout << "\n\n1. ����� ������������� ���������: " << sumNegative;
	cout << "\n2. ������������ ���������, ����������� ����� ����������� � ������������ ���������: " << multiplicationMinMax;
	cout << "\n3. ������������ ��������� � ������� ��������: " << multiplicationEven;
	cout << "\n4. ����� ���������, ����������� ����� ������ � ��������� �������������� ����������: " << sumMinMaxNegative << "\n\n\n";

	// ����� ���������
	system("pause");
	// ���������� ��������� ���������� ���������
	return 0;
}
