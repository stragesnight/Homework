/* ������� 8
task8.cpp ��������� �������� ������������� ���������� ���� � ������ � ���������� ���,
����� ������� ���������� �� �����*/

#include <iostream>			//���������� ��� �����-������ ������ �� �����
using namespace std;		//��������� �� ���������� � std �������


//����� ��������������� � ��������� ��������� ���������� ������� � ������ ��������, ��������� �� ���.
//�������� �� ����������.

//�������� ������� ���������
int main()
{
	//���������� ����������
	int input, weeks, days;
	//���� ������
	cout << "Enter total day count: ";
	cin >> input;

	//���������� ������ ����� ���������� ���� �������� �� 7,
	//� ������ �� ������� ������������� ��������� ���� ������ int
	weeks = input / 7;
	//���������� ���������� ���� ����� ������ �� ������� ������� ���������� ���� �� 7
	days = input % 7;

	//����� ���������� �� �����
	cout << "\nYou have entered: " << weeks << " weeks and " << days << " days. \n\n";

	//����� ��������� � ���������� � ����������
	system("pause"); return 0;
}