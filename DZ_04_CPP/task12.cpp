/* ЗАДАНИЕ 12

	Группа: ПВ-011
	Ученик: Шелест Александр

	task12.cpp вычисляет сезон, в котором находится введённый пользователем номер месяца */

// Загрузка необходимой для работы с вводом-выводом данных библиотеки
#include <iostream>
// Вызов этой комманды позволит не обращаться к std вручную
using namespace std;

// Основная функция программы
int main()
{
	// Добавление поддержки кириллицы
	setlocale(LC_ALL, "Russian");

	// Объявление переменных
	int month;

	// Вывод начального текста на экран
	cout << "Программа покажет, в какой поре года находится введённый вами месяц";

	// Запрос на ввод данных с клавиатуры
	cout << "\nВведите номер месяца (1-12): ";
	cin >> month;

	// Если введённый номер месяца находится в нужном диапазоне...
	if (month >= 1 && month <= 12)
	{
		// Выведение текста для соответствующего времени года
		switch (month)
		{
		case 3:
		case 4:
		case 5:
			cout << "\nВесна\n\n";
			break;
		case 6:
		case 7:
		case 8:
			cout << "\nЛето\n\n";
			break;
		case 9:
		case 10:
		case 11:
			cout << "\nОсень\n\n";
			break;
		case 12:
		case 1:
		case 2:
			cout << "\nЗима\n\n";
			break;
		}
	}
	else
		cout << "\nВведены некорректные данные";

	// Вывод результата на экран

	// Пауза программы
	system("pause");
	// Объявление успешного завершения программы
	return 0;
}