#include <stdbool.h>

/*@
    predicate in_range(integer v) = -100 <= v <= 100;
    predicate k_in_range(integer v) = 0 <= v <= 123;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e);
    requires k_in_range(k);
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long diff;
    bool result;

    diff = e - a;
    //@ assert diff == e - a;

    if (diff <= k)
    {
        //@ assert diff <= k;
        result = true;
    }
    else
    {
        //@ assert !(diff <= k);
        result = false;
    }

    return result;
}
