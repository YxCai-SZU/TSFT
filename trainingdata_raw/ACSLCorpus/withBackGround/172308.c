#include <stdbool.h>

/*@
    predicate bounds(integer a) = 1 <= a <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer a, b;
            bounds(a) && bounds(b) ==> product(a, b) <= 10000 * 10000;
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c) && bounds(d);
    ensures \result == true <==> (a * c <= b && b * d <= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert bounds(a) && bounds(c);
    //@ assert product(a, c) <= 10000 * 10000;

    //@ assert bounds(b) && bounds(d);
    //@ assert product(b, d) <= 10000 * 10000;

    if (a * c <= b && b * d <= c) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
