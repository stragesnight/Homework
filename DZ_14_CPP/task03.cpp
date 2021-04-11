/* ЗАДАНИЕ 3
	Группа: ПВ-011
	Ученик: Шелест Александр
	task03.cpp инициализирует матрицу и осуществляет её циклический сдвиг. */

#include <iostream>
#include <windows.h>
#include <time.h>

// инициализация матрицы случайными значениями
//	arr   - матрица для инициализации
//	sizeX - размер линии
//	sizeY - размер столбца
void initMatrix(int** mat, int sizeX, int sizeY)
{
	// инициализация двухмерного массива случайными значениями
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
			mat[x][y] = rand() % 10;
	}
}

// вывод матрицы на экран с декоративным обрамлением
//	arr   - матрица для инициализации
//	sizeX - размер линии
//	sizeY - размер столбца
void drawMatrix(int** mat, int sizeX, int sizeY)
{
	// так много внимания уделено выведению координатных осей
	// ради простоты интерпретации пользователем введённого сдвига 
	// координатные оси указывают на то, в каком направлении сдвинется матрица

	// вывод координатной оси Х на экран
	std::cout << "\n\t0 ";
	for (int i = 0; i < sizeX; i++)
		if (i == sizeX / 2)		// нарисовать 'X' по центру линии
			if (sizeX % 2) std::cout << "- X -";
			else std::cout << "\b X ---"; // сдвиг для выравнивания, если размер линии - четный
		else
			std::cout << "----";
	std::cout << ">\n";

	// вывод верхней линии на экран
	std::cout << "\t| +";
	for (int i = 0; i < sizeX * 4 - 1; i++)
		std::cout << "-";
	std::cout << "+\n";

	for (int y = 0; y < sizeY; y++)
	{
		// вывод координатной оси Y на экран
		if (y == sizeY / 2 && sizeY % 2)
			std::cout << "\tY ";
		else
			std::cout << "\t| ";

		// вывод непосредственно значений
		for (int x = 0; x < sizeX; x++)
			std::cout << "| " << mat[x][y] << " ";

		// переход на новую линию
		std::cout << "|\n";

		// если текущая линия - последняя, то вырваться из цикла
		if (y == sizeY - 1)
			break;

		// иначе, нарисовать "межрядовую" линию
		if (y == sizeY / 2 - 1 && sizeY % 2 == 0)
			std::cout << "\tY |";
		else
			std::cout << "\t| |";
		for (int i = 0; i < sizeX * 4 - 1; i++)
			std::cout << "-";
		std::cout << "|\n";
	}

	// вывод нижней линии на экран, идентична верхней
	std::cout << "\tV +";
	for (int i = 0; i < sizeX * 4 - 1; i++)
		std::cout << "-";
	std::cout << "+\n";
}

// сдвиг матрицы в указанном направлении
//	arr     - ссылка на матрицу для сдвига
//	sizeX   - размер линии
//	sizeY   - размер столбца
//  amountX - сдвиг по оси X
//  amountY - сдвиг по оси Y
void shiftMatrinx(int**& mat, int sizeX, int sizeY, int amountX, int amountY)
{
	// объявление невой матрицы
	
	// - новая матрица создается из-за необходимости
	// чтения изначального состояния матрицы
	int** newMat = new int* [sizeX];	// внешний массив
	for (int i = 0; i < sizeX; i++)
		newMat[i] = new int[sizeY];		// внутренние подмассивы

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			int newX, newY;
			// вычисление обновлённых координат
			newX = (x + amountX + sizeX) % sizeX;
			if (amountY >= 0)
				newY = (y + amountY) % sizeY;

			// копирование из старой матрицы в новую с учетом сдвига
			newMat[newX][newY] = mat[x][y];
		}
	}

	// освобождение динамической памяти старой матрицы
	for (int i = 0; i < sizeX; i++)
		delete[] mat[i];	// внутренние подмассивы
	delete[] mat;			// внешний массив


	// присвоение новой матрице старой
	// так как изначальная матрица была передана по ссылке,
	// теперь при обращению к "mat" будет происходить обращение к памяти "newMat"
	mat = newMat;
}

int main()
{
	// конфигурация раскладки консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// инициализация случайной генерации
	srand(time(0));

	// вывод начального текста на экран
	std::cout << "\t-= Задание 3 =- \n - наполнение матрицы {M x N} значениями и её циклический сдвиг.\n";

	// объявление переменных для начальной размерности массива
	int sizeX = 4;
	int sizeY = 4;

	// запрос на ввод размерности матрицы
	std::cout << "\nвведите размерность матрицы {x, y}: ";
	std::cin >> sizeX >> sizeY;

	// объявление матрицы
	int** mat = new int* [sizeX];	// внешний массив
	for (int i = 0; i < sizeX; i++)
		mat[i] = new int[sizeY];	// внутренние подмассивы

	// инициализация матрицы случайными значениями
	initMatrix(mat, sizeX, sizeY);

	// переменная, используемая для проверки нужды продолжения программы
	bool shouldNotExit = true;
	while (shouldNotExit)
	{
		system("cls");
		// вывод начального состояния матрицы на экран
		std::cout << "\tматрица до сдвига:";
		drawMatrix(mat, sizeX, sizeY);

		int shiftX, shiftY;
		std::cout << "\nвведите сдвиг матрицы {x, y}: ";
		std::cin >> shiftX >> shiftY;

		// произведение непосредственно сдвига
		shiftMatrinx(mat, sizeX, sizeY, shiftX, shiftY);

		// вывод результата действий на экран
		std::cout << "\n\tматрица после сдвига { ";
		// вывод направления сдвига в скобках
		if (shiftX > 0) std::cout << "->, ";
		else if (shiftX < 0) std::cout << "<-, ";
		else std::cout << "-, ";

		if (shiftY > 0) std::cout << "v }:";
		else if (shiftY < 0) std::cout << "^ }:";
		else std::cout << "- }:";

		drawMatrix(mat, sizeX, sizeY);

		// проверка нужды в продолжении работы программы
		std::cout << "\nпродолжить? (0 - нет, 1 - да): ";
		std::cin >> shouldNotExit;
	}

	// освобождение динамической памяти
	for (int i = 0; i < sizeX; i++)
		delete[] mat[i];	// внутренние подмассивы
	delete[] mat;			// внешний массив

	// пауза и завершение программы
	std::cout << "\n\nНажмите любую клавишу для выхода из программы...";
	_getwch();		// получение любого символа с клавиатуры
	return 0;
}
