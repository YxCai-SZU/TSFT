#include <limits.h>

/*@
    predicate non_overflow(integer n, integer d, integer s) =
        0 <= n && n <= 10000 &&
        0 <= d && d <= 10000 &&
        0 <= s && s <= 10000 &&
        n * d <= 10000 * 10000 &&
        s * n <= 10000 * 10000;
*/

/*@
    lemma multiplication_bounds:
        \forall integer n, d, s;
        non_overflow(n, d, s) ==>
        n * d >= 0 && s * n >= 0;
*/

/*@
    requires 0 <= n && n <= 10000;
    requires 0 <= d && d <= 10000;
    requires 0 <= s && s <= 10000;
    ensures \result >= 0;
    ensures \result == n * d || \result == s * n;
    assigns \nothing;
*/
int total_distance_before_collision(int n, int d, int s)
{
    //@ assert non_overflow(n, d, s);
    
    int result;
    
    if (n * d < s * n)
    {
        //@ assert n * d >= 0;
        result = n * d;
    }
    else
    {
        //@ assert s * n >= 0;
        result = s * n;
    }
    
    //@ assert result >= 0;
    //@ assert result == n * d || result == s * n;
    
    return result;
}
