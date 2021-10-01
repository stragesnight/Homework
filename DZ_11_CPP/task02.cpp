/* ЗАДАНИЕ 2

	Группа: ПВ-011
	Ученик: Шелест Александр

	task02.cpp содержит в себе перегруженные функции для работы с массивами */
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

/////////////////////// DOUBLE ///////////////////////

// параметры:
// - одномерный массив размером 10
// - два целых числа с начальным значением -1
double maxInArray(double in[10], double except1 = -1, double except2 = -1)
{
	double max = -1;

	for (int i = 0; i < 10; i++)
		// если текущий элемент больше максимального 
		// или максимальное значение ещё не одновлялось
		// и если текущий элемент не является исключением
		if ((in[i] > max || max == -1) && (in[i] != except1 && in[i] != except2))
			// обновить максимальное значение
			max = in[i];

	return max;
}

double maxInArray(double in[3][3])
{
	double max = -1;

	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (in[x][y] > max || max == -1)
				max = in[x][y];

	return max;
}

double maxInArray(double in[2][2][2])
{
	double max = -1;

	for (int z = 0; z < 2; z++)
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 3; x++)
				if (in[x][y][z] > max || max == -1)
					max = in[x][y][z];

	return max;
}


void maxIntInArray(double in[10], int* out1, int* out2)
{
	// переменные для содержания максимальных значений и исключений для поиска
	double max1, max2;
	// вызов поиска масимального элемента в одномерном массиве
	max1 = maxInArray(in);
	// второй вызов, на этот раз с исключением первого элемента
	max2 = maxInArray(in, *out1);

	// присвоение параметрам нужных значений
	*out1 = max1;
	*out2 = max2;
}

void maxIntInArray(double in[10], int* out1, int* out2, int* out3)
{
	// переменные для содержания максимальных значений и исключений для поиска
	double max1, max2, max3;
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


///////////////////////   INT   ///////////////////////

int maxInArray(int in[10], int except1 = -1, int except2 = -1)
{
	int max = -1;

	for (int i = 0; i < 10; i++)
		if ((in[i] > max || max == -1) && (in[i] != except1 && in[i] != except2))
			max = in[i];

	return max;
}

int maxInArray(int in[3][3])
{
	int max = -1;

	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (in[x][y] > max || max == -1)
				max = in[x][y];

	return max;
}

int maxInArray(int in[2][2][2])
{
	int max = -1;

	for (int z = 0; z < 2; z++)
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 3; x++)
				if (in[x][y][z] > max || max == -1)
					max = in[x][y][z];

	return max;
}


void maxIntInArray(int in[10], int* out1, int* out2)
{
	// вызов поиска масимального элемента в одномерном массиве
	*out1 = maxInArray(in);
	// второй вызов, на этот раз с исключением первого элемента
	*out2 = maxInArray(in, *out1);
}

void maxIntInArray(int in[10], int* out1, int* out2, int* out3)
{
	// вызов поиска масимального элемента в одномерном массиве
	*out1 = maxInArray(in);
	// второй вызов, на этот раз с исключением первого элемента
	*out2 = maxInArray(in, *out1);
	// третий вызов с исключением первоых двух элементов
	*out3 = maxInArray(in, *out1, *out2);
}


// сокращение получения случайного натурального числа
double rnd()
{
	return ((rand() % 512) / 1.23) - 256.;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	// переключение состояния этой переменной позволит управлять наполнением массивов (статическое или случайное) 
	bool initToRand = false;

	// объявление массивов с тестовыми значениями

	int narr[10] = { 63, 25, 66, 34, 34, 96, 12, 36, 67, 19};
	int narr2D[3][3] = { { 12, 75, 23 }, { 63, 81, 15 } };
	int narr3D[2][2][2] = {{{64, 73}, {26, 13}}, {{67, 23}, {95, 45}}};

	double darr[10] = { 63.51, 2.512, 6.65342, 34.234, 5.1324, 91.563, 12.523, 3.64, 67.523, 1.91 };
	double darr2D[3][3] = { { 1.213, 75.52, 23.123 }, { 63.754, 81.735, 15.742 } };
	double darr3D[2][2][2] = {{{6.512344, 73.523}, {2.55236, 13.523}}, {{67.523, 233.542}, {95.634, 45.634}}};

	int max1, max2, max3;

	// заполнение массивов случайными элементами
	// при определённом условии
	if (initToRand)
	{
		for (int i = 0; i < 10; i++)
		{
			narr[i] = rnd();
			darr[i] = rnd();
		}

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				narr2D[y][x] = rnd();
				darr2D[y][x] = rnd();
			}
		}

		for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 2; y++)
			{
				for (int z = 0; z < 2; z++)
				{
					narr3D[z][y][x] = rnd();
					darr3D[z][y][x] = rnd();
				}
			}
		}
	}

	cout << "# содержание массивов можно просмотреть в файле программы #\n";

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
