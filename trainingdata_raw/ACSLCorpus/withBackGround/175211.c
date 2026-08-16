#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer expected_result(integer a, integer b) =
        a * b - (a + b - 1);

    lemma multiplication_bounds:
        \forall integer a, b;
            valid_inputs(a, b) ==> 1 <= a * b <= 10000;

    lemma subtraction_nonnegative:
        \forall integer a, b;
            valid_inputs(a, b) ==> a * b >= a + b - 1;

    lemma result_nonnegative:
        \forall integer a, b;
            valid_inputs(a, b) ==> a * b - (a + b - 1) >= 0;

    lemma calculation_correctness:
        \forall integer a, b, c;
            valid_inputs(a, b) && c == a + b - 1 ==>
                (int)(a * b - c) == (int)a * (int)b - (int)c;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result == (int)expected_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t c;
    int32_t ans;

    //@ assert valid_inputs(a, b);
    
    //@ assert 1 <= a * b <= 10000;
    //@ assert a * b >= a + b - 1;
    //@ assert a * b - (a + b - 1) >= 0;
    
    c = a + b - 1;
    ans = (int32_t)a * (int32_t)b - (int32_t)c;
    
    //@ assert ans == (int32_t)(a * b - (a + b - 1));
    return ans;
}
