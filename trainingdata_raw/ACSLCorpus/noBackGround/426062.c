#include <stdbool.h>

/*@
    requires (0 <= (a) < 0x10000) && (0 <= (b) < 0x10000);
    ensures \result == ((((a) * (b)) % 0x10000) == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int product;
    bool is_divisible = false;
    unsigned int remainder;
    
    //@ assert a * b < 0x10000 * 0x10000;
    
    product = a * b;
    remainder = product;
    
    /*@
        loop invariant 0 <= remainder <= product;
        loop invariant remainder == product - 0x10000 * ((product - remainder) / 0x10000);
        loop invariant (0 <= (a) < 0x10000) && (0 <= (b) < 0x10000);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 0x10000)
    {
        remainder -= 0x10000;
    }
    
    if (remainder == 0)
    {
        is_divisible = true;
    }
    
    return is_divisible;
}
