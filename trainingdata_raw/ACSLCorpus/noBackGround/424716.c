#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result <= b;
    ensures \result == ((n) * (a)) || \result == b;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t product;
    uint32_t result;

    //@ assert (1 <= (n) && (n) <= 20 &&         1 <= (a) && (a) <= 50 &&         1 <= (b) && (b) <= 50);
    
    product = n * a;
    
    //@ assert product == ((n) * (a));
    
    if (product <= b)
    {
        result = product;
        //@ assert result == ((n) * (a));
    }
    else
    {
        result = b;
        //@ assert result == b;
    }
    
    //@ assert result <= b;
    return result;
}
