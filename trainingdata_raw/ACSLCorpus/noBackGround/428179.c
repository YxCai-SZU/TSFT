#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= x;
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result = 0;
    int64_t i = 1;
    int64_t xs = x;
    
    /*@
        loop invariant 1 <= i <= 1000000001;
        loop invariant xs >= 0;
        loop invariant xs <= x;
        loop invariant result >= 0;
        loop invariant result <= x;
        loop invariant result == i - 1;
        loop assigns xs, result, i;
        loop variant xs;
    */
    while (xs >= i * 100)
    {
        //@ assert xs >= i * 100;
        xs -= i * 100;
        result += 1;
        i += 1;
    }
    
    //@ assert result >= 0;
    return result;
}
