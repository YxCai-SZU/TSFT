#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        1 <= a <= 500 &&
        1 <= b <= 500 &&
        1 <= c <= 1000;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_bound: \forall integer a, b;
        bounds(a, b, 0) ==> sum(a, b) <= 1000;
*/

/*@
    requires bounds(a, b, c);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ab;
    //@ assert bounds(a, b, c);
    ab = a + b;
    //@ assert ab == sum(a, b);
    //@ assert ab <= 1000;
    return ab >= c;
}
