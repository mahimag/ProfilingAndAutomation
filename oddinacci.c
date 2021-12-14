#include <stdlib.h>
#include "oddinacci.h"
//
long oddinacci(long n) {
    if (n == 0 || n == 1) {
        return n;
    } else if (n % 2 == 0) {
        return oddinacci(n - 1) + oddinacci(n - 2);
    } else {
        return oddinacci(n - 1) + oddinacci(n - 2) + oddinacci(n - 3);
    }
}

long oddinacci_fast(long n) {
    long arr[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(long i=2; i<=n; i++){
        if(i%2==0){
            arr[i] = arr[i-1] + arr[i-2];
        }
        else{
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }
    }
    return arr[n];
}
