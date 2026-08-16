#include <stdint.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    ensures \result == (int32_t)(a * b + 1) || \result == -1;
    ensures \result == -1 ==> (uint64_t)a * b >= 0x80000000;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t c;
    uint64_t d;
    int32_t ret_val;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    //@ assert 1 <= a * b <= 10000;
    
    c = a * b;
    d = (uint64_t)c + 1;
    
    if (c <= 0x7FFFFFFF)
    {
        ret_val = (int32_t)d;
    }
    else
    {
        ret_val = -1;
    }
    
    return ret_val;
}
