#include <stdio.h>
#include "matrix.h"
#include "mat1.h"
#include "measure.h"

int main() {
    long val1 = 0;
    double slow = measure(mat1_slow, &val1);

    long val2 = 0;
    double fast = measure(mat1_fast, &val2);

    printf("slow=%f, fast=%f\n", slow, fast);
    printf("Speedup=%f\n", slow / fast);
}
