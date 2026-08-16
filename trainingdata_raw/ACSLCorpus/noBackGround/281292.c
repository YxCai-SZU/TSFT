#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((l) * (l) * (l)) / 27;
    assigns \nothing;
*/
int64_t func(uint32_t l)
{
    // Variable declarations at scope top
    int64_t l_cubed;
    int64_t result = 0;
    int64_t remainder;
    int64_t divisor = 27;
    
    //@ assert (1 <= (l) <= 1000);
    
    //@ assert l * l <= 1000000;
    //@ assert ((l) * (l) * (l)) <= 1000000000;
    
    l_cubed = (int64_t)(l * l * l);
    
    remainder = l_cubed;
    
    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant l_cubed == ((l) * (l) * (l));
        loop invariant result * divisor + remainder == l_cubed;
        loop invariant 0 <= remainder;
        loop assigns remainder, result;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        result += 1;
    }
    
    //@ assert result * 27 + remainder == ((l) * (l) * (l));
    //@ assert 0 <= remainder < 27;
    
    return result;
}
