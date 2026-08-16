#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3);
    requires (1 <= (b) <= 3);
    ensures \result == ((a * b) % 2 != 0);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product;
    
    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    
    product = a * b;
    
    //@ assert 1 <= product <= 9;
    
    result = (product % 2) != 0;
    
    return result;
}
