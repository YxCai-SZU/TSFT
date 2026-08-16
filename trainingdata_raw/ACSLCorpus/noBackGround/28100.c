#include <stdint.h>

/*@ requires ((1 <= (a) && (a) <= 12) && (1 <= (b) && (b) <= 31));
    ensures \result == 1 || \result == 0;
    ensures ((\result) == 1 ==> ((a) <= 12 && (b) <= 31));
    ensures ((\result) == 0 ==> ((a) > 12 || (b) > 31));
*/
int32_t func(uint32_t a, uint32_t b) {
    int32_t result;
    //@ assert ((1 <= (a) && (a) <= 12) && (1 <= (b) && (b) <= 31));
    
    if (a <= 12 && b <= 31) {
        //@ assert a <= 12 && b <= 31;
        result = 1;
    } else {
        //@ assert a > 12 || b > 31;
        result = 0;
    }
    
    //@ assert result == 1 || result == 0;
    //@ assert ((result) == 1 ==> ((a) <= 12 && (b) <= 31));
    //@ assert ((result) == 0 ==> ((a) > 12 || (b) > 31));
    return result;
}
