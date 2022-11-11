#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <limits>
#include <windows.h>
#include <conio.h>

int enShip4 = 1, enShip3 = 2, enShip2 = 3, enShip1 = 4;
bool flag4 = true, flag3_1 = true, flag3_2 = true, flag2_1 = true, flag2_2 = true, flag2_3 = true, flag1_1 = true, flag1_2 = true, flag1_3 = true, flag1_4 = true;

int fact_4_1, fact_3_1, fact_3_2, fact_2_1, fact_2_2, fact_2_3;
int x1_4_1, x2_4_1, x3_4_1, x4_4_1, y1_4_1, y2_4_1, y3_4_1, y4_4_1;
int x1_3_1, x2_3_1, x3_3_1, y1_3_1, y2_3_1, y3_3_1;
int x1_3_2, x2_3_2, x3_3_2, y1_3_2, y2_3_2, y3_3_2;
int x1_2_1, x2_2_1, y1_2_1, y2_2_1;
int x1_2_2, x2_2_2, y1_2_2, y2_2_2;
int x1_2_3, x2_2_3, y1_2_3, y2_2_3;
int x1_1_1, y1_1_1, x1_1_2, y1_1_2, x1_1_3, y1_1_3, x1_1_4, y1_1_4;

int mfact_4_1, mfact_3_1, mfact_3_2, mfact_2_1, mfact_2_2, mfact_2_3;
int mx1_4_1, mx2_4_1, mx3_4_1, mx4_4_1, my1_4_1, my2_4_1, my3_4_1, my4_4_1;
int mx1_3_1, mx2_3_1, mx3_3_1, my1_3_1, my2_3_1, my3_3_1;
int mx1_3_2, mx2_3_2, mx3_3_2, my1_3_2, my2_3_2, my3_3_2;
int mx1_2_1, mx2_2_1, my1_2_1, my2_2_1;
int mx1_2_2, mx2_2_2, my1_2_2, my2_2_2;
int mx1_2_3, mx2_2_3, my1_2_3, my2_2_3;
int mx1_1_1, my1_1_1, mx1_1_2, my1_1_2, mx1_1_3, my1_1_3, mx1_1_4, my1_1_4;

using namespace std;

class Ship
{
public:
	char x1; // буква начала
	char x2; // буква конца
	int y1; // цифра начала
	int y2; // цифра конца

	~Ship() {}
};

class Field
{
public:
	char map[12][12]; // клетки на поле игры
	
	Ship sh4;
	Ship sh3_1;
	Ship sh3_2;
	Ship sh2_1;
	Ship sh2_2;
	Ship sh2_3;
	Ship sh1_1;
	Ship sh1_2;
	Ship sh1_3;
	Ship sh1_4;

	Field()
	{
		for (int j = 0; j < 12; j++)
			for (int i = 0; i < 12; i++)
				map[i][j] = ' ';
	}

	void printMap() {} // метод вывода поля на экран
	~Field() {}
};

class PlayerField : public Field
{	
public:
	int meHelp[12][12]; // вспомогательный массив (для анализа игры компьютером)

	PlayerField()
	{
		for (int j = 0; j < 12; j++)
			for (int i = 0; i < 12; i++)
				meHelp[i][j] = 0;
	}

	void printMap()	// вывод поля игрока на экран (переопределённый метод)
	{
		cout << "\n\n\n\n";
		cout << "Ваше поле: " << endl;
		cout << "    a b c d e f g h i j" << endl;
		cout << "    ———————————————————" << endl;
		for (int j = 1; j < 11; j++)
		{
			if (j == 10)
				cout << j << " |";
			else
				cout << j << "  |";
			for (int i = 1; i < 11; i++)
			{
				if (i == 10)
					cout << map[i][j];
				else
					cout << map[i][j] << " ";

				if (j == 1 && i == 10)
				{
					cout << "|\t\t|----------------------------------";
				}
				if (j == 2 && i == 10)
				{
					cout << "|\t\t|Вам осталось потопить кораблей: " << enShip4 + enShip3 + enShip2 + enShip1;
				}
				if (j == 3 && i == 10)
				{
					cout << "|\t\t|\t#### \t- \t" << enShip4;
				}
				if (j == 4 && i == 10)
				{
					cout << "|\t\t|\t### \t- \t" << enShip3;
				}
				if (j == 5 && i == 10)
				{
					cout << "|\t\t|\t## \t- \t" << enShip2;
				}
				if (j == 6 && i == 10)
				{
					cout << "|\t\t|\t# \t- \t" << enShip1;
				}
				if (j == 7 && i == 10)
				{
					cout << "|\t\t|----------------------------------";
				}
			}
			if(j > 7)
				cout << "|" << endl;
			else
				cout << " " << endl;
		}
		cout << "    ———————————————————" << endl;
	}

	~PlayerField() {}
};

class EnemyField : public Field
{
public:
	void printMap()	// вывод поля противника на экран (переопределённый метод)
	{
		cout << "\nПоле противника: " << endl;
		cout << "    a b c d e f g h i j" << endl;
		cout << "    ———————————————————" << endl;
		for (int j = 1; j < 11; j++)
		{
			if (j == 10)
				cout << j << " |";
			else
				cout << j << "  |";
			for (int i = 1; i < 11; i++)
			{
				if (i == 10)
					cout << map[i][j];
				else
					cout << map[i][j] << " ";
			}
			cout << "|" << endl;
		}
		cout << "    ———————————————————" << endl;
	}

	~EnemyField() {}
};

void set4ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12]);
void set3_1ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12]);
void set3_2ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12]);
void set2_1ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12]);
void set2_2ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12]);
void set2_3ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12]);
void set1_1ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12]);
void set1_2ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12]);
void set1_3ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12]);
void set1_4ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12]);


// расстановка кораблей игроком
void checkMy4(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	cout << "Введите координаты начала и конца 4-хпалубного корабля латинскими буквами и цифрами (например, b4 b7) и нажмите клавишу Enter:\n";
	cin >> myMap.sh4.x1 >> myMap.sh4.y1 >> myMap.sh4.x2 >> myMap.sh4.y2;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while ((!(myMap.sh4.x1 >= 'a' && myMap.sh4.x1 <= 'j') || (myMap.sh4.y1 < 1 || myMap.sh4.y1 > 10)) && (!(myMap.sh4.x2 >= 'a' && myMap.sh4.x2 <= 'j') || (myMap.sh4.y2 < 1 || myMap.sh4.y2 > 10)))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты начала и конца первого 4-хпалубного корабля латинскими буквами и цифрами (например, b4 b7) и нажмите клавишу Enter:\n";
		cin >> myMap.sh4.x1 >> myMap.sh4.y1 >> myMap.sh4.x2 >> myMap.sh4.y2;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set4ByPlayer(myMap, en1Map, map, meHelp);
}

void set4ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	system("cls");
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh4.y1;
	int yk2 = myMap.sh4.y2;
	int xk1 = (int)(myMap.sh4.x1) - 96;
	int xk2 = (int)(myMap.sh4.x2) - 96;

	if (yk1 == yk2)
	{
		if (abs(xk2 - xk1) == 3)
			if (xk1 < xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2 - 1][yk1 - 1] != ' ' || map[xk2 - 1][yk1] != ' ' || map[xk2 - 1][yk1 + 1] != ' ' ||
					map[xk2][yk1] != ' ' || map[xk2][yk1 - 1] != ' ' || map[xk2][yk1 + 1] != ' ' ||
					map[xk2 + 1][yk1] != ' ' || map[xk2 + 1][yk1 - 1] != ' ' || map[xk2 + 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i <= xk2; i++)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 4;
					}
					mx1_4_1 = xk1; mx2_4_1 = xk1 + 1; mx3_4_1 = xk1 + 2;	mx4_4_1 = xk1 + 3;
					my1_4_1 = yk1; my2_4_1 = yk1;	  my3_4_1 = yk1;		my4_4_1 = yk1;
					mfact_4_1 = 13;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy4(myMap, en1Map, map, meHelp);
				}
			else if (xk1 > xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2][yk1] != ' ' || map[xk2][yk1 - 1] != ' ' || map[xk2][yk1 + 1] != ' ' ||
					map[xk2 - 1][yk1] != ' ' || map[xk2 - 1][yk1 - 1] != ' ' || map[xk2 - 1][yk1 + 1] != ' ' ||
					map[xk2 + 1][yk1] != ' ' || map[xk2 + 1][yk1 - 1] != ' ' || map[xk2 + 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i >= xk2; i--)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 4;
					}
					mx1_4_1 = xk1; mx2_4_1 = xk1 - 1;		mx3_4_1 = xk1 - 2;	mx4_4_1 = xk1 - 3;
					my1_4_1 = yk1; my2_4_1 = yk1;			my3_4_1 = yk1;		my4_4_1 = yk1;
					mfact_4_1 = 14;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy4(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy4(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy4(myMap, en1Map, map, meHelp);
		}
	}
	else if (xk1 == xk2)
	{
		if (abs(yk2 - yk1) == 3)
			if (yk1 < yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2 - 1] != ' ' || map[xk1][yk2 - 1] != ' ' || map[xk1 + 1][yk2 - 1] != ' ' ||
					map[xk1 - 1][yk2] != ' ' || map[xk1][yk2] != ' ' || map[xk1 + 1][yk2] != ' ' ||
					map[xk1 - 1][yk2 + 1] != ' ' || map[xk1][yk2 + 1] != ' ' || map[xk1 + 1][yk2 + 1] != ' '))
				{
					for (int j = yk1; j <= yk2; j++)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 4;
					}
					mx1_4_1 = xk1; mx2_4_1 = xk1;			mx3_4_1 = xk1;		mx4_4_1 = xk1;
					my1_4_1 = yk1; my2_4_1 = yk1 + 1;		my3_4_1 = yk1 + 2;	my4_4_1 = yk1 + 3;
					mfact_4_1 = 23;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy4(myMap, en1Map, map, meHelp);
				}
			else if (yk1 > yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2] != ' ' || map[xk1][yk2] != ' ' || map[xk1 + 1][yk2] != ' ' ||
					map[xk1 - 1][yk2 + 1] != ' ' || map[xk1][yk2 + 1] != ' ' || map[xk1 + 1][yk2 + 1] != ' ' ||
					map[xk1 - 1][yk2 - 1] != ' ' || map[xk1][yk2 - 1] != ' ' || map[xk1 + 1][yk2 - 1] != ' ')) {
					for (int j = yk1; j >= yk2; j--)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 4;
					}
					mx1_4_1 = xk1; mx2_4_1 = xk1;			mx3_4_1 = xk1;		mx4_4_1 = xk1;
					my1_4_1 = yk1; my2_4_1 = yk1 - 1;		my3_4_1 = yk1 - 2;	my4_4_1 = yk1 - 3;
					mfact_4_1 = 24;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy4(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy4(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy4(myMap, en1Map, map, meHelp);
		}
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy4(myMap, en1Map, map, meHelp);
	}
}


void checkMy3_1(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	cout << "Введите координаты начала и конца первого 3-хпалубного корабля латинскими буквами и цифрами (например, b4 b6) и нажмите клавишу Enter:\n";
	cin >> myMap.sh3_1.x1 >> myMap.sh3_1.y1 >> myMap.sh3_1.x2 >> myMap.sh3_1.y2;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while ((!(myMap.sh3_1.x1 >= 'a' && myMap.sh3_1.x1 <= 'j') || (myMap.sh3_1.y1 < 1 || myMap.sh3_1.y1 > 10)) && (!(myMap.sh3_1.x2 >= 'a' && myMap.sh3_1.x2 <= 'j') || (myMap.sh3_1.y2 < 1 || myMap.sh3_1.y2 > 10)))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты начала и конца первого 3-хпалубного корабля латинскими буквами и цифрами (например, b4 b6) и нажмите клавишу Enter:\n";
		cin >> myMap.sh3_1.x1 >> myMap.sh3_1.y1 >> myMap.sh3_1.x2 >> myMap.sh3_1.y2;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set3_1ByPlayer(myMap, en1Map, map, meHelp);
}

void set3_1ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	system("cls");
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh3_1.y1;
	int yk2 = myMap.sh3_1.y2;
	int xk1 = (int)(myMap.sh3_1.x1) - 96;
	int xk2 = (int)(myMap.sh3_1.x2) - 96;

	if (yk1 == yk2)
	{
		if (abs(xk2 - xk1) == 2)
			if (xk1 < xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2][yk1] != ' ' || map[xk2][yk1 - 1] != ' ' || map[xk2][yk1 + 1] != ' ' ||
					map[xk2 + 1][yk1] != ' ' || map[xk2 + 1][yk1 - 1] != ' ' || map[xk2 + 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i <= xk2; i++)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 3;
					}
					mx1_3_1 = xk1; mx2_3_1 = xk1 + 1;   mx3_3_1 = xk1 + 2;
					my1_3_1 = yk1; my2_3_1 = yk1;		my3_3_1 = yk1;
					mfact_3_1 = 13;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy3_1(myMap, en1Map, map, meHelp);
				}
			else if (xk1 > xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2][yk1] != ' ' || map[xk2][yk1 - 1] != ' ' || map[xk2][yk1 + 1] != ' ' ||
					map[xk2 - 1][yk1] != ' ' || map[xk2 - 1][yk1 - 1] != ' ' || map[xk2 - 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i >= xk2; i--)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 3;
					}
					mx1_3_1 = xk1; mx2_3_1 = xk1 - 1;		mx3_3_1 = xk1 - 2;
					my1_3_1 = yk1; my2_3_1 = yk1;			my3_3_1 = yk1;
					mfact_3_1 = 14;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy3_1(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy3_1(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy3_1(myMap, en1Map, map, meHelp);
		}
	}
	else if (xk1 == xk2)
	{
		if (abs(yk2 - yk1) == 2)
			if (yk1 < yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2] != ' ' || map[xk1][yk2] != ' ' || map[xk1 + 1][yk2] != ' ' ||
					map[xk1 - 1][yk2 + 1] != ' ' || map[xk1][yk2 + 1] != ' ' || map[xk1 + 1][yk2 + 1] != ' '))
				{
					for (int j = yk1; j <= yk2; j++)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 3;
					}
					mx1_3_1 = xk1;	mx2_3_1 = xk1;		mx3_3_1 = xk1;
					my1_3_1 = yk1;	my2_3_1 = yk1 + 1;	my3_3_1 = yk1 + 2;
					mfact_3_1 = 23;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy3_1(myMap, en1Map, map, meHelp);
				}
			else if (yk1 > yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2] != ' ' || map[xk1][yk2] != ' ' || map[xk1 + 1][yk2] != ' ' ||
					map[xk1 - 1][yk2 - 1] != ' ' || map[xk1][yk2 - 1] != ' ' || map[xk1 + 1][yk2 - 1] != ' '))
				{
					for (int j = yk1; j >= yk2; j--)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 3;
					}
					mx1_3_1 = xk1;	mx2_3_1 = xk1;		mx3_3_1 = xk1;
					my1_3_1 = yk1;	my2_3_1 = yk1 - 1;	my3_3_1 = yk1 - 2;
					mfact_3_1 = 24;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy3_1(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy3_1(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy3_1(myMap, en1Map, map, meHelp);
		}
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy3_1(myMap, en1Map, map, meHelp);
	}
}


void checkMy3_2(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	cout << "Введите координаты начала и конца второго 3-хпалубного корабля латинскими буквами и цифрами (например, b4 b6) и нажмите клавишу Enter:\n";
	cin >> myMap.sh3_2.x1 >> myMap.sh3_2.y1 >> myMap.sh3_2.x2 >> myMap.sh3_2.y2;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while ((!(myMap.sh3_2.x1 >= 'a' && myMap.sh3_2.x1 <= 'j') || (myMap.sh3_2.y1 < 1 || myMap.sh3_2.y1 > 10)) && (!(myMap.sh3_2.x2 >= 'a' && myMap.sh3_2.x2 <= 'j') || (myMap.sh3_2.y2 < 1 || myMap.sh3_2.y2 > 10)))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты начала и конца второго 3-хпалубного корабля латинскими буквами и цифрами (например, b4 b6) и нажмите клавишу Enter:\n";
		cin >> myMap.sh3_2.x1 >> myMap.sh3_2.y1 >> myMap.sh3_2.x2 >> myMap.sh3_2.y2;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set3_2ByPlayer(myMap, en1Map, map, meHelp);
}

void set3_2ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	system("cls");
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh3_2.y1;
	int yk2 = myMap.sh3_2.y2;
	int xk1 = (int)(myMap.sh3_2.x1) - 96;
	int xk2 = (int)(myMap.sh3_2.x2) - 96;

	if (yk1 == yk2)
	{
		if (abs(xk2 - xk1) == 2)
			if (xk1 < xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2][yk1] != ' ' || map[xk2][yk1 - 1] != ' ' || map[xk2][yk1 + 1] != ' ' ||
					map[xk2 + 1][yk1] != ' ' || map[xk2 + 1][yk1 - 1] != ' ' || map[xk2 + 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i <= xk2; i++)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 3;
					}
					mx1_3_2 = xk1;	mx2_3_2 = xk1 + 1;	mx3_3_2 = xk1 + 2;
					my1_3_2 = yk1;	my2_3_2 = yk1;		my3_3_2 = yk1;
					mfact_3_2 = 13;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy3_2(myMap, en1Map, map, meHelp);
				}
			else if (xk1 > xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2][yk1] != ' ' || map[xk2][yk1 - 1] != ' ' || map[xk2][yk1 + 1] != ' ' ||
					map[xk2 - 1][yk1] != ' ' || map[xk2 - 1][yk1 - 1] != ' ' || map[xk2 - 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i >= xk2; i--)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 3;
					}
					mx1_3_2 = xk1; mx2_3_2 = xk1 - 1;		mx3_3_2 = xk1 - 2;
					my1_3_2 = yk1; my2_3_2 = yk1;			my3_3_2 = yk1;
					mfact_3_2 = 14;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy3_2(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy3_2(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy3_2(myMap, en1Map, map, meHelp);
		}
	}
	else if (xk1 == xk2)
	{
		if (abs(yk2 - yk1) == 2)
			if (yk1 < yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2] != ' ' || map[xk1][yk2] != ' ' || map[xk1 + 1][yk2] != ' ' ||
					map[xk1 - 1][yk2 + 1] != ' ' || map[xk1][yk2 + 1] != ' ' || map[xk1 + 1][yk2 + 1] != ' '))
				{
					for (int j = yk1; j <= yk2; j++)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 3;
					}
					mx1_3_2 = xk1;	mx2_3_2 = xk1;		mx3_3_2 = xk1;
					my1_3_2 = yk1;	my2_3_2 = yk1 + 1;	my3_3_2 = yk1 + 2;
					mfact_3_2 = 23;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy3_2(myMap, en1Map, map, meHelp);
				}
			else if (yk1 > yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2] != ' ' || map[xk1][yk2] != ' ' || map[xk1 + 1][yk2] != ' ' ||
					map[xk1 - 1][yk2 - 1] != ' ' || map[xk1][yk2 - 1] != ' ' || map[xk1 + 1][yk2 - 1] != ' '))
				{
					for (int j = yk1; j >= yk2; j--)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 3;
					}
					mx1_3_2 = xk1;		mx2_3_2 = xk1;		mx3_3_2 = xk1;
					my1_3_2 = yk1;		my2_3_2 = yk1 - 1;	my3_3_2 = yk1 - 2;
					mfact_3_2 = 24;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy3_2(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy3_2(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy3_2(myMap, en1Map, map, meHelp);
		}
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy3_2(myMap, en1Map, map, meHelp);
	}
}


void checkMy2_1(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	cout << "Введите координаты начала и конца первого 2-хпалубного корабля латинскими буквами и цифрами (например, b4 b5) и нажмите клавишу Enter:\n";
	cin >> myMap.sh2_1.x1 >> myMap.sh2_1.y1 >> myMap.sh2_1.x2 >> myMap.sh2_1.y2;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while ((!(myMap.sh2_1.x1 >= 'a' && myMap.sh2_1.x1 <= 'j') || (myMap.sh2_1.y1 < 1 || myMap.sh2_1.y1 > 10)) && (!(myMap.sh2_1.x2 >= 'a' && myMap.sh2_1.x2 <= 'j') || (myMap.sh2_1.y2 < 1 || myMap.sh2_1.y2 > 10)))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты начала и конца первого 2-хпалубного корабля латинскими буквами и цифрами (например, b4 b5) и нажмите клавишу Enter:\n";
		cin >> myMap.sh2_1.x1 >> myMap.sh2_1.y1 >> myMap.sh2_1.x2 >> myMap.sh2_1.y2;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set2_1ByPlayer(myMap, en1Map, map, meHelp);
}

