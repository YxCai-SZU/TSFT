#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;
    predicate within_bounds(integer a, integer b, integer c, integer d, integer e, integer k) =
        a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 &&
        a <= 123 && b <= 123 && c <= 123 && d <= 123 && e <= 123 &&
        k >= 0 && k <= 123;
    predicate condition_holds(integer a, integer e, integer k) =
        e - a <= k;
*/

/*@
    requires is_ordered(a, b, c, d, e);
    requires within_bounds(a, b, c, d, e, k);
    ensures \result == true <==> condition_holds(a, e, k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    bool right = false;
    //@ assert is_ordered(a, b, c, d, e);
    //@ assert within_bounds(a, b, c, d, e, k);
    
    if (e - a <= k)
    {
        right = true;
    }
    
    //@ assert right == true <==> condition_holds(a, e, k);
    return right;
}
