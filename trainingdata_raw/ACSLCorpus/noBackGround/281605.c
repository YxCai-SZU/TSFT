#include <stdbool.h>

/*@
    requires 1 <= x <= 20;
    requires 1 <= y <= 30;
    ensures \result == ((x * y) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product;

    //@ assert 1 <= x <= 20;
    //@ assert 1 <= y <= 30;
    
    //@ assert x * y <= 600;
    
    product = x * y;
    result = (product % 2) == 0;
    
    return result;
}
