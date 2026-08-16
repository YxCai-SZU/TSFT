#include <limits.h>

/*@
    predicate valid_side(integer s) = s >= 0 && s <= INT_MAX / 4;
*/

/*@
    logic integer perimeter(integer s) = 4 * s;
*/

/*@
    lemma no_overflow: \forall integer s; valid_side(s) ==> 4 * s <= INT_MAX;
*/

/*@
    requires valid_side(s);
    ensures \result == perimeter(s);
    assigns \nothing;
*/
int perimeter_square(int s)
{
    int ret;
    //@ assert valid_side(s);
    //@ assert 4 * s <= INT_MAX;
    ret = 4 * s;
    //@ assert ret == perimeter(s);
    return ret;
}
