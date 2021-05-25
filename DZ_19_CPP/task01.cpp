/* ЗАДАНИЕ 1
Группа: ПВ-011
Ученик: Шелест Александр
task01.cpp - программа для получения данных о символах в файле. */
#include <iostream>
#include <fstream>
#include <Windows.h>

// закомментируйте для отключения записи исходного текста.
// в таком случае разместите свой текст в файл под названием "shelest_src.txt" в папке с проектом.
#define WRITE_SRC

// воспомогательные константы
#define N_VOWELS 5
#define N_CONSONANTS 22

// список гласных букв
const char vowels[] = { 'A', 'E', 'I', 'O', 'U',
						'a', 'e', 'i', 'o', 'u'
};

// список согласных букв
const char consonants[] = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z',
							'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'
};

// получение количества символов в тексте (без учета нуль-терминатора)
int getStrCharCount(const char const* str)
{
	return strlen(str);
}

// получение количества строк в тексте
int getStrLineCount(const char const* str)
{
	// начинаем с 1 для учета первой строки
	int lineCount = 1;

	// для каждого символа в строке...
	for (int i = 0; str[i] != '\0'; i++)
	{
		// если текущий символ - новая строка...
		if (str[i] == '\n')
			// инкрементировать количество строк
			lineCount++;
	}

	return lineCount;
}

// получение количества всех гласных букв в тексте
int* getStrVowelCount(const char const* str)
{
	// объявление нового динамического массива
	int* vowelCount = new int[N_VOWELS]{};

	// для каждого символа в строке...
	for (int i = 0; str[i] != '\0'; i++)
	{
		// для каждой гласной буквы...
		for (int v = 0; v < N_VOWELS; v++)
			// если текущий символ и текущая гласная (в верхнем или нижнем регистре) совпадают...
			if (str[i] == vowels[v] || str[i] == vowels[v + N_VOWELS])
				// инкрементировать количество этой гласной
				vowelCount[v]++;
	}

	return vowelCount;
}

// получение количества всех согласных букв в тексте
int* getStrConsonantCount(const char const* str)
{
	// объявление нового динамического массива
	int* consonantCount = new int[N_CONSONANTS] {};

	// для каждого символа в строке...
	for (int i = 0; str[i] != '\0'; i++)
	{
		// для каждой согласной буквы...
		for (int c = 0; c < N_CONSONANTS; c++)
			// если текущий символ и текущая согласная (в верхнем или нижнем регистре) совпадают...
			if (str[i] == consonants[c] || str[i] == consonants[c + N_CONSONANTS])
				// инкрементировать количество этой согласной
				consonantCount[c]++;
	}

	return consonantCount;
}

// получение количества всех цифр в тексте
int* getStrNumCount(const char const* str)
{
	// объявление нового динамического массива
	int* numCount = new int[10]{};

	// для каждого символа в строке...
	for (int i = 0; str[i] != '\0'; i++)
	{
		// для каждой цифры...
		for (char n = '0'; n <= '9'; n++)
			// если текущий символ равен символу текущей цифры...
			if (str[i] == n)
				// инкрементировать количество этой цифры
				numCount[(int)n - '0']++;
	}

	return numCount;
}

int main()
{
	// добавление поддержки кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// вывод начального текста на экран
	std::cout << "\t-= Задание 1 =- \n - программа для получения данных о символах в файле.";
	std::cout << "\n\nнажмите любую клавишу для начала работы...\n";
	_getwch();

#ifdef WRITE_SRC
	std::cout << "\nЗаписываем исходный текст в файл \"shelest_src.txt\"...\n\n";

	// исходный текст, который записывается в файл
	const char src[] = {"This is source text. It will be written to file for later processing.\n"
						"This chunk of text is consisting of 443 characters (excluding last zero-terminator, but with line breaks!).\n"
						"If you want to use your own text instead, execute following actions:\n"
						"\t1. Replace text in this file with your own; (consider using only latin script characters)\n"
						"\t2. Undefine \"WRITE_SRC\" preprocessor keyword (at line 11);\n"
						"\t3. Recompile and run this project;\n"
						"\t4. Done!"
	};

	// запись вышеуказанного текста в файл
	std::ofstream srcOut("shelest_src.txt");
	srcOut.write(src, sizeof(src));
	srcOut.close();
#endif

	std::cout << "Загружаем текст из файла \"shelest_src.txt\"...\n\n";

	// динамическая память для загруженного текста
	char* loaded = new char[512];

	// чтение текста из файла в массив
	std::ifstream srcIn("shelest_src.txt");
	srcIn.read(loaded, 512);
	srcIn.close();

	std::cout << "Получаем информацию о тексте...\n\n";

	// получение информации о строке
	int charCount = getStrCharCount(loaded);
	int lineCount = getStrLineCount(loaded);
	int* vowelCount = getStrVowelCount(loaded);
	int* consonantCount = getStrConsonantCount(loaded);
	int* numCount = getStrNumCount(loaded);

	std::cout << "Записываем информацию о тексте в файл...\n\n";

	// запись полученной информации в файл
	std::ofstream infoOut("shelest_info.txt");

	infoOut << "char count - " << charCount << '\n';
	infoOut << "line count - " << lineCount << '\n';

	infoOut << "\nINFO: Both upper-case and lower-case letters are considered and counted.\n";

	infoOut << "\nvowels in the text: ";

	int totalVowels = 0;
	for (int i = 0; i < N_VOWELS; i++)
	{
		infoOut << "\n'" << vowels[i] << "'s - " << vowelCount[i];
		// подсчет общего количества гласных
		totalVowels += vowelCount[i];
	}
	infoOut << "\ntotal vowel count - " << totalVowels;

	infoOut << "\n\nconsonants in the text: ";

	int totalConsonants = 0;
	for (int i = 0; i < N_CONSONANTS; i++)
	{
		infoOut << "\n'" << consonants[i] << "'s - " << consonantCount[i];
		// подсчет общего количества согласных
		totalConsonants += consonantCount[i];
	}
	infoOut << "\ntotal consonant count - " << totalConsonants;

	infoOut << "\n\nnumbers in the text: ";
	int totalNums = 0;
	for (int i = 0; i < 10; i++)
	{
		infoOut << "\n'" << i << "'s - " << numCount[i];
		// подсчет общего количества цифр
		totalNums += numCount[i];
	}
	infoOut << "\ntotal number count - " << totalNums;

	// подготовка программы к завершению
	infoOut.close();

	std::cout << "Готово! Вы можете просмотреть информацию в файле под названием \"shelest_info.txt\".\n\n";

	// освобождение динамической памяти
	delete[] loaded;
	delete[] vowelCount;
	delete[] consonantCount;
	delete[] numCount;

	std::cout << "Нажмите любую клавишу для выхода из программы...";
	// завершение программы
	_getwch();
	return 0;
}
