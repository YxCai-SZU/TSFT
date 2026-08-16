#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3);
    requires (1 <= (b) <= 3);
    ensures \result == (((((a) * (b)) % 2) != 0) ? true : false);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    bool result;
    
    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    
    //@ assert 1 <= a * b <= 9;
    
    product = a * b;
    result = (product % 2) != 0;
    
    //@ assert result == (((((a) * (b)) % 2) != 0) ? true : false);
    return result;
}
