#include <stdio.h>
#include <stdlib.h>

// void changeArr(int** test) {
// 	for (int j = 0; j < 5; j++) {
// 		test[2][j] = 5;
// 	}
// }


int main() {
	int rows = 8, cols = 5;
	int** arr;
	arr = malloc(rows * sizeof *arr);
	for (int i=0; i<rows; i++){
  	  arr[i] = malloc(cols * sizeof *arr[i]);
	}

	// int rows = 5, cols = 5, i;
	// int **x;

	// /* obtain values for rows & cols */

	// /* allocate the array */
	// x = malloc(rows * sizeof *x);
	// for (i=0; i<rows; i++)
	// {
	// 	x[i] = malloc(cols * sizeof *x[i]);
	// }

	for (int i = 0, k = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = k++;
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
	}


  	/* deallocate the array */
	for (int i=0; i<rows; i++)
	{
		free(arr[i]);
	}
	free(arr);

	// changeArr
	return 0;
}