#include <stdbool.h>

/*@
    predicate is_in_range(integer a, integer low, integer high) =
        low <= a && a <= high;
*/

/*@
    requires is_in_range(a, 1, 5000);
    requires is_in_range(b, 1, 5000);
    requires is_in_range(c, 1, 10000);
    ensures \result == (a + b >= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    if (a + b >= c)
    {
        //@ assert a + b >= c;
        result = true;
    }
    else
    {
        //@ assert !(a + b >= c);
        result = false;
    }
    
    return result;
}