void set2_1ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	system("cls");
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh2_1.y1;
	int yk2 = myMap.sh2_1.y2;
	int xk1 = (int)(myMap.sh2_1.x1) - 96;
	int xk2 = (int)(myMap.sh2_1.x2) - 96;

	if (yk1 == yk2)
	{
		if (abs(xk2 - xk1) == 1)
			if (xk1 < xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2 + 1][yk1] != ' ' || map[xk2 + 1][yk1 - 1] != ' ' || map[xk2 + 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i <= xk2; i++)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 2;
					}
					mx1_2_1 = xk1;	mx2_2_1 = xk1 + 1;
					my1_2_1 = yk1;	my2_2_1 = yk1;
					mfact_2_1 = 13;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_1(myMap, en1Map, map, meHelp);
				}
			else if (xk1 > xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2 - 1][yk1] != ' ' || map[xk2 - 1][yk1 - 1] != ' ' || map[xk2 - 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i >= xk2; i--)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 2;
					}
					mx1_2_1 = xk1; mx2_2_1 = xk1 - 1;
					my1_2_1 = yk1; my2_2_1 = yk1;
					mfact_2_1 = 14;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_1(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy2_1(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy2_1(myMap, en1Map, map, meHelp);
		}
	}
	else if (xk1 == xk2)
	{
		if (abs(yk2 - yk1) == 1)
			if (yk1 < yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2 + 1] != ' ' || map[xk1][yk2 + 1] != ' ' || map[xk1 + 1][yk2 + 1] != ' '))
				{
					for (int j = yk1; j <= yk2; j++)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 2;
					}
					mx1_2_1 = xk1;	mx2_2_1 = xk1;
					my1_2_1 = yk1;	my2_2_1 = yk1 + 1;
					mfact_2_1 = 23;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_1(myMap, en1Map, map, meHelp);
				}
			else if (yk1 > yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2 - 1] != ' ' || map[xk1][yk2 - 1] != ' ' || map[xk1 + 1][yk2 - 1] != ' '))
				{
					for (int j = yk1; j >= yk2; j--)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 2;
					}
					mx1_2_1 = xk1;	mx2_2_1 = xk1;
					my1_2_1 = yk1;	my2_2_1 = yk1 - 1;
					mfact_2_1 = 24;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_1(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy2_1(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy2_1(myMap, en1Map, map, meHelp);
		}
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy2_1(myMap, en1Map, map, meHelp);
	}
}


void checkMy2_2(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	cout << "Введите координаты начала и конца второго 2-хпалубного корабля латинскими буквами и цифрами (например, b4 b5) и нажмите клавишу Enter:\n";
	cin >> myMap.sh2_2.x1 >> myMap.sh2_2.y1 >> myMap.sh2_2.x2 >> myMap.sh2_2.y2;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while ((!(myMap.sh2_2.x1 >= 'a' && myMap.sh2_2.x1 <= 'j') || (myMap.sh2_2.y1 < 1 || myMap.sh2_2.y1 > 10)) && (!(myMap.sh2_2.x2 >= 'a' && myMap.sh2_2.x2 <= 'j') || (myMap.sh2_2.y2 < 1 || myMap.sh2_2.y2 > 10)))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты начала и конца второго 2-хпалубного корабля латинскими буквами и цифрами (например, b4 b5) и нажмите клавишу Enter:\n";
		cin >> myMap.sh2_2.x1 >> myMap.sh2_2.y1 >> myMap.sh2_2.x2 >> myMap.sh2_2.y2;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set2_2ByPlayer(myMap, en1Map, map, meHelp);
}

void set2_2ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	system("cls");
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh2_2.y1;
	int yk2 = myMap.sh2_2.y2;
	int xk1 = (int)(myMap.sh2_2.x1) - 96;
	int xk2 = (int)(myMap.sh2_2.x2) - 96;

	if (yk1 == yk2)
	{
		if (abs(xk2 - xk1) == 1)
			if (xk1 < xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2 + 1][yk1] != ' ' || map[xk2 + 1][yk1 - 1] != ' ' || map[xk2 + 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i <= xk2; i++)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 2;
					}
					mx1_2_2 = xk1;	mx2_2_2 = xk1 + 1;
					my1_2_2 = yk1;	my2_2_2 = yk1;
					mfact_2_2 = 13;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_2(myMap, en1Map, map, meHelp);
				}
			else if (xk1 > xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2 - 1][yk1] != ' ' || map[xk2 - 1][yk1 - 1] != ' ' || map[xk2 - 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i >= xk2; i--)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 2;
					}
					mx1_2_2 = xk1;	mx2_2_2 = xk1 - 1;
					my1_2_2 = yk1;	my2_2_2 = yk1;
					mfact_2_2 = 14;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_2(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy2_2(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy2_2(myMap, en1Map, map, meHelp);
		}
	}
	else if (xk1 == xk2)
	{
		if (abs(yk2 - yk1) == 1)
			if (yk1 < yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2 + 1] != ' ' || map[xk1][yk2 + 1] != ' ' || map[xk1 + 1][yk2 + 1] != ' '))
				{
					for (int j = yk1; j <= yk2; j++)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 2;
					}
					mx1_2_2 = xk1;	mx2_2_2 = xk1;
					my1_2_2 = yk1;	my2_2_2 = yk1 + 1;
					mfact_2_2 = 23;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_2(myMap, en1Map, map, meHelp);
				}
			else if (yk1 > yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2 - 1] != ' ' || map[xk1][yk2 - 1] != ' ' || map[xk1 + 1][yk2 - 1] != ' '))
				{
					for (int j = yk1; j >= yk2; j--)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 2;
					}
					mx1_2_2 = xk1;	mx2_2_2 = xk1;
					my1_2_2 = yk1;	my2_2_2 = yk1 - 1;
					mfact_2_2 = 24;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_2(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy2_2(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy2_2(myMap, en1Map, map, meHelp);
		}
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy2_2(myMap, en1Map, map, meHelp);
	}
}


void checkMy2_3(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	cout << "Введите координаты начала и конца третьего 2-хпалубного корабля латинскими буквами и цифрами (например, b4 b5) и нажмите клавишу Enter:\n";
	cin >> myMap.sh2_3.x1 >> myMap.sh2_3.y1 >> myMap.sh2_3.x2 >> myMap.sh2_3.y2;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while ((!(myMap.sh2_3.x1 >= 'a' && myMap.sh2_3.x1 <= 'j') || (myMap.sh2_3.y1 < 1 || myMap.sh2_3.y1 > 10)) && (!(myMap.sh2_3.x2 >= 'a' && myMap.sh2_3.x2 <= 'j') || (myMap.sh2_3.y2 < 1 || myMap.sh2_3.y2 > 10)))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты начала и конца третьего 2-хпалубного корабля латинскими буквами и цифрами (например, b4 b5) и нажмите клавишу Enter:\n";
		cin >> myMap.sh2_3.x1 >> myMap.sh2_3.y1 >> myMap.sh2_3.x2 >> myMap.sh2_3.y2;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set2_3ByPlayer(myMap, en1Map, map, meHelp);
}

void set2_3ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12], int meHelp[12][12])
{
	system("cls");
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh2_3.y1;
	int yk2 = myMap.sh2_3.y2;
	int xk1 = (int)(myMap.sh2_3.x1) - 96;
	int xk2 = (int)(myMap.sh2_3.x2) - 96;

	if (yk1 == yk2)
	{
		if (abs(xk2 - xk1) == 1)
			if (xk1 < xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2 + 1][yk1] != ' ' || map[xk2 + 1][yk1 - 1] != ' ' || map[xk2 + 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i <= xk2; i++)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 2;
					}
					mx1_2_3 = xk1;	mx2_2_3 = xk1 + 1;
					my1_2_3 = yk1;	my2_2_3 = yk1;
					mfact_2_3 = 13;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_3(myMap, en1Map, map, meHelp);
				}
			else if (xk1 > xk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
					map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
					map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk2 - 1][yk1] != ' ' || map[xk2 - 1][yk1 - 1] != ' ' || map[xk2 - 1][yk1 + 1] != ' '))
				{
					for (int i = xk1; i >= xk2; i--)
					{
						map[i][yk1] = '#';
						meHelp[i][yk1] = 2;
					}
					mx1_2_3 = xk1;	mx2_2_3 = xk1 - 1;
					my1_2_3 = yk1;	my2_2_3 = yk1;
					mfact_2_3 = 14;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_3(myMap, en1Map, map, meHelp);
				}
			else {
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy2_3(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy2_3(myMap, en1Map, map, meHelp);
		}
	}
	else if (xk1 == xk2)
	{
		if (abs(yk2 - yk1) == 1)
			if (yk1 < yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2 + 1] != ' ' || map[xk1][yk2 + 1] != ' ' || map[xk1 + 1][yk2 + 1] != ' '))
				{
					for (int j = yk1; j <= yk2; j++)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 2;
					}
					mx1_2_3 = xk1;	mx2_2_3 = xk1;
					my1_2_3 = yk1;	my2_2_3 = yk1 + 1;
					mfact_2_3 = 23;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_3(myMap, en1Map, map, meHelp);
				}
			else if (yk1 > yk2)
				if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
					map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
					map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
					map[xk1 - 1][yk2 - 1] != ' ' || map[xk1][yk2 - 1] != ' ' || map[xk1 + 1][yk2 - 1] != ' '))
				{
					for (int j = yk1; j >= yk2; j--)
					{
						map[xk1][j] = '#';
						meHelp[xk1][j] = 2;
					}
					mx1_2_3 = xk1;	mx2_2_3 = xk1;
					my1_2_3 = yk1;	my2_2_3 = yk1 - 1;
					mfact_2_3 = 24;
					return;
				}
				else
				{
					cout << "Неверно! Введите координаты заново." << endl;
					checkMy2_3(myMap, en1Map, map, meHelp);
				}
			else
			{
				cout << "Неверно! Введите координаты заново." << endl;
				checkMy2_3(myMap, en1Map, map, meHelp);
			}
		else
		{
			cout << "Неверно! Введите координаты заново." << endl;
			checkMy2_3(myMap, en1Map, map, meHelp);
		}
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy2_3(myMap, en1Map, map, meHelp);
	}
}


void checkMy1_1(PlayerField myMap, EnemyField en1Map, char map[12][12])
{
	cout << "Введите координаты первого 1-палубного корабля латинскими буквами и цифрами (например, b4) и нажмите клавишу Enter:\n";
	cin >> myMap.sh1_1.x1 >> myMap.sh1_1.y1;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while (!(myMap.sh1_1.x1 >= 'a' && myMap.sh1_1.x1 <= 'j') || (myMap.sh1_1.y1 < 1 || myMap.sh1_1.y1 > 10))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты первого 1-палубного корабля латинскими буквами и цифрами (например, b4) и нажмите клавишу Enter:\n";
		cin >> myMap.sh1_1.x1 >> myMap.sh1_1.y1;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set1_1ByPlayer(myMap, en1Map, map);
}

void set1_1ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12])
{
	system("cls");
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh1_1.y1;
	int xk1 = (int)(myMap.sh1_1.x1) - 96;

	if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
		map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
		map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' '))
	{
		map[xk1][yk1] = '#';
		mx1_1_1 = xk1;
		my1_1_1 = yk1;
		return;
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy1_1(myMap, en1Map, map);
	}
}


void checkMy1_2(PlayerField myMap, EnemyField en1Map, char map[12][12])
{
	cout << "Введите координаты второго 1-палубного корабля латинскими буквами и цифрами (например, b4) и нажмите клавишу Enter:\n";
	cin >> myMap.sh1_2.x1 >> myMap.sh1_2.y1;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while (!(myMap.sh1_2.x1 >= 'a' && myMap.sh1_2.x1 <= 'j') || (myMap.sh1_2.y1 < 1 || myMap.sh1_2.y1 > 10))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты второго 1-палубного корабля латинскими буквами и цифрами (например, b4) и нажмите клавишу Enter:\n";
		cin >> myMap.sh1_2.x1 >> myMap.sh1_2.y1;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set1_2ByPlayer(myMap, en1Map, map);
}

void set1_2ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12])
{
	system("cls");
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh1_2.y1;
	int xk1 = (int)(myMap.sh1_2.x1) - 96;

	if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
		map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
		map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' '))
	{
		map[xk1][yk1] = '#';
		mx1_1_2 = xk1;
		my1_1_2 = yk1;
		return;
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy1_2(myMap, en1Map, map);
	}
}


void checkMy1_3(PlayerField myMap, EnemyField en1Map, char map[12][12])
{
	cout << "Введите координаты третьего 1-палубного корабля латинскими буквами и цифрами (например, b4) и нажмите клавишу Enter:\n";
	cin >> myMap.sh1_3.x1 >> myMap.sh1_3.y1;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while (!(myMap.sh1_3.x1 >= 'a' && myMap.sh1_3.x1 <= 'j') || (myMap.sh1_3.y1 < 1 || myMap.sh1_3.y1 > 10))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты третьего 1-палубного корабля латинскими буквами и цифрами (например, b4) и нажмите клавишу Enter:\n";
		cin >> myMap.sh1_3.x1 >> myMap.sh1_3.y1;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set1_3ByPlayer(myMap, en1Map, map);
}

void set1_3ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12])
{
	system("cls");
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh1_3.y1;
	int xk1 = (int)(myMap.sh1_3.x1) - 96;

	if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
		map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
		map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' '))
	{
		map[xk1][yk1] = '#';
		mx1_1_3 = xk1;
		my1_1_3 = yk1;
		return;
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy1_3(myMap, en1Map, map);
	}
}


void checkMy1_4(PlayerField myMap, EnemyField en1Map, char map[12][12])
{
	cout << "Введите координаты четвёртого 1-палубного корабля латинскими буквами и цифрами (например, b4) и нажмите клавишу Enter:\n";
	cin >> myMap.sh1_4.x1 >> myMap.sh1_4.y1;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	while (!(myMap.sh1_4.x1 >= 'a' && myMap.sh1_4.x1 <= 'j') || (myMap.sh1_4.y1 < 1 || myMap.sh1_4.y1 > 10))
	{
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		cout << "Неверно! Введите координаты заново." << endl;
		cout << "Введите координаты четвёртого 1-палубного корабля латинскими буквами и цифрами (например, b4) и нажмите клавишу Enter:\n";
		cin >> myMap.sh1_4.x1 >> myMap.sh1_4.y1;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}

	set1_4ByPlayer(myMap, en1Map, map);
}

void set1_4ByPlayer(PlayerField myMap, EnemyField en1Map, char map[12][12])
{
	system("cls"); // функция очистки консоли
	myMap.printMap();
	en1Map.printMap();

	int yk1 = myMap.sh1_4.y1;
	int xk1 = (int)(myMap.sh1_4.x1) - 96;

	if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
		map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
		map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' '))
	{
		map[xk1][yk1] = '#';
		mx1_1_4 = xk1;
		my1_1_4 = yk1;
		return;
	}
	else
	{
		cout << "Неверно! Введите координаты заново." << endl;
		checkMy1_4(myMap, en1Map, map);
	}
}



// расстановка кораблей компьютером
void set432ByComp(EnemyField enMap, char map[12][12], int length, int number)
{
	int xk1, yk1, xk2, yk2;

	while (true)
	{
		yk1 = rand() % 10 + 1;
		xk1 = rand() % 10 + 1;
		yk2 = rand() % 10 + 1;
		xk2 = rand() % 10 + 1;
		if ((xk1 >= 1 && xk1 <= 10) && (xk2 >= 1 && xk2 <= 10) && (yk1 >= 1 && yk1 <= 10) && (yk2 >= 1 && yk2 <= 10))
			if (yk1 == yk2)
			{
				if (abs(xk2 - xk1) == length - 1)
					if (xk1 < xk2)
						if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
							map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
							map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
							map[xk2 - 1][yk1 - 1] != ' ' || map[xk2 - 1][yk1] != ' ' || map[xk2 - 1][yk1 + 1] != ' ' ||
							map[xk2][yk1] != ' ' || map[xk2][yk1 - 1] != ' ' || map[xk2][yk1 + 1] != ' ' ||
							map[xk2 + 1][yk1] != ' ' || map[xk2 + 1][yk1 - 1] != ' ' || map[xk2 + 1][yk1 + 1] != ' '))
						{
							for (int i = xk1; i <= xk2; i++)
								map[i][yk1] = '#';
							if (length == 4)
							{
								x1_4_1 = xk1; x2_4_1 = xk1 + 1; x3_4_1 = xk1 + 2;	x4_4_1 = xk1 + 3;
								y1_4_1 = yk1; y2_4_1 = yk1;		y3_4_1 = yk1;		y4_4_1 = yk1;
								fact_4_1 = 13;
							}
							if (number == 1 && length == 3)
							{
								x1_3_1 = xk1; x2_3_1 = xk1 + 1; x3_3_1 = xk1 + 2;
								y1_3_1 = yk1; y2_3_1 = yk1;		y3_3_1 = yk1;
								fact_3_1 = 13;
							}
							if (number == 2 && length == 3)
							{
								x1_3_2 = xk1;	x2_3_2 = xk1 + 1;	x3_3_2 = xk1 + 2;
								y1_3_2 = yk1;	y2_3_2 = yk1;		y3_3_2 = yk1;
								fact_3_2 = 13;
							}
							if (number == 1 && length == 2)
							{
								x1_2_1 = xk1;	x2_2_1 = xk1 + 1;
								y1_2_1 = yk1;	y2_2_1 = yk1;
								fact_2_1 = 13;
							}
							if (number == 2 && length == 2)
							{
								x1_2_2 = xk1;	x2_2_2 = xk1 + 1;
								y1_2_2 = yk1;	y2_2_2 = yk1;
								fact_2_2 = 13;
							}
							if (number == 3 && length == 2)
							{
								x1_2_3 = xk1;	x2_2_3 = xk1 + 1;
								y1_2_3 = yk1;	y2_2_3 = yk1;
								fact_2_3 = 13;
							}
							return;
						}
						else continue;
					else if (xk1 > xk2)
						if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
							map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
							map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
							map[xk2][yk1] != ' ' || map[xk2][yk1 - 1] != ' ' || map[xk2][yk1 + 1] != ' ' ||
							map[xk2 - 1][yk1] != ' ' || map[xk2 - 1][yk1 - 1] != ' ' || map[xk2 - 1][yk1 + 1] != ' ' ||
							map[xk2 + 1][yk1] != ' ' || map[xk2 + 1][yk1 - 1] != ' ' || map[xk2 + 1][yk1 + 1] != ' '))
						{
							for (int i = xk1; i >= xk2; i--)
								map[i][yk1] = '#';
							if (length == 4)
							{
								x1_4_1 = xk1; x2_4_1 = xk1 - 1;		x3_4_1 = xk1 - 2;	x4_4_1 = xk1 - 3;
								y1_4_1 = yk1; y2_4_1 = yk1;			y3_4_1 = yk1;		y4_4_1 = yk1;
								fact_4_1 = 14;
							}
							if (number == 1 && length == 3)
							{
								x1_3_1 = xk1; x2_3_1 = xk1 - 1;		x3_3_1 = xk1 - 2;
								y1_3_1 = yk1; y2_3_1 = yk1;			y3_3_1 = yk1;
								fact_3_1 = 14;
							}
							if (number == 2 && length == 3)
							{
								x1_3_2 = xk1; x2_3_2 = xk1 - 1;		x3_3_2 = xk1 - 2;
								y1_3_2 = yk1; y2_3_2 = yk1;			y3_3_2 = yk1;
								fact_3_2 = 14;
							}
							if (number == 1 && length == 2)
							{
								x1_2_1 = xk1; x2_2_1 = xk1 - 1;
								y1_2_1 = yk1; y2_2_1 = yk1;
								fact_2_1 = 14;
							}
							if (number == 2 && length == 2)
							{
								x1_2_2 = xk1;	x2_2_2 = xk1 - 1;
								y1_2_2 = yk1;	y2_2_2 = yk1;
								fact_2_2 = 14;
							}
							if (number == 3 && length == 2)
							{
								x1_2_3 = xk1;	x2_2_3 = xk1 - 1;
								y1_2_3 = yk1;	y2_2_3 = yk1;
								fact_2_3 = 14;
							}
							return;
						}
						else continue;
					else continue;
				else continue;
			}
			else if (xk1 == xk2)
			{
				if (abs(yk2 - yk1) == length - 1)
					if (yk1 < yk2)
						if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
							map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
							map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
							map[xk1 - 1][yk2 - 1] != ' ' || map[xk1][yk2 - 1] != ' ' || map[xk1 + 1][yk2 - 1] != ' ' ||
							map[xk1 - 1][yk2] != ' ' || map[xk1][yk2] != ' ' || map[xk1 + 1][yk2] != ' ' ||
							map[xk1 - 1][yk2 + 1] != ' ' || map[xk1][yk2 + 1] != ' ' || map[xk1 + 1][yk2 + 1] != ' '))
						{
							for (int j = yk1; j <= yk2; j++)
								map[xk1][j] = '#';
							if (length == 4)
							{
								x1_4_1 = xk1; x2_4_1 = xk1;			x3_4_1 = xk1;		x4_4_1 = xk1;
								y1_4_1 = yk1; y2_4_1 = yk1 + 1;		y3_4_1 = yk1 + 2;	y4_4_1 = yk1 + 3;
								fact_4_1 = 23;
							}
							if (number == 1 && length == 3)
							{
								x1_3_1 = xk1;	x2_3_1 = xk1;		x3_3_1 = xk1;
								y1_3_1 = yk1;	y2_3_1 = yk1 + 1;	y3_3_1 = yk1 + 2;
								fact_3_1 = 23;
							}
							if (number == 2 && length == 3)
							{
								x1_3_2 = xk1;	x2_3_2 = xk1;		x3_3_2 = xk1;
								y1_3_2 = yk1;	y2_3_2 = yk1 + 1;	y3_3_2 = yk1 + 2;
								fact_3_2 = 23;
							}
							if (number == 1 && length == 2)
							{
								x1_2_1 = xk1;	x2_2_1 = xk1;
								y1_2_1 = yk1;	y2_2_1 = yk1 + 1;
								fact_2_1 = 23;
							}
							if (number == 2 && length == 2)
							{
								x1_2_2 = xk1;	x2_2_2 = xk1;
								y1_2_2 = yk1;	y2_2_2 = yk1 + 1;
								fact_2_2 = 23;
							}
							if (number == 3 && length == 2)
							{
								x1_2_3 = xk1;	x2_2_3 = xk1;
								y1_2_3 = yk1;	y2_2_3 = yk1 + 1;
								fact_2_3 = 23;
							}
							return;
						}
						else continue;
					else if (yk1 > yk2)
						if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' ||
							map[xk1 - 1][yk1] != ' ' || map[xk1][yk1] != ' ' || map[xk1 + 1][yk1] != ' ' ||
							map[xk1 - 1][yk1 + 1] != ' ' || map[xk1][yk1 + 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' ' ||
							map[xk1 - 1][yk2] != ' ' || map[xk1][yk2] != ' ' || map[xk1 + 1][yk2] != ' ' ||
							map[xk1 - 1][yk2 + 1] != ' ' || map[xk1][yk2 + 1] != ' ' || map[xk1 + 1][yk2 + 1] != ' ' ||
							map[xk1 - 1][yk2 - 1] != ' ' || map[xk1][yk2 - 1] != ' ' || map[xk1 + 1][yk2 - 1] != ' '))
						{
							for (int j = yk1; j >= yk2; j--)
								map[xk1][j] = '#';
							if (length == 4)
							{
								x1_4_1 = xk1; x2_4_1 = xk1;			x3_4_1 = xk1;		x4_4_1 = xk1;
								y1_4_1 = yk1; y2_4_1 = yk1 - 1;		y3_4_1 = yk1 - 2;	y4_4_1 = yk1 - 3;
								fact_4_1 = 24;
							}
							if (number == 1 && length == 3)
							{
								x1_3_1 = xk1;	x2_3_1 = xk1;		x3_3_1 = xk1;
								y1_3_1 = yk1;	y2_3_1 = yk1 - 1;	y3_3_1 = yk1 - 2;
								fact_3_1 = 24;
							}
							if (number == 2 && length == 3)
							{
								x1_3_2 = xk1;		x2_3_2 = xk1;		x3_3_2 = xk1;
								y1_3_2 = yk1;		y2_3_2 = yk1 - 1;	y3_3_2 = yk1 - 2;
								fact_3_2 = 24;
							}
							if (number == 1 && length == 2)
							{
								x1_2_1 = xk1;	x2_2_1 = xk1;
								y1_2_1 = yk1;	y2_2_1 = yk1 - 1;
								fact_2_1 = 24;
							}
							if (number == 2 && length == 2)
							{
								x1_2_2 = xk1;	x2_2_2 = xk1;
								y1_2_2 = yk1;	y2_2_2 = yk1 - 1;
								fact_2_2 = 24;
							}
							if (number == 3 && length == 2)
							{
								x1_2_3 = xk1;	x2_2_3 = xk1;
								y1_2_3 = yk1;	y2_2_3 = yk1 - 1;
								fact_2_3 = 24;
							}
							return;
						}
						else continue;
					else continue;
				else continue;
			}
			else continue;
		else continue;
	}
}

