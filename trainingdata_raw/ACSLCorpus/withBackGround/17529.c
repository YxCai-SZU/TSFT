#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate x_in_range(integer x) = 1 <= x && x <= 200;
    predicate sum_in_range(integer a, integer b) = 1 <= a + b && a + b <= 200;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == (x <= a + b && a <= x);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long x)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert x_in_range(x);
    //@ assert sum_in_range(a, b);

    if (x <= a + b && a <= x)
    {
        //@ assert x <= a + b && a <= x;
        result = true;
    }
    else
    {
        //@ assert !(x <= a + b && a <= x);
        result = false;
    }

    return result;
}
