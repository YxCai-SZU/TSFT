#include <stdint.h>

/*@
    predicate non_negative(uint64_t x) = x >= 0;
    predicate no_overflow(uint64_t a, uint64_t b) = a <= 0xFFFFFFFFFFFFFFFF - b;
    predicate result_ge_a(uint64_t result, uint64_t a) = result >= a;
    predicate result_ge_b(uint64_t result, uint64_t b) = result >= b;
    logic integer add_spec(uint64_t a, uint64_t b) = a + b;
*/

/*@
    requires non_negative(a);
    requires non_negative(b);
    requires no_overflow(a, b);
    ensures \result == add_spec(a, b);
    ensures result_ge_a(\result, a);
    ensures result_ge_b(\result, b);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    //@ assert non_negative(a);
    //@ assert non_negative(b);
    //@ assert no_overflow(a, b);
    //@ assert a + b <= 0xFFFFFFFFFFFFFFFF;
    //@ assert a + b >= 0;
    //@ assert a + b >= a;
    //@ assert a + b >= b;
    return a + b;
}
