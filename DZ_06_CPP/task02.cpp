/* ЗАДАНИЕ 2

	Группа: ПВ-011
	Ученик: Шелест Александр

	task02.cpp выводит на экран числа от А до В в порядке возрастания, а также количество выведенных чисел. */
// Загрузка необходимой для работы с вводом-выводом данных библиотеки
#include <iostream>
// Вызов этой комманды позволит не обращаться к std вручную
using namespace std;

// Основная функция программы
int main()
{
	// Добавление поддержки кириллицы
	setlocale(LC_ALL, "Russian");

	int A, B;

	// Вывод начального текста на экран и сбор данных с клавиатуры
	cout << "\tВведiть цiлi числа A i B (A<B): ";
	cin >> A >> B;
	cout << endl;

	if (A < B)
	{
		for (int i = A; i <= B; i++)
		{
			cout << "\tчисло " << i << endl;
		}

		cout << "\n\n\tКiлькiсть чисел N = " << B - A + 1 << "\n\n";
	}
	else
		cout << "A > B!\n";


	// Пауза программы
	system("pause");
	// Объявление успешного завершения программы
	return 0;
}