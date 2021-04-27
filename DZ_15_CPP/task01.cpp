/* ЗАДАНИЕ 1
    Группа: ПВ-011
    Ученик: Шелест Александр
    task01.cpp - программа-библиотека позволяющая просматривать, редактировать, сортировать, искать и добавлять новые книги */

#include <iostream>
#include <windows.h>


// перечисление для удобной реализации пунктов меню
enum menuAction { EXIT, DISPLAY_ALL, SEARCH, SORT, EDIT_ENTRY, ADD_ENTRY };
// важная составляющая программы - глобальное перечисление, отвечающее за поля структуры "книга"
enum structSubscript { TITLE = 1, AUTOR, PUBLISHER, GENRE };

// структура книги
//  - некоторые функции реализованы как методы внутри структуры, что делает код более чистым
struct Book
{
	std::string title;		// название
	std::string autor;		// автор
	std::string publisher;	// издательство
	std::string genre;		// жанр

	// метод, который возвращает поле структуры в соответствии с соответствующим элементом перечисления
	std::string getValueBySubscript(structSubscript subscript)
	{
		switch (subscript)
		{
		case TITLE:
			return title;
		case AUTOR:
			return autor;
		case PUBLISHER:
			return publisher;
		case GENRE:
			return genre;
		default:
			return "invalid subscript";
		}
	}

	// метод, изменяющий значение поля этой структуры в соответствии с соответствующим элементом перечисления
	//  - возвращает true при успехе, false при некорректном вводе данных
	bool setValueBySubscript(structSubscript subscript, const std::string value)
	{
		switch (subscript)
		{
		case TITLE:
			title = value;
			return true;
		case AUTOR:
			autor = value;
			return true;
		case PUBLISHER:
			publisher = value;
			return true;
		case GENRE:
			genre = value;
			return true;
		}

		return false;
	}

	// вывод структуры на экран
	void display()
	{
		std::cout << "\"" << title << "\"\n"
			<< "\tАвтор - " << autor << '\n'
			<< "\tИздательство - " << publisher << '\n'
			<< "\tЖанр - " << genre << "\n\n";
	}
};

// структура библиотеки
// состоит из массива книг и размера библиотеки
struct Library
{
	unsigned size;
	Book* books;
};

// вывод заданного количества книг из массива на экран
void displayAll(Book* books, const unsigned size)
{
	for (unsigned i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". ";
		books[i].display();
	}
}

// вывод всей библиотеки на экран
void displayAll(const Library& library)
{
	std::cout	<< "+=======================================+\n"
				<< "|              СПИСОК КНИГ              |\n"
				<< "+=======================================+\n\n";

	for (unsigned i = 0; i < library.size; i++)
	{
		std::cout << i + 1 << ". ";
		library.books[i].display();
	}
}

// редактирование содержания книги в библиотеке
void editBook(const Library& library, const unsigned index)
{
	// очиска экрана и вывод начального текста
	system("cls");

	std::cout	<< "+========================+\n"
				<< "|  РЕДАКТИРОВАНИЕ КНИГИ  |\n"
				<< "+========================+\n\n";

	// вывод библиотеки на экран для удобства пользователя при выборе
	std::cout << " - ";
	library.books[index].display();

	unsigned input;
	char newValue[256];

	// ввод желаемого параметра для редактирования
	std::cout << "\nВыберите параметр для редактирования:\n"
		<< "1. Название\n"
		<< "2. Автор\n"
		<< "3. Издательство\n"
		<< "4. Жанр\n\nваш выбор: ";
	std::cin >> input;
	std::cin.get();	// защищает последующий cin.getline от некорректной работы
	// ввод нового значения
	std::cout << "Новое значение выбранного параметра: ";
	std::cin.getline(newValue, 256);

	// вызов метода внутри структуры и сохранение результата в переменную success
	bool success = library.books[index].setValueBySubscript((structSubscript)input, newValue);
	// вывод сообщения в зависимости от результата операции
	if (success)
		std::cout << "\nДанные были успешно редактированы.";
	else
		std::cout << "\nОшибка при редактировании данных. (выбран неправильный пункт меню)";
}

// добавление новой книги в массив
void addEntry(Book*& arr, unsigned& size, const Book& bookToAdd)
{
	size++;		// инкремент размера
	// создание нового динамического массива
	Book* newArr = new Book[size];

	// копирование старого массива в новый
	for (int i = 0; i < size - 1; i++)
		newArr[i] = arr[i];

	// добавление нового элемента в конец
	newArr[size - 1] = bookToAdd;
	// освобождение памяти старого массива
	delete[] arr;
	// обновление адреса памяти старого массива на новый
	arr = newArr;
}

