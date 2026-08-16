#include <stdbool.h>

/*@ predicate strict_ascending(integer a, integer b, integer c, integer d, integer e) =
    a < b && b < c && c < d && d < e;
*/

/*@ logic integer diff(integer e, integer a) = e - a;
*/

/*@ lemma diff_nonnegative:
    \forall integer a, e; a <= e ==> diff(e, a) >= 0;
*/

/*@ requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires strict_ascending(a, b, c, d, e);
    ensures \result == true <==> diff(e, a) <= k;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int local_diff;
    bool result;

    local_diff = e - a;

    //@ assert local_diff == diff(e, a);
    //@ assert local_diff >= 0;

    if (local_diff <= k)
    {
        result = true;
        //@ assert local_diff <= k;
    }
    else
    {
        //@ assert local_diff > k;
        result = false;
    }

    //@ assert result == true <==> diff(e, a) <= k;
    return result;
}
