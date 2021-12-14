#include <time.h>
#include "measure.h"

double measure(long (*func)(), long* result) {
    clock_t start = clock();
    *result = func();
    clock_t end = clock();
    return end - start;
}
