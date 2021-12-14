#include <stdio.h>
#include <time.h>
#include "matrix.h"
#include "measure.h"

long mat1_slow() {
    matrix_t mat;
    matrix_init(&mat, 10, 20, 1);

    long sum = 0;
    for (int i = 0; i < matrix_rows(mat); i++) {
        int row_result = 0;
        for (int j = 0; j < matrix_cols(mat); j++) {
            row_result = matrix_get(mat, i, 0) + matrix_get(mat, i, j);
        }
        printf("%d %d\n", i, row_result);
        sum += row_result;
    }
    return sum;
}

long mat1_fast() {
    matrix_t mat;
    matrix_init(&mat, 10, 20, 1);
    int row = matrix_rows(mat);
    int col = matrix_cols(mat);
    int row_result = 0;
    long sum = 0;
    for (int i = 0; i < row ; i++) {
	int first = matrix_get(mat, i, 0);
        for (int j = 0; j < col ; j++) {
            row_result = first + matrix_get(mat, i, j);
        }
        printf("%d %d\n", i, row_result);
        sum += row_result;
    }
    return sum;
}
