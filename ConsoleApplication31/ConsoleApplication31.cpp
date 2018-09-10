// ConsoleApplication31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

//функция рандомного заполнения и распечатки массива

void printA(int **a, int N, int M) {

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			a[i][j] = 0 + rand() % 9;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
//функция удаления массива из памяти
void _del(int **a, int n) {

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}

	delete[] a;

}

//1.	Написать программу, которая удаляет из двухмерного массива, заполненного случайными числами строки, содержащие нулевые элементы.

void delZ(int **&a, int &n, int m) {

	int k = 0;
	

	//сортировка строк с нулевыми элементами
	for (int pass = 0; pass < n - 1; pass++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 0)
				{
					swap(a[i], a[i + 1]);
					break;
				}
			}
		}
	}

	//счетчик строк с 0-ми елементами
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
			{
				k++;
				break;
			}
		}
	}

	n = n - k; //количество строк без нулевых елементов

	//удаление нулевых елементов из массива
	for (int i = n - 1; i >= n; i--)
	{
		delete[] a[i];
	}

	//вывод массива без строк которые содержат 0 елементы..
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//2.	Написать программу, которая поэлементно суммирует два динамических двумерных массива, заполненных случайными числами и сохраняет результат в третьем массиве. Размеры исходных массивов  задаются пользователем.

void sumArr(int **a, int **b, int n, int m) {

	int **c;
	c = new int*[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
			cout << setw(3) << c[i][j] ;
		}
		cout << endl;
	}
	_del(c, n);
}


//3.	Создайте динамический массив, хранящий в первой строке идетификационный номер, а во второй - телефон. Организуйте поиск по ID и по номеру телефона и возможность ввода и изменения данных

void rand_in(int **p, const int s)
{
	int *k = p[0];
	int *n = p[1];
	for (int i = 0; i < s; i++)
	{
		*(k + i) = rand() % 20;
		*(n + i) = (rand() % 200);
	}
	p[0] = k;
	p[1] = n;
}
void out(int **p, const int s)
{
	cout << "ID  Телефон" << endl;
	for (int i = 0; i < s; i++)
	{
		cout << setw(3) << p[0][i];
		cout << setw(8) << p[1][i] << endl;
	}
}

int find1(int **p, const int s)
{
	int *k = p[0];
	int *n = p[1];
	int key, number;
	cout << "Введите ID : ";
	cin >> key;
	cout << "Введите номер телефона : ";
	cin >> number;
	cout << endl;
	for (int i = 0; i < s; i++)
		if (*(k + i) == key)
			if (*(n + i) == number)
				return i;
	return -1;
}
void change(int **p, const int s)
{
	int *k = p[0];
	int *n = p[1];
	int key, number;
	int new_key, new_number;
	cout << "Введите ID : ";
	cin >> key;
	cout << "Введите номер телефона : ";
	cin >> number;
	cout << endl;
	cout << "Введите замену для ID: ";
	cin >> new_key;
	cout << "Введите замену для телефона: ";
	cin >> new_number;
	for (int i = 0; i < s; i++)
	{
		if (*(k + i) == key)
		{
			*(k + i) = new_key;
		}
		if (*(n + i) == number)
		{
			*(n + i) = new_number;
		}
	}
}
void add(int **p, int& s)
{
	int *k = p[0];
	int *n = p[1];
	int *k_add = new int[++s];
	int *n_add = new int[s];

	for (int i = 0; i < s - 1; i++)
		*(k_add + i) = *(k + i);
	for (int i = 0; i < s - 1; i++)
		*(n_add + i) = *(n + i);

	int key, number;
	cout << "Введите код города : ";
	cin >> key;
	cout << "Введите номер телефона : ";
	cin >> number;
	cout << endl;
	*(k_add + s - 1) = key;
	*(n_add + s - 1) = number;

	p[0] = k_add;
	p[1] = n_add;
}





int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int **p, **p1, **p2;
	int n, m;
	
	//1.
	cout << "1. vvedite n m = ";
	cin >> n >> m;

	p = new int*[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = new int[m];
	}
	
	printA(p, n, m);
	cout << endl;
	cout << endl;
	delZ(p, n, m);
	_del(p, n);
	
	//2.
	cout << "2. vvedite n m = ";
	cin >> n >> m;

	p1 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		p1[i] = new int[m];
	}

	p2 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		p2[i] = new int[m];
	}

	printA(p1, n, m);
	cout << endl;
	printA(p2, n, m);
	cout << endl;
	
	sumArr(p1, p2, n, m);
	_del(p1, n);
	_del(p2, n);
	cout << endl;

	//3.
	cout << "3." << endl;
	int nSize = 5;
	int *pKey, *pNumber;
	srand(time(NULL));

	pKey = new int[nSize];
	pNumber = new int[nSize];
	int *masP[] = { pKey, pNumber };


	rand_in(masP, nSize);
	out(masP, nSize);

	bool f = true;
	while (f)
	{
		int c;

		cout << "Выберите действие :\n1 - поиск по номеру и по ID, \n2 - добавить номер"
			<< "\n3 - Изменить данные \n4 - выход\n";
		cin >> c;
		switch (c)
		{
		case 1:
		{
			int n = find1(masP, nSize);
			if (n > -1)
				cout << "Введенный номер в списке на " << n + 1 << " месте\n";
			else cout << "Такого номера в списке нет\n";
		}
		break;
		case 2:
		{
			add(masP, nSize);
			out(masP, nSize);
		}
		break;
		case 3:
		{
			change(masP, nSize);
			out(masP, nSize);
		}
		break;
		case 4:
		{
			f = false;
		}
		break;

		}
	}


    return 0;
}

