#include <stdio.h>
#include "matrix.h"
#include "mat0.h"
#include "measure.h"

int main() {
    long val1 = 0;
    double slow = measure(mat0_slow, &val1);

    long val2 = 0;
    double fast = measure(mat0_fast, &val2);

    printf("slow=%f, fast=%f\n", slow, fast);
    printf("Speedup=%f\n", slow / fast);
}
