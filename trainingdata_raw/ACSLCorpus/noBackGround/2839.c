#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 12 &&
        1 <= (b) && (b) <= 31);
    ensures \result <= \old(a);
    ensures \result == \old(a) - 1 || \result == \old(a);
*/
uint64_t func(uint64_t a, uint64_t b)
{
    uint64_t ret;
    
    //@ assert (1 <= (a) && (a) <= 12 &&         1 <= (b) && (b) <= 31);
    
    if (a > b) {
        ret = a - 1;
        //@ assert ret == a - 1;
    } else {
        ret = a;
        //@ assert ret == a;
    }
    
    //@ assert ret <= a;
    //@ assert ret == a - 1 || ret == a;
    
    return ret;
}
