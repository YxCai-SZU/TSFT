#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 10;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> product(a, b) <= 100;
*/

/*@
    requires in_range(x);
    requires in_range(y);
    requires in_range(z);
    ensures \result == (x * y <= z || y * z <= x || x * z <= y);
*/
bool func(int x, int y, int z)
{
    // Variable declarations at scope top
    bool result;

    //@ assert in_range(x);
    //@ assert in_range(y);
    //@ assert in_range(z);
    //@ assert product(x, y) <= 100;
    //@ assert product(y, z) <= 100;
    //@ assert product(x, z) <= 100;

    result = (x * y <= z || y * z <= x || x * z <= y);
    return result;
}
