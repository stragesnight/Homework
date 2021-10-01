/* ЗАДАНИЕ 1

	Группа: ПВ-011
	Ученик: Шелест Александр

	task01.cpp содержит перегруженные функции для работы с матрицами */
#include <iostream>		// ввод-вывод данных
#include <algorithm>	// содержит алгоритм сортировки
#include <stdlib.h>		// содержит srand
#include <ctime>		// используется для задания ключа генерации

using namespace std;

// объявление размера матрицы глобальной константой
// *программа работает и при изменении этого значения*
// **таким образом получая матрицу любой размерности**
const int SIZE = 3;


/////////////////////////////////////////////
// - комментарии были написаны только для  //
//  одного типа данных для экономии места  //
/////////////////////////////////////////////


//////////////////    INT    ////////////////
void initMat(int in[SIZE * SIZE], int out[SIZE][SIZE])
{
	// преобразование одномерного массива
	// в матрицу размером SIZE
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			out[y][x] = in[y * SIZE + x];
}

void coutMat(int mat[SIZE][SIZE])
{
	cout << "\n - Матрица: \n\n";
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
			cout << mat[y][x] << "\t";

		cout << "\n\n";
	}

}

void minMaxMat(int mat[SIZE][SIZE])
{
	cout << "\n - Минимальный а максимальный элементы на главной диагонали: \n\n";

	int min = -1, max = -1;

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

void sortMat(int mat[SIZE][SIZE])
{
	cout << "\n - Сортировка матрицы...";

	for (int y = 0; y < SIZE; y++)
		// применение алгоритма сортировки из библиотеки algorithm
		// от ячейки первого элемента в ряду до ячейки последнего элемента
		sort(&mat[y][0], &mat[y][SIZE]);

	coutMat(mat);
}

//////////////////  DOUBLE  ////////////////
void initMat(double in[SIZE * SIZE], double out[SIZE][SIZE])
{
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			out[y][x] = in[y * SIZE + x];
}

void coutMat(double mat[SIZE][SIZE])
{
	cout << "\n - Матрица: \n\n";
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
			cout << mat[y][x] << "\t";

		cout << "\n\n";
	}

}

void minMaxMat(double mat[SIZE][SIZE])
{
	cout << "\n - Минимальный а максимальный элементы на главной диагонали: \n\n";

	double min = -1, max = -1;

	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (x == y)
			{
				cout << "|" << mat[y][x] << "|" << "\t";

				if (mat[y][x] > max || max == -1)
					max = mat[y][x];
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

void sortMat(double mat[SIZE][SIZE])
{
	cout << "\n - Сортировка матрицы...";

	for (int y = 0; y < SIZE; y++)
		sort(&mat[y][0], &mat[y][SIZE]);

	coutMat(mat);
}

//////////////////   CHAR   ////////////////
void initMat(char in[SIZE * SIZE], char out[SIZE][SIZE])
{
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			out[y][x] = in[y * SIZE + x];
}

void coutMat(char mat[SIZE][SIZE])
{
	cout << "\n - Матрица: \n\n";
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
			cout << mat[y][x] << "\t";

		cout << "\n\n";
	}

}

void minMaxMat(char mat[SIZE][SIZE])
{
	cout << "\n - Минимальный а максимальный элементы на главной диагонали: \n\n";

	char min = -1, max = -1;

	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (x == y)
			{
				cout << "|" << mat[y][x] << "|" << "\t";

				if (mat[y][x] > max || max == -1)
					max = mat[y][x];
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

void sortMat(char mat[SIZE][SIZE])
{
	cout << "\n - Сортировка матрицы...";

	for (int y = 0; y < SIZE; y++)
		sort(&mat[y][0], &mat[y][SIZE]);

	coutMat(mat);
}

// сокращение получения случайного натурального числа
double rnd()
{
	return ((rand() % 256) / 1.15);
}

int main()
{
	// добавление поддержки кириллицы
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

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

	// завершеные работы программы
	cout << "\n\n";
	system("pause");
	return 0;
}
