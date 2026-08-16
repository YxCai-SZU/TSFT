#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100;

    logic integer arithmetic_property(integer a, integer b, integer c) =
        (b - a == c - b) ? 1 : 0;

    lemma range_lemma:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==>
            arithmetic_property(a, b, c) == (b - a == c - b);
*/

/*@
    requires in_range(a);
    requires in_range(b);
    requires in_range(c);
    ensures \result == (arithmetic_property(a, b, c) == 1);
    ensures \result == (b - a == c - b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);

    result = (b - a == c - b);
    return result;
}
