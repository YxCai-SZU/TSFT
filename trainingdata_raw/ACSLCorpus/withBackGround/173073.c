#include <stdbool.h>

/*@
    predicate strict_ascending(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;

    predicate within_k(integer x, integer y, integer k) =
        y - x <= k;

    predicate result_condition(integer a, integer b, integer c, integer d, integer e, integer k) =
        within_k(a, b, k) || within_k(a, c, k) || within_k(a, d, k) || within_k(a, e, k) ||
        within_k(b, c, k) || within_k(b, d, k) || within_k(b, e, k) ||
        within_k(c, d, k) || within_k(c, e, k) ||
        within_k(d, e, k);

    lemma bounds_lemma:
        \forall integer a, b, c, d, e, k;
            a < 124 && b < 124 && c < 124 && d < 124 && e < 124 && k < 124 &&
            strict_ascending(a, b, c, d, e) ==>
            result_condition(a, b, c, d, e, k) ==>
            true;
*/

/*@
    requires a < 124 && b < 124 && c < 124 && d < 124 && e < 124 && k < 124;
    requires a < b && b < c && c < d && d < e;
    ensures \result == ( (b - a <= k || c - a <= k || d - a <= k || e - a <= k) ||
                        (c - b <= k || d - b <= k || e - b <= k) ||
                        (d - c <= k || e - c <= k) ||
                        (e - d <= k) );
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    bool result = false;

    //@ assert a < b && b < c && c < d && d < e;
    //@ assert k < 124;

    if (b - a <= k || c - a <= k || d - a <= k || e - a <= k)
    {
        result = true;
    }
    else if (c - b <= k || d - b <= k || e - b <= k)
    {
        result = true;
    }
    else if (d - c <= k || e - c <= k)
    {
        result = true;
    }
    else if (e - d <= k)
    {
        result = true;
    }

    return result;
}
