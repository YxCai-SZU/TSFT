#include <stdbool.h>

/*@ predicate in_range(integer x) = 1 <= x <= 100; */

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result <==> ((a + b + c) % 3 == 0);
    assigns \nothing;
*/
bool can_distribute_evenly(unsigned long a, unsigned long b, unsigned long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);

    result = ((a + b + c) % 3 == 0);
    return result;
}
