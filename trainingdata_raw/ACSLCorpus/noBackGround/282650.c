#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures \result == 0 || \result == (integer)(a * b + 1);
    ensures \result >= 0;
*/
int32_t func(uint32_t a, uint32_t b) {
    int32_t res;
    
    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    
    if (a > 9 || b > 9) {
        res = 0;
        //@ assert res == 0;
        //@ assert res >= 0;
        return res;
    }
    
    //@ assert a <= 9 && b <= 9;
    //@ assert a * b <= 81;
    //@ assert a * b + 1 <= 82;
    //@ assert 0 < a * b + 1;
    
    res = (int32_t)(a * b + 1);
    //@ assert res == (integer)(a * b + 1);
    //@ assert res >= 0;
    
    return res;
}
