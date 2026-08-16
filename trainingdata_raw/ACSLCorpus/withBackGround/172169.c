#include <stdbool.h>

/*@
    predicate is_sum_ge(integer a, integer b, integer c) =
        a + b >= c;
 */

/*@
    requires 1 <= a && a <= 5000;
    requires 1 <= b && b <= 5000;
    requires 1 <= c && c <= 10000;
    ensures \result <==> is_sum_ge(a, b, c);
 */
bool func(int a, int b, int c)
{
    int ab;
    bool ans;

    ab = a + b;
    //@ assert ab == a + b;

    if (ab >= c)
    {
        ans = true;
        //@ assert is_sum_ge(a, b, c);
    }
    else
    {
        ans = false;
        //@ assert !is_sum_ge(a, b, c);
    }

    //@ assert ans <==> is_sum_ge(a, b, c);
    return ans;
}
