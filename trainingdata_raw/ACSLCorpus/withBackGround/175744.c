#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer low, integer high) =
        low <= a <= high;
*/

/*@
    logic integer sum(integer a, integer b) = a + b;
*/

/*@
    lemma sum_commutative:
        \forall integer x, y; sum(x, y) == sum(y, x);
*/

/*@
    requires valid_range(a, 1, 5000);
    requires valid_range(b, 1, 5000);
    requires valid_range(c, 1, 100000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int ab;
    //@ assert valid_range(a, 1, 5000);
    //@ assert valid_range(b, 1, 5000);
    //@ assert valid_range(c, 1, 100000);
    
    ab = a + b;
    //@ assert ab == sum(a, b);
    
    return ab >= c;
}