void set1ByComp(EnemyField enMap, char map[12][12], int number)
{
	int xk1, yk1;

	while (true)
	{
		yk1 = rand() % 10 + 1;
		xk1 = rand() % 10 + 1;

		if ((xk1 >= 1 && xk1 <= 10) || (yk1 < 1 || yk1 > 10))
			if (!(map[xk1 - 1][yk1 - 1] != ' ' || map[xk1 - 1][yk1] != ' ' || map[xk1 - 1][yk1 + 1] != ' ' ||
				map[xk1][yk1] != ' ' || map[xk1][yk1 - 1] != ' ' || map[xk1][yk1 + 1] != ' ' ||
				map[xk1 + 1][yk1] != ' ' || map[xk1 + 1][yk1 - 1] != ' ' || map[xk1 + 1][yk1 + 1] != ' '))
			{
				map[xk1][yk1] = '#';
				if (number == 1)
				{
					x1_1_1 = xk1;
					y1_1_1 = yk1;
				}
				if (number == 2)
				{
					x1_1_2 = xk1;
					y1_1_2 = yk1;
				}
				if (number == 3)
				{
					x1_1_3 = xk1;
					y1_1_3 = yk1;
				}
				if (number == 4)
				{
					x1_1_4 = xk1;
					y1_1_4 = yk1;
				}
				return;
			}
			else continue;
	}
}

