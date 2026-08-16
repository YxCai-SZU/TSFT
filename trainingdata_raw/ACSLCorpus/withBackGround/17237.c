#include <stdbool.h>

/*@
    predicate in_range(integer x) = 0 <= x <= 20;

    lemma product_in_range:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> 0 <= a * b <= 400;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (a * b <= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert in_range(a) && in_range(b) && in_range(c);
    //@ assert 0 <= a * b <= 400;

    result = (a * b <= c);
    return result;
}
