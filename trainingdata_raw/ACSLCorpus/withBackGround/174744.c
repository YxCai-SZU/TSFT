#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x && x <= 1000000000;
    logic integer compute_result(integer x) = 
        (x / 500) * 1000 + (x % 500) / 5 * 5;
*/

/*@
    requires is_valid_input(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t n;
    uint64_t m;
    uint64_t o;
    uint64_t p;

    n = x / 500;
    m = x % 500;
    o = m / 5;
    p = n * 1000 + o * 5;

    //@ assert p == (x / 500) * 1000 + (x % 500) / 5 * 5;
    return p;
}
