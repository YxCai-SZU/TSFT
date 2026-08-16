#include <stdbool.h>

/*@
    predicate min_is_a(integer a, integer b, integer m) =
        (a < b) ==> (m == a);
    predicate max_is_a(integer a, integer b, integer m) =
        (a > b) ==> (m == a);
    predicate min_is_b(integer a, integer b, integer m) =
        (a >= b) ==> (m == b);
    predicate max_is_b(integer a, integer b, integer m) =
        (a <= b) ==> (m == b);
*/

/*@
    requires 3 <= a <= 20;
    requires 3 <= b <= 20;
    ensures \result == a + a - 1 || \result == b + b - 1 || 
            \result == a + b || \result == b + a;
*/
int func(int a, int b)
{
    int min_ab;
    int max_ab;
    int result;

    // Calculate min_ab
    //@ assert min_is_a(a, b, a) && min_is_b(a, b, b);
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    // Calculate max_ab
    //@ assert max_is_a(a, b, a) && max_is_b(a, b, b);
    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }

    //@ assert min_ab == (a < b ? a : b);
    //@ assert max_ab == (a > b ? a : b);
    //@ assert min_ab <= max_ab;
    //@ assert a + b == max_ab + min_ab;

    if (max_ab + 1 < min_ab * 2) {
        //@ assert max_ab + min_ab == a + b || max_ab + min_ab == b + a;
        result = max_ab + min_ab;
    } else {
        //@ assert min_ab * 2 - 1 == a + a - 1 || min_ab * 2 - 1 == b + b - 1;
        result = min_ab * 2 - 1;
    }

    return result;
}
