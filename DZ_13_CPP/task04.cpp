/* ������� 4
	������: ��-011
	������: ������ ���������
	task04.cpp �������� �������, ������� �������� ��� ������� ����� � ������ �� ������� ���������������� �����. */

#include <iostream>
#include <windows.h>

// ��������� �������� ������ �� �������� ������� � ������
void replaceDots(char* str, int* nReplaced)
{
	// ��� ������� ������� � ������...
	for (int i = 0, len = strlen(str); i < len; i++)
	{
		// ���� ������� ������ ����� �����
		if (str[i] == '.')
		{
			// �������� ������� ������ �� ��������������� ����
			str[i] = '!';
			// ���������������� ���������� ���������� ��������
			(*nReplaced)++;
		}
	}
}

int main()
{
	// ������������ ��������� �������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ���������� ����������
	char test[] = "���.�����.������.����������.��.�����.�����������,.�����.���-��.�����.��.��.�����...";
	char* str = new char[96];
	int nReplaced = 0;

	// ����� ���������� ������ �� �����
	std::cout << "\t-= ������� 4 =- \n - �������� �������, ������� �������� ��� ������� ����� \'.\' � ������," 
		<< "\n�������� �������������, �� ������� ���������������� ����� \'!\'.\n\n";
	std::cout << "������� ������, ��� �� \"test\" ��� ������������� ���������\n";
	std::cout << "������������ ����� ������ - 96:\n";
	// ���� ������ � ����������
	std::cin.getline(str, 96);

	// �������� �� ������� �����
	// "� ���", �� ��� ������� ������ ����������
	if (str[0] == 't' && str[1] == 'e' && str[2] == 's' && str[3] == 't')
		str = test;

	// ����� ������
	std::cout << "\n������ - \"" << str << "\"\n";

	// ����� �������, ������� ������� �����
	replaceDots(str, &nReplaced);

	// ����� ���������� ������
	std::cout << "\n������ - \"" << str << "\"\n";
	std::cout << "\t- ���������� ���������� �������� - " << nReplaced;

	// ����� � ���������� ���������
	std::cout << "\n\n������� ����� ������� ��� ������ �� ���������...";
	_getwch();		// ��������� ������ ������� � ����������
	return 0;
}