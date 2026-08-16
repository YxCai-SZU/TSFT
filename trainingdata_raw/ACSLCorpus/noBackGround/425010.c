#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3);
    ensures \result == ((((a) * (b)) * 2 % 2) == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product_parity;
    bool result;
    
    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    //@ assert a * b <= 9;
    
    product_parity = (a * b) * 2 % 2;
    result = (product_parity == 0);
    
    return result;
}
