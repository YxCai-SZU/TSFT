#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (x / 100 * 100 <= x && x < (x / 100 + 1) * 100);
*/
uint32_t func(uint64_t x)
{
    uint64_t n;
    uint64_t no_carry;
    uint32_t res;

    n = x / 100;
    no_carry = n * 100;
    
    //@ assert n == x / 100;
    //@ assert no_carry == (x / 100) * 100;
    
    if (x < no_carry + 100)
    {
        res = 1;
        //@ assert res == 1;
        //@ assert x < (x / 100 + 1) * 100;
    }
    else
    {
        res = 0;
        //@ assert res == 0;
    }
    
    return res;
}
