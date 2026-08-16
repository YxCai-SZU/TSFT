#include <stdbool.h>

/*@
    predicate a_less_b_less_c_less_d_less_e(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
*/

/*@
    requires 0 <= a && a <= 123;
    requires 0 <= b && b <= 123;
    requires 0 <= c && c <= 123;
    requires 0 <= d && d <= 123;
    requires 0 <= e && e <= 123;
    requires 0 <= k && k <= 123;
    requires a_less_b_less_c_less_d_less_e(a, b, c, d, e);
    ensures \result == true <==> e - a <= k;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    unsigned long long dist;
    bool result;

    //@ assert a_less_b_less_c_less_d_less_e(a, b, c, d, e);
    dist = e - a;

    if (dist <= k)
    {
        //@ assert dist <= k;
        result = true;
    }
    else
    {
        //@ assert dist > k;
        result = false;
    }

    return result;
}
