#include <stdbool.h>

/*@
    requires (1 <= (a) < 10000) && (1 <= (b) < 10000);
    ensures \result == (a * b < 10000);
    assigns \nothing;
*/
bool myfun(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    bool res;
    unsigned int product;

    //@ assert (1 <= (a) < 10000);
    //@ assert (1 <= (b) < 10000);
    
    //@ assert a * b < 10000 * 10000;
    
    product = a * b;
    res = product < 10000;
    
    return res;
}
