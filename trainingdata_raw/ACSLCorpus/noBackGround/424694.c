#include <stdint.h>

/*@
    requires ((a) <= 1000000000 &&
        (b) <= 1000000000 &&
        (c) <= 1000000000 &&
        (k) <= 100000000000000000 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= (-1 * (c)) && \result <= (1 * (a));
*/
int64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t k)
{
    int64_t res = 0;
    uint64_t remaining_k = k;
    
    //@ assert res == 0;
    //@ assert remaining_k == k;
    
    if (remaining_k >= a) {
        //@ assert remaining_k >= a;
        res += (int64_t)a;
        remaining_k -= a;
        //@ assert res == (int64_t)a;
    } else {
        //@ assert remaining_k < a;
        res += (int64_t)remaining_k;
        remaining_k = 0;
        //@ assert res == (int64_t)k;
    }
    
    //@ assert res >= (-1 * (c));
    //@ assert res <= (1 * (a));
    
    if (remaining_k != 0) {
        if (remaining_k >= b) {
            remaining_k -= b;
        } else {
            remaining_k = 0;
        }
    }
    
    //@ assert res >= (-1 * (c));
    //@ assert res <= (1 * (a));
    
    if (remaining_k != 0) {
        if (remaining_k >= c) {
            res -= (int64_t)c;
            remaining_k -= c;
        } else {
            res -= (int64_t)remaining_k;
            remaining_k = 0;
        }
    }
    
    //@ assert res >= (-1 * (c));
    //@ assert res <= (1 * (a));
    
    return res;
}
