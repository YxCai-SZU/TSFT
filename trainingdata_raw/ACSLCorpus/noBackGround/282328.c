#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == (integer)(a * b) - (integer)(c * d);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    // Variable declarations
    uint32_t product1;
    uint32_t product2;
    int32_t result;
    
    // Precondition verification
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    // Overflow prevention
    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;
    
    product1 = a * b;
    product2 = c * d;
    
    // Product verification
    //@ assert product1 == a * b;
    //@ assert product2 == c * d;
    
    result = (int32_t)product1 - (int32_t)product2;
    
    // Postcondition verification
    //@ assert result == (integer)(a * b) - (integer)(c * d);
    
    return result;
}
