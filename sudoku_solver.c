#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j=0; j<9; j++)
  {
    for (int i=0; i<9;i++)
    {
      printf("%d  ",sudoku[j][i]);
    }
    printf("\n");
  }
}

int subGrid(int sudoku[9][9], int row, int col, int num)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(sudoku[i+row][j+col] == num)
				return 1;
		}
	}
	return 0;
}

int check_sudoku(int sudoku[9][9])
{
  /*
   *  This function checks whether a Sudoku is properly
   * solved. That means that each row, column, and
   * 3x3 subgrid uses each digit only once.
   * 
   *  If *ignores* zeros, so you can use it to check
   * that a partial solution is valid
   */
  
	return 0;
}

int checkValid(int sudoku[9][9], int row, int col, int num)
{
	for (int i = 0; i< 9; i++)
		if (sudoku[row][i] == num || sudoku[i][col] == num)
			return 1;
	//for (int j = 0; j < 9; j++)
		//if (sudoku[j][col] == num)
			//return 1;
	if (subGrid(sudoku, (row/3)*3, (col/3)*3, num))
		return 1;
	return 0;
}

int solved(int sudoku[9][9])
{
  /*
   * This function checks whether a given Sudoku is
   * completely solved (it has no zeros, all digits
   * are used once per row, column, and sub-grid.
   * It returns 1 if the Sudoku is solved, zero
   * otherwise
   */

   for (int i = 0; i < 9; i++)
   {
	   for (int j = 0; j < 9; j++)
	   {
		   if (sudoku[i][j] == 0)
			   return 0;
	   }
   }
   return 1;  
}

int findZero(int sudoku[9][9], int *row, int *col)
{
   for (int i = 0; i < 9; i++)
   {
	   for (int j = 0; j < 9; j++)
	   {
		   if (sudoku[i][j] == 0){
			   *row = i;
			   *col = j;
			   return 0;
		   }
	   }
   }
   return 1;  
}

void solve_sudoku(int sudoku[9][9], int depth)
{
  /*
   * This function solves an input Sudoku, the
   * input has a value of 0 for any entries that
   * are not yet decided. If no solution exists
   * the function returns the input array *exactly
   * as it was* when the function was called.
   * 
   */
   
   int row=0, col=0;
   
   // gets first entry of 0
   if (findZero(sudoku, &row, &col)) return;
   
   // loop 1-9 and puts into sudoku
   for (int i = 1; i <= 9; i++)
   {
	   if (checkValid(sudoku, row, col, i) == 0 && sudoku[row][col] == 0) // check valid input
	   {
		   sudoku[row][col] = i;
		   // if there are any more 0
		   solve_sudoku(sudoku,0);
		   if (solved(sudoku) == 1)
			   return;
		   sudoku[row][col] = 0;
	   }
   }
   return;	// should cause backtracking
}

int main()
{
   int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
		     {6, 0, 0, 1, 9, 5, 0, 0, 0},
		     {0, 9, 8, 0, 0, 0, 0, 6, 0},
		     {8, 0, 0, 0, 6, 0, 0, 0, 3},
		     {4, 0, 0, 8, 0, 3, 0, 0, 1},
		     {7, 0, 0, 0, 2, 0, 0, 0, 6},
		     {0, 6, 0, 0, 0, 0, 2, 8, 0},
		     {0, 0, 0, 4, 1, 9, 0, 0, 5},
		     {0, 0, 0, 0, 8, 0, 0, 7, 9}};


  printf("Input puzzle is:\n");
  print_sudoku(Sudoku);
  
  solve_sudoku(Sudoku,0);
  
  printf("Solution is:\n");
  print_sudoku(Sudoku);
  
}
