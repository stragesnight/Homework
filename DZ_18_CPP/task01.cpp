/* ЗАДАНИЕ 1
    Группа: ПВ-011
    Ученик: Шелест Александр
    task01.cpp - программа для добавления записей в базу данных. */
#include <iostream>
#include <fstream>
#include <Windows.h>

// похоже, что при использовании file.write() и отсутствии file.close(),
// данные фактически не записываются в файл, 
// поэтому в программу был добавлен режим записи в файл после каждой итерации цикла,
// для обеспечения записи в файл при некорректном выходе из программы.
//
// (заккоментируйте следующую строку при отсутствии необходимости в этом режиме)
#define PER_ENTRY_WRITE

int main()
{
    // добавление поддержки кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // вывод начального текста на экран
    std::cout << "\t-= Задание 1 =- \n - программа для добавления записей в базу данных.";
    std::cout << "\n\nнажмите любую клавишу для начала работы...\n";
    _getwch();

    // рабочие переменные
    char buff[512];         // буффер строки, вводимой пользователем
    std::ofstream file;     // файл, в который будут записываться данные

#ifndef PER_ENTRY_WRITE
    file.open("shelest_db.txt", std::ios::app);
#endif

    // главный цикл выполнения
    do
    {
        // очистка экрана и вывод заголовка
        system("cls");
        std::cout << "==============================================\n";
        std::cout << "|| Добавление нового контакта в базу данных ||\n";
        std::cout << "==============================================\n\n";
   
#ifdef PER_ENTRY_WRITE
        // открытие файла, если активирован соответствующий режим
        file.open("shelest_db.txt", std::ios::app);
#endif

        // получиение данных с клавиатуры
        do
        {
            std::cout << "\rВведите фамилию нового контакта: ";
            std::cin.getline(buff, 512);
        } while (strlen(buff) == 0); // обеспечение корректного размера строки

        // запись буффера в файл и переход на новую строку
        file.write(buff, strlen(buff));
        file.write("\n", 1);

        std::cout << "\n\n";

        // получение данных с клавиатуры
        do
        {
            std::cout << "\rВведите номер телефона нового контакта: ";
            std::cin.getline(buff, 512);
        } while (strlen(buff) == 0);  // обеспечение корректного размера строки

        // запись буффера в файл и переход на новую строку
        file.write(buff, strlen(buff));
        file.write("\n", 1);

#ifdef PER_ENTRY_WRITE
        // закрытие файла, если активирован соответствующий режим
        file.close();
#endif

        std::cout << "\n\nдля выхода из программы нажмите ctrl+Z, \n\tили любую другую клавишу для продолжения работы... ";
    } while (getchar() != EOF);

#ifndef PER_ENTRY_WRITE
    file.close();
#endif

    // завершение программы
    return 0;
}