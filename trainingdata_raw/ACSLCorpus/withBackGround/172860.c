#include <stdbool.h>
#include <limits.h>

/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        a <= b && b <= c && c <= d && d <= e;
*/

/*@
    logic integer safe_sub(integer x, integer y) =
        x - y;
*/

/*@
    lemma subtraction_bounds:
        \forall integer a, e;
            a <= e && e <= INT_MAX && a >= 0 ==>
            safe_sub(e, a) <= INT_MAX;
*/

/*@
    requires a <= INT_MAX && b <= INT_MAX && c <= INT_MAX;
    requires d <= INT_MAX && e <= INT_MAX && k <= INT_MAX;
    requires is_ordered(a, b, c, d, e);
    requires k <= 123;
    ensures \result == (e - a <= k);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    //@ assert a <= e;
    //@ assert e - a <= INT_MAX;
    
    bool result;
    result = (e - a) <= k;
    return result;
}
