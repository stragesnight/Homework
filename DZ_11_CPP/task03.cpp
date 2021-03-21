/* ЗАДАНИЕ 3

	Группа: ПВ-011
	Ученик: Шелест Александр

	task03.cpp содержит задачи из первых двух заданий, но с применением шаблонов */
#include <iostream>		// ввод-вывод данных
#include <algorithm>	// содержит алгоритм сортировки
#include <stdlib.h>		// содержит srand
#include <ctime>		// используется для задания ключа генерации

using namespace std;

// объявление размера матрицы глобальной константой
// *программа работает и при изменении этого значения*
// **таким образом получая матрицу любой размерности**
const int SIZE = 3;

/////////////////  ПЕРВОЕ ЗАДАНИЕ   /////////////////

template <class T>
void initMat(T in[SIZE * SIZE], T out[SIZE][SIZE])
{
	// преобразование одномерного массива
	// в матрицу размером SIZE
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			out[y][x] = in[y * SIZE + x];
}

template <class T>
void coutMat(T mat[SIZE][SIZE])
{
	cout << "\n - Матрица: \n\n";
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
			cout << mat[y][x] << "\t";

		cout << "\n\n";
	}

}

template <class T>
void minMaxMat(T mat[SIZE][SIZE])
{
	cout << "\n - Минимальный а максимальный элементы на главной диагонали: \n\n";

	T min = -1, max = -1;

	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			// если текущий элемент находится на главной диагонали
			if (x == y)
			{
				cout << "|" << mat[y][x] << "|" << "\t";

				// если текущий элемент больше максимального или максимальный элемент ещё не обновлялся
				if (mat[y][x] > max || max == -1)
					max = mat[y][x];
				// если текущий элемент меньше минимального или минимальный элемент ещё не обновлялся
				if (mat[y][x] < min || min == -1)
					min = mat[y][x];
			}
			else
				cout << " " << mat[y][x] << "\t";
		}

		cout << "\n\n";
	}

	cout << "\nМинимальный элемент на главной диагонали - " << min;
	cout << "\nМаксимальный элемент на главной диагонали - " << max << "\n\n";
}

template <class T>
void sortMat(T mat[SIZE][SIZE])
{
	cout << "\n - Сортировка матрицы...";

	for (int y = 0; y < SIZE; y++)
		// применение алгоритма сортировки из библиотеки algorithm
		// от ячейки первого элемента в ряду до ячейки последнего элемента
		sort(&mat[y][0], &mat[y][SIZE]);

	coutMat(mat);
}

/////////////////  ВТОРОЕ ЗАДАНИЕ  /////////////////

// параметры:
// - одномерный массив размером 10
// - два целых числа с начальным значением -1
template <class T>
T maxInArray(T in[10], T except1 = -1, T except2 = -1)
{
	T max = -1;

	for (int i = 0; i < 10; i++)
		// если текущий элемент больше максимального 
		// или максимальное значение ещё не одновлялось
		// и если текущий элемент не является исключением
		if ((in[i] > max || max == -1) && (in[i] != except1 && in[i] != except2))
			// обновить максимальное значение
			max = in[i];

	return max;
}

template <class T>
T maxInArray(T in[3][3])
{
	T max = -1;

	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (in[x][y] > max || max == -1)
				max = in[x][y];

	return max;
}

template <class T>
T maxInArray(T in[2][2][2])
{
	T max = -1;

	for (int z = 0; z < 2; z++)
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 3; x++)
				if (in[x][y][z] > max || max == -1)
					max = in[x][y][z];

	return max;
}

template <class T>
void maxIntInArray(T in[10], int* out1, int* out2)
{
	// переменные для содержания максимальных значений и исключений для поиска
	T max1, max2;
	// вызов поиска масимального элемента в одномерном массиве
	max1 = maxInArray(in);
	// второй вызов, на этот раз с исключением первого элемента
	max2 = maxInArray(in, max1);

	// присвоение параметрам нужных значений
	*out1 = max1;
	*out2 = max2;
}

template <class T>
void maxIntInArray(T in[10], int* out1, int* out2, int* out3)
{
	// переменные для содержания максимальных значений и исключений для поиска
	T max1, max2, max3;
	// вызов поиска масимального элемента в одномерном массиве
	max1 = maxInArray(in);
	// второй вызов, на этот раз с исключением первого элемента
	max2 = maxInArray(in, max1);
	// третий вызов с исключением первоых двух элементов
	max3 = maxInArray(in, max1, max2);

	// присвоение параметрам нужных значений
	*out1 = max1;
	*out2 = max2;
	*out3 = max3;
}

