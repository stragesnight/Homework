/* ������� 3
task3.cpp ��������� ���������� ��������� ��� ������������� ��������������� ��������*/

#include <iostream>			//���������� ��� �����-������ ������ �� �����
using namespace std;		//��������� �� ���������� � std �������

//S = v * t + (a * t * t) / 2

int main()	//�������� ������� ���������
{
	float v, t, a, S;				//���������� ����������

	cout << "Enter v: ";			//�������� ������ � ���������� � ���������� �������� ����������
	cin >> v;

	cout << "Enter t: ";
	cin >> t;

	cout << "Enter a: ";
	cin >> a;

	S = v * t + (a * t * t) / 2;

	cout << "\nS = " << S << endl;	//����� �������� �� �����

	system("pause"); return 0;		//����� ��������� � ���������� � ����������
}