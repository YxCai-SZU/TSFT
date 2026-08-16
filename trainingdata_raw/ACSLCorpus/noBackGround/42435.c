#include <stdint.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result >= 0;
    ensures (500 * (k)) >= x ==> \result == 1;
    ensures (500 * (k)) < x ==> \result == 0;
*/
int64_t func(int64_t k, int64_t x) {
    int64_t en;
    int64_t res;

    //@ assert 1 <= k <= 100;
    //@ assert 1 <= x <= 100000;
    
    //@ assert 500 <= 500 * k <= 50000;
    en = 500 * k;
    
    if (en >= x) {
        res = 1;
    } else {
        res = 0;
    }
    
    //@ assert res >= 0;
    //@ assert (en >= x ==> res == 1) && (en < x ==> res == 0);
    return res;
}
