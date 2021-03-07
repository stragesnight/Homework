/* ������� 3

	������: ��-011
	������: ������ ���������

	task03.cpp ������� �� ����� "�������������" ����� � ��������� ������������� ��������� ��� ������ ������� */
#include <iostream>


void calculate(int a, int b, bool showAll)
{
	// ���� � ��������� �� a �� b
	// ���������� ����������� ���������� ����������, ��� ��� ��� � ��� ��� ����
	for (; a < b; a++)
	{
		int sum = 0;

		// ����, ������������ ����� ���� ��������� ����� �
		for (int i = 1; i < a; i++)
		{
			// ���� ������ �� ������� ����� ����...
			if (a % i == 0)
				sum += i;
		}

		// ����������, ������� ������� � ����������� ������ ����� " ��", ���� ����� �� �������� �����������
		const char *modifier = sum == a ? "" : " ��";

		// ������� ����������� �� ����� ���� ���� ����� �������� ����������
		// ��� ���� ������� ����� ����������� ���� �����������
		if (sum == a || showAll)
			std::cout << "����� " << a << modifier << " �������� �����������.\n";
	}
}

int main()
{
	std::setlocale(LC_ALL, "Russian");

	int a, b;
	bool showAll;

	std::cout << "= ���������� \"�������������\" ����� �� ���������� ������������ ��������� ��� ������ ������� =";
	// �������� ������ � �������� �� �� ������������
	do
	{
		std::cout << "\n\n������� ��� ����� - ������ � ������� ������� ���������: ";
		std::cin >> a >> b;

		if (a == b)
			std::cout << "\n��� ���������� ������ ��������� ��������� ��� ������ �����.";

	} while (a == b);

	std::cout	<< "\n\n-- ����� ������ --\n"
				<< "\n0 - ��������� ������ ��� �����, ������� ������������� �������;"
				<< "\n1 - ��������� ���� ����� � ����������� ���������.";

	std::cout << "\n\n������� ����� ������: ";
	std::cin >> showAll;
	std::cout << "\n\n";

	// ��������� � ���, ��� ������ ������� ������ ����� ���� �������
	if (a > b)
		std::swap(a, b);

	// ����� ������� �� ����������
	calculate(a, b, showAll);

	// ���������� ������ ���������
	std::cout << "\n\n";
	system("pause");
	return 0;
}