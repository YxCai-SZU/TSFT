#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;

    logic integer func_res(integer a) =
        a <= 5 ? 2 * a : 2 * a + 1;

    lemma func_correctness:
        \forall integer a;
        a_in_range(a) ==> func_res(a) == (a <= 5 ? 2 * a : 2 * a + 1);
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == (a <= 5 ? 2 * a : 2 * a + 1);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    int32_t res;
    int32_t a_;
    uint32_t b_;

    //@ assert a_in_range(a);

    if (a <= 5)
    {
        a_ = (int32_t)a;
        //@ assert a <= 5;
        res = 2 * a_;
        //@ assert res == 2 * a;
    }
    else
    {
        a_ = (int32_t)a;
        b_ = a * 2 + 1;
        //@ assert a > 5;
        res = (int32_t)b_;
        //@ assert res == 2 * a + 1;
    }

    //@ assert res == func_res(a);
    return res;
}