// добавление новой книги в библиотеку
void addEntry(Library& library, const Book& bookToAdd)
{
	library.size++;		// инкремент размера
	// создание нового динамического массива
	Book* newDatabase = new Book[library.size];

	// копирование старого массива в новый
	for (int i = 0; i < library.size - 1; i++)
		newDatabase[i] = library.books[i];

	// добавление нового элемента в конец
	newDatabase[library.size - 1] = bookToAdd;
	// освобождение памяти старого массива
	delete[] library.books;
	// обновление адреса памяти старого массива на новый
	library.books = newDatabase;

	std::cout << "Книга была успешно добавлена в базу библиотеки.";
}

// поиск книги в библиотеке по заданному элементу и параметру
// возвращает список найденных книг и их количество в параметре nFound
Book* searchBooks(const Library& library, structSubscript subscript, const std::string query, unsigned& nFound)
{
	nFound = 0;	// обнуление количества найденных книг
	Book* foundBooks = new Book[1];

	// для каждой книги...
	for (int i = 0; i < library.size; i++)
		// если значение поля книги и критерий поиска одинаковы...
		if (library.books[i].getValueBySubscript(subscript) == query)
			// добавить эту книгу в массив
			addEntry(foundBooks, nFound, library.books[i]);

	// возвратить найденные книги
	return foundBooks;
}

// сравнение двух книг по заданному полю
// возвращает false, если первая книга "выше" второй по алфавиту
// и true, если вторая книга "выше"
bool compareBooks(Book& a, Book& b, structSubscript subscript)
{
	// получение значений для сравнения
	std::string cmpA = a.getValueBySubscript(subscript);
	std::string cmpB = b.getValueBySubscript(subscript);

	// задание максимального количества итераций цикла
	// исходя из размера обоих элементов
	unsigned size = (cmpA.size() > cmpB.size()) ? cmpB.size() : cmpA.size();
	
	// для каждого символа в словах...
	for (unsigned i = 0; i < size; i++)
	{
		// так как символ - это закодированное целое число,
		// то их можно сравнивать так же
		if (cmpA[i] > cmpB[i])
			return false;
		else if (cmpA[i] < cmpB[i])
			return true;
		// продолжить цикл если символы совпадают
	}

	// защитная мера в случае, если слова одинаковы
	return false;
}

// сортировка книг в библиотеке по заданному полю в структуре
void sortBooks(Library& library, structSubscript subscript)
{
	std::cout << "Сортировка книг...";

	// алгоритм "selection sort", или же "сортировка выбором"
	int n;
	for (int j = 0; j < library.size - 1; j++)
	{
		n = j + 1;
		for (int i = n + 1; i < library.size; i++)
			// вызов функции для сравнения книг
			if (compareBooks(library.books[i], library.books[n], subscript))
				n = i;

		// вызов функции для сравнения книг
		if (compareBooks(library.books[n], library.books[j], subscript))
			// заменить значения, если в этом есть потребность
			std::swap(library.books[j], library.books[n]);
	}

	std::cout << "\nКниги были успешно сортированы по алфавиту.";
}

