/* ������� 7
task7.cpp ��������� �������� ��������� ����������� ������, ����������� �� �������� ������������� ������ 
� ������� ��������� �� �����*/

#include <iostream>			//���������� ��� �����-������ ������ �� �����
using namespace std;		//��������� �� ���������� � std �������


int main()	//�������� ������� ���������
{
	float costPerMinute, t, totalCost;		//���������� ����������
	int hrn, kop;

	//���� ������
	cout << "==Phone call cost calculator=="
		 << "\n\nEnter cost per minute (hrn.kop): ";
	cin >> costPerMinute;
	cout << "Enter phone call time (sec): ";
	cin >> t;

	//������� �������� ������ � ������
	//t /= 60 ������������ t = t / 60
	t /= 60;

	//���������� �������� ��������� ������ (���.���)
	totalCost = t * costPerMinute;
	//���������� ��������� �� ������ � �������
	hrn = totalCost;
	kop = (totalCost - hrn) * 100;

	//����� ���������� �� �����
	cout << "\nTotal phone call cost: " << hrn << " hrn, " << kop << " kopeck. \n\n";

	system("pause"); return 0;				//����� ��������� � ���������� � ����������
}