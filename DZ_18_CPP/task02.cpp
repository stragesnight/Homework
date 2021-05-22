/* ������� 2
    ������: ��-011
    ������: ������ ���������
    task02.cpp - ��������� ��� ������ ������ � ���� ������, ��������� � ������� �������. */
#include <iostream>
#include <fstream>
#include <Windows.h>

// ��������� ��������, ������� �� ������� � ������ ��������
struct DBEntry
{
    char* name;
    char* phoneNumber;
};

// ��������� ���� ������, ������� �� ������� ���� � ������������� ������� ���������
struct DataBase
{
    unsigned size;
    DBEntry* entries;
} database{0};  // ���������� ������� ���� ��������� � �������� 0


// ����� ���������� ������� ��������� �� ����� �������
void display(const DBEntry const* entries, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << i + 1 << ". " << entries[i].name << ", " << entries[i].phoneNumber << "\n\n";
}

// ���������� ������ �������� � ������������ ������
void addEntry(DBEntry*& oldArr, DBEntry added, int& size)
{
    // ���������� ������ �������
    size++; // ���������� �������
    DBEntry* newArr = new DBEntry[size];    // �������������� ������ ��� ������ �������

    // ����������� ������ �� ������� �������
    for (int i = 0; i < size - 1; i++)
        newArr[i] = oldArr[i];

    // ���������� ������ ������� � ����� �������
    newArr[size - 1] = added;

    // ������ ������� ��������� �����
    delete[] oldArr;
    oldArr = newArr;
}

// ����� ��������� � ���� ������ �� ���������� ���������
DBEntry* search(int mode, int& nFound)
{
    // ����� ���������
    system("cls");
    std::cout << "==================================\n";
    std::cout << "||\t����� �� ";
    if (mode == 1) std::cout << "�������\t||\n";
    else std::cout << "��������\t||\n";
    std::cout << "==================================\n\n";

    // ���������� ������� ����������
    nFound = 0;
    DBEntry* found = nullptr;
    char query[256];

    // ���� ������ � ����������
    std::cout << "������� �������� ������: ";
    std::cin.ignore(1, '\n');
    std::cin.getline(query, 256);

    // ���� ������
    for (int i = 0; i < database.size; i++)
    {
        // ����� ������ ��� ��������� � ����������� �� ��������� mode
        const char* cmpd = (mode == 1)  ? database.entries[i].name 
                                        : database.entries[i].phoneNumber;

        // ���� �������� ������ ����� ������������ ������...
        if (strcmp(cmpd, query) == 0)
            // ���������� �������� �������� � ������������ ������
            addEntry(found, database.entries[i], nFound);
    }

    return found;
}

// ��������� ���������� ����� � �����
int getLineCount(std::ifstream& file)
{
    int n = 0;  // ���������� �����
    char buff[256]; // ��������� �����

    // ���� ���� �� ��������� ����� �����...
    while (!file.eof())
    {
        // �������� ������ � ����� � ������
        file.getline(buff, 256);
        // ���������������� ���������� �����
        n++;
    }

    // ����������� ������� � ������ �����
    file.clear();   // ������� ������ �����
    file.seekg(0);  // ����������� ������� �� ������� 0 (������ �����)

    return n;
}

// �������� ���� ������ �� ����� � ������ ���������
int loadDatabase()
{
    // �������� ����� � ������ ������
    std::ifstream file("shelest_db.txt");

    // �������� �� �������� �����
    if (!file.is_open())
        return 0;

    // ������������� ������
    int nEntries = getLineCount(file) / 2;      // ��������� ���������� ��������� � ����� (���. ����� / 2 ��� ��� ��������� ������� �� ���� �����)
    database.size = nEntries;                   // ������� ������� ���� ������
    database.entries = new DBEntry[nEntries];   // ������������� ������������� �������

    // ������ ��� ������
    char buff[256];

    // ��� ������� �������� � ���� ������...
    for (int i = 0; i < nEntries; i++)
    {
        // �������� ������� �������� � �����
        database.entries[i].name = new char[256];           // ���������������� ������ ��� �������� 
        file.getline(database.entries[i].name, 256);        // ��������� ������ � �����

        // �������� ������� �������� � �����
        database.entries[i].phoneNumber = new char[256];    // ���������������� ������ ��� ��������
        file.getline(database.entries[i].phoneNumber, 256); // ��������� ������ � �����
    }

    // �������� �����
    file.close();

    return 1;
}

// �������� ���� ������ (������������ ������ ������� ���������)
void unloadDatabase()
{
    // ��� ������� �������� � ���� ������...
    for (int i = 0; i < database.size; i++)
    {
        // ���������� ������ ����� ��������
        delete[] database.entries[i].name;
        delete[] database.entries[i].phoneNumber;
    }
    // ������������ ������ ���������
    delete[] database.entries;

    // ����� ������� ���� ������
    database.size = 0;
}

int main()
{
    // ���������� ��������� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ����� ���������� ������ �� �����
    std::cout << "\t-= ������� 2 =- \n - ��������� ��� ������ ������ � ���� ������, ��������� � ������� �������.";
    std::cout << "\n\n������� ����� ������� ��� ������ ������...\n";
    _getwch();

    // ����� ����, ��������� �������������
    int option;

    // �������� ���� ������ �� �����
    if (!loadDatabase())
    {
        // ����� ������ � ������, ���� ���� ������ �� ���� ���������
        std::cout << "\n������: ���������� ������� ����.\n���������, ������� �� ���� ���� ������ ����� �������� �������.";
        _getwch();
        return 1;
    }

    // ������� ���� ����������
    do
    {
        // ����� ����
        system("cls");
        std::cout << "================\n";
        std::cout << "||    ����    ||\n";
        std::cout << "================\n\n";

        std::cout << "1. ����� �� �������;\n";
        std::cout << "2. ����� �� ������ ��������;\n\n";
        std::cout << "0. ����� �� ���������.\n\n";
        // ���� ������ � ����������
        std::cout << "������� �������� �������� �� ���������������� ������ ������ ����: ";
        std::cin >> option;

        // ���������� �������� � ����������� �� ������ ������������
        switch (option)
        {
        case 1: // ���������� ���� ��, ��� � � case 2
        case 2:
        {
            // ����� ��������� � ���� ������
            int nFound;
            DBEntry* found = search(option, nFound);

            std::cout << "=======================================================\n\n";

            // ����� ����������� �� �����
            if (nFound != 0)
            {
                std::cout << "��������� ������� �� ������ �������� - " << nFound << ":\n\n";
                display(found, nFound);
            }
            else
                std::cout << "�� ������� ����� ������ �� ������ ��������.";

            break;
        }
        case 0:
            return 0;

        default:
            std::cout << "\n\n������ �������� ����� ����.";
            break;
        }

        // ����� ���������
        std::cout << "\n\n������� ����� ������� ��� �����������...";
        _getwch();

    } while (option != 0);

    // ������������ ������������ ������ ���� ������
    unloadDatabase();

    // ���������� ���������
    return 0;
}