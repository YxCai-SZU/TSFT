#include <stdint.h>


int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at scope top
    int64_t res;

    //@ assert n * m <= 400;
    //@ assert n * m - n >= 0;
    //@ assert n * m - n - m >= -20;

    res = n * m - n - m + 1;
    
    if (res < 0) {
        return 0;
    }
    return res;
}
