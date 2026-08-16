#include <stdint.h>

/*@
    predicate bounds(integer a, integer b) =
        a < 1000000000 && b < 1000000000;
*/

/*@
    logic integer multiply(integer a, integer b) = a * b;
*/

/*@
    lemma mult_associative:
        \forall integer x, y, z;
            bounds(x, y) && bounds(y, z) ==>
            x * (y * z) == (x * y) * z;
*/

/*@
    lemma mult_distributive:
        \forall integer x, y, z;
            bounds(x, y) && bounds(y, z) ==>
            x * (y + z) == x * y + x * z;
*/

/*@
    lemma mult_commutes:
        \forall integer x, y;
            bounds(x, y) ==>
            x * y == y * x;
*/

/*@
    requires a < 1000000000 && b < 1000000000;
    ensures \result == a * b;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    //@ assert a * b < 18446744073709551615;
    return a * b;
}
