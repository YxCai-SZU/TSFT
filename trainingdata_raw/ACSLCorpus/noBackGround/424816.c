#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000);
    ensures \result == ((a * b) <= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool result;
    
    //@ assert (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    //@ assert a * b <= 10000 * 10000;
    
    product = a * b;
    result = product <= c;
    
    return result;
}
