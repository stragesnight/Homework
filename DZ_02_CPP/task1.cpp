/* ЗАДАНИЕ 1
task1.cpp выводит один куплет песни на экран 
и использует escape-последовательности для форматирования */

#include <iostream>			//библиотека для ввода-вывода текста на экран
using namespace std;		//позволяет не обращаться к std вручную

int main()					//основная функция программы
{
	cout << "I'm giving you a night call to tell you how I feel\n"		//вывод текста на экран при помощи cout
		 << "(We'll go all, all, all night long)\n"
		 << "I want to drive you through the night, down the hills\n"
		 << "(We'll go all, all, all night long)\n"
		 << "I'm gonna tell you something you don't want to hear\n"
		 << "(We'll go all, all, all night long)\n"
		 << "I'm gonna show you where it's dark, but have no fear\n"
		 << "(We'll go all, all, all night long)\n";

	system("pause"); return 0;											//пауза программы и объявление её завершения
}