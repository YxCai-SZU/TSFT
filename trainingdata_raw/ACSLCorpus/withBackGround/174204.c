#include <stdint.h>

/*@
    predicate is_in_range(integer x) =
        101 <= x && x <= 100000000000000000;

    logic integer compute_result(integer x) =
        (x / 100) * 100 + (((x % 100) + 5) / 100) * 100;
*/

/*@
    requires is_in_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t a;
    uint64_t b;
    uint64_t c;
    uint64_t d;
    uint64_t result;

    a = x / 100;
    //@ assert a == x / 100;

    b = x % 100;
    //@ assert b == x % 100;

    c = b + 5;
    //@ assert c == b + 5;

    d = c / 100;
    //@ assert d == c / 100;

    result = a * 100 + d * 100;
    return result;
}
