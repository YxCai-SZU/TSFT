#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer low, integer high) =
        low <= a && a <= high;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_range:
        \forall integer a, b, low_a, high_a, low_b, high_b;
        valid_range(a, low_a, high_a) && valid_range(b, low_b, high_b) ==>
        sum(a, b) >= low_a + low_b;
*/

/*@
    requires valid_range(a, 1, 5000);
    requires valid_range(b, 1, 5000);
    requires valid_range(c, 1, 10000);
    ensures \result == (a + b >= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool result;

    sum = a + b;
    //@ assert sum == a + b;
    //@ assert valid_range(a, 1, 5000);
    //@ assert valid_range(b, 1, 5000);
    //@ assert valid_range(c, 1, 10000);

    result = (sum >= c);
    return result;
}
