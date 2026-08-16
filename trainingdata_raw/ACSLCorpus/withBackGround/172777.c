#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_range: \forall integer x, y; valid_range(x) && valid_range(y) ==> sum(x, y) <= 20000;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    requires valid_range(z);
    ensures \result == (x + y >= z);
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x + y <= 20000;
    return (x + y) >= z;
}
