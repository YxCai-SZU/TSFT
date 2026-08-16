#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer compute_expr(integer a, integer b) = a + b * 2;

    predicate expr_even(integer a, integer b) = compute_expr(a, b) % 2 == 0;

    logic integer result_value(integer a, integer b) =
        compute_expr(a, b) / 2 - b;

    lemma division_ge_b: \forall integer a, b;
        valid_range(a, b) && expr_even(a, b) ==>
        compute_expr(a, b) / 2 >= b;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> expr_even(a, b) && \result == result_value(a, b);
    ensures \result == -1 ==> !expr_even(a, b);
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t expr;
    int32_t ret_val;

    expr = a + b * 2;
    
    if (expr % 2 == 0)
    {
        //@ assert expr_even(a, b);
        //@ assert expr / 2 >= b;
        ret_val = (int32_t)(expr / 2) - (int32_t)b;
        //@ assert ret_val == result_value(a, b);
        return ret_val;
    }
    else
    {
        //@ assert !expr_even(a, b);
        //@ assert expr / 2 >= b;
        return -1;
    }
}