int main()
{
	// конфигурация раскладки консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// объявление и инициализация библиотеки
	Library library;
	library.size = 10;
	library.books = new Book[library.size] {
		{ "Маленький принц",	"Антуан де Сент-Экзюпери",	"Франц паблишинг",		"Фэнтезийная новелла" },
		{ "1984",				"Джордж Оруэлл",			"Юнайтед паблишинг",	"Антиутопическая фантастика" },
		{ "Превращение",		"Франц Кафка",				"Дай вьессен",			"Фэнтезийная новелла" },
		{ "Дом странных детей", "Ренсом Риггз",				"Джейкоб паблишинг",	"Фэнтезийный роман" },
		{ "Дагон",				"Говард Лавкрафт",			"Ретро-Хьюго",			"Фэнтезийный рассказ" },
		{ "Лосось сомнений",	"Дуглас Адамс",				"Адамс-Нью паблиш",		"Юмористический роман" },
		{ "Властелин колец",	"Джон Рональд Руэл Толкин", "Ретро-Хьюго",			"Фэнтезийный роман" },
		{ "Меловой Человек",	"С. Дж. Тюдор",				"Триллер медиа",		"Психологический реализм" },
		{ "Пятая Салли",		"Дэниел Киз",				"Биллис букс",			"Художественный вымысел" },
		{ "Горящие клети",		"Кейт Мосс",				"Биллис букс",			"исторический роман" },
	};

	// выбор пункта меню, вводимый пользователем
	menuAction action = DISPLAY_ALL;

	// вывод начального текста на экран
	std::cout << "\t-= Задание 1 =- \n - программа-библиотека с использование структур и перечнем возможностей по взаимодейтвию с книгами.\n";
	std::cout << "\n\nнажмите любую клавишу для выхода в меню программы...";
	_getwch();

	// главный цикл выполнения программы
	while (action != EXIT)
	{
		// очистка экрана и вывод начального текста на экран
		system("cls");

		std::cout	<< "+=======================+\n"
					<< "|    МЕНЮ БИБЛИОТЕКИ    |\n"
					<< "+=======================+\n\n";

		std::cout	<< "1. Показать все книги\n"
					<< "2. Поиск книги по критерию\n"
					<< "3. Сортировка книг по критерию\n"
					<< "4. Редактирование книги\n"
					<< "5. Добавление новой книги\n\n"
					<< "0. Выход из программы\n\n";

		// сбор данных с клавиатуры
		int input;
		std::cout << "Выберите действие по его номеру: ";
		std::cin >> input;
		// сначала пользователь вводит int,
		// затем это значение меняет свой тип на тип перечисления
		// и выбранному пункту меню в виде элемента перечисления присваивается это значение
		action = (menuAction)input;

		// очистка экрана ещё раз
		system("cls");

		// выполнение блока действий в зависимости от выбора пользователя
		switch (action)
		{
		case DISPLAY_ALL:
		{
			// вызов функции для вывода всей библиотеки на экран
			displayAll(library);
			break;
		}
		case SEARCH:
		{
			std::cout	<< "+====================+\n"
						<< "|    ПОИСК КНИГИ     |\n"
						<< "+====================+\n\n";

			unsigned input;
			char query[256];
			unsigned nFound = 0;

			// выбор пользователем параметра поиска
			std::cout << "\nВыберите параметр, по которому будет производиться поиск:\n"
				<< "1. Название\n"
				<< "2. Автор\n"
				<< "3. Издательство\n"
				<< "4. Жанр\n\nваш выбор: ";
			std::cin >> input;

			// введение пользователем ключевого слова
			std::cout << "\nВведите ключевое слово для поиска: ";
			std::cin.get();	// защищает последующий cin.getline от некорректной работы
			std::cin.getline(query, 256);

			// получение списка найденных книг по выбранному критерию
			// при этом выбранный пункт меню превращается в тип перечисления
			Book* foundBooks = searchBooks(library, (structSubscript)input, query, nFound);

			// вывод результатов на экран
			std::cout << "\n\nКниг найдено по запросу \"" << query << "\": " << nFound << '\n';
			displayAll(foundBooks, nFound);

			// очистка динамической памяти
			delete[] foundBooks;

			break;
		}
		case SORT:
		{
			std::cout	<< "+====================+\n"
						<< "|  СОРТИРОВКА КНИГ   |\n"
						<< "+====================+\n\n";

			unsigned input;

			// выбор пользователем параметра сортировки
			std::cout << "\nВыберите параметр, по которому будет производиться сортировка:\n"
				<< "1. Название\n"
				<< "2. Автор\n"
				<< "3. Издательство\n"
				<< "4. Жанр\n\nваш выбор: ";
			std::cin >> input;

			// вызов функции сортировки
			sortBooks(library, (structSubscript)input);

			break;
		}
		case EDIT_ENTRY:
		{
			// вывод всей библиотеки на экран для удобства пользователя при выборе
			displayAll(library);
			// выбор пользователем книги для редактирования
			unsigned index;
			std::cout	<< "\n========================================"
						<< "\n\n  Введите номер книги для редактирования: ";
			std::cin >> index;
			// вызов функции для дальнейшего редактирования,
			// при этом нужно отнять от выбранного пункта меню 1
			// для его превращения в индекс
			editBook(library, index - 1);
			break;
		}
		case ADD_ENTRY:
		{
			// объявление новой книги и буфера для ввода строк
			Book bookToAdd;
			char buffer[256];

			std::cout	<< "+========================+\n"
						<< "|    ДОБАВЛЕНИЕ КНИГИ    |\n"
						<< "+========================+\n\n";

			std::cin.get();	// защита от некорректной работы
			// ввод данных пользователем с клавиатуры
			// и заполнение сруктуры данными
			std::cout << "Название книги: ";
			std::cin.getline(buffer, 256);
			bookToAdd.title = buffer;
			std::cout << "Автор: ";
			std::cin.getline(buffer, 256);
			bookToAdd.autor = buffer;
			std::cout << "Издательство: ";
			std::cin.getline(buffer, 256);
			bookToAdd.publisher = buffer;
			std::cout << "Жанр: ";
			std::cin.getline(buffer, 256);
			bookToAdd.genre = buffer;

			// вызов функции для добавления книги в библиотеку
			addEntry(library, bookToAdd);

			break;
		}
		case EXIT:
			// выход из программы
			return 0;
		default:
		{
			// вывод сообщении о выборе некорректного пункта меню
			std::cout << "Выбран некорректный пункт меню!";
			break;
		}
		}

		// пауза
		std::cout << "\n\nНажмите любую клавишу для выхода в меню...";
		_getwch();		// получение любого символа с клавиатуры
	}

	// освобождение динамической памяти
	delete[] library.books;

	// завершение программы
	return 0;
}
