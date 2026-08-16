#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b) =
        1 <= a <= 10000 && 1 <= b <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b; bounds(a, b) ==> product(a, b) <= 10000 * 10000;
*/

/*@
    requires bounds(a, b);
    ensures \result == ( (a * b) % 2 == 0 );
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_even;

    //@ assert bounds(a, b);
    //@ assert a * b <= 10000 * 10000;

    product = a * b;
    is_even = (product % 2) == 0;
    return is_even;
}
