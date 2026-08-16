#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    requires (1 <= (y) <= 100);
    ensures \result == ((((x) * (y)) % 2) != 0);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool result;

    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    
    // Proof of product bound
    //@ assert x * y <= 10000;
    
    product = x * y;
    result = (product % 2) != 0;
    
    //@ assert (((x) * (y)) % 2) == product % 2;
    
    return result;
}
