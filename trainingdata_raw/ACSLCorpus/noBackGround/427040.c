#include <stdbool.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == true <==> ((x / 100) * 100 + 89) <= x;
    assigns \nothing;
*/
bool func(unsigned int x)
{
    // Variable declarations at top of scope
    unsigned int quotient;
    unsigned int product;
    bool result;

    //@ assert 1 <= x <= 100000;
    
    quotient = x / 100;
    //@ assert quotient <= 1000;
    
    product = quotient * 100;
    //@ assert product <= 100000;
    
    if (product + 89 <= x) {
        //@ assert (x / 100) * 100 + 89 <= x;
        result = true;
    } else {
        //@ assert !((x / 100) * 100 + 89 <= x);
        result = false;
    }
    
    return result;
}
