/* ЗАДАНИЕ 3
task3.cpp вычисляет пройденное растояние при прямолинейном равноускоренном движении*/

#include <iostream>			//библиотека для ввода-вывода текста на экран
using namespace std;		//позволяет не обращаться к std вручную

//S = v * t + (a * t * t) / 2

int main()	//основная функция программы
{
	float v, t, a, S;				//объявление переменных

	cout << "Enter v: ";			//введение данных с клавиатуры и присвоение значения переменным
	cin >> v;

	cout << "Enter t: ";
	cin >> t;

	cout << "Enter a: ";
	cin >> a;

	S = v * t + (a * t * t) / 2;

	cout << "\nS = " << S << endl;	//вывод значения на экран

	system("pause"); return 0;		//пауза программы и объявление её завершения
}