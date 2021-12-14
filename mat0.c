#include <stdio.h>
#include "matrix.h"


long mat0_slow() {
    matrix_t mat; // initialized array / object
    matrix_init(&mat, 10, 10, 0); // object, row, columns, 0
    long sum = 0; // variable that holds sum
    for (int i = 0; i < matrix_rows(mat); i++) {
        for (int j = 0; j < matrix_cols(mat); j++) {
            int value = matrix_get(mat, i, j);
            printf("%d ", value);
            sum += value;
        }
        printf("\n");
    }
    return sum;
}

long mat0_fast() {
    matrix_t mat; // initialized array / object
    matrix_init(&mat, 10, 10, 0); // object, row, columns, 0
    long sum = 0; // variable that holds sum
    int row = matrix_rows(mat);
    int col = matrix_cols(mat);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int value = matrix_get(mat, i, j);
            printf("%d ", value);
            sum += value;
        }
        printf("\n");
    }
    return sum;
}
