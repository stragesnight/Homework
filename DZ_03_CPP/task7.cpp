/* ЗАДАНИЕ 7
task7.cpp вычисляет конечную стоимость телефонного звонка, остовываясь на введённых пользователем данных 
и выводит результат на экран*/

#include <iostream>			//библиотека для ввода-вывода текста на экран
using namespace std;		//позволяет не обращаться к std вручную


int main()	//основная функция программы
{
	float costPerMinute, t, totalCost;		//объявление переменных
	int hrn, kop;

	//ввод данных
	cout << "==Phone call cost calculator=="
		 << "\n\nEnter cost per minute (hrn.kop): ";
	cin >> costPerMinute;
	cout << "Enter phone call time (sec): ";
	cin >> t;

	//перевод введённых секунд в минуты
	//t /= 60 эквивалентно t = t / 60
	t /= 60;

	//вычисление конечной стоимости звонка (грн.коп)
	totalCost = t * costPerMinute;
	//разделение стоимости на гривны и копейки
	hrn = totalCost;
	kop = (totalCost - hrn) * 100;

	//вывод результата на экран
	cout << "\nTotal phone call cost: " << hrn << " hrn, " << kop << " kopeck. \n\n";

	system("pause"); return 0;				//пауза программы и объявление её завершения
}