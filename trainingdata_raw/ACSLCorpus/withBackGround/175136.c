#include <stdbool.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 100;
    predicate sum_in_range(integer a, integer b) = 0 <= a + b <= 200;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(x);
    ensures \result == (x >= a && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(x);
    //@ assert sum_in_range(a, b);
    
    if (x < a || x > a + b)
    {
        return false;
    }
    else
    {
        return true;
    }
}
