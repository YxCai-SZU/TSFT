#include <stdint.h>

/*@
    predicate in_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
            in_range(a, b) ==> 1 <= product(a, b) <= 10000;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    //@ assert in_range(a, b);
    //@ assert 1 <= a * b <= 10000;
    return a * b;
}
