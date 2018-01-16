
#include <stdio.h>
#include <stdlib.h>
int array[9][9];
int outputArray[9][9];
int input_value(int x, int y, int value) {
	int i, j;
	// Ïîèñê ïî ãîðèçîíòàëè è âåðòèêàëè 
	for (i = 0; i < 9; i++) 
	{
		if (value == outputArray[i][y] || value == outputArray[x][i]) 
		{
			return 0;
		}
	}
	// Ñêàíèðîâàíèå ìàëûõ êâàäðàòîâ "Ñóäîêó"
	if (x < 3) 
	{
		if (y < 3) 
		{
			for (i = 0; i < 3; i++) 
			{
				for (j = 0; j < 3; j++) 
				{
					if (value == outputArray[i][j]) 
					{
						return 0;
					}
				}
			}
		}
		else if (y < 6) 
		{
			for (i = 0; i < 3; i++) 
			{
				for (j = 3; j < 6; j++) 
				{
					if (value == outputArray[i][j]) 
					{
						return 0;
					}
				}
			}
		}
		else 
		{
			for (i = 0; i < 3; i++) 
			{
				for (j = 6; j < 9; j++) 
				{
					if (value == outputArray[i][j]) 
					{
						return 0;
					}
				}
			}
		}
	}
	else if (x < 6) 
	{
		if (y < 3) 
		{
			for (i = 3; i < 6; i++) 
			{
				for (j = 0; j < 3; j++) 
				{
					if (value == outputArray[i][j]) 
					{
						return 0;
					}
				}
			}
		}
		else if (y < 6) 
		{
			for (i = 3; i < 6; i++) 
			{
				for (j = 3; j < 6; j++) 
				{
					if (value == outputArray[i][j]) 
					{
						return 0;
					}
				}
			}
		}
		else 
		{
			for (i = 3; i < 6; i++) 
			{
				for (j = 6; j < 9; j++) 
				{
					if (value == outputArray[i][j]) 
					{
						return 0;
					}
				}
			}
		}
	}
	else 
	{
		if (y < 3) 
		{
			for (i = 6; i < 9; i++) 
			{
				for (j = 0; j < 3; j++) 
				{
					if (value == outputArray[i][j]) 
					{
						return 0;
					}
				}
			}
		}
		else if (y < 6) 
		{
			for (i = 6; i < 9; i++) 
			{
				for (j = 3; j < 6; j++) 
				{
					if (value == outputArray[i][j]) 
					{
						return 0;
					}
				}
			}
		}
		else 
		{
			for (i = 6; i < 9; i++) 
			{
				for (j = 6; j < 9; j++) 
				{
					if (value == outputArray[i][j]) 
					{
						return 0;
					}
				}
			}
		}
	}
	return value;
}
// Àëãîðèòì âîçâðàòà
int backtrack(int x, int y) 
{
	int temp, i, j;
	if (outputArray[x][y] == 0) 
	{
		for (i = 1; i < 10; i++) 
		{
			temp = input_value(x, y, i);
			if (temp > 0) 
			{
				outputArray[x][y] = temp;
				if (x == 8 && y == 8) 
				{
					return 1;
				}
				else if (x == 8) 
				{
					if (backtrack(0, y + 1)) return 1;
				}
				else 
				{
					if (backtrack(x + 1, y)) return 1;
				}
			}
		}
		if (i == 10) 
		{
			if (outputArray[x][y] != array[x][y]) outputArray[x][y] = 0;
			return 0;
		}
	}
	else 
	{
		if (x == 8 && y == 8) 
		{
			return 1;
		}
		else if (x == 8) 
		{
			if (backtrack(0, y + 1)) return 1;
		}
		else 
		{
			if (backtrack(x + 1, y)) return 1;
		}
	}
}
int main() 
{
	int i, j;
	FILE * pFile;
	printf("Original Sudoku:\n");
	pFile = fopen("input.dat", "r+");
	for (i = 0; i < 9; i++) 
	{
		fscanf(pFile, "%d %d %d %d %d %d %d %d %d",
			&array[i][0], &array[i][1], &array[i][2],
			&array[i][3], &array[i][4], &array[i][5],
			&array[i][6], &array[i][7], &array[i][8]);
	}
	fclose(pFile);
	for (i = 0; i < 9; i++) 
	{
		for (j = 0; j < 9; j++) 
		{
			outputArray[i][j] = array[i][j];
		}
	}
	for (i = 0; i < 9; i++) 
	{
		for (j = 0; j < 9; j++) 
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	pFile = fopen("output.ans", "w");
	if (backtrack(0, 0)) 
	{
		printf("\nSolution is :\n");
		for (i = 0; i < 9; i++) 
		{
			printf("%d %d %d %d %d %d %d %d %d\n", 
				outputArray[i][0], outputArray[i][1], outputArray[i][2], 
				outputArray[i][3], outputArray[i][4], outputArray[i][5], 
				outputArray[i][6], outputArray[i][7], outputArray[i][8]);
			fprintf(pFile, "%d %d %d %d %d %d %d %d %d\n", 
				outputArray[i][0], outputArray[i][1], outputArray[i][2],
				outputArray[i][3], outputArray[i][4], outputArray[i][5],
				outputArray[i][6], outputArray[i][7], outputArray[i][8]);
		}
	}
	else
	{
		printf("\nNo Solution\n");
		fprintf(pFile, "No Solution\n");
	}
	fclose(pFile);
	system("pause");
	return 0;
}
