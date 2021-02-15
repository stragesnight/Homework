/* ЗАДАНИЕ 8

	Группа: ПВ-011
	Ученик: Шелест Александр

	task8.cpp Вычисляет разницу между двумя введёнными пользователем датами
	Этот метод я бы назвал "грязным", так как на стадии с месяцами данные были введены вручную */

// Загрузка необходимой для работы с вводом-выводом данных библиотеки
#include <iostream>
// Загрузка библиотеки для работы с математическими функциями
// В данной программе используется для нахождения модуля чисел
#include <cmath>
// Вызов этой комманды позволит не обращаться к std вручную
using namespace std;

// Основная функция программы
int main()
{
	// Добавление поддержки кириллицы
	setlocale(LC_ALL, "Russian");

	// Перечисление месяцев для удобства написания программы
	enum Months { January = 1, Febreuary, March, April, May, June, July, August, September, October, November, December };

	// Объявление переменных
	int day1, month1, year1, totalDays1 = 0;
	int day2, month2, year2, totalDays2 = 0;
	long totalDayDiff;

	// Вывод начального текста на экран
	cout << "Вычисление разницы (в днях) между двумя введённыеми датами";

	// Запрос на ввод данных с клавиатуры
	cout << "\nПоследовательно введите три целых числа ПЕРВОЙ даты (день -> месяц -> год):\n";
	cin >> day1 >> month1 >> year1;
	cout << "\nПоследовательно введите три целых числа ВТОРОЙ даты (день -> месяц -> год):\n";
	cin >> day2 >> month2 >> year2;

	// Выичсление общего количества дней обеих дат

	// ПЕРВАЯ ДАТА
	// К общему количеству дней прибавить введённые дни
	totalDays1 += day1;

	// Вычисление дней, прошедших за прошлые месяца в этом году
	switch (month1)
	{
	case January:
		break;
	case Febreuary:
		totalDays1 += 31;
		break;
	case March:
		totalDays1 += 59;
		break;
	case April:
		totalDays1 += 90;
		break;
	case May:
		totalDays1 += 120;
		break;
	case June:
		totalDays1 += 151;
		break;
	case July:
		totalDays1 += 181;
		break;
	case August:
		totalDays1 += 212;
		break;
	case September:
		totalDays1 += 243;
		break;
	case October:
		totalDays1 += 273;
		break;
	case November:
		totalDays1 += 304;
		break;
	case December:
		totalDays1 += 334;
	default:
		cout << "\nВведены некорректные данные.";
		return 0;
	}

	// Общее количество дней в годах = количество лет * 365 + количество прошедших високосных лет
	totalDays1 += year1 * 365 + (year1 / 4);


	// ВТОРАЯ ДАТА
	// К общему количеству дней прибавить введённые дни
	totalDays2 += day2;

	// Вычисление дней, прошедших за прошлые месяца в этом году
	switch (month2)
	{
	case January:
		break;
	case Febreuary:
		totalDays2 += 31;
		break;
	case March:
		totalDays2 += 59;
		break;
	case April:
		totalDays2 += 90;
		break;
	case May:
		totalDays2 += 120;
		break;
	case June:
		totalDays2 += 151;
		break;
	case July:
		totalDays2 += 181;
		break;
	case August:
		totalDays2 += 212;
		break;
	case September:
		totalDays2 += 243;
		break;
	case October:
		totalDays2 += 273;
		break;
	case November:
		totalDays2 += 304;
		break;
	case December:
		totalDays2 += 334;
	default:
		cout << "\nВведены некорректные данные.";
		return 0;
	}

	// Общее количество дней в годах = количество лет * 365 + количество прошедших високосных лет
	totalDays2 += year2 * 365 + (year2 / 4);

	// Разница между датами равна модулю разницы общего количества дней
	totalDayDiff = abs(totalDays2 - totalDays1);

	// Вывод результата на экран
	cout << "\nРазница между введёнными датами (в днях) : " << totalDayDiff << endl;

	// Пауза программы
	system("pause");
	// Объявление успешного завершения программы
	return 0;
}