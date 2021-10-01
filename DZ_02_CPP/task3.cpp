/* ЗАДАНИЕ 3
task3.cpp выводит на экран объявление о продаже гаража*/

#include <iostream>			//библиотека для ввода-вывода текста на экран
using namespace std;		//позволяет не обращаться к std вручную

int main()					//основная функция программы
{
	cout << "PRODAM GARAJ\n\n"					// вывод текста на экран
		 << "Mestopolozhenie: ul.Primernaya, 43\n"
		 << "Telephon: 8800-555-35-35\n";

	system("pause"); return 0;					//пауза программы и объявление её завершения
}