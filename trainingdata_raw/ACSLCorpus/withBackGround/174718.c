/*@
    predicate valid_range(integer x, integer low, integer high) =
        low <= x && x <= high;

    lemma sum_range:
        \forall integer a, b, c;
        valid_range(a, 1, 500) && valid_range(b, 1, 500) && valid_range(c, 1, 1000) ==>
        (a + b >= c) == (a + b >= c);
*/

#include <stdbool.h>

/*@
    requires valid_range(a, 1, 500);
    requires valid_range(b, 1, 500);
    requires valid_range(c, 1, 1000);
    ensures \result == (a + b >= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert valid_range(a, 1, 500);
    //@ assert valid_range(b, 1, 500);
    //@ assert valid_range(c, 1, 1000);

    result = (a + b >= c);
    return result;
}
