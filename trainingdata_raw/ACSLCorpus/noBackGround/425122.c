#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == ( (a * b) % 2 == 0 );
    assigns \nothing;
*/
bool input_tuple(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    bool result;
    unsigned int product;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    
    product = a * b;
    
    //@ assert product == ((a) * (b));
    //@ assert product <= 10000 * 10000;
    
    result = (product % 2 == 0);
    
    //@ assert result == ( (a * b) % 2 == 0 );
    return result;
}
