#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 20 && 1 <= b <= 20;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        valid_input(a, b) ==> 1 <= product(a, b) <= 400;
*/

/*@
    requires valid_input(a, b);
    ensures (a < 10 && b < 10) ==> \result == product(a, b);
    ensures (a < 10 && b >= 10) ==> \result == -1;
    ensures (a >= 10 && b < 10) ==> \result == -1;
    ensures (a >= 10 && b >= 10) ==> \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t a_i32;
    int32_t b_i32;
    int32_t product_val;
    int32_t result;

    a_i32 = (int32_t)a;
    b_i32 = (int32_t)b;

    //@ assert valid_input(a, b);
    //@ assert product_bounds: 1 <= product(a, b) <= 400;

    product_val = a_i32 * b_i32;

    //@ assert product_val == product(a, b);

    if (a_i32 < 10 && b_i32 < 10)
    {
        result = product_val;
    }
    else
    {
        result = -1;
    }

    //@ assert (a_i32 < 10 && b_i32 < 10) ==> result == product(a, b);
    //@ assert (a_i32 < 10 && b_i32 >= 10) ==> result == -1;
    //@ assert (a_i32 >= 10 && b_i32 < 10) ==> result == -1;
    //@ assert (a_i32 >= 10 && b_i32 >= 10) ==> result == -1;

    return result;
}
