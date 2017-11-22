#include<stdio.h>

bool unassigned_row_col(int sudoku[9][9],int &row,int &col);
bool safe_number(int sudoku[9][9], int i,int j,int k);
bool safe_row(int sudoku[9][9],int i,int j,int k);
bool safe_col(int sudoku[9][9],int i,int j,int k);
bool safe_box(int sudoku[9][9],int i,int j,int k);

bool solve_sudoku(int sudoku[9][9]) //the recursion program
{
	int row,col;//initializing rows and cols
	
	if(unassigned_row_col(sudoku,row,col)==false)	//finds a 0 in the sudoku array
	return true;
	
	for(int value=1;value<=9;value++)//for values of sudoku from 1 to 9
		{
			if(safe_number(sudoku,row,col,value))
			{				
				sudoku[row][col]=value;//places the value into the array
				if(solve_sudoku(sudoku))//undergoes recursion
					return true;
				sudoku[row][col]=0;//If previous recursion returns false the backtrace
			}							
		}
	return false; //this is responsible for backtracking by converting corresponding row and col value to 0
}

bool unassigned_row_col(int sudoku[9][9],int &row,int &col)//refrence of rows and cols taken to change the actual parameters
{
	for(row=0;row<9;row++)//rows sequence
	{
		for(col=0;col<9;col++)//columns sequence
		{
			if(sudoku[row][col]==0)//If a 0 is found return true else false and sudoku solved!!!
				return true;			
		}
	}
	return false;
}

bool safe_number(int sudoku[9][9], int i,int j,int k)//this is used to check the rows,cols and box are safe to put the number or not
{
	if(safe_row(sudoku,i,j,k))
		if(safe_col(sudoku,i,j,k))
			if(safe_box(sudoku,i,j,k))
				return true;
	return false;
}

bool safe_row(int sudoku[9][9],int i,int j,int k)//checks for row if it is can put value or k
{
	for(int y=0;y<9;y++)				
		if(sudoku[i][y]==k)
			return false;
	return true;	
}

bool safe_col(int sudoku[9][9],int i,int j,int k)//checks for col if it is can put value or k
{
	for(int x=0;x<9;x++)		
		if(sudoku[x][j]==k)
			return false;
	return true;				
}

bool safe_box(int sudoku[9][9],int i,int j,int k)//checks for box if it is can put value or k
{
	int x=(int)(i/3);
	int y=(int)(j/3);
	for(int r=x*3;r<=x*3+2;r++)		
			for(int s=y*3;s<=y*3+2;s++)						
				if(sudoku[r][s]==k)
				return false;
	return true;
}

void print_solution(int sudoku[9][9])//function to print the sudoku
{
	for(int i=0;i<9;i++)//rows sequence
	{
		for(int j=0;j<9;j++)//columns sequence
			printf("%d ",sudoku[i][j]);
			printf("\n");
	}		
}

int main() // starting function
{	
	//sudoku array is used to contain the values which are known to us initially
	//This array will contain the solution and the initial input
	int sudoku[9][9]={
					{1, 0, 0, 0, 0, 7, 0, 9, 0},
					{0, 3, 0, 0, 2, 0, 0, 0, 8},
					{0, 0, 9, 6, 0, 0, 5, 0, 0},
					{0, 0, 5, 3, 0, 0, 9, 0, 0},
					{0, 1, 0, 0, 8, 0, 0, 0, 2},
					{6, 0, 0, 0, 0, 4, 0, 0, 0},
					{3, 0, 0, 0, 0, 0, 0, 1, 0},
					{0, 4, 0, 0, 0, 5, 0, 0, 7},
					{0, 0, 7, 0, 0, 0, 3, 0, 0}
				};
	//starting to solve the sudoku in recursion
	//If the sudoku returns true then printing the solution
	//Else the sudoku cannot be solved
	if(solve_sudoku(sudoku)==true)		
		print_solution(sudoku);	//printing the sudoku	
	else	
		printf("Error");
}
