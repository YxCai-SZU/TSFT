#include <limits.h>

/*@
    predicate is_minimum(integer ret, integer a, integer b) =
        (ret == a || ret == b) && ret <= a && ret <= b;
*/

/*@
    requires a >= INT_MIN && a <= INT_MAX;
    requires b >= INT_MIN && b <= INT_MAX;
    ensures \result == a || \result == b;
    ensures \result <= a;
    ensures \result <= b;
    assigns \nothing;
*/
int minimum(int a, int b)
{
    int ret;
    if (a < b)
    {
        //@ assert a <= b;
        ret = a;
    }
    else
    {
        //@ assert b <= a;
        ret = b;
    }
    //@ assert is_minimum(ret, a, b);
    return ret;
}
