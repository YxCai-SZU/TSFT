#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 20;

    logic integer div_mul(integer t, integer a, integer b) = (t / a) * b;

    lemma div_bound: \forall integer t, a; 1 <= t <= 20 && 1 <= a <= 20 ==> t / a <= 20;
    lemma mul_bound: \forall integer x, b; 0 <= x <= 20 && 1 <= b <= 20 ==> 0 <= x * b <= 400;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(t);
    ensures \result == div_mul(t, a, b);
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t)
{
    uint32_t div_result;
    uint32_t result;

    //@ assert 1 <= a <= 20;
    //@ assert 1 <= b <= 20;
    //@ assert 1 <= t <= 20;

    div_result = t / a;

    //@ assert div_result <= 20;
    //@ assert div_result >= 0;

    result = div_result * b;

    //@ assert result <= 400;
    //@ assert result >= 0;
    //@ assert result == div_mul(t, a, b);

    return result;
}
