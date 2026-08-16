#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (k) && (k) <= (n));
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> (n - k) % 2 == 0;
    ensures \result == 1 ==> (n - k) % 2 == 1;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t k)
{
    uint32_t diff;
    int32_t result;

    diff = n - k;
    
    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (k) && (k) <= (n));
    
    if (diff % 2 == 0)
    {
        result = 0;
        //@ assert result == 0;
        //@ assert (n - k) % 2 == 0;
    }
    else
    {
        //@ assert diff <= 99;
        result = 1;
        //@ assert result == 1;
        //@ assert (n - k) % 2 == 1;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
