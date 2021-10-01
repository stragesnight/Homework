/* ЗАДАНИЕ 2
    Группа: ПВ-011
    Ученик: Шелест Александр
    task02.cpp - программа для поиска данных в базе данных, созданной в прошлом задании. */
#include <iostream>
#include <fstream>
#include <Windows.h>

// структура контакта, состоит из фамилии и номера телефона
struct DBEntry
{
    char* name;
    char* phoneNumber;
};

// структура базы данных, состоит из размера базы и динамического массива контактов
struct DataBase
{
    unsigned size;
    DBEntry* entries;
} database{0};  // обьявление объекта этой структуры с размером 0


// вывод указанного списока контактов на экран консоли
void display(const DBEntry const* entries, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << i + 1 << ". " << entries[i].name << ", " << entries[i].phoneNumber << "\n\n";
}

// добавление нового контакта в динамический массив
void addEntry(DBEntry*& oldArr, DBEntry added, int& size)
{
    // объявление нового массива
    size++; // инкремента размера
    DBEntry* newArr = new DBEntry[size];    // резервирование памяти для нового массива

    // копирование данных со старого массива
    for (int i = 0; i < size - 1; i++)
        newArr[i] = oldArr[i];

    // добавление нового объекта в конец массива
    newArr[size - 1] = added;

    // замена старого указателя новым
    delete[] oldArr;
    oldArr = newArr;
}

// поиск контактов в базе данных по выбранному параметру
DBEntry* search(int mode, int& nFound)
{
    // вывод заголовка
    system("cls");
    std::cout << "==================================\n";
    std::cout << "||\tпоиск по ";
    if (mode == 1) std::cout << "фамилии\t||\n";
    else std::cout << "телефону\t||\n";
    std::cout << "==================================\n\n";

    // объявление рабочих переменных
    nFound = 0;
    DBEntry* found = nullptr;
    char query[256];

    // сбор данных с клавиатуры
    std::cout << "Введите критерий поиска: ";
    std::cin.ignore(1, '\n');
    std::cin.getline(query, 256);

    // цикл поиска
    for (int i = 0; i < database.size; i++)
    {
        // выбор строки здя сравнения в зависимости от параметра mode
        const char* cmpd = (mode == 1)  ? database.entries[i].name 
                                        : database.entries[i].phoneNumber;

        // если критерий поиска равен сравниваемой строке...
        if (strcmp(cmpd, query) == 0)
            // добавление текущего контакта в динамический массив
            addEntry(found, database.entries[i], nFound);
    }

    return found;
}

// получение количества строк в файле
int getLineCount(std::ifstream& file)
{
    int n = 0;  // количество строк
    char buff[256]; // временный буфер

    // пока цикл не достигнет конца файла...
    while (!file.eof())
    {
        // получить строку с файла в буффер
        file.getline(buff, 256);
        // ункрементировать количество строк
        n++;
    }

    // возвращение курсора в начало файла
    file.clear();   // очистка флагов файла
    file.seekg(0);  // перемещение курсора на позицию 0 (начало файла)

    return n;
}

// загрузка базы данных из файла в объект структуры
int loadDatabase()
{
    // открытие файла в режиме чтения
    std::ifstream file("shelest_db.txt");

    // проверка на открытие файла
    if (!file.is_open())
        return 0;

    // инициализация данных
    int nEntries = getLineCount(file) / 2;      // получение количества контактов в файле (кол. строк / 2 так как структура состоит из двух полей)
    database.size = nEntries;                   // задание размера базы данных
    database.entries = new DBEntry[nEntries];   // инициализация динамического массива

    // буффер для строки
    char buff[256];

    // для каждого контакта в базе данных...
    for (int i = 0; i < nEntries; i++)
    {
        // получить фамилию контакта с файла
        database.entries[i].name = new char[256];           // инициализировать строку для хранения 
        file.getline(database.entries[i].name, 256);        // получение строки с фалйа

        // получить телефон контакта с файла
        database.entries[i].phoneNumber = new char[256];    // инициализировать строку для хранения
        file.getline(database.entries[i].phoneNumber, 256); // получение строки с файла
    }

    // закрытие файла
    file.close();

    return 1;
}

// выгрузка базы данных (освобождение памяти объекта структуры)
void unloadDatabase()
{
    // для каждого контакта в базе данных...
    for (int i = 0; i < database.size; i++)
    {
        // освободить память полей контакта
        delete[] database.entries[i].name;
        delete[] database.entries[i].phoneNumber;
    }
    // освобождение памяти контактов
    delete[] database.entries;

    // сброс размера базы данных
    database.size = 0;
}

int main()
{
    // добавление поддержки кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // вывод начального текста на экран
    std::cout << "\t-= Задание 2 =- \n - программа для поиска данных в базе данных, созданной в прошлом задании.";
    std::cout << "\n\nнажмите любую клавишу для начала работы...\n";
    _getwch();

    // опция меню, выбранная пользователем
    int option;

    // загрузка базы данных из файла
    if (!loadDatabase())
    {
        // вывод ошибки в случае, если база данных не была загружена
        std::cout << "\nОшибка: невозможно открыть файл.\nПроверьте, остался ли файл базы данных после прошлого задания.";
        _getwch();
        return 1;
    }

    // главный цикл выполнения
    do
    {
        // вывод меню
        system("cls");
        std::cout << "================\n";
        std::cout << "||    МЕНЮ    ||\n";
        std::cout << "================\n\n";

        std::cout << "1. Поиск по фамилии;\n";
        std::cout << "2. Поиск по номеру телефона;\n\n";
        std::cout << "0. Выход из программы.\n\n";
        // сбор данных с клавиатуры
        std::cout << "Введите желаемое действие по соответствующему номеру пункта меню: ";
        std::cin >> option;

        // выполнение действие в зависимости от выбора пользователя
        switch (option)
        {
        case 1: // выполнение того же, что и в case 2
        case 2:
        {
            // поиск контактов в базе данных
            int nFound;
            DBEntry* found = search(option, nFound);

            std::cout << "=======================================================\n\n";

            // вывод результатов на экран
            if (nFound != 0)
            {
                std::cout << "Контактов найдено по вашему критерию - " << nFound << ":\n\n";
                display(found, nFound);
            }
            else
                std::cout << "Не удалось найти данные по вашему критерию.";

            break;
        }
        case 0:
            return 0;

        default:
            std::cout << "\n\nВыбран неверный пункт меню.";
            break;
        }

        // пауза программы
        std::cout << "\n\nнажмите любую клавищу для продолжения...";
        _getwch();

    } while (option != 0);

    // освобождение динамической памяти базы данных
    unloadDatabase();

    // завершение программы
    return 0;
}