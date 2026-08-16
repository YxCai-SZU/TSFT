#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 == 0);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    bool result;
    
    // Precondition assertions
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    
    // Product range verification
    //@ assert ((a) * (b) <= 10000 * 10000);
    
    result = (a * b % 2 == 0);
    return result;
}
