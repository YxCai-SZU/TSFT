#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    ensures \result == (((a) * (b)) % 2 != 0);
    assigns \nothing;
*/
bool input_tuple(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool result;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    //@ assert a * b <= 10000 * 10000;
    
    product = a * b;
    result = (product % 2) != 0;
    
    //@ assert result == (((a) * (b)) % 2 != 0);
    return result;
}