// проверка полной потопленности корабля компьютера и выделение его точками по краям
void checkDeadOfComp(EnemyField enMap, EnemyField en1Map, char mapEn[12][12], char mapEn1[12][12])
{
	if (mapEn[x1_4_1][y1_4_1] == 'X' && mapEn[x2_4_1][y2_4_1] == 'X' && mapEn[x3_4_1][y3_4_1] == 'X' && mapEn[x4_4_1][y4_4_1] == 'X')
	{
		if (flag4)
		{
			flag4 = false;
			enShip4--;
			switch (fact_4_1)
			{
			case 13:
				mapEn[x1_4_1 - 1][y1_4_1] = '*';		mapEn[x4_4_1 + 1][y1_4_1] = '*';
				mapEn[x1_4_1 - 1][y1_4_1 - 1] = '*';	mapEn[x1_4_1][y1_4_1 - 1] = '*';
				mapEn[x2_4_1][y1_4_1 - 1] = '*';		mapEn[x4_4_1][y1_4_1 - 1] = '*';
				mapEn[x4_4_1 + 1][y1_4_1 - 1] = '*';	mapEn[x1_4_1 - 1][y1_4_1 + 1] = '*';
				mapEn[x1_4_1][y1_4_1 + 1] = '*';		mapEn[x2_4_1][y1_4_1 + 1] = '*';
				mapEn[x4_4_1][y1_4_1 + 1] = '*';		mapEn[x4_4_1 + 1][y1_4_1 + 1] = '*';
				mapEn[x3_4_1][y1_4_1 - 1] = '*';		mapEn[x3_4_1][y1_4_1 + 1] = '*';

				mapEn1[x1_4_1 - 1][y1_4_1] = '*';		mapEn1[x4_4_1 + 1][y1_4_1] = '*';
				mapEn1[x1_4_1 - 1][y1_4_1 - 1] = '*';	mapEn1[x1_4_1][y1_4_1 - 1] = '*';
				mapEn1[x2_4_1][y1_4_1 - 1] = '*';		mapEn1[x4_4_1][y1_4_1 - 1] = '*';
				mapEn1[x4_4_1 + 1][y1_4_1 - 1] = '*';	mapEn1[x1_4_1 - 1][y1_4_1 + 1] = '*';
				mapEn1[x1_4_1][y1_4_1 + 1] = '*';		mapEn1[x2_4_1][y1_4_1 + 1] = '*';
				mapEn1[x4_4_1][y1_4_1 + 1] = '*';		mapEn1[x4_4_1 + 1][y1_4_1 + 1] = '*';
				mapEn1[x3_4_1][y1_4_1 - 1] = '*';		mapEn1[x3_4_1][y1_4_1 + 1] = '*';
				break;
			case 14:
				mapEn[x4_4_1 - 1][y1_4_1] = '*';		mapEn[x1_4_1 + 1][y1_4_1] = '*';
				mapEn[x4_4_1 - 1][y1_4_1 - 1] = '*';	mapEn[x1_4_1][y1_4_1 - 1] = '*';
				mapEn[x2_4_1][y1_4_1 - 1] = '*';		mapEn[x4_4_1][y1_4_1 - 1] = '*';
				mapEn[x1_4_1 + 1][y1_4_1 - 1] = '*';	mapEn[x4_4_1 - 1][y1_4_1 + 1] = '*';
				mapEn[x1_4_1][y1_4_1 + 1] = '*';		mapEn[x2_4_1][y1_4_1 + 1] = '*';
				mapEn[x4_4_1][y1_4_1 + 1] = '*';		mapEn[x1_4_1 + 1][y1_4_1 + 1] = '*';
				mapEn[x3_4_1][y1_4_1 - 1] = '*';		mapEn[x3_4_1][y1_4_1 + 1] = '*';

				mapEn1[x4_4_1 - 1][y1_4_1] = '*';		mapEn1[x1_4_1 + 1][y1_4_1] = '*';
				mapEn1[x4_4_1 - 1][y1_4_1 - 1] = '*';	mapEn1[x1_4_1][y1_4_1 - 1] = '*';
				mapEn1[x2_4_1][y1_4_1 - 1] = '*';		mapEn1[x4_4_1][y1_4_1 - 1] = '*';
				mapEn1[x1_4_1 + 1][y1_4_1 - 1] = '*';	mapEn1[x4_4_1 - 1][y1_4_1 + 1] = '*';
				mapEn1[x1_4_1][y1_4_1 + 1] = '*';		mapEn1[x2_4_1][y1_4_1 + 1] = '*';
				mapEn1[x4_4_1][y1_4_1 + 1] = '*';		mapEn1[x1_4_1 + 1][y1_4_1 + 1] = '*';
				mapEn1[x3_4_1][y1_4_1 - 1] = '*';		mapEn1[x3_4_1][y1_4_1 + 1] = '*';
				break;
			case 23:
				mapEn[x1_4_1][y1_4_1 - 1] = '*';		mapEn[x1_4_1][y4_4_1 + 1] = '*';
				mapEn[x1_4_1 - 1][y1_4_1 - 1] = '*';	mapEn[x1_4_1 - 1][y1_4_1] = '*';
				mapEn[x1_4_1 - 1][y2_4_1] = '*';		mapEn[x1_4_1 - 1][y4_4_1] = '*';
				mapEn[x1_4_1 - 1][y4_4_1 + 1] = '*';	mapEn[x1_4_1 + 1][y1_4_1 - 1] = '*';
				mapEn[x1_4_1 + 1][y1_4_1] = '*';		mapEn[x1_4_1 + 1][y2_4_1] = '*';
				mapEn[x1_4_1 + 1][y4_4_1] = '*';		mapEn[x1_4_1 + 1][y4_4_1 + 1] = '*';
				mapEn[x1_4_1 - 1][y3_4_1] = '*';		mapEn[x1_4_1 + 1][y3_4_1] = '*';

				mapEn1[x1_4_1][y1_4_1 - 1] = '*';		mapEn1[x1_4_1][y4_4_1 + 1] = '*';
				mapEn1[x1_4_1 - 1][y1_4_1 - 1] = '*';	mapEn1[x1_4_1 - 1][y1_4_1] = '*';
				mapEn1[x1_4_1 - 1][y2_4_1] = '*';		mapEn1[x1_4_1 - 1][y4_4_1] = '*';
				mapEn1[x1_4_1 - 1][y4_4_1 + 1] = '*';	mapEn1[x1_4_1 + 1][y1_4_1 - 1] = '*';
				mapEn1[x1_4_1 + 1][y1_4_1] = '*';		mapEn1[x1_4_1 + 1][y2_4_1] = '*';
				mapEn1[x1_4_1 + 1][y4_4_1] = '*';		mapEn1[x1_4_1 + 1][y4_4_1 + 1] = '*';
				mapEn1[x1_4_1 - 1][y3_4_1] = '*';		mapEn1[x1_4_1 + 1][y3_4_1] = '*';
				break;
			case 24:
				mapEn[x1_4_1][y4_4_1 - 1] = '*';		mapEn[x1_4_1][y1_4_1 + 1] = '*';
				mapEn[x1_4_1 - 1][y4_4_1 - 1] = '*';	mapEn[x1_4_1 - 1][y1_4_1] = '*';
				mapEn[x1_4_1 - 1][y2_4_1] = '*';		mapEn[x1_4_1 - 1][y4_4_1] = '*';
				mapEn[x1_4_1 - 1][y1_4_1 + 1] = '*';	mapEn[x1_4_1 + 1][y4_4_1 - 1] = '*';
				mapEn[x1_4_1 + 1][y1_4_1] = '*';		mapEn[x1_4_1 + 1][y2_4_1] = '*';
				mapEn[x1_4_1 + 1][y4_4_1] = '*';		mapEn[x1_4_1 + 1][y1_4_1 + 1] = '*';
				mapEn[x1_4_1 - 1][y3_4_1] = '*';		mapEn[x1_4_1 + 1][y3_4_1] = '*';

				mapEn1[x1_4_1][y4_4_1 - 1] = '*';		mapEn1[x1_4_1][y1_4_1 + 1] = '*';
				mapEn1[x1_4_1 - 1][y4_4_1 - 1] = '*';	mapEn1[x1_4_1 - 1][y1_4_1] = '*';
				mapEn1[x1_4_1 - 1][y2_4_1] = '*';		mapEn1[x1_4_1 - 1][y4_4_1] = '*';
				mapEn1[x1_4_1 - 1][y1_4_1 + 1] = '*';	mapEn1[x1_4_1 + 1][y4_4_1 - 1] = '*';
				mapEn1[x1_4_1 + 1][y1_4_1] = '*';		mapEn1[x1_4_1 + 1][y2_4_1] = '*';
				mapEn1[x1_4_1 + 1][y4_4_1] = '*';		mapEn1[x1_4_1 + 1][y1_4_1 + 1] = '*';
				mapEn1[x1_4_1 - 1][y3_4_1] = '*';		mapEn1[x1_4_1 + 1][y3_4_1] = '*';
				break;
			}
		}
	}

	if (mapEn[x1_3_1][y1_3_1] == 'X' && mapEn[x2_3_1][y2_3_1] == 'X' && mapEn[x3_3_1][y3_3_1] == 'X')
	{
		if (flag3_1)
		{
			flag3_1 = false;
			enShip3--;
			switch (fact_3_1)
			{
			case 13:
				mapEn[x1_3_1 - 1][y1_3_1] = '*';		mapEn[x3_3_1 + 1][y1_3_1] = '*';
				mapEn[x1_3_1 - 1][y1_3_1 - 1] = '*';	mapEn[x1_3_1][y1_3_1 - 1] = '*';
				mapEn[x2_3_1][y1_3_1 - 1] = '*';		mapEn[x3_3_1][y1_3_1 - 1] = '*';
				mapEn[x3_3_1 + 1][y1_3_1 - 1] = '*';	mapEn[x1_3_1 - 1][y1_3_1 + 1] = '*';
				mapEn[x1_3_1][y1_3_1 + 1] = '*';		mapEn[x2_3_1][y1_3_1 + 1] = '*';
				mapEn[x3_3_1][y1_3_1 + 1] = '*';		mapEn[x3_3_1 + 1][y1_3_1 + 1] = '*';

				mapEn1[x1_3_1 - 1][y1_3_1] = '*';		mapEn1[x3_3_1 + 1][y1_3_1] = '*';
				mapEn1[x1_3_1 - 1][y1_3_1 - 1] = '*';	mapEn1[x1_3_1][y1_3_1 - 1] = '*';
				mapEn1[x2_3_1][y1_3_1 - 1] = '*';		mapEn1[x3_3_1][y1_3_1 - 1] = '*';
				mapEn1[x3_3_1 + 1][y1_3_1 - 1] = '*';	mapEn1[x1_3_1 - 1][y1_3_1 + 1] = '*';
				mapEn1[x1_3_1][y1_3_1 + 1] = '*';		mapEn1[x2_3_1][y1_3_1 + 1] = '*';
				mapEn1[x3_3_1][y1_3_1 + 1] = '*';		mapEn1[x3_3_1 + 1][y1_3_1 + 1] = '*';
				break;
			case 14:
				mapEn[x3_3_1 - 1][y1_3_1] = '*';		mapEn[x1_3_1 + 1][y1_3_1] = '*';
				mapEn[x3_3_1 - 1][y1_3_1 - 1] = '*';	mapEn[x3_3_1][y1_3_1 - 1] = '*';
				mapEn[x2_3_1][y1_3_1 - 1] = '*';		mapEn[x1_3_1][y1_3_1 - 1] = '*';
				mapEn[x1_3_1 + 1][y1_3_1 - 1] = '*';	mapEn[x3_3_1 - 1][y1_3_1 + 1] = '*';
				mapEn[x3_3_1][y1_3_1 + 1] = '*';		mapEn[x2_3_1][y1_3_1 + 1] = '*';
				mapEn[x1_3_1][y1_3_1 + 1] = '*';		mapEn[x1_3_1 + 1][y1_3_1 + 1] = '*';

				mapEn1[x3_3_1 - 1][y1_3_1] = '*';		mapEn1[x1_3_1 + 1][y1_3_1] = '*';
				mapEn1[x3_3_1 - 1][y1_3_1 - 1] = '*';	mapEn1[x3_3_1][y1_3_1 - 1] = '*';
				mapEn1[x2_3_1][y1_3_1 - 1] = '*';		mapEn1[x1_3_1][y1_3_1 - 1] = '*';
				mapEn1[x1_3_1 + 1][y1_3_1 - 1] = '*';	mapEn1[x3_3_1 - 1][y1_3_1 + 1] = '*';
				mapEn1[x3_3_1][y1_3_1 + 1] = '*';		mapEn1[x2_3_1][y1_3_1 + 1] = '*';
				mapEn1[x1_3_1][y1_3_1 + 1] = '*';		mapEn1[x1_3_1 + 1][y1_3_1 + 1] = '*';
				break;
			case 23:
				mapEn[x1_3_1][y1_3_1 - 1] = '*';		mapEn[x1_3_1][y3_3_1 + 1] = '*';
				mapEn[x1_3_1 - 1][y1_3_1 - 1] = '*';	mapEn[x1_3_1 - 1][y1_3_1] = '*';
				mapEn[x1_3_1 - 1][y2_3_1] = '*';		mapEn[x1_3_1 - 1][y3_3_1] = '*';
				mapEn[x1_3_1 - 1][y3_3_1 + 1] = '*';	mapEn[x1_3_1 + 1][y1_3_1 - 1] = '*';
				mapEn[x1_3_1 + 1][y1_3_1] = '*';		mapEn[x1_3_1 + 1][y2_3_1] = '*';
				mapEn[x1_3_1 + 1][y3_3_1] = '*';		mapEn[x1_3_1 + 1][y3_3_1 + 1] = '*';

				mapEn1[x1_3_1][y1_3_1 - 1] = '*';		mapEn1[x1_3_1][y3_3_1 + 1] = '*';
				mapEn1[x1_3_1 - 1][y1_3_1 - 1] = '*';	mapEn1[x1_3_1 - 1][y1_3_1] = '*';
				mapEn1[x1_3_1 - 1][y2_3_1] = '*';		mapEn1[x1_3_1 - 1][y3_3_1] = '*';
				mapEn1[x1_3_1 - 1][y3_3_1 + 1] = '*';	mapEn1[x1_3_1 + 1][y1_3_1 - 1] = '*';
				mapEn1[x1_3_1 + 1][y1_3_1] = '*';		mapEn1[x1_3_1 + 1][y2_3_1] = '*';
				mapEn1[x1_3_1 + 1][y3_3_1] = '*';		mapEn1[x1_3_1 + 1][y3_3_1 + 1] = '*';
				break;
			case 24:
				mapEn[x1_3_1][y3_3_1 - 1] = '*';		mapEn[x1_3_1][y1_3_1 + 1] = '*';
				mapEn[x1_3_1 - 1][y3_3_1 - 1] = '*';	mapEn[x1_3_1 - 1][y1_3_1] = '*';
				mapEn[x1_3_1 - 1][y2_3_1] = '*';		mapEn[x1_3_1 - 1][y3_3_1] = '*';
				mapEn[x1_3_1 - 1][y1_3_1 + 1] = '*';	mapEn[x1_3_1 + 1][y3_3_1 - 1] = '*';
				mapEn[x1_3_1 + 1][y1_3_1] = '*';		mapEn[x1_3_1 + 1][y2_3_1] = '*';
				mapEn[x1_3_1 + 1][y3_3_1] = '*';		mapEn[x1_3_1 + 1][y1_3_1 + 1] = '*';

				mapEn1[x1_3_1][y3_3_1 - 1] = '*';		mapEn1[x1_3_1][y1_3_1 + 1] = '*';
				mapEn1[x1_3_1 - 1][y3_3_1 - 1] = '*';	mapEn1[x1_3_1 - 1][y1_3_1] = '*';
				mapEn1[x1_3_1 - 1][y2_3_1] = '*';		mapEn1[x1_3_1 - 1][y3_3_1] = '*';
				mapEn1[x1_3_1 - 1][y1_3_1 + 1] = '*';	mapEn1[x1_3_1 + 1][y3_3_1 - 1] = '*';
				mapEn1[x1_3_1 + 1][y1_3_1] = '*';		mapEn1[x1_3_1 + 1][y2_3_1] = '*';
				mapEn1[x1_3_1 + 1][y3_3_1] = '*';		mapEn1[x1_3_1 + 1][y1_3_1 + 1] = '*';
				break;
			}
		}
	}
	if (mapEn[x1_3_2][y1_3_2] == 'X' && mapEn[x2_3_2][y2_3_2] == 'X' && mapEn[x3_3_2][y3_3_2] == 'X')
	{
		if (flag3_2)
		{
			flag3_2 = false;
			enShip3--;
			switch (fact_3_2)
			{
			case 13:
				mapEn[x1_3_2 - 1][y1_3_2] = '*';		mapEn[x3_3_2 + 1][y1_3_2] = '*';
				mapEn[x1_3_2 - 1][y1_3_2 - 1] = '*';	mapEn[x1_3_2][y1_3_2 - 1] = '*';
				mapEn[x2_3_2][y1_3_2 - 1] = '*';		mapEn[x3_3_2][y1_3_2 - 1] = '*';
				mapEn[x3_3_2 + 1][y1_3_2 - 1] = '*';	mapEn[x1_3_2 - 1][y1_3_2 + 1] = '*';
				mapEn[x1_3_2][y1_3_2 + 1] = '*';		mapEn[x2_3_2][y1_3_2 + 1] = '*';
				mapEn[x3_3_2][y1_3_2 + 1] = '*';		mapEn[x3_3_2 + 1][y1_3_2 + 1] = '*';

				mapEn1[x1_3_2 - 1][y1_3_2] = '*';		mapEn1[x3_3_2 + 1][y1_3_2] = '*';
				mapEn1[x1_3_2 - 1][y1_3_2 - 1] = '*';	mapEn1[x1_3_2][y1_3_2 - 1] = '*';
				mapEn1[x2_3_2][y1_3_2 - 1] = '*';		mapEn1[x3_3_2][y1_3_2 - 1] = '*';
				mapEn1[x3_3_2 + 1][y1_3_2 - 1] = '*';	mapEn1[x1_3_2 - 1][y1_3_2 + 1] = '*';
				mapEn1[x1_3_2][y1_3_2 + 1] = '*';		mapEn1[x2_3_2][y1_3_2 + 1] = '*';
				mapEn1[x3_3_2][y1_3_2 + 1] = '*';		mapEn1[x3_3_2 + 1][y1_3_2 + 1] = '*';
				break;
			case 14:
				mapEn[x3_3_2 - 1][y1_3_2] = '*';		mapEn[x1_3_2 + 1][y1_3_2] = '*';
				mapEn[x3_3_2 - 1][y1_3_2 - 1] = '*';	mapEn[x3_3_2][y1_3_2 - 1] = '*';
				mapEn[x2_3_2][y1_3_2 - 1] = '*';		mapEn[x1_3_2][y1_3_2 - 1] = '*';
				mapEn[x1_3_2 + 1][y1_3_2 - 1] = '*';	mapEn[x3_3_2 - 1][y1_3_2 + 1] = '*';
				mapEn[x3_3_2][y1_3_2 + 1] = '*';		mapEn[x2_3_2][y1_3_2 + 1] = '*';
				mapEn[x1_3_2][y1_3_2 + 1] = '*';		mapEn[x1_3_2 + 1][y1_3_2 + 1] = '*';

				mapEn1[x3_3_2 - 1][y1_3_2] = '*';		mapEn1[x1_3_2 + 1][y1_3_2] = '*';
				mapEn1[x3_3_2 - 1][y1_3_2 - 1] = '*';	mapEn1[x3_3_2][y1_3_2 - 1] = '*';
				mapEn1[x2_3_2][y1_3_2 - 1] = '*';		mapEn1[x1_3_2][y1_3_2 - 1] = '*';
				mapEn1[x1_3_2 + 1][y1_3_2 - 1] = '*';	mapEn1[x3_3_2 - 1][y1_3_2 + 1] = '*';
				mapEn1[x3_3_2][y1_3_2 + 1] = '*';		mapEn1[x2_3_2][y1_3_2 + 1] = '*';
				mapEn1[x1_3_2][y1_3_2 + 1] = '*';		mapEn1[x1_3_2 + 1][y1_3_2 + 1] = '*';
				break;
			case 23:
				mapEn[x1_3_2][y1_3_2 - 1] = '*';		mapEn[x1_3_2][y3_3_2 + 1] = '*';
				mapEn[x1_3_2 - 1][y1_3_2 - 1] = '*';	mapEn[x1_3_2 - 1][y1_3_2] = '*';
				mapEn[x1_3_2 - 1][y2_3_2] = '*';		mapEn[x1_3_2 - 1][y3_3_2] = '*';
				mapEn[x1_3_2 - 1][y3_3_2 + 1] = '*';	mapEn[x1_3_2 + 1][y1_3_2 - 1] = '*';
				mapEn[x1_3_2 + 1][y1_3_2] = '*';		mapEn[x1_3_2 + 1][y2_3_2] = '*';
				mapEn[x1_3_2 + 1][y3_3_2] = '*';		mapEn[x1_3_2 + 1][y3_3_2 + 1] = '*';

				mapEn1[x1_3_2][y1_3_2 - 1] = '*';		mapEn1[x1_3_2][y3_3_2 + 1] = '*';
				mapEn1[x1_3_2 - 1][y1_3_2 - 1] = '*';	mapEn1[x1_3_2 - 1][y1_3_2] = '*';
				mapEn1[x1_3_2 - 1][y2_3_2] = '*';		mapEn1[x1_3_2 - 1][y3_3_2] = '*';
				mapEn1[x1_3_2 - 1][y3_3_2 + 1] = '*';	mapEn1[x1_3_2 + 1][y1_3_2 - 1] = '*';
				mapEn1[x1_3_2 + 1][y1_3_2] = '*';		mapEn1[x1_3_2 + 1][y2_3_2] = '*';
				mapEn1[x1_3_2 + 1][y3_3_2] = '*';		mapEn1[x1_3_2 + 1][y3_3_2 + 1] = '*';
				break;
			case 24:
				mapEn[x1_3_2][y3_3_2 - 1] = '*';		mapEn[x1_3_2][y1_3_2 + 1] = '*';
				mapEn[x1_3_2 - 1][y3_3_2 - 1] = '*';	mapEn[x1_3_2 - 1][y1_3_2] = '*';
				mapEn[x1_3_2 - 1][y2_3_2] = '*';		mapEn[x1_3_2 - 1][y3_3_2] = '*';
				mapEn[x1_3_2 - 1][y1_3_2 + 1] = '*';	mapEn[x1_3_2 + 1][y3_3_2 - 1] = '*';
				mapEn[x1_3_2 + 1][y1_3_2] = '*';		mapEn[x1_3_2 + 1][y2_3_2] = '*';
				mapEn[x1_3_2 + 1][y3_3_2] = '*';		mapEn[x1_3_2 + 1][y1_3_2 + 1] = '*';

				mapEn1[x1_3_2][y3_3_2 - 1] = '*';		mapEn1[x1_3_2][y1_3_2 + 1] = '*';
				mapEn1[x1_3_2 - 1][y3_3_2 - 1] = '*';	mapEn1[x1_3_2 - 1][y1_3_2] = '*';
				mapEn1[x1_3_2 - 1][y2_3_2] = '*';		mapEn1[x1_3_2 - 1][y3_3_2] = '*';
				mapEn1[x1_3_2 - 1][y1_3_2 + 1] = '*';	mapEn1[x1_3_2 + 1][y3_3_2 - 1] = '*';
				mapEn1[x1_3_2 + 1][y1_3_2] = '*';		mapEn1[x1_3_2 + 1][y2_3_2] = '*';
				mapEn1[x1_3_2 + 1][y3_3_2] = '*';		mapEn1[x1_3_2 + 1][y1_3_2 + 1] = '*';
				break;
			}
		}
	}

	if (mapEn[x1_2_1][y1_2_1] == 'X' && mapEn[x2_2_1][y2_2_1] == 'X')
	{
		if (flag2_1)
		{
			flag2_1 = false;
			enShip2--;
			switch (fact_2_1)
			{
			case 13:
				mapEn[x1_2_1 - 1][y1_2_1] = '*';		mapEn[x2_2_1 + 1][y1_2_1] = '*';
				mapEn[x1_2_1 - 1][y1_2_1 - 1] = '*';	mapEn[x1_2_1][y1_2_1 - 1] = '*';
				mapEn[x2_2_1][y1_2_1 - 1] = '*';
				mapEn[x2_2_1 + 1][y1_2_1 - 1] = '*';	mapEn[x1_2_1 - 1][y1_2_1 + 1] = '*';
				mapEn[x1_2_1][y1_2_1 + 1] = '*';
				mapEn[x2_2_1][y1_2_1 + 1] = '*';		mapEn[x2_2_1 + 1][y1_2_1 + 1] = '*';

				mapEn1[x1_2_1 - 1][y1_2_1] = '*';		mapEn1[x2_2_1 + 1][y1_2_1] = '*';
				mapEn1[x1_2_1 - 1][y1_2_1 - 1] = '*';	mapEn1[x1_2_1][y1_2_1 - 1] = '*';
				mapEn1[x2_2_1][y1_2_1 - 1] = '*';
				mapEn1[x2_2_1 + 1][y1_2_1 - 1] = '*';	mapEn1[x1_2_1 - 1][y1_2_1 + 1] = '*';
				mapEn1[x1_2_1][y1_2_1 + 1] = '*';
				mapEn1[x2_2_1][y1_2_1 + 1] = '*';		mapEn1[x2_2_1 + 1][y1_2_1 + 1] = '*';
				break;
			case 14:
				mapEn[x2_2_1 - 1][y1_2_1] = '*';		mapEn[x1_2_1 + 1][y1_2_1] = '*';
				mapEn[x2_2_1 - 1][y1_2_1 - 1] = '*';	mapEn[x1_2_1][y1_2_1 - 1] = '*';
				mapEn[x2_2_1][y1_2_1 - 1] = '*';
				mapEn[x1_2_1 + 1][y1_2_1 - 1] = '*';	mapEn[x2_2_1 - 1][y1_2_1 + 1] = '*';
				mapEn[x1_2_1][y1_2_1 + 1] = '*';
				mapEn[x2_2_1][y1_2_1 + 1] = '*';		mapEn[x1_2_1 + 1][y1_2_1 + 1] = '*';

				mapEn1[x2_2_1 - 1][y1_2_1] = '*';		mapEn1[x1_2_1 + 1][y1_2_1] = '*';
				mapEn1[x2_2_1 - 1][y1_2_1 - 1] = '*';	mapEn1[x1_2_1][y1_2_1 - 1] = '*';
				mapEn1[x2_2_1][y1_2_1 - 1] = '*';
				mapEn1[x1_2_1 + 1][y1_2_1 - 1] = '*';	mapEn1[x2_2_1 - 1][y1_2_1 + 1] = '*';
				mapEn1[x1_2_1][y1_2_1 + 1] = '*';
				mapEn1[x2_2_1][y1_2_1 + 1] = '*';		mapEn1[x1_2_1 + 1][y1_2_1 + 1] = '*';
				break;
			case 23:
				mapEn[x1_2_1][y1_2_1 - 1] = '*';		mapEn[x1_2_1][y2_2_1 + 1] = '*';
				mapEn[x1_2_1 - 1][y1_2_1 - 1] = '*';	mapEn[x1_2_1 - 1][y1_2_1] = '*';
				mapEn[x1_2_1 - 1][y2_2_1] = '*';
				mapEn[x1_2_1 - 1][y2_2_1 + 1] = '*';	mapEn[x1_2_1 + 1][y1_2_1 - 1] = '*';
				mapEn[x1_2_1 + 1][y1_2_1] = '*';
				mapEn[x1_2_1 + 1][y2_2_1] = '*';		mapEn[x1_2_1 + 1][y2_2_1 + 1] = '*';

				mapEn1[x1_2_1][y1_2_1 - 1] = '*';		mapEn1[x1_2_1][y2_2_1 + 1] = '*';
				mapEn1[x1_2_1 - 1][y1_2_1 - 1] = '*';	mapEn1[x1_2_1 - 1][y1_2_1] = '*';
				mapEn1[x1_2_1 - 1][y2_2_1] = '*';
				mapEn1[x1_2_1 - 1][y2_2_1 + 1] = '*';	mapEn1[x1_2_1 + 1][y1_2_1 - 1] = '*';
				mapEn1[x1_2_1 + 1][y1_2_1] = '*';
				mapEn1[x1_2_1 + 1][y2_2_1] = '*';		mapEn1[x1_2_1 + 1][y2_2_1 + 1] = '*';
				break;
			case 24:
				mapEn[x1_2_1][y2_2_1 - 1] = '*';		mapEn[x1_2_1][y1_2_1 + 1] = '*';
				mapEn[x1_2_1 - 1][y2_2_1 - 1] = '*';	mapEn[x1_2_1 - 1][y1_2_1] = '*';
				mapEn[x1_2_1 - 1][y2_2_1] = '*';
				mapEn[x1_2_1 - 1][y1_2_1 + 1] = '*';	mapEn[x1_2_1 + 1][y2_2_1 - 1] = '*';
				mapEn[x1_2_1 + 1][y1_2_1] = '*';
				mapEn[x1_2_1 + 1][y2_2_1] = '*';		mapEn[x1_2_1 + 1][y1_2_1 + 1] = '*';

				mapEn1[x1_2_1][y2_2_1 - 1] = '*';		mapEn1[x1_2_1][y1_2_1 + 1] = '*';
				mapEn1[x1_2_1 - 1][y2_2_1 - 1] = '*';	mapEn1[x1_2_1 - 1][y1_2_1] = '*';
				mapEn1[x1_2_1 - 1][y2_2_1] = '*';
				mapEn1[x1_2_1 - 1][y1_2_1 + 1] = '*';	mapEn1[x1_2_1 + 1][y2_2_1 - 1] = '*';
				mapEn1[x1_2_1 + 1][y1_2_1] = '*';
				mapEn1[x1_2_1 + 1][y2_2_1] = '*';		mapEn1[x1_2_1 + 1][y1_2_1 + 1] = '*';
				break;
			}
		}
	}
	if (mapEn[x1_2_2][y1_2_2] == 'X' && mapEn[x2_2_2][y2_2_2] == 'X')
	{
		if (flag2_2)
		{
			flag2_2 = false;
			enShip2--;
			switch (fact_2_2)
			{
			case 13:
				mapEn[x1_2_2 - 1][y1_2_2] = '*';		mapEn[x2_2_2 + 1][y1_2_2] = '*';
				mapEn[x1_2_2 - 1][y1_2_2 - 1] = '*';	mapEn[x1_2_2][y1_2_2 - 1] = '*';
				mapEn[x2_2_2][y1_2_2 - 1] = '*';
				mapEn[x2_2_2 + 1][y1_2_2 - 1] = '*';	mapEn[x1_2_2 - 1][y1_2_2 + 1] = '*';
				mapEn[x1_2_2][y1_2_2 + 1] = '*';
				mapEn[x2_2_2][y1_2_2 + 1] = '*';		mapEn[x2_2_2 + 1][y1_2_2 + 1] = '*';

				mapEn1[x1_2_2 - 1][y1_2_2] = '*';		mapEn1[x2_2_2 + 1][y1_2_2] = '*';
				mapEn1[x1_2_2 - 1][y1_2_2 - 1] = '*';	mapEn1[x1_2_2][y1_2_2 - 1] = '*';
				mapEn1[x2_2_2][y1_2_2 - 1] = '*';
				mapEn1[x2_2_2 + 1][y1_2_2 - 1] = '*';	mapEn1[x1_2_2 - 1][y1_2_2 + 1] = '*';
				mapEn1[x1_2_2][y1_2_2 + 1] = '*';
				mapEn1[x2_2_2][y1_2_2 + 1] = '*';		mapEn1[x2_2_2 + 1][y1_2_2 + 1] = '*';
				break;
			case 14:
				mapEn[x2_2_2 - 1][y1_2_2] = '*';		mapEn[x1_2_2 + 1][y1_2_2] = '*';
				mapEn[x2_2_2 - 1][y1_2_2 - 1] = '*';	mapEn[x1_2_2][y1_2_2 - 1] = '*';
				mapEn[x2_2_2][y1_2_2 - 1] = '*';
				mapEn[x1_2_2 + 1][y1_2_2 - 1] = '*';	mapEn[x2_2_2 - 1][y1_2_2 + 1] = '*';
				mapEn[x1_2_2][y1_2_2 + 1] = '*';
				mapEn[x2_2_2][y1_2_2 + 1] = '*';		mapEn[x1_2_2 + 1][y1_2_2 + 1] = '*';

				mapEn1[x2_2_2 - 1][y1_2_2] = '*';		mapEn1[x1_2_2 + 1][y1_2_2] = '*';
				mapEn1[x2_2_2 - 1][y1_2_2 - 1] = '*';	mapEn1[x1_2_2][y1_2_2 - 1] = '*';
				mapEn1[x2_2_2][y1_2_2 - 1] = '*';
				mapEn1[x1_2_2 + 1][y1_2_2 - 1] = '*';	mapEn1[x2_2_2 - 1][y1_2_2 + 1] = '*';
				mapEn1[x1_2_2][y1_2_2 + 1] = '*';
				mapEn1[x2_2_2][y1_2_2 + 1] = '*';		mapEn1[x1_2_2 + 1][y1_2_2 + 1] = '*';
				break;
			case 23:
				mapEn[x1_2_2][y1_2_2 - 1] = '*';		mapEn[x1_2_2][y2_2_2 + 1] = '*';
				mapEn[x1_2_2 - 1][y1_2_2 - 1] = '*';	mapEn[x1_2_2 - 1][y1_2_2] = '*';
				mapEn[x1_2_2 - 1][y2_2_2] = '*';
				mapEn[x1_2_2 - 1][y2_2_2 + 1] = '*';	mapEn[x1_2_2 + 1][y1_2_2 - 1] = '*';
				mapEn[x1_2_2 + 1][y1_2_2] = '*';
				mapEn[x1_2_2 + 1][y2_2_2] = '*';		mapEn[x1_2_2 + 1][y2_2_2 + 1] = '*';

				mapEn1[x1_2_2][y1_2_2 - 1] = '*';		mapEn1[x1_2_2][y2_2_2 + 1] = '*';
				mapEn1[x1_2_2 - 1][y1_2_2 - 1] = '*';	mapEn1[x1_2_2 - 1][y1_2_2] = '*';
				mapEn1[x1_2_2 - 1][y2_2_2] = '*';
				mapEn1[x1_2_2 - 1][y2_2_2 + 1] = '*';	mapEn1[x1_2_2 + 1][y1_2_2 - 1] = '*';
				mapEn1[x1_2_2 + 1][y1_2_2] = '*';
				mapEn1[x1_2_2 + 1][y2_2_2] = '*';		mapEn1[x1_2_2 + 1][y2_2_2 + 1] = '*';
				break;
			case 24:
				mapEn[x1_2_2][y2_2_2 - 1] = '*';		mapEn[x1_2_2][y1_2_2 + 1] = '*';
				mapEn[x1_2_2 - 1][y2_2_2 - 1] = '*';	mapEn[x1_2_2 - 1][y1_2_2] = '*';
				mapEn[x1_2_2 - 1][y2_2_2] = '*';
				mapEn[x1_2_2 - 1][y1_2_2 + 1] = '*';	mapEn[x1_2_2 + 1][y2_2_2 - 1] = '*';
				mapEn[x1_2_2 + 1][y1_2_2] = '*';
				mapEn[x1_2_2 + 1][y2_2_2] = '*';		mapEn[x1_2_2 + 1][y1_2_2 + 1] = '*';

				mapEn1[x1_2_2][y2_2_2 - 1] = '*';		mapEn1[x1_2_2][y1_2_2 + 1] = '*';
				mapEn1[x1_2_2 - 1][y2_2_2 - 1] = '*';	mapEn1[x1_2_2 - 1][y1_2_2] = '*';
				mapEn1[x1_2_2 - 1][y2_2_2] = '*';
				mapEn1[x1_2_2 - 1][y1_2_2 + 1] = '*';	mapEn1[x1_2_2 + 1][y2_2_2 - 1] = '*';
				mapEn1[x1_2_2 + 1][y1_2_2] = '*';
				mapEn1[x1_2_2 + 1][y2_2_2] = '*';		mapEn1[x1_2_2 + 1][y1_2_2 + 1] = '*';
				break;
			}
		}
	}
	if (mapEn[x1_2_3][y1_2_3] == 'X' && mapEn[x2_2_3][y2_2_3] == 'X')
	{
		if (flag2_3)
		{
			flag2_3 = false;
			enShip2--;
			switch (fact_2_3)
			{
			case 13:
				mapEn[x1_2_3 - 1][y1_2_3] = '*';		mapEn[x2_2_3 + 1][y1_2_3] = '*';
				mapEn[x1_2_3 - 1][y1_2_3 - 1] = '*';	mapEn[x1_2_3][y1_2_3 - 1] = '*';
				mapEn[x2_2_3][y1_2_3 - 1] = '*';
				mapEn[x2_2_3 + 1][y1_2_3 - 1] = '*';	mapEn[x1_2_3 - 1][y1_2_3 + 1] = '*';
				mapEn[x1_2_3][y1_2_3 + 1] = '*';
				mapEn[x2_2_3][y1_2_3 + 1] = '*';		mapEn[x2_2_3 + 1][y1_2_3 + 1] = '*';

				mapEn1[x1_2_3 - 1][y1_2_3] = '*';		mapEn1[x2_2_3 + 1][y1_2_3] = '*';
				mapEn1[x1_2_3 - 1][y1_2_3 - 1] = '*';	mapEn1[x1_2_3][y1_2_3 - 1] = '*';
				mapEn1[x2_2_3][y1_2_3 - 1] = '*';
				mapEn1[x2_2_3 + 1][y1_2_3 - 1] = '*';	mapEn1[x1_2_3 - 1][y1_2_3 + 1] = '*';
				mapEn1[x1_2_3][y1_2_3 + 1] = '*';
				mapEn1[x2_2_3][y1_2_3 + 1] = '*';		mapEn1[x2_2_3 + 1][y1_2_3 + 1] = '*';
				break;
			case 14:
				mapEn[x2_2_3 - 1][y1_2_3] = '*';		mapEn[x1_2_3 + 1][y1_2_3] = '*';
				mapEn[x2_2_3 - 1][y1_2_3 - 1] = '*';	mapEn[x1_2_3][y1_2_3 - 1] = '*';
				mapEn[x2_2_3][y1_2_3 - 1] = '*';
				mapEn[x1_2_3 + 1][y1_2_3 - 1] = '*';	mapEn[x2_2_3 - 1][y1_2_3 + 1] = '*';
				mapEn[x1_2_3][y1_2_3 + 1] = '*';
				mapEn[x2_2_3][y1_2_3 + 1] = '*';		mapEn[x1_2_3 + 1][y1_2_3 + 1] = '*';

				mapEn1[x2_2_3 - 1][y1_2_3] = '*';		mapEn1[x1_2_3 + 1][y1_2_3] = '*';
				mapEn1[x2_2_3 - 1][y1_2_3 - 1] = '*';	mapEn1[x1_2_3][y1_2_3 - 1] = '*';
				mapEn1[x2_2_3][y1_2_3 - 1] = '*';
				mapEn1[x1_2_3 + 1][y1_2_3 - 1] = '*';	mapEn1[x2_2_3 - 1][y1_2_3 + 1] = '*';
				mapEn1[x1_2_3][y1_2_3 + 1] = '*';
				mapEn1[x2_2_3][y1_2_3 + 1] = '*';		mapEn1[x1_2_3 + 1][y1_2_3 + 1] = '*';
				break;
			case 23:
				mapEn[x1_2_3][y1_2_3 - 1] = '*';		mapEn[x1_2_3][y2_2_3 + 1] = '*';
				mapEn[x1_2_3 - 1][y1_2_3 - 1] = '*';	mapEn[x1_2_3 - 1][y1_2_3] = '*';
				mapEn[x1_2_3 - 1][y2_2_3] = '*';
				mapEn[x1_2_3 - 1][y2_2_3 + 1] = '*';	mapEn[x1_2_3 + 1][y1_2_3 - 1] = '*';
				mapEn[x1_2_3 + 1][y1_2_3] = '*';
				mapEn[x1_2_3 + 1][y2_2_3] = '*';		mapEn[x1_2_3 + 1][y2_2_3 + 1] = '*';

				mapEn1[x1_2_3][y1_2_3 - 1] = '*';		mapEn1[x1_2_3][y2_2_3 + 1] = '*';
				mapEn1[x1_2_3 - 1][y1_2_3 - 1] = '*';	mapEn1[x1_2_3 - 1][y1_2_3] = '*';
				mapEn1[x1_2_3 - 1][y2_2_3] = '*';
				mapEn1[x1_2_3 - 1][y2_2_3 + 1] = '*';	mapEn1[x1_2_3 + 1][y1_2_3 - 1] = '*';
				mapEn1[x1_2_3 + 1][y1_2_3] = '*';
				mapEn1[x1_2_3 + 1][y2_2_3] = '*';		mapEn1[x1_2_3 + 1][y2_2_3 + 1] = '*';
				break;
			case 24:
				mapEn[x1_2_3][y2_2_3 - 1] = '*';		mapEn[x1_2_3][y1_2_3 + 1] = '*';
				mapEn[x1_2_3 - 1][y2_2_3 - 1] = '*';	mapEn[x1_2_3 - 1][y1_2_3] = '*';
				mapEn[x1_2_3 - 1][y2_2_3] = '*';
				mapEn[x1_2_3 - 1][y1_2_3 + 1] = '*';	mapEn[x1_2_3 + 1][y2_2_3 - 1] = '*';
				mapEn[x1_2_3 + 1][y1_2_3] = '*';
				mapEn[x1_2_3 + 1][y2_2_3] = '*';		mapEn[x1_2_3 + 1][y1_2_3 + 1] = '*';

				mapEn1[x1_2_3][y2_2_3 - 1] = '*';		mapEn1[x1_2_3][y1_2_3 + 1] = '*';
				mapEn1[x1_2_3 - 1][y2_2_3 - 1] = '*';	mapEn1[x1_2_3 - 1][y1_2_3] = '*';
				mapEn1[x1_2_3 - 1][y2_2_3] = '*';
				mapEn1[x1_2_3 - 1][y1_2_3 + 1] = '*';	mapEn1[x1_2_3 + 1][y2_2_3 - 1] = '*';
				mapEn1[x1_2_3 + 1][y1_2_3] = '*';
				mapEn1[x1_2_3 + 1][y2_2_3] = '*';		mapEn1[x1_2_3 + 1][y1_2_3 + 1] = '*';
				break;
			}
		}
	}

	if (mapEn[x1_1_1][y1_1_1] == 'X')
	{
		if (flag1_1)
		{
			flag1_1 = false;
			enShip1--;
			mapEn[x1_1_1 - 1][y1_1_1 - 1] = '*';
			mapEn[x1_1_1][y1_1_1 - 1] = '*';
			mapEn[x1_1_1 + 1][y1_1_1 - 1] = '*';
			mapEn[x1_1_1 - 1][y1_1_1 + 1] = '*';
			mapEn[x1_1_1][y1_1_1 + 1] = '*';
			mapEn[x1_1_1 + 1][y1_1_1 + 1] = '*';
			mapEn[x1_1_1 - 1][y1_1_1] = '*';
			mapEn[x1_1_1 + 1][y1_1_1] = '*';

			mapEn1[x1_1_1 - 1][y1_1_1 - 1] = '*';
			mapEn1[x1_1_1][y1_1_1 - 1] = '*';
			mapEn1[x1_1_1 + 1][y1_1_1 - 1] = '*';
			mapEn1[x1_1_1 - 1][y1_1_1 + 1] = '*';
			mapEn1[x1_1_1][y1_1_1 + 1] = '*';
			mapEn1[x1_1_1 + 1][y1_1_1 + 1] = '*';
			mapEn1[x1_1_1 - 1][y1_1_1] = '*';
			mapEn1[x1_1_1 + 1][y1_1_1] = '*';
		}
	}
	if (mapEn[x1_1_2][y1_1_2] == 'X')
	{
		if (flag1_2)
		{
			flag1_2 = false;
			enShip1--;
			mapEn[x1_1_2 - 1][y1_1_2 - 1] = '*';
			mapEn[x1_1_2][y1_1_2 - 1] = '*';
			mapEn[x1_1_2 + 1][y1_1_2 - 1] = '*';
			mapEn[x1_1_2 - 1][y1_1_2 + 1] = '*';
			mapEn[x1_1_2][y1_1_2 + 1] = '*';
			mapEn[x1_1_2 + 1][y1_1_2 + 1] = '*';
			mapEn[x1_1_2 - 1][y1_1_2] = '*';
			mapEn[x1_1_2 + 1][y1_1_2] = '*';

			mapEn1[x1_1_2 - 1][y1_1_2 - 1] = '*';
			mapEn1[x1_1_2][y1_1_2 - 1] = '*';
			mapEn1[x1_1_2 + 1][y1_1_2 - 1] = '*';
			mapEn1[x1_1_2 - 1][y1_1_2 + 1] = '*';
			mapEn1[x1_1_2][y1_1_2 + 1] = '*';
			mapEn1[x1_1_2 + 1][y1_1_2 + 1] = '*';
			mapEn1[x1_1_2 - 1][y1_1_2] = '*';
			mapEn1[x1_1_2 + 1][y1_1_2] = '*';
		}
	}
	if (mapEn[x1_1_3][y1_1_3] == 'X')
	{
		if (flag1_3)
		{
			flag1_3 = false;
			enShip1--;
			mapEn[x1_1_3 - 1][y1_1_3 - 1] = '*';
			mapEn[x1_1_3][y1_1_3 - 1] = '*';
			mapEn[x1_1_3 + 1][y1_1_3 - 1] = '*';
			mapEn[x1_1_3 - 1][y1_1_3 + 1] = '*';
			mapEn[x1_1_3][y1_1_3 + 1] = '*';
			mapEn[x1_1_3 + 1][y1_1_3 + 1] = '*';
			mapEn[x1_1_3 - 1][y1_1_3] = '*';
			mapEn[x1_1_3 + 1][y1_1_3] = '*';

			mapEn1[x1_1_3 - 1][y1_1_3 - 1] = '*';
			mapEn1[x1_1_3][y1_1_3 - 1] = '*';
			mapEn1[x1_1_3 + 1][y1_1_3 - 1] = '*';
			mapEn1[x1_1_3 - 1][y1_1_3 + 1] = '*';
			mapEn1[x1_1_3][y1_1_3 + 1] = '*';
			mapEn1[x1_1_3 + 1][y1_1_3 + 1] = '*';
			mapEn1[x1_1_3 - 1][y1_1_3] = '*';
			mapEn1[x1_1_3 + 1][y1_1_3] = '*';
		}
	}
	if (mapEn[x1_1_4][y1_1_4] == 'X')
	{
		if (flag1_4)
		{
			flag1_4 = false;
			enShip1--;
			mapEn[x1_1_4 - 1][y1_1_4 - 1] = '*';
			mapEn[x1_1_4][y1_1_4 - 1] = '*';
			mapEn[x1_1_4 + 1][y1_1_4 - 1] = '*';
			mapEn[x1_1_4 - 1][y1_1_4 + 1] = '*';
			mapEn[x1_1_4][y1_1_4 + 1] = '*';
			mapEn[x1_1_4 + 1][y1_1_4 + 1] = '*';
			mapEn[x1_1_4 - 1][y1_1_4] = '*';
			mapEn[x1_1_4 + 1][y1_1_4] = '*';

			mapEn1[x1_1_4 - 1][y1_1_4 - 1] = '*';
			mapEn1[x1_1_4][y1_1_4 - 1] = '*';
			mapEn1[x1_1_4 + 1][y1_1_4 - 1] = '*';
			mapEn1[x1_1_4 - 1][y1_1_4 + 1] = '*';
			mapEn1[x1_1_4][y1_1_4 + 1] = '*';
			mapEn1[x1_1_4 + 1][y1_1_4 + 1] = '*';
			mapEn1[x1_1_4 - 1][y1_1_4] = '*';
			mapEn1[x1_1_4 + 1][y1_1_4] = '*';
		}
	}
}

