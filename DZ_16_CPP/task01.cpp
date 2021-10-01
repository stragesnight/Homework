/* ЗАДАНИЕ 1
	Группа: ПВ-011
	Ученик: Шелест Александр
	task01.cpp - программа, реализующая структуру автомобиля и взаимодействия с ней */

#include <iostream>
#include <windows.h>

// перечисления для удобства написания программы
enum TRANSMISSION_TYPE { MANUAL, AUTOMATIC };
enum MENU_ACTION { EXIT, DISPLAY, EDIT, FIND };

// структура, описывающая двигатель
struct Engine
{
	float volume;
	float power;
};

// структура, описывающая машину
struct Car
{
	float length;
	float clearance;
	Engine engine;
	float wheel_diameter;
	std::string color;
	int transmission;
};

// вывод информации об автомобиле на экран
void displayCarInfo(const Car& car)
{
	std::cout << "\n1. Длина - " << car.length << " см;";
	std::cout << "\n2. Клиренс - " << car.clearance << " см;";
	std::cout << "\n-  Двигатель: ";
	std::cout << "\n     3. Объем - " << car.engine.volume << " л;";
	std::cout << "\n     4. Мощность - " << car.engine.power << " кВт;";
	std::cout << "\n5. Диаметр колёс - " << car.wheel_diameter << " см;";
	std::cout << "\n6. Цвет - " << car.color;
	std::cout << "\n7. Тип коробки передач - ";
	if (car.transmission == MANUAL)
		std::cout << "ручная";
	else
		std::cout << "автоматическая";
}

// редактирование информации об автомобиле
void editCarInfo(Car& car)
{
	// вывод информации об автомобиле на экран для удобства пользователя
	displayCarInfo(car);

	// ввод данных с клавиатуры
	int input;
	std::cout << "\n\nВведите желаемый для изменения параметр по его номеру в списке: ";
	std::cin >> input;

	// ввод нового значение с клавиатуры
	std::cout << "\n\nВведите новое значение для ";
	// поиск нужного для изменения параметра
	switch (input)
	{
		case 1:
		{
			std::cout << "длины (см): ";
			std::cin >> car.length;
			break;
		}
		case 2:
		{
			std::cout << "клиренса (см): ";
			std::cin >> car.clearance;
			break;
		}
		case 3:
		{
			std::cout << "объема двигателя (л): ";
			std::cin >> car.engine.volume;
			break;
		}
		case 4:
		{
			std::cout << "мощности двигателя (кВт): ";
			std::cin >> car.engine.power;
			break;
		}
		case 5:
		{
			std::cout << "диаметра колёс (см)";
			std::cin >> car.wheel_diameter;
			break;
		}
		case 6:
		{
			std::cout << "цвета (строка): ";
			std::cin >> car.color;
			break;
		}
		case 7:
		{
			std::cout << "типа коробки передач (0 - ручная, 1 - авто): ";
			std::cin >> car.transmission;
			break;
		}
		// вывод ошибки в случае введенмя неверного пункта меню
		default:
		{
			for (int i = 0; i < 64; i++)
				std::cout << "\b";
			std::cout << "Выбран неверный пункт меню.";
			return;
		}
	}

	std::cout << "\n\nИнформация об автомобиле изменена успешно.";
}

// поиск информации об автомобиле
void findCarInfo(const Car& car)
{
	// вывод полей для поиска
	std::cout << "\n1. Длина;";
	std::cout << "\n2. Клиренс;";
	std::cout << "\n-  Двигатель: ";
	std::cout << "\n     3. Объем;";
	std::cout << "\n     4. Мощность;";
	std::cout << "\n5. Диаметр колёс;";
	std::cout << "\n6. Цвет;";
	std::cout << "\n7. Тип коробки передач;";

	// ввод данных с клавиатуры
	int input;
	std::cout << "\n\nВведите желаемый для поиска параметр по его номеру в списке: ";
	std::cin >> input;
	std::cout << '\n';

	// выбор поля для вывода
	switch (input)
	{
		case 1:
		{
			std::cout << "Длина - " << car.length << " см";
			break;
		}
		case 2:
		{
			std::cout << "Клиренс-  " << car.clearance << " см";
			break;
		}
		case 3:
		{
			std::cout << "Объем двигателя - " << car.engine.volume << " л";
			break;
		}
		case 4:
		{
			std::cout << "Мощность двигателя - " << car.engine.power << " кВт";
			break;
		}
		case 5:
		{
			std::cout << "Диаметр колёс - " << car.wheel_diameter << " см";
			break;
		}
		case 6:
		{
			std::cout << "Цвет: " << car.color;
			break;
		}
		case 7:
		{
			std::cout << "Тип коробки передач - ";
			if (car.transmission == MANUAL)
				std::cout << "ручная";
			else
				std::cout << "автоматическая";
			break;
		}
		// вывод ошибки в случае введения неверного пункта меню
		default:
		{
			for (int i = 0; i < 64; i++)
				std::cout << "\b";
			std::cout << "Выбран неверный пункт меню.";
			return;
		}
	}
}

int main()
{
	// конфигурация раскладки консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// вывод начального текста на экран
	std::cout << "\t-= Задание 1 =- \n - программа, реализующая структуру автомобиля и взаимодействия с ней\n";
	std::cout << "\n\nнажмите любую клавишу для выхода в меню...";
	_getwch();
	system("cls");

	// объявления объекта структуры
	Car car = { 293, 11, 1.6f, 81, 31, "белый", 1 };

	// переменная, хранящая выбранный пользователем пункт меню
	int user_action = DISPLAY;
	while (user_action != EXIT)
	{
		system("cls");

		// вывод меню на экран
		std::cout	<< "+==================+\n"
					<< "|       МЕНЮ       |\n"
					<< "+==================+\n";
		std::cout << "\n1. Информация об автомобиле;";
		std::cout << "\n2. Редактирование параметров;";
		std::cout << "\n3. Поиск;";
		std::cout << "\n\n0. Выход из программы;";
		// ввод данных с клавиатуры
		std::cout << "\n\nвведите действие по его номеру в меню: ";
		std::cin >> user_action;
		system("cls");

		// выбор действия в зависимости от выбора пользователя
		switch (user_action)
		{
			case DISPLAY:
			{
				std::cout	<< "+==================================+\n"
							<< "|     ИНФОРМАЦИЯ ОБ АВТОМОБИЛЕ     |\n"
							<< "+==================================+\n";
				displayCarInfo(car);

				break;
			}
			case EDIT:
			{
				std::cout	<< "+==================================+\n"
							<< "|       ИЗМЕНЕНИЕ ИНФОРМАЦИИ       |\n"
							<< "|          ОБ АВТОМОБИЛЕ           |\n"
							<< "+==================================+\n";
				editCarInfo(car);

				break;
			}
			case FIND:
			{
				std::cout	<< "+==================================+\n"
							<< "|         ПОИСК ИНФОРМАЦИИ         |\n"
							<< "|          ОБ АВТОМОБИЛЕ           |\n"
							<< "+==================================+\n";
				findCarInfo(car);
				break;
			}
			case EXIT:
			{
				return 0;
			}
			// вывод ошибки в случае введения неверного пункта меню
			default:
			{
				std::cout << "выбран неверный пункт меню.";
				break;
			}
		}

		// пауза
		std::cout << "\n\nНажмите любую клавишу для выхода в меню...";
		_getwch();		// получение любого символа с клавиатуры
	}

	// завершение программы
	return 0;
}
