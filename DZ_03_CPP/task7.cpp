/* «јƒјЌ»≈ 7
task7.cpp вычисл€ет конечную стоимость телефонного звонка, остовыва€сь на введЄнных пользователем данных 
и выводит результат на экран*/

#include <iostream>			//библиотека дл€ ввода-вывода текста на экран
using namespace std;		//позвол€ет не обращатьс€ к std вручную


int main()	//основна€ функци€ программы
{
	float costPerMinute, t, totalCost;		//объ€вление переменных
	int hrn, kop;

	//ввод данных
	cout << "==Phone call cost calculator=="
		 << "\n\nEnter cost per minute (hrn.kop): ";
	cin >> costPerMinute;
	cout << "Enter phone call time (sec): ";
	cin >> t;

	//перевод введЄнных секунд в минуты
	//t /= 60 эквивалентно t = t / 60
	t /= 60;

	//вычисление конечной стоимости звонка (грн.коп)
	totalCost = t * costPerMinute;
	//разделение стоимости на гривны и копейки
	hrn = totalCost;
	kop = (totalCost - hrn) * 100;

	//вывод результата на экран
	cout << "\nTotal phone call cost: " << hrn << " hrn, " << kop << " kopeck. \n\n";

	system("pause"); return 0;				//пауза программы и объ€вление еЄ завершени€
}