/* ЗАДАНИЕ 6

	Группа: ПВ-011
	Ученик: Шелест Александр

	task06.cpp выводит на экран сумму пяти случайных чисел в диапазоне от А до В. */
// Библиотека для работы с вводом-выводом данных
#include <iostream>
// Библиотека нужная для указания "сида"("отправной точки") генератора случайных чисел
#include <stdlib.h>
// Библиотека для получения доступа к системному времени
#include <time.h>

// Вызов этой комманды позволит не обращаться к std вручную
using namespace std;

// Основная функция программы
int main()
{
	// Добавление поддержки кириллицы
	setlocale(LC_ALL, "Ukrainian");
	// Изменение "сида"("отправной точки") генератора случайных чисел
	srand(time(NULL));

	int A, B;
	int summ = 0, currTemp;

	// Вывод начального текста на экран и сбор данных с клавиатуры
	cout << "\tВведiть цiлi числа дiапазону вiд А до В (A<B): ";
	cin >> A >> B;

	cout << endl;

	for (int i = 1; i <= 5; i++)
	{
		// Генерация числа в диапазоне от А до В
		currTemp = rand() % (B - A) + A;
		summ += currTemp;

		cout << "\n\tчисло " << i << " = " << currTemp;
	}

	cout << "\n\n\tСума п’яти чисел вiд " << A << " до " << B << " = " << summ << "\n\n\n";

	// Пауза программы
	system("pause");
	// Объявление успешного завершения программы
	return 0;
}