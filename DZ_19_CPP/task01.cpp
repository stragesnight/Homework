/* ������� 1
    ������: ��-011
    ������: ������ ���������
    task01.cpp - ��������� ��� ��������� ������ � �������� � �����. */
#include <iostream>
#include <fstream>
#include <Windows.h>

// ���������������� ���������
#define N_VOWELS 5 
#define N_CONSONANTS 21

// ������ ������� ����
const char vowels[] = { 'A', 'E', 'I', 'O', 'U', 
                        'a', 'e', 'i', 'o', 'u' 
};

// ������ ��������� ����
const char consonants[] = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z',
                            'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' 
};

// ��������� ���������� �������� � ������ (��� ����� ����-�����������)
int getStrCharCount(const char const* str)
{
    return strlen(str);
}

// ��������� ���������� ����� � ������
int getStrLineCount(const char const* str)
{
    int lineCount = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
            lineCount++;
    }

    return lineCount;
}

int* getStrVowelCount(const char const* str)
{
    int* vowelCount = new int[N_VOWELS]{};

    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int v = 0; v < N_VOWELS; v++)
            if (str[i] == vowels[v] || str[i] == vowels[v + N_VOWELS])
                vowelCount[v]++;
    }

    return vowelCount;
}

int* getStrConsonantCount(const char const* str)
{
    int* consonantCount = new int[N_CONSONANTS]{};

    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int c = 0; c < N_CONSONANTS; c++)
            if (str[i] == consonants[c] || str[i] == consonants[c + N_CONSONANTS])
                consonantCount[c]++;
    }

    return consonantCount;
}

int* getStrNumCount(const char const* str)
{
    int* numCount = new int[10]{};

    for (int i = 0; str[i] != '\0'; i++)
    {
        for (char n = '0'; n <= '9'; n++)
            if (str[i] == n)
                numCount[(int)n - '0']++;
    }

    return numCount;
}

int main()
{
    // ���������� ��������� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ����� ���������� ������ �� �����
    std::cout << "\t-= ������� 1 =- \n - ��������� ��� ��������� ������ � �������� � �����.";
    std::cout << "\n\n������� ����� ������� ��� ������ ������...\n";
    _getwch();

    std::cout << "\n���������� �������� ����� � ���� \"shelest_src.txt\"...\n\n";

    const char src[] = {    "This is source text. It will be written to file for later processing.\n"
                            "This chunk of text is consisting of 178 characters (excluding last zero-terminator, but with line breaks!).\n" 
    };

    std::ofstream srcOut("shelest_src.txt");
    srcOut.write(src, sizeof(src));
    srcOut.close();

    std::cout << "��������� ����� �� ����� \"shelest_src.txt\"...\n\n";

    char* loaded = new char[sizeof(src)];

    std::ifstream srcIn("shelest_src.txt");

    srcIn.read(loaded, sizeof(src));
    srcIn.close();

    std::cout << "�������� ���������� � ������...\n\n";

    int* vowelCount = getStrVowelCount(loaded);
    int* consonantCount = getStrConsonantCount(loaded);
    int* numCount = getStrNumCount(loaded);

    std::cout << "���������� ���������� � ������ � ����...\n\n";

    std::ofstream infoOut("shelest_info.txt");

    infoOut << "char count - " << getStrCharCount(loaded) << '\n';
    infoOut << "line count - " << getStrLineCount(loaded) << '\n';

    infoOut << "\n\nvowels in the text: ";
    int totalVowels = 0;
    for (int i = 0; i < N_VOWELS; i++)
    {
        infoOut << "\n'" << vowels[i] << "'s - " << vowelCount[i];
        totalVowels += vowelCount[i];
    }
    infoOut << "\ntotal vowel count - " << totalVowels;

    infoOut << "\n\nconsonants in the text: ";
    int totalConsonants = 0;
    for (int i = 0; i < N_CONSONANTS; i++)
    {
        infoOut << "\n'" << consonants[i] << "'s - " << consonantCount[i];
        totalConsonants += consonantCount[i];
    }
    infoOut << "\ntotal consonant count - " << totalConsonants;

    infoOut << "\n\nnumbers in the text: ";
    int totalNums = 0;
    for (int i = 0; i < 10; i++)
    {
        infoOut << "\n'" << i << "'s - " << numCount[i];
        totalNums += numCount[i];
    }
    infoOut << "\ntotal number count - " << totalNums;
    
    infoOut.close();

    std::cout << "������! �� ������ ����������� ���������� � ����� ��� ��������� \"shelest_info.txt\".\n\n";

    delete[] loaded;

    std::cout << "������� ����� ������� ��� ������ �� ���������...";
    // ���������� ���������
    _getwch();
    return 0;
}