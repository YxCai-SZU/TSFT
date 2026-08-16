#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (a * b + 1) || \result == -1;
    ensures \result == -1 ==> (a * b) == 0;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t c;
    
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a * b <= 10000;
    
    c = a * b;
    
    if (c <= 10000) {
        return (int32_t)(c + 1);
    } else {
        return -1;
    }
}
