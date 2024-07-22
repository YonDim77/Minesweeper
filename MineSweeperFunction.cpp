#include <iostream>
#include <string>
#include <iomanip> 
#include <cmath>
#include <utility>
#include <sstream>
#include <ctype.h>
#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <memory>

using namespace std;

int adjacentCellsMined(char** matrix, const int &row, const int &col, const size_t &rows, const size_t &cols)
{
	int sum = 0;
	for (int r = -1; r < 2; r++)
	{
		for (int c = -1; c < 2; c++)
		{
			if (row + r < 0 || row + r == rows || col + c < 0 || col + c == cols)
				continue;
			if (matrix[row + r][col + c] == '!')
				sum += 1;
		}
	}

	return sum;
}

int main()
{
	size_t rows, cols;
	cin >> rows >> cols;

	char** matrix = new (nothrow) char* [rows];
	if (matrix == nullptr)
		return 0;

	for (int row = 0; row < rows; row++)
	{
		matrix[row] = new (nothrow) char[cols];
		if (!matrix[row])
		{
			for (int i = 0; i < row; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
			return 0;
		}
		for (int col = 0; col < cols; col++)
			cin >> *(*(matrix + row) + col);
	}

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{			
			cout << adjacentCellsMined(matrix, row, col, rows, cols);
		}
		cout << endl;
	}

	for (int row = 0; row < rows; row++)
		delete[] matrix[row];
	delete[] matrix;

	return 0;
}

/*
5 8 
........ 
...!....
....!...
........
...!....

*/