// проверка полной потопленности корабля игрока и выделение его точками по краям
void checkDeadOfMe(PlayerField myMap, char mapMe[12][12], char helpMap[12][12])
{
	if (helpMap[mx1_4_1][my1_4_1] == 'X' && helpMap[mx2_4_1][my2_4_1] == 'X' && helpMap[mx3_4_1][my3_4_1] == 'X' && helpMap[mx4_4_1][my4_4_1] == 'X')
	{
		switch (mfact_4_1)
		{
		case 13:
			helpMap[mx1_4_1 - 1][my1_4_1] = '*';		helpMap[mx4_4_1 + 1][my1_4_1] = '*';
			helpMap[mx1_4_1 - 1][my1_4_1 - 1] = '*';	helpMap[mx1_4_1][my1_4_1 - 1] = '*';
			helpMap[mx2_4_1][my1_4_1 - 1] = '*';		helpMap[mx4_4_1][my1_4_1 - 1] = '*';
			helpMap[mx4_4_1 + 1][my1_4_1 - 1] = '*';	helpMap[mx1_4_1 - 1][my1_4_1 + 1] = '*';
			helpMap[mx1_4_1][my1_4_1 + 1] = '*';		helpMap[mx2_4_1][my1_4_1 + 1] = '*';
			helpMap[mx4_4_1][my1_4_1 + 1] = '*';		helpMap[mx4_4_1 + 1][my1_4_1 + 1] = '*';
			helpMap[mx3_4_1][my1_4_1 - 1] = '*';		helpMap[mx3_4_1][my1_4_1 + 1] = '*';

			mapMe[mx1_4_1 - 1][my1_4_1] = '*';		mapMe[mx4_4_1 + 1][my1_4_1] = '*';
			mapMe[mx1_4_1 - 1][my1_4_1 - 1] = '*';	mapMe[mx1_4_1][my1_4_1 - 1] = '*';
			mapMe[mx2_4_1][my1_4_1 - 1] = '*';		mapMe[mx4_4_1][my1_4_1 - 1] = '*';
			mapMe[mx4_4_1 + 1][my1_4_1 - 1] = '*';	mapMe[mx1_4_1 - 1][my1_4_1 + 1] = '*';
			mapMe[mx1_4_1][my1_4_1 + 1] = '*';		mapMe[mx2_4_1][my1_4_1 + 1] = '*';
			mapMe[mx4_4_1][my1_4_1 + 1] = '*';		mapMe[mx4_4_1 + 1][my1_4_1 + 1] = '*';
			mapMe[mx3_4_1][my1_4_1 - 1] = '*';		mapMe[mx3_4_1][my1_4_1 + 1] = '*';
			break;
		case 14:
			helpMap[mx4_4_1 - 1][my1_4_1] = '*';		helpMap[mx1_4_1 + 1][my1_4_1] = '*';
			helpMap[mx4_4_1 - 1][my1_4_1 - 1] = '*';	helpMap[mx1_4_1][my1_4_1 - 1] = '*';
			helpMap[mx2_4_1][my1_4_1 - 1] = '*';		helpMap[mx4_4_1][my1_4_1 - 1] = '*';
			helpMap[mx1_4_1 + 1][my1_4_1 - 1] = '*';	helpMap[mx4_4_1 - 1][my1_4_1 + 1] = '*';
			helpMap[mx1_4_1][my1_4_1 + 1] = '*';		helpMap[mx2_4_1][my1_4_1 + 1] = '*';
			helpMap[mx4_4_1][my1_4_1 + 1] = '*';		helpMap[mx1_4_1 + 1][my1_4_1 + 1] = '*';
			helpMap[mx3_4_1][my1_4_1 - 1] = '*';		helpMap[mx3_4_1][my1_4_1 + 1] = '*';

			mapMe[mx4_4_1 - 1][my1_4_1] = '*';		mapMe[mx1_4_1 + 1][my1_4_1] = '*';
			mapMe[mx4_4_1 - 1][my1_4_1 - 1] = '*';	mapMe[mx1_4_1][my1_4_1 - 1] = '*';
			mapMe[mx2_4_1][my1_4_1 - 1] = '*';		mapMe[mx4_4_1][my1_4_1 - 1] = '*';
			mapMe[mx1_4_1 + 1][my1_4_1 - 1] = '*';	mapMe[mx4_4_1 - 1][my1_4_1 + 1] = '*';
			mapMe[mx1_4_1][my1_4_1 + 1] = '*';		mapMe[mx2_4_1][my1_4_1 + 1] = '*';
			mapMe[mx4_4_1][my1_4_1 + 1] = '*';		mapMe[mx1_4_1 + 1][my1_4_1 + 1] = '*';
			mapMe[mx3_4_1][my1_4_1 - 1] = '*';		mapMe[mx3_4_1][my1_4_1 + 1] = '*';
			break;
		case 23:
			helpMap[mx1_4_1][my1_4_1 - 1] = '*';		helpMap[mx1_4_1][my4_4_1 + 1] = '*';
			helpMap[mx1_4_1 - 1][my1_4_1 - 1] = '*';	helpMap[mx1_4_1 - 1][my1_4_1] = '*';
			helpMap[mx1_4_1 - 1][my2_4_1] = '*';		helpMap[mx1_4_1 - 1][my4_4_1] = '*';
			helpMap[mx1_4_1 - 1][my4_4_1 + 1] = '*';	helpMap[mx1_4_1 + 1][my1_4_1 - 1] = '*';
			helpMap[mx1_4_1 + 1][my1_4_1] = '*';		helpMap[mx1_4_1 + 1][my2_4_1] = '*';
			helpMap[mx1_4_1 + 1][my4_4_1] = '*';		helpMap[mx1_4_1 + 1][my4_4_1 + 1] = '*';
			helpMap[mx1_4_1 - 1][my3_4_1] = '*';		helpMap[mx1_4_1 + 1][my3_4_1] = '*';

			mapMe[mx1_4_1][my1_4_1 - 1] = '*';		mapMe[mx1_4_1][my4_4_1 + 1] = '*';
			mapMe[mx1_4_1 - 1][my1_4_1 - 1] = '*';	mapMe[mx1_4_1 - 1][my1_4_1] = '*';
			mapMe[mx1_4_1 - 1][my2_4_1] = '*';		mapMe[mx1_4_1 - 1][my4_4_1] = '*';
			mapMe[mx1_4_1 - 1][my4_4_1 + 1] = '*';	mapMe[mx1_4_1 + 1][my1_4_1 - 1] = '*';
			mapMe[mx1_4_1 + 1][my1_4_1] = '*';		mapMe[mx1_4_1 + 1][my2_4_1] = '*';
			mapMe[mx1_4_1 + 1][my4_4_1] = '*';		mapMe[mx1_4_1 + 1][my4_4_1 + 1] = '*';
			mapMe[mx1_4_1 - 1][my3_4_1] = '*';		mapMe[mx1_4_1 + 1][my3_4_1] = '*';
			break;
		case 24:
			helpMap[mx1_4_1][my4_4_1 - 1] = '*';		helpMap[mx1_4_1][my1_4_1 + 1] = '*';
			helpMap[mx1_4_1 - 1][my4_4_1 - 1] = '*';	helpMap[mx1_4_1 - 1][my1_4_1] = '*';
			helpMap[mx1_4_1 - 1][my2_4_1] = '*';		helpMap[mx1_4_1 - 1][my4_4_1] = '*';
			helpMap[mx1_4_1 - 1][my1_4_1 + 1] = '*';	helpMap[mx1_4_1 + 1][my4_4_1 - 1] = '*';
			helpMap[mx1_4_1 + 1][my1_4_1] = '*';		helpMap[mx1_4_1 + 1][my2_4_1] = '*';
			helpMap[mx1_4_1 + 1][my4_4_1] = '*';		helpMap[mx1_4_1 + 1][my1_4_1 + 1] = '*';
			helpMap[mx1_4_1 - 1][my3_4_1] = '*';		helpMap[mx1_4_1 + 1][my3_4_1] = '*';

			mapMe[mx1_4_1][my4_4_1 - 1] = '*';		mapMe[mx1_4_1][my1_4_1 + 1] = '*';
			mapMe[mx1_4_1 - 1][my4_4_1 - 1] = '*';	mapMe[mx1_4_1 - 1][my1_4_1] = '*';
			mapMe[mx1_4_1 - 1][my2_4_1] = '*';		mapMe[mx1_4_1 - 1][my4_4_1] = '*';
			mapMe[mx1_4_1 - 1][my1_4_1 + 1] = '*';	mapMe[mx1_4_1 + 1][my4_4_1 - 1] = '*';
			mapMe[mx1_4_1 + 1][my1_4_1] = '*';		mapMe[mx1_4_1 + 1][my2_4_1] = '*';
			mapMe[mx1_4_1 + 1][my4_4_1] = '*';		mapMe[mx1_4_1 + 1][my1_4_1 + 1] = '*';
			mapMe[mx1_4_1 - 1][my3_4_1] = '*';		mapMe[mx1_4_1 + 1][my3_4_1] = '*';
			break;
		}
	}

	if (helpMap[mx1_3_1][my1_3_1] == 'X' && helpMap[mx2_3_1][my2_3_1] == 'X' && helpMap[mx3_3_1][my3_3_1] == 'X')
	{
		switch (mfact_3_1)
		{
		case 13:
			helpMap[mx1_3_1 - 1][my1_3_1] = '*';		helpMap[mx3_3_1 + 1][my1_3_1] = '*';
			helpMap[mx1_3_1 - 1][my1_3_1 - 1] = '*';	helpMap[mx1_3_1][my1_3_1 - 1] = '*';
			helpMap[mx2_3_1][my1_3_1 - 1] = '*';		helpMap[mx3_3_1][my1_3_1 - 1] = '*';
			helpMap[mx3_3_1 + 1][my1_3_1 - 1] = '*';	helpMap[mx1_3_1 - 1][my1_3_1 + 1] = '*';
			helpMap[mx1_3_1][my1_3_1 + 1] = '*';		helpMap[mx2_3_1][my1_3_1 + 1] = '*';
			helpMap[mx3_3_1][my1_3_1 + 1] = '*';		helpMap[mx3_3_1 + 1][my1_3_1 + 1] = '*';

			mapMe[mx1_3_1 - 1][my1_3_1] = '*';		mapMe[mx3_3_1 + 1][my1_3_1] = '*';
			mapMe[mx1_3_1 - 1][my1_3_1 - 1] = '*';	mapMe[mx1_3_1][my1_3_1 - 1] = '*';
			mapMe[mx2_3_1][my1_3_1 - 1] = '*';		mapMe[mx3_3_1][my1_3_1 - 1] = '*';
			mapMe[mx3_3_1 + 1][my1_3_1 - 1] = '*';	mapMe[mx1_3_1 - 1][my1_3_1 + 1] = '*';
			mapMe[mx1_3_1][my1_3_1 + 1] = '*';		mapMe[mx2_3_1][my1_3_1 + 1] = '*';
			mapMe[mx3_3_1][my1_3_1 + 1] = '*';		mapMe[mx3_3_1 + 1][my1_3_1 + 1] = '*';
			break;
		case 14:
			helpMap[mx3_3_1 - 1][my1_3_1] = '*';		helpMap[mx1_3_1 + 1][my1_3_1] = '*';
			helpMap[mx3_3_1 - 1][my1_3_1 - 1] = '*';	helpMap[mx3_3_1][my1_3_1 - 1] = '*';
			helpMap[mx2_3_1][my1_3_1 - 1] = '*';		helpMap[mx1_3_1][my1_3_1 - 1] = '*';
			helpMap[mx1_3_1 + 1][my1_3_1 - 1] = '*';	helpMap[mx3_3_1 - 1][my1_3_1 + 1] = '*';
			helpMap[mx3_3_1][my1_3_1 + 1] = '*';		helpMap[mx2_3_1][my1_3_1 + 1] = '*';
			helpMap[mx1_3_1][my1_3_1 + 1] = '*';		helpMap[mx1_3_1 + 1][my1_3_1 + 1] = '*';

			mapMe[mx3_3_1 - 1][my1_3_1] = '*';		mapMe[mx1_3_1 + 1][my1_3_1] = '*';
			mapMe[mx3_3_1 - 1][my1_3_1 - 1] = '*';	mapMe[mx3_3_1][my1_3_1 - 1] = '*';
			mapMe[mx2_3_1][my1_3_1 - 1] = '*';		mapMe[mx1_3_1][my1_3_1 - 1] = '*';
			mapMe[mx1_3_1 + 1][my1_3_1 - 1] = '*';	mapMe[mx3_3_1 - 1][my1_3_1 + 1] = '*';
			mapMe[mx3_3_1][my1_3_1 + 1] = '*';		mapMe[mx2_3_1][my1_3_1 + 1] = '*';
			mapMe[mx1_3_1][my1_3_1 + 1] = '*';		mapMe[mx1_3_1 + 1][my1_3_1 + 1] = '*';
			break;
		case 23:
			helpMap[mx1_3_1][my1_3_1 - 1] = '*';		helpMap[mx1_3_1][my3_3_1 + 1] = '*';
			helpMap[mx1_3_1 - 1][my1_3_1 - 1] = '*';	helpMap[mx1_3_1 - 1][my1_3_1] = '*';
			helpMap[mx1_3_1 - 1][my2_3_1] = '*';		helpMap[mx1_3_1 - 1][my3_3_1] = '*';
			helpMap[mx1_3_1 - 1][my3_3_1 + 1] = '*';	helpMap[mx1_3_1 + 1][my1_3_1 - 1] = '*';
			helpMap[mx1_3_1 + 1][my1_3_1] = '*';		helpMap[mx1_3_1 + 1][my2_3_1] = '*';
			helpMap[mx1_3_1 + 1][my3_3_1] = '*';		helpMap[mx1_3_1 + 1][my3_3_1 + 1] = '*';

			mapMe[mx1_3_1][my1_3_1 - 1] = '*';		mapMe[mx1_3_1][my3_3_1 + 1] = '*';
			mapMe[mx1_3_1 - 1][my1_3_1 - 1] = '*';	mapMe[mx1_3_1 - 1][my1_3_1] = '*';
			mapMe[mx1_3_1 - 1][my2_3_1] = '*';		mapMe[mx1_3_1 - 1][my3_3_1] = '*';
			mapMe[mx1_3_1 - 1][my3_3_1 + 1] = '*';	mapMe[mx1_3_1 + 1][my1_3_1 - 1] = '*';
			mapMe[mx1_3_1 + 1][my1_3_1] = '*';		mapMe[mx1_3_1 + 1][my2_3_1] = '*';
			mapMe[mx1_3_1 + 1][my3_3_1] = '*';		mapMe[mx1_3_1 + 1][my3_3_1 + 1] = '*';
			break;
		case 24:
			helpMap[mx1_3_1][my3_3_1 - 1] = '*';		helpMap[mx1_3_1][my1_3_1 + 1] = '*';
			helpMap[mx1_3_1 - 1][my3_3_1 - 1] = '*';	helpMap[mx1_3_1 - 1][my1_3_1] = '*';
			helpMap[mx1_3_1 - 1][my2_3_1] = '*';		helpMap[mx1_3_1 - 1][my3_3_1] = '*';
			helpMap[mx1_3_1 - 1][my1_3_1 + 1] = '*';	helpMap[mx1_3_1 + 1][my3_3_1 - 1] = '*';
			helpMap[mx1_3_1 + 1][my1_3_1] = '*';		helpMap[mx1_3_1 + 1][my2_3_1] = '*';
			helpMap[mx1_3_1 + 1][my3_3_1] = '*';		helpMap[mx1_3_1 + 1][my1_3_1 + 1] = '*';

			mapMe[mx1_3_1][my3_3_1 - 1] = '*';		mapMe[mx1_3_1][my1_3_1 + 1] = '*';
			mapMe[mx1_3_1 - 1][my3_3_1 - 1] = '*';	mapMe[mx1_3_1 - 1][my1_3_1] = '*';
			mapMe[mx1_3_1 - 1][my2_3_1] = '*';		mapMe[mx1_3_1 - 1][my3_3_1] = '*';
			mapMe[mx1_3_1 - 1][my1_3_1 + 1] = '*';	mapMe[mx1_3_1 + 1][my3_3_1 - 1] = '*';
			mapMe[mx1_3_1 + 1][my1_3_1] = '*';		mapMe[mx1_3_1 + 1][my2_3_1] = '*';
			mapMe[mx1_3_1 + 1][my3_3_1] = '*';		mapMe[mx1_3_1 + 1][my1_3_1 + 1] = '*';
			break;
		}
	}
	if (helpMap[mx1_3_2][my1_3_2] == 'X' && helpMap[mx2_3_2][my2_3_2] == 'X' && helpMap[mx3_3_2][my3_3_2] == 'X')
	{
		switch (mfact_3_2)
		{
		case 13:
			helpMap[mx1_3_2 - 1][my1_3_2] = '*';		helpMap[mx3_3_2 + 1][my1_3_2] = '*';
			helpMap[mx1_3_2 - 1][my1_3_2 - 1] = '*';	helpMap[mx1_3_2][my1_3_2 - 1] = '*';
			helpMap[mx2_3_2][my1_3_2 - 1] = '*';		helpMap[mx3_3_2][my1_3_2 - 1] = '*';
			helpMap[mx3_3_2 + 1][my1_3_2 - 1] = '*';	helpMap[mx1_3_2 - 1][my1_3_2 + 1] = '*';
			helpMap[mx1_3_2][my1_3_2 + 1] = '*';		helpMap[mx2_3_2][my1_3_2 + 1] = '*';
			helpMap[mx3_3_2][my1_3_2 + 1] = '*';		helpMap[mx3_3_2 + 1][my1_3_2 + 1] = '*';

			mapMe[mx1_3_2 - 1][my1_3_2] = '*';		mapMe[mx3_3_2 + 1][my1_3_2] = '*';
			mapMe[mx1_3_2 - 1][my1_3_2 - 1] = '*';	mapMe[mx1_3_2][my1_3_2 - 1] = '*';
			mapMe[mx2_3_2][my1_3_2 - 1] = '*';		mapMe[mx3_3_2][my1_3_2 - 1] = '*';
			mapMe[mx3_3_2 + 1][my1_3_2 - 1] = '*';	mapMe[mx1_3_2 - 1][my1_3_2 + 1] = '*';
			mapMe[mx1_3_2][my1_3_2 + 1] = '*';		mapMe[mx2_3_2][my1_3_2 + 1] = '*';
			mapMe[mx3_3_2][my1_3_2 + 1] = '*';		mapMe[mx3_3_2 + 1][my1_3_2 + 1] = '*';
			break;
		case 14:
			helpMap[mx3_3_2 - 1][my1_3_2] = '*';		helpMap[mx1_3_2 + 1][my1_3_2] = '*';
			helpMap[mx3_3_2 - 1][my1_3_2 - 1] = '*';	helpMap[mx3_3_2][my1_3_2 - 1] = '*';
			helpMap[mx2_3_2][my1_3_2 - 1] = '*';		helpMap[mx1_3_2][my1_3_2 - 1] = '*';
			helpMap[mx1_3_2 + 1][my1_3_2 - 1] = '*';	helpMap[mx3_3_2 - 1][my1_3_2 + 1] = '*';
			helpMap[mx3_3_2][my1_3_2 + 1] = '*';		helpMap[mx2_3_2][my1_3_2 + 1] = '*';
			helpMap[mx1_3_2][my1_3_2 + 1] = '*';		helpMap[mx1_3_2 + 1][my1_3_2 + 1] = '*';

			mapMe[mx3_3_2 - 1][my1_3_2] = '*';		mapMe[mx1_3_2 + 1][my1_3_2] = '*';
			mapMe[mx3_3_2 - 1][my1_3_2 - 1] = '*';	mapMe[mx3_3_2][my1_3_2 - 1] = '*';
			mapMe[mx2_3_2][my1_3_2 - 1] = '*';		mapMe[mx1_3_2][my1_3_2 - 1] = '*';
			mapMe[mx1_3_2 + 1][my1_3_2 - 1] = '*';	mapMe[mx3_3_2 - 1][my1_3_2 + 1] = '*';
			mapMe[mx3_3_2][my1_3_2 + 1] = '*';		mapMe[mx2_3_2][my1_3_2 + 1] = '*';
			mapMe[mx1_3_2][my1_3_2 + 1] = '*';		mapMe[mx1_3_2 + 1][my1_3_2 + 1] = '*';
			break;
		case 23:
			helpMap[mx1_3_2][my1_3_2 - 1] = '*';		helpMap[mx1_3_2][my3_3_2 + 1] = '*';
			helpMap[mx1_3_2 - 1][my1_3_2 - 1] = '*';	helpMap[mx1_3_2 - 1][my1_3_2] = '*';
			helpMap[mx1_3_2 - 1][my2_3_2] = '*';		helpMap[mx1_3_2 - 1][my3_3_2] = '*';
			helpMap[mx1_3_2 - 1][my3_3_2 + 1] = '*';	helpMap[mx1_3_2 + 1][my1_3_2 - 1] = '*';
			helpMap[mx1_3_2 + 1][my1_3_2] = '*';		helpMap[mx1_3_2 + 1][my2_3_2] = '*';
			helpMap[mx1_3_2 + 1][my3_3_2] = '*';		helpMap[mx1_3_2 + 1][my3_3_2 + 1] = '*';

			mapMe[mx1_3_2][my1_3_2 - 1] = '*';		mapMe[mx1_3_2][my3_3_2 + 1] = '*';
			mapMe[mx1_3_2 - 1][my1_3_2 - 1] = '*';	mapMe[mx1_3_2 - 1][my1_3_2] = '*';
			mapMe[mx1_3_2 - 1][my2_3_2] = '*';		mapMe[mx1_3_2 - 1][my3_3_2] = '*';
			mapMe[mx1_3_2 - 1][my3_3_2 + 1] = '*';	mapMe[mx1_3_2 + 1][my1_3_2 - 1] = '*';
			mapMe[mx1_3_2 + 1][my1_3_2] = '*';		mapMe[mx1_3_2 + 1][my2_3_2] = '*';
			mapMe[mx1_3_2 + 1][my3_3_2] = '*';		mapMe[mx1_3_2 + 1][my3_3_2 + 1] = '*';
			break;
		case 24:
			helpMap[mx1_3_2][my3_3_2 - 1] = '*';		helpMap[mx1_3_2][my1_3_2 + 1] = '*';
			helpMap[mx1_3_2 - 1][my3_3_2 - 1] = '*';	helpMap[mx1_3_2 - 1][my1_3_2] = '*';
			helpMap[mx1_3_2 - 1][my2_3_2] = '*';		helpMap[mx1_3_2 - 1][my3_3_2] = '*';
			helpMap[mx1_3_2 - 1][my1_3_2 + 1] = '*';	helpMap[mx1_3_2 + 1][my3_3_2 - 1] = '*';
			helpMap[mx1_3_2 + 1][my1_3_2] = '*';		helpMap[mx1_3_2 + 1][my2_3_2] = '*';
			helpMap[mx1_3_2 + 1][my3_3_2] = '*';		helpMap[mx1_3_2 + 1][my1_3_2 + 1] = '*';

			mapMe[mx1_3_2][my3_3_2 - 1] = '*';		mapMe[mx1_3_2][my1_3_2 + 1] = '*';
			mapMe[mx1_3_2 - 1][my3_3_2 - 1] = '*';	mapMe[mx1_3_2 - 1][my1_3_2] = '*';
			mapMe[mx1_3_2 - 1][my2_3_2] = '*';		mapMe[mx1_3_2 - 1][my3_3_2] = '*';
			mapMe[mx1_3_2 - 1][my1_3_2 + 1] = '*';	mapMe[mx1_3_2 + 1][my3_3_2 - 1] = '*';
			mapMe[mx1_3_2 + 1][my1_3_2] = '*';		mapMe[mx1_3_2 + 1][my2_3_2] = '*';
			mapMe[mx1_3_2 + 1][my3_3_2] = '*';		mapMe[mx1_3_2 + 1][my1_3_2 + 1] = '*';
			break;
		}
	}

	if (helpMap[mx1_2_1][my1_2_1] == 'X' && helpMap[mx2_2_1][my2_2_1] == 'X')
	{
		switch (mfact_2_1)
		{
		case 13:
			helpMap[mx1_2_1 - 1][my1_2_1] = '*';		helpMap[mx2_2_1 + 1][my1_2_1] = '*';
			helpMap[mx1_2_1 - 1][my1_2_1 - 1] = '*';	helpMap[mx1_2_1][my1_2_1 - 1] = '*';
			helpMap[mx2_2_1][my1_2_1 - 1] = '*';
			helpMap[mx2_2_1 + 1][my1_2_1 - 1] = '*';	helpMap[mx1_2_1 - 1][my1_2_1 + 1] = '*';
			helpMap[mx1_2_1][my1_2_1 + 1] = '*';
			helpMap[mx2_2_1][my1_2_1 + 1] = '*';		helpMap[mx2_2_1 + 1][my1_2_1 + 1] = '*';

			mapMe[mx1_2_1 - 1][my1_2_1] = '*';		mapMe[mx2_2_1 + 1][my1_2_1] = '*';
			mapMe[mx1_2_1 - 1][my1_2_1 - 1] = '*';	mapMe[mx1_2_1][my1_2_1 - 1] = '*';
			mapMe[mx2_2_1][my1_2_1 - 1] = '*';
			mapMe[mx2_2_1 + 1][my1_2_1 - 1] = '*';	mapMe[mx1_2_1 - 1][my1_2_1 + 1] = '*';
			mapMe[mx1_2_1][my1_2_1 + 1] = '*';
			mapMe[mx2_2_1][my1_2_1 + 1] = '*';		mapMe[mx2_2_1 + 1][my1_2_1 + 1] = '*';
			break;
		case 14:
			helpMap[mx2_2_1 - 1][my1_2_1] = '*';		helpMap[mx1_2_1 + 1][my1_2_1] = '*';
			helpMap[mx2_2_1 - 1][my1_2_1 - 1] = '*';	helpMap[mx1_2_1][my1_2_1 - 1] = '*';
			helpMap[mx2_2_1][my1_2_1 - 1] = '*';
			helpMap[mx1_2_1 + 1][my1_2_1 - 1] = '*';	helpMap[mx2_2_1 - 1][my1_2_1 + 1] = '*';
			helpMap[mx1_2_1][my1_2_1 + 1] = '*';
			helpMap[mx2_2_1][my1_2_1 + 1] = '*';		helpMap[mx1_2_1 + 1][my1_2_1 + 1] = '*';

			mapMe[mx2_2_1 - 1][my1_2_1] = '*';		mapMe[mx1_2_1 + 1][my1_2_1] = '*';
			mapMe[mx2_2_1 - 1][my1_2_1 - 1] = '*';	mapMe[mx1_2_1][my1_2_1 - 1] = '*';
			mapMe[mx2_2_1][my1_2_1 - 1] = '*';
			mapMe[mx1_2_1 + 1][my1_2_1 - 1] = '*';	mapMe[mx2_2_1 - 1][my1_2_1 + 1] = '*';
			mapMe[mx1_2_1][my1_2_1 + 1] = '*';
			mapMe[mx2_2_1][my1_2_1 + 1] = '*';		mapMe[mx1_2_1 + 1][my1_2_1 + 1] = '*';
			break;
		case 23:
			helpMap[mx1_2_1][my1_2_1 - 1] = '*';		helpMap[mx1_2_1][my2_2_1 + 1] = '*';
			helpMap[mx1_2_1 - 1][my1_2_1 - 1] = '*';	helpMap[mx1_2_1 - 1][my1_2_1] = '*';
			helpMap[mx1_2_1 - 1][my2_2_1] = '*';
			helpMap[mx1_2_1 - 1][my2_2_1 + 1] = '*';	helpMap[mx1_2_1 + 1][my1_2_1 - 1] = '*';
			helpMap[mx1_2_1 + 1][my1_2_1] = '*';
			helpMap[mx1_2_1 + 1][my2_2_1] = '*';		helpMap[mx1_2_1 + 1][my2_2_1 + 1] = '*';

			mapMe[mx1_2_1][my1_2_1 - 1] = '*';		mapMe[mx1_2_1][my2_2_1 + 1] = '*';
			mapMe[mx1_2_1 - 1][my1_2_1 - 1] = '*';	mapMe[mx1_2_1 - 1][my1_2_1] = '*';
			mapMe[mx1_2_1 - 1][my2_2_1] = '*';
			mapMe[mx1_2_1 - 1][my2_2_1 + 1] = '*';	mapMe[mx1_2_1 + 1][my1_2_1 - 1] = '*';
			mapMe[mx1_2_1 + 1][my1_2_1] = '*';
			mapMe[mx1_2_1 + 1][my2_2_1] = '*';		mapMe[mx1_2_1 + 1][my2_2_1 + 1] = '*';
			break;
		case 24:
			helpMap[mx1_2_1][my2_2_1 - 1] = '*';		helpMap[mx1_2_1][my1_2_1 + 1] = '*';
			helpMap[mx1_2_1 - 1][my2_2_1 - 1] = '*';	helpMap[mx1_2_1 - 1][my1_2_1] = '*';
			helpMap[mx1_2_1 - 1][my2_2_1] = '*';
			helpMap[mx1_2_1 - 1][my1_2_1 + 1] = '*';	helpMap[mx1_2_1 + 1][my2_2_1 - 1] = '*';
			helpMap[mx1_2_1 + 1][my1_2_1] = '*';
			helpMap[mx1_2_1 + 1][my2_2_1] = '*';		helpMap[mx1_2_1 + 1][my1_2_1 + 1] = '*';

			mapMe[mx1_2_1][my2_2_1 - 1] = '*';		mapMe[mx1_2_1][my1_2_1 + 1] = '*';
			mapMe[mx1_2_1 - 1][my2_2_1 - 1] = '*';	mapMe[mx1_2_1 - 1][my1_2_1] = '*';
			mapMe[mx1_2_1 - 1][my2_2_1] = '*';
			mapMe[mx1_2_1 - 1][my1_2_1 + 1] = '*';	mapMe[mx1_2_1 + 1][my2_2_1 - 1] = '*';
			mapMe[mx1_2_1 + 1][my1_2_1] = '*';
			mapMe[mx1_2_1 + 1][my2_2_1] = '*';		mapMe[mx1_2_1 + 1][my1_2_1 + 1] = '*';
			break;
		}
	}
	if (helpMap[mx1_2_2][my1_2_2] == 'X' && helpMap[mx2_2_2][my2_2_2] == 'X')
	{
		switch (mfact_2_2)
		{
		case 13:
			helpMap[mx1_2_2 - 1][my1_2_2] = '*';		helpMap[mx2_2_2 + 1][my1_2_2] = '*';
			helpMap[mx1_2_2 - 1][my1_2_2 - 1] = '*';	helpMap[mx1_2_2][my1_2_2 - 1] = '*';
			helpMap[mx2_2_2][my1_2_2 - 1] = '*';
			helpMap[mx2_2_2 + 1][my1_2_2 - 1] = '*';	helpMap[mx1_2_2 - 1][my1_2_2 + 1] = '*';
			helpMap[mx1_2_2][my1_2_2 + 1] = '*';
			helpMap[mx2_2_2][my1_2_2 + 1] = '*';		helpMap[mx2_2_2 + 1][my1_2_2 + 1] = '*';

			mapMe[mx1_2_2 - 1][my1_2_2] = '*';		mapMe[mx2_2_2 + 1][my1_2_2] = '*';
			mapMe[mx1_2_2 - 1][my1_2_2 - 1] = '*';	mapMe[mx1_2_2][my1_2_2 - 1] = '*';
			mapMe[mx2_2_2][my1_2_2 - 1] = '*';
			mapMe[mx2_2_2 + 1][my1_2_2 - 1] = '*';	mapMe[mx1_2_2 - 1][my1_2_2 + 1] = '*';
			mapMe[mx1_2_2][my1_2_2 + 1] = '*';
			mapMe[mx2_2_2][my1_2_2 + 1] = '*';		mapMe[mx2_2_2 + 1][my1_2_2 + 1] = '*';
			break;
		case 14:
			helpMap[mx2_2_2 - 1][my1_2_2] = '*';		helpMap[mx1_2_2 + 1][my1_2_2] = '*';
			helpMap[mx2_2_2 - 1][my1_2_2 - 1] = '*';	helpMap[mx1_2_2][my1_2_2 - 1] = '*';
			helpMap[mx2_2_2][my1_2_2 - 1] = '*';
			helpMap[mx1_2_2 + 1][my1_2_2 - 1] = '*';	helpMap[mx2_2_2 - 1][my1_2_2 + 1] = '*';
			helpMap[mx1_2_2][my1_2_2 + 1] = '*';
			helpMap[mx2_2_2][my1_2_2 + 1] = '*';		helpMap[mx1_2_2 + 1][my1_2_2 + 1] = '*';

			mapMe[mx2_2_2 - 1][my1_2_2] = '*';		mapMe[mx1_2_2 + 1][my1_2_2] = '*';
			mapMe[mx2_2_2 - 1][my1_2_2 - 1] = '*';	mapMe[mx1_2_2][my1_2_2 - 1] = '*';
			mapMe[mx2_2_2][my1_2_2 - 1] = '*';
			mapMe[mx1_2_2 + 1][my1_2_2 - 1] = '*';	mapMe[mx2_2_2 - 1][my1_2_2 + 1] = '*';
			mapMe[mx1_2_2][my1_2_2 + 1] = '*';
			mapMe[mx2_2_2][my1_2_2 + 1] = '*';		mapMe[mx1_2_2 + 1][my1_2_2 + 1] = '*';
			break;
		case 23:
			helpMap[mx1_2_2][my1_2_2 - 1] = '*';		helpMap[mx1_2_2][my2_2_2 + 1] = '*';
			helpMap[mx1_2_2 - 1][my1_2_2 - 1] = '*';	helpMap[mx1_2_2 - 1][my1_2_2] = '*';
			helpMap[mx1_2_2 - 1][my2_2_2] = '*';
			helpMap[mx1_2_2 - 1][my2_2_2 + 1] = '*';	helpMap[mx1_2_2 + 1][my1_2_2 - 1] = '*';
			helpMap[mx1_2_2 + 1][my1_2_2] = '*';
			helpMap[mx1_2_2 + 1][my2_2_2] = '*';		helpMap[mx1_2_2 + 1][my2_2_2 + 1] = '*';

			mapMe[mx1_2_2][my1_2_2 - 1] = '*';		mapMe[mx1_2_2][my2_2_2 + 1] = '*';
			mapMe[mx1_2_2 - 1][my1_2_2 - 1] = '*';	mapMe[mx1_2_2 - 1][my1_2_2] = '*';
			mapMe[mx1_2_2 - 1][my2_2_2] = '*';
			mapMe[mx1_2_2 - 1][my2_2_2 + 1] = '*';	mapMe[mx1_2_2 + 1][my1_2_2 - 1] = '*';
			mapMe[mx1_2_2 + 1][my1_2_2] = '*';
			mapMe[mx1_2_2 + 1][my2_2_2] = '*';		mapMe[mx1_2_2 + 1][my2_2_2 + 1] = '*';
			break;
		case 24:
			helpMap[mx1_2_2][my2_2_2 - 1] = '*';		helpMap[mx1_2_2][my1_2_2 + 1] = '*';
			helpMap[mx1_2_2 - 1][my2_2_2 - 1] = '*';	helpMap[mx1_2_2 - 1][my1_2_2] = '*';
			helpMap[mx1_2_2 - 1][my2_2_2] = '*';
			helpMap[mx1_2_2 - 1][my1_2_2 + 1] = '*';	helpMap[mx1_2_2 + 1][my2_2_2 - 1] = '*';
			helpMap[mx1_2_2 + 1][my1_2_2] = '*';
			helpMap[mx1_2_2 + 1][my2_2_2] = '*';		helpMap[mx1_2_2 + 1][my1_2_2 + 1] = '*';

			mapMe[mx1_2_2][my2_2_2 - 1] = '*';		mapMe[mx1_2_2][my1_2_2 + 1] = '*';
			mapMe[mx1_2_2 - 1][my2_2_2 - 1] = '*';	mapMe[mx1_2_2 - 1][my1_2_2] = '*';
			mapMe[mx1_2_2 - 1][my2_2_2] = '*';
			mapMe[mx1_2_2 - 1][my1_2_2 + 1] = '*';	mapMe[mx1_2_2 + 1][my2_2_2 - 1] = '*';
			mapMe[mx1_2_2 + 1][my1_2_2] = '*';
			mapMe[mx1_2_2 + 1][my2_2_2] = '*';		mapMe[mx1_2_2 + 1][my1_2_2 + 1] = '*';
			break;
		}
	}
	if (helpMap[mx1_2_3][my1_2_3] == 'X' && helpMap[mx2_2_3][my2_2_3] == 'X')
	{
		switch (mfact_2_3)
		{
		case 13:
			helpMap[mx1_2_3 - 1][my1_2_3] = '*';		helpMap[mx2_2_3 + 1][my1_2_3] = '*';
			helpMap[mx1_2_3 - 1][my1_2_3 - 1] = '*';	helpMap[mx1_2_3][my1_2_3 - 1] = '*';
			helpMap[mx2_2_3][my1_2_3 - 1] = '*';
			helpMap[mx2_2_3 + 1][my1_2_3 - 1] = '*';	helpMap[mx1_2_3 - 1][my1_2_3 + 1] = '*';
			helpMap[mx1_2_3][my1_2_3 + 1] = '*';
			helpMap[mx2_2_3][my1_2_3 + 1] = '*';		helpMap[mx2_2_3 + 1][my1_2_3 + 1] = '*';

			mapMe[mx1_2_3 - 1][my1_2_3] = '*';		mapMe[mx2_2_3 + 1][my1_2_3] = '*';
			mapMe[mx1_2_3 - 1][my1_2_3 - 1] = '*';	mapMe[mx1_2_3][my1_2_3 - 1] = '*';
			mapMe[mx2_2_3][my1_2_3 - 1] = '*';
			mapMe[mx2_2_3 + 1][my1_2_3 - 1] = '*';	mapMe[mx1_2_3 - 1][my1_2_3 + 1] = '*';
			mapMe[mx1_2_3][my1_2_3 + 1] = '*';
			mapMe[mx2_2_3][my1_2_3 + 1] = '*';		mapMe[mx2_2_3 + 1][my1_2_3 + 1] = '*';
			break;
		case 14:
			helpMap[mx2_2_3 - 1][my1_2_3] = '*';		helpMap[mx1_2_3 + 1][my1_2_3] = '*';
			helpMap[mx2_2_3 - 1][my1_2_3 - 1] = '*';	helpMap[mx1_2_3][my1_2_3 - 1] = '*';
			helpMap[mx2_2_3][my1_2_3 - 1] = '*';
			helpMap[mx1_2_3 + 1][my1_2_3 - 1] = '*';	helpMap[mx2_2_3 - 1][my1_2_3 + 1] = '*';
			helpMap[mx1_2_3][my1_2_3 + 1] = '*';
			helpMap[mx2_2_3][my1_2_3 + 1] = '*';		helpMap[mx1_2_3 + 1][my1_2_3 + 1] = '*';

			mapMe[mx2_2_3 - 1][my1_2_3] = '*';		mapMe[mx1_2_3 + 1][my1_2_3] = '*';
			mapMe[mx2_2_3 - 1][my1_2_3 - 1] = '*';	mapMe[mx1_2_3][my1_2_3 - 1] = '*';
			mapMe[mx2_2_3][my1_2_3 - 1] = '*';
			mapMe[mx1_2_3 + 1][my1_2_3 - 1] = '*';	mapMe[mx2_2_3 - 1][my1_2_3 + 1] = '*';
			mapMe[mx1_2_3][my1_2_3 + 1] = '*';
			mapMe[mx2_2_3][my1_2_3 + 1] = '*';		mapMe[mx1_2_3 + 1][my1_2_3 + 1] = '*';
			break;
		case 23:
			helpMap[mx1_2_3][my1_2_3 - 1] = '*';		helpMap[mx1_2_3][my2_2_3 + 1] = '*';
			helpMap[mx1_2_3 - 1][my1_2_3 - 1] = '*';	helpMap[mx1_2_3 - 1][my1_2_3] = '*';
			helpMap[mx1_2_3 - 1][my2_2_3] = '*';
			helpMap[mx1_2_3 - 1][my2_2_3 + 1] = '*';	helpMap[mx1_2_3 + 1][my1_2_3 - 1] = '*';
			helpMap[mx1_2_3 + 1][my1_2_3] = '*';
			helpMap[mx1_2_3 + 1][my2_2_3] = '*';		helpMap[mx1_2_3 + 1][my2_2_3 + 1] = '*';

			mapMe[mx1_2_3][my1_2_3 - 1] = '*';		mapMe[mx1_2_3][my2_2_3 + 1] = '*';
			mapMe[mx1_2_3 - 1][my1_2_3 - 1] = '*';	mapMe[mx1_2_3 - 1][my1_2_3] = '*';
			mapMe[mx1_2_3 - 1][my2_2_3] = '*';
			mapMe[mx1_2_3 - 1][my2_2_3 + 1] = '*';	mapMe[mx1_2_3 + 1][my1_2_3 - 1] = '*';
			mapMe[mx1_2_3 + 1][my1_2_3] = '*';
			mapMe[mx1_2_3 + 1][my2_2_3] = '*';		mapMe[mx1_2_3 + 1][my2_2_3 + 1] = '*';
			break;
		case 24:
			helpMap[mx1_2_3][my2_2_3 - 1] = '*';		helpMap[mx1_2_3][my1_2_3 + 1] = '*';
			helpMap[mx1_2_3 - 1][my2_2_3 - 1] = '*';	helpMap[mx1_2_3 - 1][my1_2_3] = '*';
			helpMap[mx1_2_3 - 1][my2_2_3] = '*';
			helpMap[mx1_2_3 - 1][my1_2_3 + 1] = '*';	helpMap[mx1_2_3 + 1][my2_2_3 - 1] = '*';
			helpMap[mx1_2_3 + 1][my1_2_3] = '*';
			helpMap[mx1_2_3 + 1][my2_2_3] = '*';		helpMap[mx1_2_3 + 1][my1_2_3 + 1] = '*';

			mapMe[mx1_2_3][my2_2_3 - 1] = '*';		mapMe[mx1_2_3][my1_2_3 + 1] = '*';
			mapMe[mx1_2_3 - 1][my2_2_3 - 1] = '*';	mapMe[mx1_2_3 - 1][my1_2_3] = '*';
			mapMe[mx1_2_3 - 1][my2_2_3] = '*';
			mapMe[mx1_2_3 - 1][my1_2_3 + 1] = '*';	mapMe[mx1_2_3 + 1][my2_2_3 - 1] = '*';
			mapMe[mx1_2_3 + 1][my1_2_3] = '*';
			mapMe[mx1_2_3 + 1][my2_2_3] = '*';		mapMe[mx1_2_3 + 1][my1_2_3 + 1] = '*';
			break;
		}
	}

	if (helpMap[mx1_1_1][my1_1_1] == 'X')
	{
		helpMap[mx1_1_1 - 1][my1_1_1 - 1] = '*';
		helpMap[mx1_1_1][my1_1_1 - 1] = '*';
		helpMap[mx1_1_1 + 1][my1_1_1 - 1] = '*';
		helpMap[mx1_1_1 - 1][my1_1_1 + 1] = '*';
		helpMap[mx1_1_1][my1_1_1 + 1] = '*';
		helpMap[mx1_1_1 + 1][my1_1_1 + 1] = '*';
		helpMap[mx1_1_1 - 1][my1_1_1] = '*';
		helpMap[mx1_1_1 + 1][my1_1_1] = '*';

		mapMe[mx1_1_1 - 1][my1_1_1 - 1] = '*';
		mapMe[mx1_1_1][my1_1_1 - 1] = '*';
		mapMe[mx1_1_1 + 1][my1_1_1 - 1] = '*';
		mapMe[mx1_1_1 - 1][my1_1_1 + 1] = '*';
		mapMe[mx1_1_1][my1_1_1 + 1] = '*';
		mapMe[mx1_1_1 + 1][my1_1_1 + 1] = '*';
		mapMe[mx1_1_1 - 1][my1_1_1] = '*';
		mapMe[mx1_1_1 + 1][my1_1_1] = '*';
	}
	if (helpMap[mx1_1_2][my1_1_2] == 'X')
	{
		helpMap[mx1_1_2 - 1][my1_1_2 - 1] = '*';
		helpMap[mx1_1_2][my1_1_2 - 1] = '*';
		helpMap[mx1_1_2 + 1][my1_1_2 - 1] = '*';
		helpMap[mx1_1_2 - 1][my1_1_2 + 1] = '*';
		helpMap[mx1_1_2][my1_1_2 + 1] = '*';
		helpMap[mx1_1_2 + 1][my1_1_2 + 1] = '*';
		helpMap[mx1_1_2 - 1][my1_1_2] = '*';
		helpMap[mx1_1_2 + 1][my1_1_2] = '*';

		mapMe[mx1_1_2 - 1][my1_1_2 - 1] = '*';
		mapMe[mx1_1_2][my1_1_2 - 1] = '*';
		mapMe[mx1_1_2 + 1][my1_1_2 - 1] = '*';
		mapMe[mx1_1_2 - 1][my1_1_2 + 1] = '*';
		mapMe[mx1_1_2][my1_1_2 + 1] = '*';
		mapMe[mx1_1_2 + 1][my1_1_2 + 1] = '*';
		mapMe[mx1_1_2 - 1][my1_1_2] = '*';
		mapMe[mx1_1_2 + 1][my1_1_2] = '*';
	}
	if (helpMap[mx1_1_3][my1_1_3] == 'X')
	{
		helpMap[mx1_1_3 - 1][my1_1_3 - 1] = '*';
		helpMap[mx1_1_3][my1_1_3 - 1] = '*';
		helpMap[mx1_1_3 + 1][my1_1_3 - 1] = '*';
		helpMap[mx1_1_3 - 1][my1_1_3 + 1] = '*';
		helpMap[mx1_1_3][my1_1_3 + 1] = '*';
		helpMap[mx1_1_3 + 1][my1_1_3 + 1] = '*';
		helpMap[mx1_1_3 - 1][my1_1_3] = '*';
		helpMap[mx1_1_3 + 1][my1_1_3] = '*';

		mapMe[mx1_1_3 - 1][my1_1_3 - 1] = '*';
		mapMe[mx1_1_3][my1_1_3 - 1] = '*';
		mapMe[mx1_1_3 + 1][my1_1_3 - 1] = '*';
		mapMe[mx1_1_3 - 1][my1_1_3 + 1] = '*';
		mapMe[mx1_1_3][my1_1_3 + 1] = '*';
		mapMe[mx1_1_3 + 1][my1_1_3 + 1] = '*';
		mapMe[mx1_1_3 - 1][my1_1_3] = '*';
		mapMe[mx1_1_3 + 1][my1_1_3] = '*';
	}
	if (helpMap[mx1_1_4][my1_1_4] == 'X')
	{
		helpMap[mx1_1_4 - 1][my1_1_4 - 1] = '*';
		helpMap[mx1_1_4][my1_1_4 - 1] = '*';
		helpMap[mx1_1_4 + 1][my1_1_4 - 1] = '*';
		helpMap[mx1_1_4 - 1][my1_1_4 + 1] = '*';
		helpMap[mx1_1_4][my1_1_4 + 1] = '*';
		helpMap[mx1_1_4 + 1][my1_1_4 + 1] = '*';
		helpMap[mx1_1_4 - 1][my1_1_4] = '*';
		helpMap[mx1_1_4 + 1][my1_1_4] = '*';

		mapMe[mx1_1_4 - 1][my1_1_4 - 1] = '*';
		mapMe[mx1_1_4][my1_1_4 - 1] = '*';
		mapMe[mx1_1_4 + 1][my1_1_4 - 1] = '*';
		mapMe[mx1_1_4 - 1][my1_1_4 + 1] = '*';
		mapMe[mx1_1_4][my1_1_4 + 1] = '*';
		mapMe[mx1_1_4 + 1][my1_1_4 + 1] = '*';
		mapMe[mx1_1_4 - 1][my1_1_4] = '*';
		mapMe[mx1_1_4 + 1][my1_1_4] = '*';
	}
}

