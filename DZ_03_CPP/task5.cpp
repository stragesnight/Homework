/* ЗАДАНИЕ 5
task5.cpp преобразует введённое дробное число в денежний эквивалент и выводит его на экран*/

#include <iostream>			//библиотека для ввода-вывода текста на экран
using namespace std;		//позволяет не обращаться к std вручную


int main()	//основная функция программы
{
	float input;						//объявление переменных
	int hrn, kopeck;

	cout << "Enter float value: ";		//ввод данных
	cin >> input;

	//при присвоении int значению типа float отсекается его дробная часть,
	//что и нужно сделать для получения желаемого результата
	hrn = input;
	//количество копеек равно дробной части введённого значения (разнице между его значением и int эквивалентом) умноженному на 100
	kopeck = (input - hrn) * 100;

	//вывод результата на экран
	cout << "\nYou entered: " << hrn << " hrn, " << kopeck << " kopeck \n";

	system("pause"); return 0;			//пауза программы и объявление её завершения
}