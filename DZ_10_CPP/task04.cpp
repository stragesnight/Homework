/* ������� 4

	������: ��-011
	������: ������ ���������

	task04.cpp ���������� �������� �� "����������" �������� ������������� ������������ ����� ��� ������ ������� */
#include <iostream>

bool isHappy(int num)
{
	int sumLeft = 0, sumRight = 0;
	// ������ ��� �������� "��������" ��������� ��������� num
	int fractured[6];

	for (int i = 0; i < 6; i++)
	{
		// ��������������� ������� ��� ���������� ������������������
		int index = 5 - i;

		// ���������� �������� ����������� �������
		fractured[index] = num % 10;
		// ������� ��������� ����� �� 10 ��� �������� �� ��������� �������
		num /= 10;

		// ���������� ���� � ����������� �� ������������ �����
		if (index < 3)
			sumLeft += fractured[index];
		else
			sumRight += fractured[index];
	}

	// ����������� ���������� �������� ��������� ����
	return sumLeft == sumRight;
}

int main()
{
	std::setlocale(LC_ALL, "Russian");

	int input;
	bool valid = false;

	std::cout << "= ��������� ���������� �������� �� \"����������\" �������� ���� ������������ ����� =\n";

	do
	{
		std::cout << "\n������� ������������ �����: ";
		std::cin >> input;

		// �������� ����, �������� �� ����� ������������
		valid = (input / 100000 > 0) && (input / 1000000 == 0);

		if (!valid)
			std::cout << "�������� ���� ����� �� �������� ������������!\n\n";

	} while (!valid);

	// ��������� ������ � ����������� �� ����������, ������������� ��������
	if (isHappy(input))
		std::cout << "\n\n. : * �������� ���� ����� " << input << " - ����������! * : .";
	else
		std::cout << "\n\n�������� ���� ����� " << input << " �� �������� ����������...";

	// ���������� ������ ���������
	std::cout << "\n\n";
	system("pause");
	return 0;
}
