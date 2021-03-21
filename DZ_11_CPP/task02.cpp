/* ������� 2

	������: ��-011
	������: ������ ���������

	task02.cpp �������� � ���� ������������� ������� ��� ������ � ��������� */
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

/////////////////////// DOUBLE ///////////////////////

// ���������:
// - ���������� ������ �������� 10
// - ��� ����� ����� � ��������� ��������� -1
double maxInArray(double in[10], double except1 = -1, double except2 = -1)
{
	double max = -1;

	for (int i = 0; i < 10; i++)
		// ���� ������� ������� ������ ������������� 
		// ��� ������������ �������� ��� �� �����������
		// � ���� ������� ������� �� �������� �����������
		if ((in[i] > max || max == -1) && (in[i] != except1 && in[i] != except2))
			// �������� ������������ ��������
			max = in[i];

	return max;
}

double maxInArray(double in[3][3])
{
	double max = -1;

	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (in[x][y] > max || max == -1)
				max = in[x][y];

	return max;
}

double maxInArray(double in[2][2][2])
{
	double max = -1;

	for (int z = 0; z < 2; z++)
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 3; x++)
				if (in[x][y][z] > max || max == -1)
					max = in[x][y][z];

	return max;
}


void maxIntInArray(double in[10], int* out1, int* out2)
{
	// ���������� ��� ���������� ������������ �������� � ���������� ��� ������
	double max1, max2;
	// ����� ������ ������������ �������� � ���������� �������
	max1 = maxInArray(in);
	// ������ �����, �� ���� ��� � ����������� ������� ��������
	max2 = maxInArray(in, *out1);

	// ���������� ���������� ������ ��������
	*out1 = max1;
	*out2 = max2;
}

void maxIntInArray(double in[10], int* out1, int* out2, int* out3)
{
	// ���������� ��� ���������� ������������ �������� � ���������� ��� ������
	double max1, max2, max3;
	// ����� ������ ������������ �������� � ���������� �������
	max1 = maxInArray(in);
	// ������ �����, �� ���� ��� � ����������� ������� ��������
	max2 = maxInArray(in, max1);
	// ������ ����� � ����������� ������� ���� ���������
	max3 = maxInArray(in, max1, max2);

	// ���������� ���������� ������ ��������
	*out1 = max1;
	*out2 = max2;
	*out3 = max3;
}


///////////////////////   INT   ///////////////////////

int maxInArray(int in[10], int except1 = -1, int except2 = -1)
{
	int max = -1;

	for (int i = 0; i < 10; i++)
		if ((in[i] > max || max == -1) && (in[i] != except1 && in[i] != except2))
			max = in[i];

	return max;
}

int maxInArray(int in[3][3])
{
	int max = -1;

	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (in[x][y] > max || max == -1)
				max = in[x][y];

	return max;
}

int maxInArray(int in[2][2][2])
{
	int max = -1;

	for (int z = 0; z < 2; z++)
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 3; x++)
				if (in[x][y][z] > max || max == -1)
					max = in[x][y][z];

	return max;
}


void maxIntInArray(int in[10], int* out1, int* out2)
{
	// ����� ������ ������������ �������� � ���������� �������
	*out1 = maxInArray(in);
	// ������ �����, �� ���� ��� � ����������� ������� ��������
	*out2 = maxInArray(in, *out1);
}

void maxIntInArray(int in[10], int* out1, int* out2, int* out3)
{
	// ����� ������ ������������ �������� � ���������� �������
	*out1 = maxInArray(in);
	// ������ �����, �� ���� ��� � ����������� ������� ��������
	*out2 = maxInArray(in, *out1);
	// ������ ����� � ����������� ������� ���� ���������
	*out3 = maxInArray(in, *out1, *out2);
}


// ���������� ��������� ���������� ������������ �����
double rnd()
{
	return ((rand() % 512) / 1.23) - 256.;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	// ������������ ��������� ���� ���������� �������� ��������� ����������� �������� (����������� ��� ���������) 
	bool initToRand = false;

	// ���������� �������� � ��������� ����������

	int narr[10] = { 63, 25, 66, 34, 34, 96, 12, 36, 67, 19};
	int narr2D[3][3] = { { 12, 75, 23 }, { 63, 81, 15 } };
	int narr3D[2][2][2] = {{{64, 73}, {26, 13}}, {{67, 23}, {95, 45}}};

	double darr[10] = { 63.51, 2.512, 6.65342, 34.234, 5.1324, 91.563, 12.523, 3.64, 67.523, 1.91 };
	double darr2D[3][3] = { { 1.213, 75.52, 23.123 }, { 63.754, 81.735, 15.742 } };
	double darr3D[2][2][2] = {{{6.512344, 73.523}, {2.55236, 13.523}}, {{67.523, 233.542}, {95.634, 45.634}}};

	int max1, max2, max3;

	// ���������� �������� ���������� ����������
	// ��� ����������� �������
	if (initToRand)
	{
		for (int i = 0; i < 10; i++)
		{
			narr[i] = rnd();
			darr[i] = rnd();
		}

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				narr2D[y][x] = rnd();
				darr2D[y][x] = rnd();
			}
		}

		for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 2; y++)
			{
				for (int z = 0; z < 2; z++)
				{
					narr3D[z][y][x] = rnd();
					darr3D[z][y][x] = rnd();
				}
			}
		}
	}

	cout << "# ���������� �������� ����� ����������� � ����� ��������� #\n";

	cout << "\n - ������������ ����� � ���������� ������� int - " << maxInArray(narr);
	cout << "\n - ������������ ����� � ��������� ������� int - " << maxInArray(narr2D);
	cout << "\n - ������������ ����� � ��������� ������� int - " << maxInArray(narr3D);
	maxIntInArray(narr, &max1, &max2);
	cout << "\n\n - 2 ������������ ����� ����� � ������� int - " << max1 << " � " << max2;
	maxIntInArray(narr, &max1, &max2, &max3);
	cout << "\n - 3 ������������ ����� ����� � ������� int - " << max1 << ", " << max2 << " � " << max3;

	cout << "\n\n\n - ������������ ����� � ���������� ������� double - " << maxInArray(darr);
	cout << "\n - ������������ ����� � ��������� ������� double - " << maxInArray(darr2D);
	cout << "\n - ������������ ����� � ��������� ������� double - " << maxInArray(darr3D);
	maxIntInArray(darr, &max1, &max2);
	cout << "\n\n - 2 ������������ ����� ����� � ������� double - " << max1 << " � " << max2;
	maxIntInArray(darr, &max1, &max2, &max3);
	cout << "\n - 3 ������������ ����� ����� � ������� double - " << max1 << ", " << max2 << " � " << max3;

	// ���������� ������ ���������
	cout << "\n\n";
	system("pause");
	return 0;
}
