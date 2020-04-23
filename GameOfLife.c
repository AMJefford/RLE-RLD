/*
* Student ID: 201343599
* Student Name: Ashley Jefford
* Email: a.m.jefford@student.liverpool.ac.uk
*
* User: sgajeffo
*
* Problem ID: 1081
* RunID: 14118
* Result: Accepted
*/

#include <stdio.h>
#include <string.h> //used for memcpy

int ROWS, COLUMNS, STEPS; //defining global vars

void printGen(char grid[ROWS][COLUMNS]) //print gen once #STEPS complete
{
	for (int i = 0; i < ROWS; i++) //iterate through rows and columns to print grid
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			printf("%c", grid[i][j]);
		}
		if (i < ROWS -1) //print \n unless last line
		{
			printf("\n");
		}
	}
}

void simulation(char grid[ROWS][COLUMNS])
{
	int aliveNeighbours;
	int stepCount = 0;

	//iterate for number of STEPS
	while (stepCount < STEPS)
	{
		//new 2D array to store next generation
		char nextGen[ROWS][COLUMNS];

		//iterate through each cell
		for (int rowIndex = 0; rowIndex < ROWS; rowIndex++)
		{
			for (int colIndex = 0; colIndex < COLUMNS; colIndex++)
			{
					//if itself is alive, start with -1 as it will count itself as a neighbour
					if (grid[rowIndex][colIndex] == 'X')
					{
						aliveNeighbours = -1;
					}
					else
					{
						aliveNeighbours = 0;
					}
					for (int i = -1; i <= 1; i++) //iterate through diagonals, vertcials, horizontals
					{
						for (int j = -1; j <= 1; j++)
						{
							//only count neighbour if alive and index is within range
							if ((rowIndex + i >= 0) && (rowIndex + i < ROWS) && (colIndex + j >= 0) && (colIndex + j < COLUMNS) && (grid[rowIndex + i][colIndex + j] == 'X'))
							{
								aliveNeighbours++;
							}
						}
					}

					//any live cell with fewer than 2 live neighbours dies
					//any live cell with 2 or 3 neighbours lives
					//any live cell with more than 3 live neighbours dies
					//any dead cell with exactly 3 live neighbours becomes a live cell
					if ((grid[rowIndex][colIndex] == 'X') && (aliveNeighbours < 2)) //live cells marked with X
					{
						nextGen[rowIndex][colIndex] = '.';
					}

					else if ((grid[rowIndex][colIndex] == 'X') && (aliveNeighbours > 3))
					{
						nextGen[rowIndex][colIndex] = '.';
					}

					else if ((grid[rowIndex][colIndex] == '.') && (aliveNeighbours == 3))
					{
						nextGen[rowIndex][colIndex] = 'X';
					}

					else
					{
						nextGen[rowIndex][colIndex] = grid[rowIndex][colIndex];
					}
				}
			}

			//make grid update to new generation
			memcpy(grid, nextGen,  ROWS * COLUMNS);
			stepCount++;
		}

		printGen(grid); //one #steps reached, print grid
	}

int main()
{
	scanf("%d%d%d", &ROWS, &COLUMNS, &STEPS); //read input

	char grid[ROWS][COLUMNS]; //define grid size based on input

	for (int rowIndex = 0; rowIndex < ROWS; rowIndex++)
	{
		for (int colIndex = 0; colIndex < COLUMNS; colIndex++)
		{
			scanf(" %c", &grid[rowIndex][colIndex]); //need space before char to ignore white space + new lines
		}
	}

	simulation(grid);

return 0;

}
