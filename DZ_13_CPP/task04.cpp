/* ЗАДАНИЕ 4
	Группа: ПВ-011
	Ученик: Шелест Александр
	task04.cpp содержит функцию, которая заменяет все символы точки в строке на символы восклицательного знака. */

#include <iostream>
#include <windows.h>

// вставляет заданный символ на заданную позицию в строке
void replaceDots(char* str, int* nReplaced)
{
	// для каждого символа в строке...
	for (int i = 0, len = strlen(str); i < len; i++)
	{
		// если текущий символ равен точке
		if (str[i] == '.')
		{
			// заменить текущий символ на восклицательный знак
			str[i] = '!';
			// инкрементировать количество заменённых символов
			(*nReplaced)++;
		}
	}
}

int main()
{
	// конфигурация раскладки консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// объявление переменных
	char test[] = "Все.точки.должны.измениться.на.знаки.восклицания,.иначе.что-то.пошло.не.по.плану...";
	char* str = new char[96];
	int nReplaced = 0;

	// вывод начального текста на экран
	std::cout << "\t-= Задание 4 =- \n - написать функцию, которая заменяет все символы точки \'.\' в строке," 
		<< "\nвведённой пользователем, на символы восклицательного знака \'!\'.\n\n";
	std::cout << "Введите строку, или же \"test\" для использования заготовки\n";
	std::cout << "максимальная длина строки - 96:\n";
	// ввод строки с клавиатуры
	std::cin.getline(str, 96);

	// проверка на кодовое слово
	// "в лоб", но для данного случая достаточно
	if (str[0] == 't' && str[1] == 'e' && str[2] == 's' && str[3] == 't')
		str = test;

	// вывод строки
	std::cout << "\nстрока - \"" << str << "\"\n";

	// вызов функции, которая заменит точки
	replaceDots(str, &nReplaced);

	// вывод изменённой строки
	std::cout << "\nстрока - \"" << str << "\"\n";
	std::cout << "\t- количество заменённых символов - " << nReplaced;

	// пауза и завершение программы
	std::cout << "\n\nНажмите любую клавишу для выхода из программы...";
	_getwch();		// получение любого символа с клавиатуры
	return 0;
}