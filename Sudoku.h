#include<iostream>
using namespace std;

class Sudoku{
      public:
	  	 Sudoku();
		 void giveQuestion();
		 void readIn();
		 void solve();
		 void changeNum(int a, int b);
		 void changeRow(int a, int b);
		 void changeCol(int a, int b);
		 void rotate(int n);
		 void flip(int n);
		 void transform();
		 void printOut(int arr[9][9]);
		 void change();
		 bool Check(int n,int key);
		 int ANS(int n);
		 private:
		 int map[9][9];
		 bool sign;
		 };
