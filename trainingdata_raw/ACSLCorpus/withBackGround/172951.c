#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - (a + b - 1);

    lemma a_plus_b_minus_1_bound:
        \forall integer a, b;
            valid_range(a, b) ==> a + b - 1 <= 199;

    lemma a_times_b_bound:
        \forall integer a, b;
            valid_range(a, b) ==> a * b <= 10000;

    lemma non_negative_result:
        \forall integer a, b;
            valid_range(a, b) ==> a * b >= a + b - 1;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t sum_minus_one;
    uint32_t product;
    int32_t result;

    //@ assert valid_range(a, b);
    
    sum_minus_one = a + b - 1;
    //@ assert sum_minus_one <= 199;
    
    product = a * b;
    //@ assert product <= 10000;
    
    //@ assert product >= sum_minus_one;
    
    result = (int32_t)(product - sum_minus_one);
    //@ assert result == compute_result(a, b);
    
    return result;
}
