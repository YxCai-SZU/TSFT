#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (int)(a * b + 1) || \result == -1;
    ensures \result != -1 ==> \result == (int)(a * b + 1);
    ensures \result == -1 ==> a * b >= 1000000;
*/
int32_t func(uint32_t a, uint32_t b)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    //@ assert 1 <= a * b <= 10000;
    //@ assert 2 <= a * b + 1 <= 10001;
    
    if (a * b >= 1000000) {
        //@ assert a * b >= 1000000;
        return -1;
    }
    
    //@ assert a * b < 1000000;
    //@ assert a * b + 1 <= 10001;
    return (int32_t)(a * b + 1);
}
