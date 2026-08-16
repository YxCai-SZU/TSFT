#include <stdint.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c) {
    int64_t min_val;
    int64_t res;

    //@ assert a - b >= 0;
    min_val = (a - b) < c ? (a - b) : c;
    
    //@ assert min_val >= 0;
    //@ assert min_val <= c;
    
    res = c - min_val;
    
    //@ assert res <= c;
    
    if (res < 0) {
        //@ assert res == 0;
        return 0;
    } else {
        //@ assert res == c - (a - b) || res == 0;
        return res;
    }
}
