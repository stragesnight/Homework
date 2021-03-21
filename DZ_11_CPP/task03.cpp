/* ������� 3

	������: ��-011
	������: ������ ���������

	task03.cpp �������� ������ �� ������ ���� �������, �� � ����������� �������� */
#include <iostream>		// ����-����� ������
#include <algorithm>	// �������� �������� ����������
#include <stdlib.h>		// �������� srand
#include <ctime>		// ������������ ��� ������� ����� ���������

using namespace std;

// ���������� ������� ������� ���������� ����������
// *��������� �������� � ��� ��������� ����� ��������*
// **����� ������� ������� ������� ����� �����������**
const int SIZE = 3;

/////////////////  ������ �������   /////////////////

template <class T>
void initMat(T in[SIZE * SIZE], T out[SIZE][SIZE])
{
	// �������������� ����������� �������
	// � ������� �������� SIZE
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			out[y][x] = in[y * SIZE + x];
}

template <class T>
void coutMat(T mat[SIZE][SIZE])
{
	cout << "\n - �������: \n\n";
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
			cout << mat[y][x] << "\t";

		cout << "\n\n";
	}

}

template <class T>
void minMaxMat(T mat[SIZE][SIZE])
{
	cout << "\n - ����������� � ������������ �������� �� ������� ���������: \n\n";

	T min = -1, max = -1;

	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			// ���� ������� ������� ��������� �� ������� ���������
			if (x == y)
			{
				cout << "|" << mat[y][x] << "|" << "\t";

				// ���� ������� ������� ������ ������������� ��� ������������ ������� ��� �� ����������
				if (mat[y][x] > max || max == -1)
					max = mat[y][x];
				// ���� ������� ������� ������ ������������ ��� ����������� ������� ��� �� ����������
				if (mat[y][x] < min || min == -1)
					min = mat[y][x];
			}
			else
				cout << " " << mat[y][x] << "\t";
		}

		cout << "\n\n";
	}

	cout << "\n����������� ������� �� ������� ��������� - " << min;
	cout << "\n������������ ������� �� ������� ��������� - " << max << "\n\n";
}

template <class T>
void sortMat(T mat[SIZE][SIZE])
{
	cout << "\n - ���������� �������...";

	for (int y = 0; y < SIZE; y++)
		// ���������� ��������� ���������� �� ���������� algorithm
		// �� ������ ������� �������� � ���� �� ������ ���������� ��������
		sort(&mat[y][0], &mat[y][SIZE]);

	coutMat(mat);
}

/////////////////  ������ �������  /////////////////

// ���������:
// - ���������� ������ �������� 10
// - ��� ����� ����� � ��������� ��������� -1
template <class T>
T maxInArray(T in[10], T except1 = -1, T except2 = -1)
{
	T max = -1;

	for (int i = 0; i < 10; i++)
		// ���� ������� ������� ������ ������������� 
		// ��� ������������ �������� ��� �� �����������
		// � ���� ������� ������� �� �������� �����������
		if ((in[i] > max || max == -1) && (in[i] != except1 && in[i] != except2))
			// �������� ������������ ��������
			max = in[i];

	return max;
}

template <class T>
T maxInArray(T in[3][3])
{
	T max = -1;

	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (in[x][y] > max || max == -1)
				max = in[x][y];

	return max;
}

template <class T>
T maxInArray(T in[2][2][2])
{
	T max = -1;

	for (int z = 0; z < 2; z++)
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 3; x++)
				if (in[x][y][z] > max || max == -1)
					max = in[x][y][z];

	return max;
}

template <class T>
void maxIntInArray(T in[10], int* out1, int* out2)
{
	// ���������� ��� ���������� ������������ �������� � ���������� ��� ������
	T max1, max2;
	// ����� ������ ������������ �������� � ���������� �������
	max1 = maxInArray(in);
	// ������ �����, �� ���� ��� � ����������� ������� ��������
	max2 = maxInArray(in, max1);

	// ���������� ���������� ������ ��������
	*out1 = max1;
	*out2 = max2;
}

