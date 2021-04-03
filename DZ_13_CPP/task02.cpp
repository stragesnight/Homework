/* ������� 2
	������: ��-011
	������: ������ ���������
	task02.cpp �������� �������, ������� ������� ��� ��������� ���������� ������������� ������� �� ������ */

#include <iostream>
#include <windows.h>

// ������� ��� ��������� ��������� ������� � ������
// � ���������� ���������� �������� ��������
void removeSymbol(char* str, char charToRemove, int* nRemoved)
{
	// ��� ������� ������� � ������...
	for (int i = 0; str[i] != '\0'; i++)
	{
		// ���� ������� ������ ����� ������...
		if (str[i] == charToRemove)
		{
			// �������� ��� ����������� ������� �� ���� ������ ����
			// ��� ����� ������ �������� ������
			for (int j = i; str[j] != '\0'; j++)
				str[j] = str[j + 1];

			// ��������� ���������� �������� ��������
			(*nRemoved)++;
			// ����������� �� ���� ������ �����
			// � ������ ���� ���� �������� �������� ����� ���� ������
			i--;
		}
	}
}

int main()
{
	// ������������ ��������� �������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ���������� ����������
	char test[] = "��� ��������� ��������� ������� ������ ��������, ����� ���-�� ����� �� �� �����...";
	char* str = new char[96];
	char removeChar[2];		// ������������� ������� ��� ���������� ������� ��������� ����
	int nRemoved = 0;

	// ����� ���������� ������ �� �����
	std::cout << "\t-= ������� 2 =- \n - �������� �������, ������� ������� �� ������ ��� ��������� ��������� �������.\n\n";
	std::cout << "������� ������, ��� �� \"test\" ��� ������������� ���������\n";
	std::cout << "������������ ����� ������ - 96:\n";
	// ���� ������ � ����������
	std::cin.getline(str, 96);

	// �������� �� ������� �����
	// "� ���", �� ��� ������� ������ ����������
	if (str[0] == 't' && str[1] == 'e' && str[2] == 's' && str[3] == 't')
		str = test;

	// ���� �������
	std::cout << "\n������� ������, ������� ����� ����� �� ������ (��������, ������ - \' \'): ";
	// getline ������������ ��� ����������� ����� ������������� �������
	// ������ ��������� ������ � ������ - ������ \0
	// ��� ���������� ������������ ������ ��� ����� �������,			removeChar == { '<����� ������>', '\0' }
	// ������� �� ������ ����� ��� ������, � �� ������ - \0
	std::cin.getline(removeChar, 2);

	system("cls");

	// ����� ������
	std::cout << "������ - \"" << str << "\"";

	std::cout << "\n���� �����������...\n";
	// ����� �������, ������� ������ �������
	// ������ ���������� ���� ��� ������, �.�. �� ������ � �������
	removeSymbol(str, removeChar[0], &nRemoved);

	// ����� ���������� ������
	std::cout << "\n������ - \"" << str << "\"\n";
	std::cout << "\t- �������� ������ - \'" << removeChar << "\', �� ���������� � ������ - " << nRemoved;

	// ����� � ���������� ���������
	std::cout << "\n\n\n������� ����� ������� ��� ������ �� ���������...";
	_getwch();		// ��������� ������ ������� � ����������
	return 0;
}