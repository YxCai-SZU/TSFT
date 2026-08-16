#include <stddef.h>

/*@
    requires (1 <= (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t res = 0;
    size_t temp_n = n;
    size_t three = 3;
    
    /*@
        loop invariant 0 <= res <= ((n) / 3);
        loop invariant temp_n == n - res * 3;
        loop invariant (1 <= (n) <= 1000);
        loop assigns res, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= three)
    {
        //@ assert temp_n >= three;
        temp_n -= three;
        res += 1;
        //@ assert temp_n == n - res * 3;
    }
    
    //@ assert res == ((n) / 3);
    return res;
}
