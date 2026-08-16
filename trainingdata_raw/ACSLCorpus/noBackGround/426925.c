#include <stdint.h>

/*@
requires ((a) >= 1 && (a) <= 1000000000000000000 &&
    (b) >= 1 && (b) <= 1000000000000000000 &&
    (c) >= 1 && (c) <= 1000000000000000000 &&
    (k) >= 1 && (k) <= 1000000000000000000 &&
    (a) + (b) + (c) >= (k));
ensures \result >= -c && \result <= a;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t max_sum;
    
    //@ assert a >= 1 && a <= 1000000000000000000;
    
    if (a >= k) {
        max_sum = k;
    } else {
        max_sum = a;
    }
    
    //@ assert max_sum == (((a) >= (k)) ? (k) : (a));
    
    if (max_sum < c) {
        max_sum = -c;
    }
    
    //@ assert max_sum == ((((((a)) >= ((k))) ? ((k)) : ((a))) < (c)) ? -(c) : ((((a)) >= ((k))) ? ((k)) : ((a))));
    
    return max_sum;
}
