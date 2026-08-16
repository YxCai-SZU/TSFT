#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 10000;

    logic integer product_mod2(integer a, integer b) = (a * b) % 2;

    lemma product_bound: \forall integer a, b; in_range(a) && in_range(b) ==> a * b <= 10000 * 10000;
    lemma mod2_identity: \forall integer a, b; in_range(a) && in_range(b) ==> product_mod2(a, b) == (a * b) % 2;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == (product_mod2(a, b) == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Declare all variables at the top
    unsigned int product;
    bool result;

    //@ assert in_range(a) && in_range(b);
    product = a * b;
    //@ assert product_mod2(a, b) == (product % 2);
    result = (product % 2) == 0;

    return result;
}
