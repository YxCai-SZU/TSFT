#include <stdint.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 10;

    logic integer add(integer a, integer b) = a + b;
    logic integer sub(integer a, integer b) = a - b;
    logic integer mul(integer a, integer b) = a * b;

    lemma mul_bound: \forall integer a, b; in_range(a) && in_range(b) ==> mul(a, b) <= 100;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == add(a, b) || \result == sub(a, b) || \result == mul(a, b);
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t res;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert mul(a, b) <= 100;

    if (a > b) {
        res = a - b;
    } else if (a + b > 10) {
        res = a + b;
    } else {
        res = a * b;
    }

    //@ assert res == add(a, b) || res == sub(a, b) || res == mul(a, b);
    //@ assert res >= 0;
    return res;
}
