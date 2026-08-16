#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && 1 <= k && k <= a + b + c;

    logic integer func_result(integer a, integer b, integer c, integer k) =
        k >= a ? a : (k >= a + b ? a : (k >= a + b + c ? a : k));

    lemma result_bound: \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==> func_result(a, b, c, k) <= a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t a_cnt;
    int32_t k_cnt;
    int32_t c_cnt;

    a_cnt = a;
    k_cnt = k;

    //@ assert a_cnt >= 0 && k_cnt >= 1;

    if (k_cnt >= a_cnt)
    {
        k_cnt = k_cnt - a_cnt;
        //@ assert a_cnt <= a;
        return a_cnt;
    }
    else
    {
        a_cnt = k_cnt;
        k_cnt = 0;
    }

    //@ assert a_cnt >= 0 && a_cnt <= a;

    if (k_cnt >= b)
    {
        k_cnt = k_cnt - b;
    }
    else
    {
        k_cnt = 0;
    }

    //@ assert k_cnt >= 0;

    c_cnt = -k_cnt;

    //@ assert a_cnt + c_cnt <= a;

    return a_cnt + c_cnt;
}
