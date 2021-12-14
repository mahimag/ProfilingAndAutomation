#include <stdio.h>
#include "oddinacci.h"
#include "measure.h"

#define ODDINACCI_ITERS 40

long run_odd() {
    long sum = 0;
    for (int i = 0; i < ODDINACCI_ITERS; i++) {
        long value = oddinacci(i);
        printf("oddinacci(%d): %ld\n", i, value);
        sum += value;
    }
    return sum;
}

long run_odd_fast() {
    long sum = 0;
    for (int i = 0; i < ODDINACCI_ITERS; i++) {
        long value =  oddinacci_fast(i);
        printf("oddinacci_fast(%d): %ld\n", i, value);
        sum += value;
    }
    return sum;
}

int main(int argc, char** argv) {
    long val1 = 0;
    double slow = measure(run_odd, &val1);

    long val2 = 0;
    double fast = measure(run_odd_fast, &val2);

    printf("slow=%f, fast=%f\n", slow, fast);
    printf("fast=%f\n", fast);
    printf("factor=%f\n", slow / fast);
}
