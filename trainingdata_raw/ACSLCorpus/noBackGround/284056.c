#include <stdbool.h>

/*@
    requires (0 <= (a) <= 9) && (0 <= (b) <= 9);
    ensures \result == (a * b >= 10);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    bool result;
    
    //@ assert (0 <= (a) <= 9) && (0 <= (b) <= 9);
    //@ assert a * b <= 81;
    
    product = a * b;
    result = (product >= 10);
    
    //@ assert result == (a * b >= 10);
    return result;
}
