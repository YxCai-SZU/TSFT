#include <stdint.h>
/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    lemma product_bound: \forall integer x, y; valid_range(x) && valid_range(y) ==> x * y <= 10000;
*/

/*@
    requires valid_range(x) && valid_range(y);
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert x * y <= 10000;
    return x * y;
}

/*@
    requires valid_range(x) && valid_range(y);
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t func2(uint32_t x, uint32_t y)
{
    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert x * y <= 10000;
    return x * y;
}
