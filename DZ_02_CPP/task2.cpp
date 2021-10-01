/* ЗАДАНИЕ 2
task2.cpp выводит песню "Every hunter wants..." на экран
и начинает каждый "цвет" с новой строки и с соответствующим количеством табуляций */

#include <iostream>			//библиотека для ввода-вывода текста на экран
using namespace std;		//позволяет не обращаться к std вручную

int main()					//основная функция программы
{
	cout <<      "Every \n\t"					//вывод текста на экран	
		 <<     "hunter \n\t\t"
		 <<   "wants to \n\t\t\t"
		 <<       "know \n\t\t\t\t"
		 <<      "where \n\t\t\t\t\t"
		 << "a pheasant \n\t\t\t\t\t\t"
		 <<       "sits \n";

	system("pause"); return 0;					//пауза программы и объявление её завершения
}