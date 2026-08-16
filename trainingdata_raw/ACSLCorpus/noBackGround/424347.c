#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> m >= (((n) + 1) / 2 * ((n) * 2 + 1) / 2);
    ensures \result == 0 ==> m < (((n) + 1) / 2 * ((n) * 2 + 1) / 2);
*/
int32_t func(int32_t n, int32_t m) {
    int32_t result;
    int32_t t;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= n * n;
    //@ assert n * 2 + 1 <= 201;
    //@ assert n + 1 <= 101;
    //@ assert (n + 1) / 2 <= 50;
    //@ assert (n + 1) / 2 * (n * 2 + 1) <= 50 * 201;
    
    t = (n + 1) / 2 * (n * 2 + 1) / 2;
    
    if (m >= t) {
        //@ assert m >= (n + 1) / 2 * (n * 2 + 1) / 2;
        result = 1;
    } else {
        //@ assert m < (n + 1) / 2 * (n * 2 + 1) / 2;
        result = 0;
    }
    
    return result;
}
