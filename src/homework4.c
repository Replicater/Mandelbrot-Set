#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include <math.h>
#include "../incl/bitmap.h"

int color_bar(int,int);

int color_bar(int x,int N)
{
	if (x < 30)
		return 10 + 5 * x;
	else if (x < 380)
		return (int)(190 + 3/14 *(x - 30));
	else
		return 235 + x - 380;
};

int main(int argc, char *argv[])
{
	if (argc < 6)
	{
		printf("no enough argment.\n");
	}
	else
	{

		int height = 1080 * 2;
		int width = 1440 * 2;
		// point2d central_point = {.x = atof(argv[1]), .y = atof(argv[2])};
		double dimension = atof(argv[4]);
		double complex central_point = atof(argv[2]) - dimension + (atof(argv[3]) - dimension * height/width) * I;
		
		double lpp = (dimension * 2.0)/width;
		int N = atoi(argv[5]);
		char * file_name = argv[1];
		char * pic;
		pic = malloc(height * width * 3 * sizeof(char));

		for (int i = 0;i < height;i++)
		{
			for (int j = 0; j < width;j++)
			{
				int iteration_num = 0;
				double complex iteration_constant = central_point + j * lpp + i * lpp * I;
				
				double complex current_point = 0.0 + 0.0 * I;
				while (iteration_num < N)
				{
					iteration_num++;
					current_point = current_point * current_point + iteration_constant;
					if (cabs(current_point) > 2)
					{
						int pos = i * width + j;
						// pic[pos * 3] = 255;//B
						// pic[pos * 3 + 1] = 255;//G
						// pic[pos * 3 + 2] = 255;//R
						pic[pos * 3] = 180;//B
						pic[pos * 3 + 1] = color_bar(iteration_num,N);//G
						pic[pos * 3 + 2] = color_bar(iteration_num,N);//R
						break;
					}
				}
				if (iteration_num == N)
				{
					int pos = i * width + j;
					pic[pos * 3] = 0;
					pic[pos * 3 + 1] = 0;
					pic[pos * 3 + 2] = 0;
				}
			}
		}
		build_bmp(file_name, width, height, pic);
		free(pic);
	}
	return 0;
}