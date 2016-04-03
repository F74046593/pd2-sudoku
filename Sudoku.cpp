#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Sudoku.h"
using namespace std;


Sudoku::Sudoku()
{               
	int row = 9;
	int col = 9;
	for(int i = 0;i < row;i++)
		for(int j =0;j < col;j++)
		{
			map[i][j] = 0;
		}
	}
	
void Sudoku::giveQuestion()
{
	int sudoku[9][9] =
	{
	0,4,0,2,1,0,0,0,0,
	8,0,7,0,0,0,0,9,0,
	2,0,0,8,0,0,4,0,1,
	3,0,0,0,0,2,9,0,5,
	0,0,5,7,0,8,6,0,0,
	7,0,6,5,0,0,0,0,4,
	5,0,1,0,0,4,0,0,9,
	0,6,0,0,0,0,7,0,8,
	0,0,0,0,2,7,0,5,0,
	};
	printOut(sudoku);
}

void Sudoku::readIn()
{
	char in[9][9];
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		{
			cin>>in[i][j];
			map[i][j] = in[i][j] - '0';
		}	
	}
}

void Sudoku::solve()
{
	sign = false;
	ANS(0);
	cout<<"1"<<"\n";
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		cout<<map[i][j]<<" ";
		cout<<endl;
	}
}

bool Sudoku::Check(int n, int key)
{
	for (int i = 0; i < 9; i++)
	{
		int j = n / 9;
		if (map[j][i] == key) return false;
	}
	for (int i = 0; i < 9; i++)
	{
		int j = n % 9;
		if (map[i][j] == key) return false;
	}
		int x = n / 9 / 3 * 3;
		int y = n % 9 / 3 * 3;
		for (int i = x; i < x + 3; i++)
		{
			for (int j = y; j < y + 3; j++)
			{
				if (map[i][j] == key) return false;
			}
		}
		return true;
}

int Sudoku::ANS(int n)
{
	if (n > 80)
	{
		sign = true;
		return 0;
	}
	if (map[n/9][n%9] != 0)
	{
		ANS(n+1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (Check(n, i) == true)
			{
				map[n/9][n%9] = i;
				ANS(n+1);
				if (sign == true) return 0;
				map[n/9][n%9] = 0;
			}
		}
	}
}  


void Sudoku::changeNum(int a,int b)
{
	if(a == b)
	return;
	if(a == 0||b == 0)
	return;
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		{
		if(map[i][j] == a)
		map[i][j] = b;
		else if(map[i][j] == b)
		map[i][j] = a;
		}
	}
}

void Sudoku::changeCol(int a,int b)
{
	if(a == b)
	return;
	int col;
	for(int i = 0;i < 9;i++)
	for(int j = 0;j < 3;j++)
	{
		col = map[i][a * 3 + j];
		map[i][a * 3 + j] = map[i][b * 3 + j];
		map[i][b * 3 + j] = col;
	}
}


void Sudoku::changeRow(int a,int b)
{
	if(a == b)
	return;
	int row;
	for(int i = 0;i < 3;i++)
		for(int j = 0;j < 9;j++)
		{
			row = map[a * 3 + i][j];
			map[a * 3 + i][j] = map[b * 3 + i][j];
			map[b * 3 + i][j] = row;
		}
}


void Sudoku::rotate(int n)
{
	int num;
	n = n % 4;
	for(int times = 0;times < n;times++)
	{
		for(int i = 0;i < 9;i++)
		{
			for(int j = 0;j < 4;j++)
			{
				num = map[i][j];
				map[i][j] = map[i][8 - j];
				map[i][8 - j] =num;
			}
		}
		for(int i = 0;i < 9;i++)
		{
			for(int j = 0;j < 9;j++)
			{
				num = map[i][j];
				map[i][j] = map[j][i];
				map[j][i] = num;
			}
		}
	}                   
}


void Sudoku::flip(int n)
{
	int num;
		for(n = 0;n <= 1;n++)
		{
			if(n == 0)
			{
				for(int i = 0;i < 4;i++)
				{
					for(int j = 0; j < 9;j++)
					{
						num = map[i][j];
						map[i][j] = map[8 - i][j];
						map[8 - i][j] = num;
					}
				}
			}
			else if(n == 1)
			{
				for(int i = 0;i < 9;i++)
				{
					for(int j = 0;j < 4;j++)
					{
						num = map[i][j];
						map[i][j] = map[i][8 - j];
						map[i][8 - j] = num;
					}
				}
			}
	}
}


void Sudoku::transform()
{
	readIn();
	change();
	printOut(map);
}


void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand() % 10,rand() % 10);
	changeCol(rand() % 3,rand() % 3);
	changeRow(rand() % 3,rand() % 3);
	rotate(rand() % 101);
	flip(rand() % 2);
}


void Sudoku::printOut(int arr[9][9])
{
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		{
			cout<<arr[i][j]<<" ";
			cout<<"\n";
		}
	}
}
