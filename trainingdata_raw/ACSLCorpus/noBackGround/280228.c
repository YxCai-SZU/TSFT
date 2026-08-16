#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t x;
    uint32_t quotient;
    uint32_t remainder;
    int32_t result;
    uint32_t y;

    //@ assert (1 <= (n) && (n) <= 100);
    
    x = n * 800;
    
    quotient = 0;
    remainder = n;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= n / 15;
        loop invariant remainder == n - quotient * 15;
        loop invariant 0 <= remainder;
        loop assigns quotient, remainder;
    */
    while (remainder >= 15)
    {
        //@ assert remainder >= 15;
        
        quotient = quotient + 1;
        remainder = remainder - 15;
        
        //@ assert remainder == n - quotient * 15;
    }
    
    //@ assert quotient == n / 15;
    //@ assert remainder == n - quotient * 15;
    
    y = quotient * 200;
    
    //@ assert x == n * 800;
    //@ assert y == (n / 15) * 200;
    
    result = (int32_t)x - (int32_t)y;
    
    //@ assert result == ((n) * 800 - ((n) / 15) * 200);
    
    return result;
}
