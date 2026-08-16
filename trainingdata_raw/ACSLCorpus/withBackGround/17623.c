#include <stdbool.h>

/*@
    predicate valid_time(integer a, integer b) =
        0 <= a && a < 24 && 0 <= b && b < 60;

    logic integer total_minutes(integer a, integer b) =
        a * 60 + b;

    lemma time_bound_lemma:
        \forall integer a, b;
            valid_time(a, b) ==> total_minutes(a, b) < 24 * 60;
*/

/*@
    requires valid_time(a, b);
    requires valid_time(c, d);
    requires 0 <= e && e < 60;
    ensures \result == (total_minutes(a, b) <= total_minutes(c, d) + e);
*/
bool func(unsigned long long a, unsigned long long b,
          unsigned long long c, unsigned long long d,
          unsigned long long e)
{
    unsigned long long x;
    unsigned long long y;

    //@ assert a * 60 < 24 * 60;
    //@ assert c * 60 < 24 * 60;
    //@ assert d + e < 60 + 60;

    x = a * 60 + b;
    y = c * 60 + d + e;

    return x <= y;
}