// функция процесса игры
void play(PlayerField myMap, EnemyField enMap, EnemyField en1Map, int meHelp[12][12])
{
	bool flagPlay = true;
	char stepX;
	int stepY;
	int shipAmountMe = 20;
	int shipAmountEnemy = 20;
	char helpMap[12][12];
	for (int j = 0; j < 12; j++)
		for (int i = 0; i < 12; i++)
			helpMap[i][j] = ' ';
	int stepXComp;
	int stepYComp;
	bool flagRepeat = false;
	int tempX;
	int tempY;
	int tempX1Comp;
	int tempY1Comp;
	int tempX2Comp;
	int tempY2Comp;
	int dir = 0;
	int k = 0;

	while (shipAmountEnemy != 0 && shipAmountMe != 0)
	{
		if (flagPlay)	// ходит пользователь
		{
			cout << "Ваш ход. Введите координату клетки, по которой хотите ударить (например, b4), и нажмите клавишу Enter:" << endl;
			cin >> stepX >> stepY;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());

			while ((stepX < 'a' || stepX > 'j') || (stepY < 1 || stepY > 10) || (enMap.map[(char)stepX - 96][stepY] == 'X') || (enMap.map[(char)stepX - 96][stepY] == '*'))
			{
				system("cls");
				myMap.printMap();
				en1Map.printMap();

				cout << "Вы указали неверную координату! Введите координату заново." << endl;
				cout << "Введите координату клетки, по которой хотите ударить (например, b4), и нажмите клавишу Enter:" << endl;
				cin >> stepX >> stepY;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
			}

			if (enMap.map[(char)stepX - 96][stepY] == ' ')
			{
				enMap.map[(int)stepX - 96][stepY] = '*';
				en1Map.map[(int)stepX - 96][stepY] = '*';

				system("cls");
				myMap.printMap();
				en1Map.printMap();

				cout << "Мимо!" << endl;
				flagPlay = false;
			}
			else if (enMap.map[(char)stepX - 96][stepY] == '#')
			{
				enMap.map[(int)stepX - 96][stepY] = 'X';
				en1Map.map[(int)stepX - 96][stepY] = 'X';
				checkDeadOfComp(enMap, en1Map, enMap.map, en1Map.map);

				system("cls");
				myMap.printMap();
				en1Map.printMap();

				shipAmountEnemy--;
				cout << "Вы попали!" << endl;
				flagPlay = true;
			}
		}

		if (flagRepeat && !flagPlay && shipAmountMe != 0 && shipAmountEnemy != 0)	// ходит компьютер
		{
			if (meHelp[tempX][tempY] == 2)
			{
				stepXComp = rand() % 10 + 1;
				stepYComp = rand() % 10 + 1;

				while (!(((stepXComp == tempX - 1 && stepYComp == tempY) || (stepXComp == tempX && stepYComp == tempY - 1) || (stepXComp == tempX && stepYComp == tempY + 1) || (stepXComp == tempX + 1 && stepYComp == tempY)) &&
					(stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
				{
					stepXComp = rand() % 10 + 1;
					stepYComp = rand() % 10 + 1;
				}

				cout << "Компьютер бьёт по клетке " << (char)(stepXComp + 96) << stepYComp << endl;
				system("pause");
				if (myMap.map[stepXComp][stepYComp] == ' ')
				{
					helpMap[stepXComp][stepYComp] = '*';
					myMap.map[stepXComp][stepYComp] = '*';

					system("cls");
					myMap.printMap();
					en1Map.printMap();

					cout << "Компьютер промахнулся!" << endl;
					flagPlay = true;
					flagRepeat = true;
				}
				else if (myMap.map[stepXComp][stepYComp] == '#')
				{
					helpMap[stepXComp][stepYComp] = 'X';
					myMap.map[stepXComp][stepYComp] = 'X';
					checkDeadOfMe(myMap, myMap.map, helpMap);

					system("cls");
					myMap.printMap();
					en1Map.printMap();

					shipAmountMe--;
					cout << "Компьютер попал" << endl;
					flagPlay = false;
					flagRepeat = false;
				}
			}

			else if (meHelp[tempX][tempY] == 3)
			{
				stepXComp = rand() % 10 + 1;
				stepYComp = rand() % 10 + 1;

				if (dir == 1)
					while (!(((stepXComp == tempX1Comp && stepYComp == tempY1Comp + 1) || (stepXComp == tempX1Comp && stepYComp == tempY1Comp - 1) || ((stepXComp == tempX1Comp && stepYComp == tempY1Comp + 2) && (tempY1Comp < tempY)) || ((stepXComp == tempX1Comp && stepYComp == tempY1Comp - 2) && (tempY1Comp > tempY))) &&
						(stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
					{
						stepXComp = rand() % 10 + 1;
						stepYComp = rand() % 10 + 1;
					}
				else if (dir == 2)
					while (!(((stepXComp == tempX1Comp - 1 && stepYComp == tempY1Comp) || (stepXComp == tempX1Comp + 1 && stepYComp == tempY1Comp) || ((stepXComp == tempX1Comp - 2 && stepYComp == tempY1Comp) && (tempX1Comp > tempX)) || ((stepXComp == tempX1Comp + 2 && stepYComp == tempY1Comp) && (tempX1Comp < tempX))) &&
						(stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
					{
						stepXComp = rand() % 10 + 1;
						stepYComp = rand() % 10 + 1;
					}
				else
					while (!(((stepXComp == tempX - 1 && stepYComp == tempY) || (stepXComp == tempX + 1 && stepYComp == tempY) || (stepXComp == tempX && stepYComp == tempY - 1) || (stepXComp == tempX && stepYComp == tempY + 1)) &&
						(stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
					{
						stepXComp = rand() % 10 + 1;
						stepYComp = rand() % 10 + 1;
					}

				cout << "Компьютер бьёт по клетке " << (char)(stepXComp + 96) << stepYComp << endl;
				system("pause");
				if (myMap.map[stepXComp][stepYComp] == ' ')
				{
					helpMap[stepXComp][stepYComp] = '*';
					myMap.map[stepXComp][stepYComp] = '*';

					system("cls");
					myMap.printMap();
					en1Map.printMap();

					cout << "Компьютер промахнулся, теперь Ваш ход!" << endl;
					flagPlay = true;
					flagRepeat = true;
				}
				else if (myMap.map[stepXComp][stepYComp] == '#')
				{
					helpMap[stepXComp][stepYComp] = 'X';
					myMap.map[stepXComp][stepYComp] = 'X';
					checkDeadOfMe(myMap, myMap.map, helpMap);

					system("cls");
					myMap.printMap();
					en1Map.printMap();

					shipAmountMe--;
					cout << "Компьютер попал" << endl;
					k++;
					tempX1Comp = stepXComp;
					tempY1Comp = stepYComp;

					if (tempX == tempX1Comp) dir = 1; // корабль стоит вертикально
					else if (tempY == tempY1Comp) dir = 2; // корабль стоит горизонтально
					flagPlay = false;
					flagRepeat = true;
				}
				if (k == 2)
				{
					flagRepeat = false;
					k = 0;
					dir = 0;
				}
			}

			else if (meHelp[tempX][tempY] == 4)
			{
				stepXComp = rand() % 10 + 1;
				stepYComp = rand() % 10 + 1;

				if (dir == 1 && k == 2)
					while (!(((stepXComp == tempX2Comp && stepYComp == tempY2Comp - 1 && tempY2Comp < tempY1Comp) || (stepXComp == tempX2Comp && stepYComp == tempY2Comp + 3 && tempY2Comp < tempY1Comp) ||
						(stepXComp == tempX2Comp && stepYComp == tempY2Comp + 1 && tempY2Comp > tempY1Comp) || (stepXComp == tempX2Comp && stepYComp == tempY2Comp - 3 && tempY2Comp > tempY1Comp)) &&
						(stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
					{
						stepXComp = rand() % 10 + 1;
						stepYComp = rand() % 10 + 1;
					}
				else if (dir == 2 && k == 2)
					while (!(((stepXComp == tempX2Comp - 1 && stepYComp == tempY2Comp && tempX2Comp < tempX1Comp) || (stepXComp == tempX2Comp + 3 && stepYComp == tempY2Comp && tempX2Comp < tempX1Comp) ||
						(stepXComp == tempX2Comp + 1 && stepYComp == tempY2Comp && tempX2Comp > tempX1Comp) || (stepXComp == tempX2Comp - 3 && stepYComp == tempY2Comp && tempX2Comp > tempX1Comp)) &&
						(stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
					{
						stepXComp = rand() % 10 + 1;
						stepYComp = rand() % 10 + 1;
					}

				else if (dir == 1 && k == 1)
					while (!(((stepXComp == tempX1Comp && stepYComp == tempY1Comp + 1 && tempY1Comp > tempY) || (stepXComp == tempX1Comp && stepYComp == tempY1Comp - 1 && tempY1Comp < tempY) ||
						(stepXComp == tempX1Comp && stepYComp == tempY1Comp - 2 && tempY1Comp > tempY) || (stepXComp == tempX1Comp && stepYComp == tempY1Comp + 2 && tempY1Comp < tempY)) &&
						(stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
					{
						stepXComp = rand() % 10 + 1;
						stepYComp = rand() % 10 + 1;
					}
				else if (dir == 2 && k == 1)
					while (!(((stepXComp == tempX1Comp - 1 && stepYComp == tempY1Comp && tempX1Comp < tempX) || (stepXComp == tempX1Comp + 1 && stepYComp == tempY1Comp && tempX1Comp > tempX) ||
						(stepXComp == tempX1Comp + 2 && stepYComp == tempY1Comp && tempX1Comp < tempX) || (stepXComp == tempX1Comp - 2 && stepYComp == tempY1Comp && tempX1Comp > tempX)) &&
						(stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
					{
						stepXComp = rand() % 10 + 1;
						stepYComp = rand() % 10 + 1;
					}
				else
					while (!(((stepXComp == tempX - 1 && stepYComp == tempY) || (stepXComp == tempX + 1 && stepYComp == tempY) || (stepXComp == tempX && stepYComp == tempY - 1) || (stepXComp == tempX && stepYComp == tempY + 1)) &&
						(stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
					{
						stepXComp = rand() % 10 + 1;
						stepYComp = rand() % 10 + 1;
					}

				cout << "Компьютер бьёт по клетке " << (char)(stepXComp + 96) << stepYComp << endl;
				system("pause");
				if (myMap.map[stepXComp][stepYComp] == ' ')
				{
					helpMap[stepXComp][stepYComp] = '*';
					myMap.map[stepXComp][stepYComp] = '*';

					system("cls");
					myMap.printMap();
					en1Map.printMap();

					cout << "Компьютер промахнулся, теперь Ваш ход!" << endl;
					flagPlay = true;
					flagRepeat = true;
				}
				else if (myMap.map[stepXComp][stepYComp] == '#')
				{
					helpMap[stepXComp][stepYComp] = 'X';
					myMap.map[stepXComp][stepYComp] = 'X';
					checkDeadOfMe(myMap, myMap.map, helpMap);

					system("cls");
					myMap.printMap();
					en1Map.printMap();

					shipAmountMe--;
					cout << "Компьютер попал" << endl;
					k++;
					if (k == 1)
					{
						tempX1Comp = stepXComp;
						tempY1Comp = stepYComp;
					}
					else if (k == 2)
					{
						tempX2Comp = stepXComp;
						tempY2Comp = stepYComp;
					}

					if (tempX == tempX1Comp) dir = 1; // корабль стоит вертикально
					else if (tempY == tempY1Comp) dir = 2; // корабль стоит горизонтально
					flagPlay = false;
					flagRepeat = true;
				}
				if (k == 3)
				{
					flagRepeat = false;
					k = 0;
					dir = 0;
				}
			}

			else flagRepeat = false;
		}

		if (!flagPlay && !flagRepeat  && shipAmountMe != 0 && shipAmountEnemy != 0)	// ходит компьютер
		{
			stepXComp = rand() % 10 + 1;
			stepYComp = rand() % 10 + 1;

			while (!((stepXComp >= 1 && stepXComp <= 10) && (stepYComp >= 1 && stepYComp <= 10) && helpMap[stepXComp][stepYComp] == ' '))
			{
				stepXComp = rand() % 10 + 1;
				stepYComp = rand() % 10 + 1;
			}

			cout << "Компьютер бьёт по клетке " << (char)(stepXComp + 96) << stepYComp << endl;
			system("pause");
			if (myMap.map[stepXComp][stepYComp] == ' ')
			{
				helpMap[stepXComp][stepYComp] = '*';
				myMap.map[stepXComp][stepYComp] = '*';

				system("cls");
				myMap.printMap();
				en1Map.printMap();

				cout << "Компьютер промахнулся!" << endl;
				flagPlay = true;
				flagRepeat = false;
			}
			else if (myMap.map[stepXComp][stepYComp] == '#')
			{
				helpMap[stepXComp][stepYComp] = 'X';
				myMap.map[stepXComp][stepYComp] = 'X';
				checkDeadOfMe(myMap, myMap.map, helpMap);

				system("cls");
				myMap.printMap();
				en1Map.printMap();

				shipAmountMe--;
				cout << "Компьютер попал" << endl;
				flagPlay = false;
				flagRepeat = true;
				tempX = stepXComp;
				tempY = stepYComp;
			}
		}
	}

	if (shipAmountMe == 0)
	{
		system("cls");
		myMap.printMap();
		enMap.printMap();
		cout << "ПОБЕДИЛ КОМПЬЮТЕР. Не расстраивайтесь, Вы достойно боролись!";
	}
	if (shipAmountEnemy == 0)
	{
		system("cls");
		myMap.printMap();
		enMap.printMap();
		cout << "ВЫ ПОБЕДИЛИ! Примите поздравления!";
	}
}

void service()	// служебная функция
{
	setlocale(0, "Rus");
	const int NotUsed = system("color 17");
	system("mode con lines=50 cols=137");
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 400, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	srand(time(NULL));


	cout << "\n \n \n \n \n \n \n \n \n \n       ========== " << "ПОЖАЛУЙСТА, ОЗНАКОМЬТЕСЬ С ИНСТРУКЦИЕЙ ПЕРЕД НАЧАЛОМ ИГРЫ " << "==========" << "\n \n \n \n";
	system("pause");

	system("cls");
	cout << "\n\n\n       ========== " << "ПОЖАЛУЙСТА, ОЗНАКОМЬТЕСЬ С ИНСТРУКЦИЕЙ ПЕРЕД НАЧАЛОМ ИГРЫ " << "==========" << endl << endl << endl;
	cout << "                                    Игра \"Морской бой\" " << endl << endl;
	cout << "Суть игры заключается в том, что каждый из игроков расставляет корабли на поле 10х10" << endl;
	cout << "и по очереди называет координату клетки поля противника с целью попасть в корабль." << endl << endl;
	cout << "Если игрок попадает по кораблю, клетка помечается крестиком, а игрок имеет возможность" << endl;
	cout << "сделать ещё один ход. Если игрок попадает по пустому полю, оно помечается точкой и" << endl;
	cout << "ход переходит противнику." << endl;
	cout << "Игра заканчивается тогда, когда все корабли одного из игроков окажутся потопленными." << endl << endl;
	cout << "=================================================================================================" << endl << endl;
	cout << "Сначала Вам будет предложено расставить корабли. Расстановка происходит следующим образом: " << endl;
	cout << "Вам необходимо будет по очереди вводить координаты начала и координаты конца каждого из кораблей." << endl;
	cout << "После ввода координат корабль появляется на поле. Перед Вами будет два поля: Ваше и" << endl;
	cout << "поле компьютера, на котором будут отмечаться Ваши ходы. В случае поражения в конце игры" << endl;
	cout << "Вы увидите поле компьютера, чтобы удостовериться, в каких местах стояли неубитые корабли." << endl;
	cout << "В ходе игры Вам будет предложено вводить координаты клетки, по которой вы хотите ударить." << endl << endl;
	cout << "Корабли обозначаются символом \'#\', потопленная часть корабля обозначается символом \'X\'," << endl;
	cout << "свободная клетка, по которой был сделан выстрел, обозначается символом \'*\'." << endl;
	cout << "Если корабль потоплен, то он по краям помечается символом \'*\'." << endl;
	cout << "Все буквенные координаты должны вводится латинскими символами." << endl << endl;
	cout << "Если Вы готовы начать игру, нажмите любую кнопку. Удачи!" << endl << endl;
	cout << "=================================================================================================" << endl << endl;
	cout << "РТУ МИРЭА, автор: Дмитрий Терентьев, ИКБО-03-18, 2019 г." << endl;
	cout << "\n \n \n \n \n \n \n \n \n \n";
	system("pause");
}



int main(int argc, char** argv)
{
	char pl;
	while (true)
	{
		service();

		PlayerField myMap;
		EnemyField en1Map; // поле противника глазами игрока
		EnemyField enMap; // реальное поле противника, невидимое для игрока

		system("cls"); // функция очистки консоли
		myMap.printMap();
		en1Map.printMap();


		// расстановка кораблей игроком
		checkMy4(myMap, en1Map, myMap.map, myMap.meHelp);
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		checkMy3_1(myMap, en1Map, myMap.map, myMap.meHelp);
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		checkMy3_2(myMap, en1Map, myMap.map, myMap.meHelp);
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		checkMy2_1(myMap, en1Map, myMap.map, myMap.meHelp);
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		checkMy2_2(myMap, en1Map, myMap.map, myMap.meHelp);
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		checkMy2_3(myMap, en1Map, myMap.map, myMap.meHelp);
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		checkMy1_1(myMap, en1Map, myMap.map);
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		checkMy1_2(myMap, en1Map, myMap.map);
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		checkMy1_3(myMap, en1Map, myMap.map);
		system("cls");
		myMap.printMap();
		en1Map.printMap();

		checkMy1_4(myMap, en1Map, myMap.map);
		system("cls");
		myMap.printMap();
		en1Map.printMap();


		// расстановка кораблей компьютером
		set432ByComp(enMap, enMap.map, 4, 1);
		set432ByComp(enMap, enMap.map, 3, 1);
		set432ByComp(enMap, enMap.map, 3, 2);
		set432ByComp(enMap, enMap.map, 2, 1);
		set432ByComp(enMap, enMap.map, 2, 2);
		set432ByComp(enMap, enMap.map, 2, 3);
		set1ByComp(enMap, enMap.map, 1);
		set1ByComp(enMap, enMap.map, 2);
		set1ByComp(enMap, enMap.map, 3);
		set1ByComp(enMap, enMap.map, 4);


		// функция процесса игры
		play(myMap, enMap, en1Map, myMap.meHelp);


		// окончание игры
		cout << "\n\nЕсли Вы хотите начать заново, введите 1. \nЕсли Вы хотите выйти из игры, введите 0." << endl;
		pl = _getch(); cout << pl;
		while (pl != '0' && pl != '1')
		{
			system("cls");
			cout << "Вы можете ввести только 0 или 1. Повторите ввод." << endl;
			cout << "\n\nЕсли Вы хотите начать заново, введите 1. \nЕсли Вы хотите выйти из игры, введите 0." << endl;
			pl = _getch(); cout << pl;
		}
		if (pl == '1')
			continue;
		else if (pl == '0')
		{
			cout << endl;
			return 0;
		}
	}
}