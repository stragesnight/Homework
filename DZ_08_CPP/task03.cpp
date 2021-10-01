/* ЗАДАНИЕ 3

	Группа: ПВ-011
	Ученик: Шелест Александр

	task03.cpp производит операции над элементами массива и выводит результаты на экран. */
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

	float numbers[100];

	int n;
	int indexMin = -1, indexMax = -1;
	int indexFirstNegative = -1, indexLastNegative = -1;
	long float sumNegative = 0, multiplicationMinMax = 1, multiplicationEven = 1, sumMinMaxNegative = 0;

	// Вывод начального текста
	cout << "Программа для проведения различных операций над элементами массива.\n";

	// Сбор данных и проверка их подлинности
	do
	{
		cout << "Введите количество элементов массива (1 - 100): ";
		cin >> n;

		if (n < 1 || n > 100)
			cout << "Введите корректные данные!\n\n";

	} while (!(n > 1 && n < 100));

	cout << "\nПоследовательно введите элементы массива\n(введите 0 для заполнения массива случайными значениями): ";
	cin >> numbers[0];

	// Если введено число 0 - заполнить массив случайными вещественными числами
	if (numbers[0] == 0)
		for (int i = 0; i < n; i++)
			numbers[i] = rand() / 22.12 - 740.;
	// Иначе - собрать данные с клавиатуры
	else
		for (int i = 1; i < n; i++)
			cin >> numbers[i];

	cout << "\n\n";

	// Проверка индексов максимального и минимального значений элементов массива
	// А также индекса первого и последнего отрицательного элемента
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
		// Вынесение текущего элемента в переменную для простоты обращения
		float curr = numbers[i];

		cout << curr << "\n";

		// Проверка нужных для задачи условий...
		// Сумма отрицательных
		if (curr < 0)
			sumNegative += curr;

		// Сумма элементов между минимальным и максимальным значением
		if (indexMin < indexMax)
		{
			if (i > indexMin && i < indexMax)
				multiplicationMinMax *= curr;
		}
		else
			if (i < indexMin && i > indexMax)
				multiplicationMinMax *= curr;

		// Произведение чётных
		if (i % 2 == 0)
			multiplicationEven *= curr;

		// Сумма элементов между первым и последним орицательными
		if (i > indexFirstNegative && i < indexLastNegative)
			sumMinMaxNegative += curr;
	}

	cout << "\n\n1. Сумма отрицательных элементов: " << sumNegative;
	cout << "\n2. Произведение элементов, находящихся между минимальным и максимальным значением: " << multiplicationMinMax;
	cout << "\n3. Произведение элементов с чётными номерами: " << multiplicationEven;
	cout << "\n4. Сумма элементов, находящихся между первым и последним отрицательными элементами: " << sumMinMaxNegative << "\n\n\n";

	// Пауза программы
	system("pause");
	// Объявление успешного завершения программы
	return 0;
}