template <class T>
void maxIntInArray(T in[10], int* out1, int* out2, int* out3)
{
	// ���������� ��� ���������� ������������ �������� � ���������� ��� ������
	T max1, max2, max3;
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

// ���������� ��������� ���������� ������������ �����
double rnd()
{
	return (rand() % 512) / 1.23;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "�������� ������� �11, ������� 3. ���� .cpp �������� � ����"
		 << "\n������� ������ ���� �����, �� � ����������� �������� �������."
		 << "\n������� Enter ��� ������������ ���� ���� ��������.\n\n";

	cin.get();

	// ������������ ��� �������� ������ � ��������� ����� ������
	enum dataType { INT = 1, DOUBLE, CHAR };

	int dataTypeIndex;
	int initRand;

	int inputINT[SIZE * SIZE] = {};
	double inputDOUBLE[SIZE * SIZE] = {};
	char inputCHAR[SIZE * SIZE] = {};

	cout << "��������� ���� ������:\n\t1 - int\n\t2 - double\n\t3 - char\n\n";
	cout << "������� �����, ��������������� ��������� ���� ������: ";
	cin >> dataTypeIndex;

	cout << "\n������� 0 ��� ����� ������ �������,\n\t��� ����� ������ ������� ��� ��������� ��������� - ";
	cin >> initRand;

	if (!initRand)
		cout << "\n��������������� ������� " << SIZE * SIZE << " ��������(-�) ���������� ���� ������: ";

	// ����� ���� ������ � ����������� �� ������ ������������
	switch (dataTypeIndex)
	{
	case INT:
		// ����������, ������� ����� ������������� ����� ��������� �������
		int matINT[SIZE][SIZE];

		// ���������� ������� �������� �������
		for (int i = 0; i < SIZE * SIZE; i++)
			if (initRand)
				inputINT[i] = rnd();
			else
				cin >> inputINT[i];

		// ����� ������ ������� �� ����������
		initMat(inputINT, matINT);
		coutMat(matINT);
		minMaxMat(matINT);
		sortMat(matINT);

		break;

	case DOUBLE:
		double matDOUBLE[SIZE][SIZE];

		for (int i = 0; i < SIZE * SIZE; i++)
			if (initRand)
				inputDOUBLE[i] = rnd();
			else
				cin >> inputDOUBLE[i];

		initMat(inputDOUBLE, matDOUBLE);
		coutMat(matDOUBLE);
		minMaxMat(matDOUBLE);
		sortMat(matDOUBLE);

		break;

	case CHAR:
		char matCHAR[SIZE][SIZE];

		for (int i = 0; i < SIZE * SIZE; i++)
			if (initRand)
				inputCHAR[i] = rnd();
			else
				cin >> inputCHAR[i];

		initMat(inputCHAR, matCHAR);
		coutMat(matCHAR);
		minMaxMat(matCHAR);
		sortMat(matCHAR);

		break;
	}

	///////////////////   ������� 2   ///////////////////

	// ���������� �������� � ��������� ����������

	int narr[10] = { 63, 25, 66, 34, 34, 96, 12, 36, 67, 19 };
	int narr2D[3][3] = { { 12, 75, 23 }, { 63, 81, 15 } };
	int narr3D[2][2][2] = { {{64, 73}, {26, 13}}, {{67, 23}, {95, 45}} };

	double darr[10] = { 63.51, 2.512, 6.65342, 34.234, 5.1324, 91.563, 12.523, 3.64, 67.523, 1.91 };
	double darr2D[3][3] = { { 1.213, 75.52, 23.123 }, { 63.754, 81.735, 15.742 } };
	double darr3D[2][2][2] = { {{6.512344, 73.523}, {2.55236, 13.523}}, {{67.523, 233.542}, {95.634, 45.634}} };

	int max1, max2, max3;

	cout << "\n\n\n# ������� 2 #\n# ���������� �������� ����� ����������� � ����� ��������� #\n";

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
