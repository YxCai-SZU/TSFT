#include <limits.h>

/*@
    predicate in_range(integer x) = -10000 <= x && x <= 10000;
*/

/*@
    logic integer sum(integer a, integer b, integer c) = a + b + c;
*/

/*@
    lemma sum_in_range:
        \forall integer a, b, c;
        in_range(a) && in_range(b) && in_range(c) && in_range(a + b + c) ==>
        in_range(sum(a, b, c));
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    requires in_range(a + b + c);
    ensures \result == sum(a, b, c);
    ensures in_range(\result);
*/
int associative_add(int a, int b, int c) {
    int result;
    //@ assert in_range(a) && in_range(b) && in_range(c);
    //@ assert in_range(a + b + c);
    result = a + b + c;
    //@ assert result == sum(a, b, c);
    //@ assert in_range(result);
    return result;
}
