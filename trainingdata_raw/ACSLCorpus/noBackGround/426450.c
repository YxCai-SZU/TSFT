#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures \result >= -1 && \result <= 20;
    ensures \result == -1 || \result == a + b;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t res;
    
    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20);
    
    if (a > 9 || b > 9) {
        res = -1;
        //@ assert res == -1;
    } else {
        //@ assert a <= 9 && b <= 9;
        //@ assert ((a) + (b)) <= 20;
        res = (int32_t)(a + b);
        //@ assert res == a + b;
    }
    
    //@ assert res >= -1 && res <= 20;
    //@ assert res == -1 || res == a + b;
    
    return res;
}