// сокращение получения случайного натурального числа
double rnd()
{
	return (rand() % 512) / 1.23;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "Домашнее задание №11, задание 3. Файл .cpp содержит в себе"
		 << "\nрешение первых двух задач, но с применением шаблонов функций."
		 << "\nНажмите Enter для тестирования этих двух программ.\n\n";

	cin.get();

	// перечисления для простоты работы с индексами типов данных
	enum dataType { INT = 1, DOUBLE, CHAR };

	int dataTypeIndex;
	int initRand;

	int inputINT[SIZE * SIZE] = {};
	double inputDOUBLE[SIZE * SIZE] = {};
	char inputCHAR[SIZE * SIZE] = {};

	cout << "Доступные типы данных:\n\t1 - int\n\t2 - double\n\t3 - char\n\n";
	cout << "Введите число, соответствующее желаемому типу данных: ";
	cin >> dataTypeIndex;

	cout << "\nВведите 0 для ввода данных вручную,\n\tили любую другую клавишу для случайной генерации - ";
	cin >> initRand;

	if (!initRand)
		cout << "\nПоследовательно введите " << SIZE * SIZE << " значения(-й) выбранного типа данных: ";

	// выбор типа данных в зависимости от выбора пользователя
	switch (dataTypeIndex)
	{
	case INT:
		// переменная, которая после инициализации будет описывать матрицу
		int matINT[SIZE][SIZE];

		// заполнение входных массивов данными
		for (int i = 0; i < SIZE * SIZE; i++)
			if (initRand)
				inputINT[i] = rnd();
			else
				cin >> inputINT[i];

		// вызов набора функций на выполненик
		initMat(inputINT, matINT);
		coutMat(matINT);
		minMaxMat(matINT);
		sortMat(matINT);

		break;

	case DOUBLE:
		double matDOUBLE[SIZE][SIZE];

		for (int i = 0; i < SIZE * SIZE; i++)
			if (initRand)
				inputDOUBLE[i] = rnd();
			else
				cin >> inputDOUBLE[i];

		initMat(inputDOUBLE, matDOUBLE);
		coutMat(matDOUBLE);
		minMaxMat(matDOUBLE);
		sortMat(matDOUBLE);

		break;

	case CHAR:
		char matCHAR[SIZE][SIZE];

		for (int i = 0; i < SIZE * SIZE; i++)
			if (initRand)
				inputCHAR[i] = rnd();
			else
				cin >> inputCHAR[i];

		initMat(inputCHAR, matCHAR);
		coutMat(matCHAR);
		minMaxMat(matCHAR);
		sortMat(matCHAR);

		break;
	}

	///////////////////   ЗАДАНИЕ 2   ///////////////////

	// объявление массивов с тестовыми значениями

	int narr[10] = { 63, 25, 66, 34, 34, 96, 12, 36, 67, 19 };
	int narr2D[3][3] = { { 12, 75, 23 }, { 63, 81, 15 } };
	int narr3D[2][2][2] = { {{64, 73}, {26, 13}}, {{67, 23}, {95, 45}} };

	double darr[10] = { 63.51, 2.512, 6.65342, 34.234, 5.1324, 91.563, 12.523, 3.64, 67.523, 1.91 };
	double darr2D[3][3] = { { 1.213, 75.52, 23.123 }, { 63.754, 81.735, 15.742 } };
	double darr3D[2][2][2] = { {{6.512344, 73.523}, {2.55236, 13.523}}, {{67.523, 233.542}, {95.634, 45.634}} };

	int max1, max2, max3;

	cout << "\n\n\n# ЗАДАНИЕ 2 #\n# содержание массивов можно просмотреть в файле программы #\n";

	cout << "\n - Максимальное число в одномерном массиве int - " << maxInArray(narr);
	cout << "\n - Максимальное число в двумерном массиве int - " << maxInArray(narr2D);
	cout << "\n - Максимальное число в трёхмерном массиве int - " << maxInArray(narr3D);
	maxIntInArray(narr, &max1, &max2);
	cout << "\n\n - 2 максимальных целых числа в массиве int - " << max1 << " и " << max2;
	maxIntInArray(narr, &max1, &max2, &max3);
	cout << "\n - 3 максимальных целых числа в массиве int - " << max1 << ", " << max2 << " и " << max3;

	cout << "\n\n\n - Максимальное число в одномерном массиве double - " << maxInArray(darr);
	cout << "\n - Максимальное число в двумерном массиве double - " << maxInArray(darr2D);
	cout << "\n - Максимальное число в трёхмерном массиве double - " << maxInArray(darr3D);
	maxIntInArray(darr, &max1, &max2);
	cout << "\n\n - 2 максимальных целых числа в массиве double - " << max1 << " и " << max2;
	maxIntInArray(darr, &max1, &max2, &max3);
	cout << "\n - 3 максимальных целых числа в массиве double - " << max1 << ", " << max2 << " и " << max3;

	// завершеные работы программы
	cout << "\n\n";
	system("pause");
	return 0;
}
