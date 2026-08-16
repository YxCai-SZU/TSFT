#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 2 <= a && a <= 100;
    predicate b_in_range(integer b) = 2 <= b && b <= 100;
    predicate product_in_range(integer a, integer b) = a * b <= 10000;
    predicate sum_in_range(integer a, integer b) = a + b - 1 <= 199;
    predicate product_ge_sum(integer a, integer b) = a * b >= a + b - 1;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == (a * b - (a + b - 1));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t product;
    uint32_t sum_minus_one;
    uint32_t result_u32;
    int32_t result;

    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    //@ assert product_in_range(a, b);
    //@ assert sum_in_range(a, b);
    //@ assert product_ge_sum(a, b);
    
    product = a * b;
    sum_minus_one = a + b - 1;
    result_u32 = product - sum_minus_one;
    result = (int32_t)result_u32;
    
    return result;
}
