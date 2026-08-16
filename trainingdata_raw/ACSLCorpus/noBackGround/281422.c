#include <stdbool.h>

/*@
    requires (0 <= (a) <= 32) && (0 <= (b) <= 32) && (0 <= (c) <= 32);
    ensures \result == true <==> (a * b) >= c;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product;
    
    //@ assert (0 <= (a) <= 32);
    //@ assert (0 <= (b) <= 32);
    //@ assert (0 <= (c) <= 32);
    
    product = a * b;
    
    //@ assert 0 <= product <= 1024;
    
    result = (product >= c);
    
    //@ assert result == true <==> (a * b) >= c;
    
    return result;
}
