#include <stdint.h>

/*@
    predicate bounds(integer v) = 1 <= v <= 10000;

    lemma sum_bounds:
        \forall integer a, integer c;
            bounds(a) && bounds(c) ==> a + c <= 20000;

    lemma result_range:
        \forall integer a, integer b, integer c, integer d;
            bounds(a) && bounds(b) && bounds(c) && bounds(d) ==>
            (a + c < b + d ==> 0 == 0 || 0 == 1) &&
            (a + c > b + d ==> 1 == 0 || 1 == 1) &&
            (a + c == b + d ==> 0 == 0 || 0 == 1);
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c) && bounds(d);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t ac_sum;
    uint32_t bd_sum;
    int32_t result;

    //@ assert bounds(a);
    //@ assert bounds(c);
    ac_sum = a + c;
    //@ assert ac_sum <= 20000;

    //@ assert bounds(b);
    //@ assert bounds(d);
    bd_sum = b + d;
    //@ assert bd_sum <= 20000;

    if (ac_sum < bd_sum)
    {
        result = 0;
    }
    else if (ac_sum > bd_sum)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    //@ assert result == 0 || result == 1;
    return result;
}
