#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == (l / 3) * (l / 3) * (l / 3);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t e = 0;
    int64_t temp_l = l;
    
    /*@
        loop invariant 0 <= e <= 333;
        loop invariant 0 <= temp_l <= l;
        loop invariant l == 3 * e + temp_l;
        loop invariant (1 <= (l) <= 1000);
        loop assigns e, temp_l;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        e += 1;
    }
    
    //@ assert e >= 0 && e <= 333;
    //@ assert temp_l == l - 3 * e;
    
    //@ assert l / 3 >= 0;
    //@ assert l / 3 <= 333;
    //@ assert (l / 3) * (l / 3) <= 333 * 333;
    //@ assert (l / 3) * (l / 3) * (l / 3) <= 333 * 333 * 333;
    
    int64_t result = e * e * e;
    return result;
}
