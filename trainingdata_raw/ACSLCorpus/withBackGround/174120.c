#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 100000;
    
    logic integer compute_n(integer x) = 100 * (x / 100);
    
    predicate postcondition(integer x, bool result) = 
        result == (x >= 2000 || (100 * (x / 100) <= x));
*/

/*@
    requires is_valid_range(x);
    ensures postcondition(x, \result);
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int n;
    bool result;
    
    // Variable declarations at scope top
    n = 100 * (x / 100);
    result = false;
    
    if (x >= 2000)
    {
        //@ assert x >= 2000;
        result = true;
    }
    else if (n <= x)
    {
        //@ assert n <= x;
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}
