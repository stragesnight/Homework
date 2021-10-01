/* ЗАДАНИЕ 2

	Группа: ПВ-011
	Ученик: Шелест Александр

	task02.cpp показывает некоторые статистичесукие данные фирмы за год (мин. и макс. прибыль в месяц в указанном диапазоне). */
// Библиотека для работы с вводом-выводом данных
#include <iostream>
// Библиотека нужная для получения доступа к srand()
#include <stdlib.h>
// Библиотека нужная для получения системного времени
#include <time.h>

// Вызов этой комманды позволит не обращаться к std вручную
using namespace std;

// Основная функция программы
int main()
{
	// Добавление поддержки кириллицы
	setlocale(LC_ALL, "Russian");
	// Используя эту команду программа каждый раз будет генерировать разные числа
	srand(time(NULL));

	float income[12];
	int rangeFrom = 0, rangeTo = 0;

	// Вывод начального текста
	cout << "= Финансовая статистика фирмы за год. =\n";
	cout << "\nПоследовательно введите доход фирмы за 12 месяцев \n(введите 0 для заполнения массива случайными числами) : ";

	cin >> income[0];
	if (income[0] == 0)
	{
		// Присвоение элементам массива случайных значений
		for (int i = 0; i < 12; i++)
			income[i] = rand() % 999 + 1;
	}
	else
	{
		// Введение данных
		for (int i = 1; i < 12; i++)
			cin >> income[i];
	}

	// Введение диапазона и убеждение в том, что числа разные
	do
	{
		cout << "\nВведите диапазон проверки (от .. , до .. включительно): ";
		cin >> rangeFrom >> rangeTo;

		if (rangeFrom == rangeTo)
			cout << "\nВведите два разных месяца!";

	} while (rangeFrom == rangeTo);

	// Если нижняя граница диапазона выше верхней...
	if (rangeFrom > rangeTo)
	{
		// Перевернуть значения для корректности работы программы
		float tmp = rangeFrom;
		rangeFrom = rangeTo;
		rangeTo = tmp;
	}

	int indexMin = 0, indexMax = 0;
	// Проверка индекса минимального и максимального значение в диапазоне
	for (int i = rangeFrom; i < rangeTo; i++)
	{
		if (income[i] > income[indexMax] || i == rangeFrom)
			indexMax = i;
		else if (income[i] < income[indexMin] || i == rangeFrom)
			indexMin = i;
	}

	system("cls");

	cout << "|| Статистика доходов от " << rangeFrom << "-го до " << rangeTo << "-го месяца ||\n\n";

	for (int i = 0; i < 12; i++)
		cout << "|  " << income[i] << "\t";

	cout << "|\n";

	// Флаг координации рисуемого текста
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

	cout << "\n\n\tМаксимальный доход в диапазоне фирма получила за " << indexMax + 1 << "-й месяц. Сумма дохода: " << income[indexMax];
	cout << "\n\tМинимальный доход в диапазоне фирма получила за " << indexMin + 1 << "-й месяц. Сумма дохода: " << income[indexMin];

	cout << "\n\n";

	// Пауза программы
	system("pause");
	// Объявление успешного завершения программы
	return 0;
}
