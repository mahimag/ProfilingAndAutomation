#include <gtest/gtest.h>
#include <stdio.h>


extern "C" {
#include "matrix.h"
#include "oddinacci.h"
#include "mat0.h"
#include "mat1.h"
#include "measure.h"
}

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

TEST(Oddinacci, Test) {
    long val1 = 0;
    double slow = measure(run_odd, &val1);

    long val2 = 0;
    double fast = measure(run_odd_fast, &val2);

    printf("slow=%f, fast=%f\n", slow, fast);
    printf("factor=%f\n", (double) slow / fast);

    ASSERT_EQ(val1, val2);
    ASSERT_TRUE(slow / fast > 100);
}

TEST(Matrix, Mat0) {
    long val1 = 0;
    double slow = measure(mat0_slow, &val1);

    long val2 = 0;
    double fast = measure(mat0_fast, &val2);

    printf("slow=%f, fast=%f\n", slow, fast);
    printf("factor=%f\n", (double) slow / fast);

    ASSERT_EQ(val1, val2);
    ASSERT_TRUE(slow / fast > 10);
}

TEST(Matrix, Mat1) {
    long val1 = 0;
    double slow = measure(mat1_slow, &val1);

    long val2 = 0;
    double fast = measure(mat1_fast, &val2);

    printf("slow=%f, fast=%f\n", slow, fast);
    printf("factor=%f\n", slow / fast);

    ASSERT_EQ(val1, val2);
    ASSERT_TRUE(slow / fast > 1.5);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
