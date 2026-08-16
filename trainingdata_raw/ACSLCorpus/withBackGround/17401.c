#include <stdint.h>

/*@
    predicate is_valid_u64(integer x) = 0 <= x <= 1000000000;

    logic integer func_spec(integer a, integer b) =
        a > 2 * b ? b + (a - 2 * b) / 4 : b + a / 2;

    lemma func_lemma1:
        \forall integer a, b;
            is_valid_u64(a) && is_valid_u64(b) ==>
            func_spec(a, b) <= a + b;

    lemma func_lemma2:
        \forall integer a, b;
            is_valid_u64(a) && is_valid_u64(b) ==>
            func_spec(a, b) >= b;
*/

/*@
    requires is_valid_u64(a);
    requires is_valid_u64(b);
    ensures \result <= a + b;
    ensures \result >= b;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    uint64_t extra;
    uint64_t ans;

    if (a > 2 * b)
    {
        //@ assert a >= 2 * b;
        //@ assert a - 2 * b <= 1000000000;

        extra = a - 2 * b;
        ans = b + extra / 4;

        //@ assert ans <= a + b;
        //@ assert ans >= b;
        return ans;
    }
    else
    {
        //@ assert b + a / 2 <= a + b;
        return b + a / 2;
    }
}
