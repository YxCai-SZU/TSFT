#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
int64_t func(uint32_t l)
{
    // Variable declarations at scope top
    uint32_t l_cubed;
    uint32_t divisor;
    uint32_t result;
    uint32_t temp;
    
    //@ assert (1 <= (l) <= 1000);
    
    //@ assert l * l <= 1000000;
    //@ assert l * l * l <= 1000000000;
    
    l_cubed = l * l * l;
    divisor = 27;
    result = 0;
    temp = l_cubed;
    
    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant l_cubed == l * l * l;
        loop invariant divisor == 27;
        loop invariant temp >= 0;
        loop invariant result >= 0;
        loop invariant temp + result * divisor == l_cubed;
        loop invariant result <= l_cubed / divisor;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        result += 1;
    }
    
    //@ assert result == (l * l * l) / 27;
    
    return (int64_t)result;
}
