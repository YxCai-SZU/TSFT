#include <stdbool.h>

/*@ predicate sum_ge(integer a, integer b, integer c) = a + b >= c; */

/*@
    requires 1 <= a && a <= 5000;
    requires 1 <= b && b <= 5000;
    requires 1 <= c && c <= 10000;
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    bool result;
    unsigned long sum;
    
    result = false;
    sum = a + b;
    
    if (sum >= c)
    {
        result = true;
    }
    
    //@ assert result == (a + b >= c);
    
    return result;
}
