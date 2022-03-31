#include <stdio.h>
#include <unistd.h> //you need this for linux!
#include <time.h>
#include <stdlib.h>

void printMatrix(int height, int width, int matriz[height][width])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%02d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int fireWidth = 5;
	int fireHeight = 37;
	int fire[fireHeight][fireWidth];
	for (int row = 0; row < fireHeight; row++)
	{
		for (int column = 0; column < fireWidth; column++)
		{
			fire[row][column] = 0;
		}
	}

	for (int column = 0; column < fireWidth; column++)
	{
		// printf("%d \n", column);
		fire[fireHeight - 1][column] = 36;
	}

	for (int i = 0; i < 36; i++)
	{
		for (int row = 0; row < fireHeight - 1; row++)
		{
			for (int column = 0; column < fireWidth; column++)
			{
				fire[row][column] = (fire[row + 1][column] != 0 && fire[row + 1][column] != 1) ? fire[row + 1][column] - rand() % 3 : 0;
			}
		}
		printf("\n");
		printMatrix(fireHeight, fireWidth, fire);
		usleep(500 * 1000);
	}
}
