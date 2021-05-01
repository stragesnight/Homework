/* ������� 1
	������: ��-011
	������: ������ ���������
	task01.cpp - ���������, ����������� ��������� ���������� � �������������� � ��� */

#include <iostream>
#include <windows.h>

// ������������ ��� �������� ��������� ���������
enum TRANSMISSION_TYPE { MANUAL, AUTOMATIC };
enum MENU_ACTION { EXIT, DISPLAY, EDIT, FIND };

// ���������, ����������� ���������
struct Engine
{
	float volume;
	float power;
};

// ���������, ����������� ������
struct Car
{
	float length;
	float clearance;
	Engine engine;
	float wheel_diameter;
	std::string color;
	int transmission;
};

// ����� ���������� �� ���������� �� �����
void displayCarInfo(const Car& car)
{
	std::cout << "\n1. ����� - " << car.length << " ��;";
	std::cout << "\n2. ������� - " << car.clearance << " ��;";
	std::cout << "\n-  ���������: ";
	std::cout << "\n     3. ����� - " << car.engine.volume << " �;";
	std::cout << "\n     4. �������� - " << car.engine.power << " ���;";
	std::cout << "\n5. ������� ���� - " << car.wheel_diameter << " ��;";
	std::cout << "\n6. ���� - " << car.color;
	std::cout << "\n7. ��� ������� ������� - ";
	if (car.transmission == MANUAL)
		std::cout << "������";
	else
		std::cout << "��������������";
}

// �������������� ���������� �� ����������
void editCarInfo(Car& car)
{
	// ����� ���������� �� ���������� �� ����� ��� �������� ������������
	displayCarInfo(car);

	// ���� ������ � ����������
	int input;
	std::cout << "\n\n������� �������� ��� ��������� �������� �� ��� ������ � ������: ";
	std::cin >> input;

	// ���� ������ �������� � ����������
	std::cout << "\n\n������� ����� �������� ��� ";
	// ����� ������� ��� ��������� ���������
	switch (input)
	{
		case 1:
		{
			std::cout << "����� (��): ";
			std::cin >> car.length;
			break;
		}
		case 2:
		{
			std::cout << "�������� (��): ";
			std::cin >> car.clearance;
			break;
		}
		case 3:
		{
			std::cout << "������ ��������� (�): ";
			std::cin >> car.engine.volume;
			break;
		}
		case 4:
		{
			std::cout << "�������� ��������� (���): ";
			std::cin >> car.engine.power;
			break;
		}
		case 5:
		{
			std::cout << "�������� ���� (��)";
			std::cin >> car.wheel_diameter;
			break;
		}
		case 6:
		{
			std::cout << "����� (������): ";
			std::cin >> car.color;
			break;
		}
		case 7:
		{
			std::cout << "���� ������� ������� (0 - ������, 1 - ����): ";
			std::cin >> car.transmission;
			break;
		}
		// ����� ������ � ������ �������� ��������� ������ ����
		default:
		{
			for (int i = 0; i < 64; i++)
				std::cout << "\b";
			std::cout << "������ �������� ����� ����.";
			return;
		}
	}

	std::cout << "\n\n���������� �� ���������� �������� �������.";
}

// ����� ���������� �� ����������
void findCarInfo(const Car& car)
{
	// ����� ����� ��� ������
	std::cout << "\n1. �����;";
	std::cout << "\n2. �������;";
	std::cout << "\n-  ���������: ";
	std::cout << "\n     3. �����;";
	std::cout << "\n     4. ��������;";
	std::cout << "\n5. ������� ����;";
	std::cout << "\n6. ����;";
	std::cout << "\n7. ��� ������� �������;";

	// ���� ������ � ����������
	int input;
	std::cout << "\n\n������� �������� ��� ������ �������� �� ��� ������ � ������: ";
	std::cin >> input;
	std::cout << '\n';

	// ����� ���� ��� ������
	switch (input)
	{
		case 1:
		{
			std::cout << "����� - " << car.length << " ��";
			break;
		}
		case 2:
		{
			std::cout << "�������-  " << car.clearance << " ��";
			break;
		}
		case 3:
		{
			std::cout << "����� ��������� - " << car.engine.volume << " �";
			break;
		}
		case 4:
		{
			std::cout << "�������� ��������� - " << car.engine.power << " ���";
			break;
		}
		case 5:
		{
			std::cout << "������� ���� - " << car.wheel_diameter << " ��";
			break;
		}
		case 6:
		{
			std::cout << "����: " << car.color;
			break;
		}
		case 7:
		{
			std::cout << "��� ������� ������� - ";
			if (car.transmission == MANUAL)
				std::cout << "������";
			else
				std::cout << "��������������";
			break;
		}
		// ����� ������ � ������ �������� ��������� ������ ����
		default:
		{
			for (int i = 0; i < 64; i++)
				std::cout << "\b";
			std::cout << "������ �������� ����� ����.";
			return;
		}
	}
}

int main()
{
	// ������������ ��������� �������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ����� ���������� ������ �� �����
	std::cout << "\t-= ������� 1 =- \n - ���������, ����������� ��������� ���������� � �������������� � ���\n";
	std::cout << "\n\n������� ����� ������� ��� ������ � ����...";
	_getwch();
	system("cls");

	// ���������� ������� ���������
	Car car = { 293, 11, 1.6f, 81, 31, "�����", 1 };

	// ����������, �������� ��������� ������������� ����� ����
	int user_action = DISPLAY;
	while (user_action != EXIT)
	{
		system("cls");

		// ����� ���� �� �����
		std::cout	<< "+==================+\n"
					<< "|       ����       |\n"
					<< "+==================+\n";
		std::cout << "\n1. ���������� �� ����������;";
		std::cout << "\n2. �������������� ����������;";
		std::cout << "\n3. �����;";
		std::cout << "\n\n0. ����� �� ���������;";
		// ���� ������ � ����������
		std::cout << "\n\n������� �������� �� ��� ������ � ����: ";
		std::cin >> user_action;
		system("cls");

		// ����� �������� � ����������� �� ������ ������������
		switch (user_action)
		{
			case DISPLAY:
			{
				std::cout	<< "+==================================+\n"
							<< "|     ���������� �� ����������     |\n"
							<< "+==================================+\n";
				displayCarInfo(car);

				break;
			}
			case EDIT:
			{
				std::cout	<< "+==================================+\n"
							<< "|       ��������� ����������       |\n"
							<< "|          �� ����������           |\n"
							<< "+==================================+\n";
				editCarInfo(car);

				break;
			}
			case FIND:
			{
				std::cout	<< "+==================================+\n"
							<< "|         ����� ����������         |\n"
							<< "|          �� ����������           |\n"
							<< "+==================================+\n";
				findCarInfo(car);
				break;
			}
			case EXIT:
			{
				return 0;
			}
			// ����� ������ � ������ �������� ��������� ������ ����
			default:
			{
				std::cout << "������ �������� ����� ����.";
				break;
			}
		}

		// �����
		std::cout << "\n\n������� ����� ������� ��� ������ � ����...";
		_getwch();		// ��������� ������ ������� � ����������
	}

	// ���������� ���������
	return 0;
}
