#include <stdbool.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 8;

    logic integer mul_bounded(integer a, integer b) =
        a * b;

    lemma mul_bound_lemma:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> mul_bounded(x, y) <= 100;
*/

/*@
    requires in_range(x);
    requires in_range(y);
    requires in_range(z);
    ensures \result == (x * y >= z);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product;

    //@ assert in_range(x);
    //@ assert in_range(y);
    //@ assert in_range(z);

    //@ assert mul_bounded(x, y) <= 100;

    product = x * y;
    //@ assert product == mul_bounded(x, y);
    
    result = (product >= z);
    //@ assert result == (mul_bounded(x, y) >= z);
    
    return result;
}
