#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
*/

/*@
    lemma ordering_equivalence:
        \forall integer a, b, c;
            a < b && b < c <==> is_ordered(a, b, c);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> is_ordered(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert a < b && b < c <==> is_ordered(a, b, c);
    result = (a < b) && (b < c);
    return result;
}
