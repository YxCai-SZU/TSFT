#include <stdint.h>

/*@ predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate sum_valid(integer a, integer b, integer sum) = sum == a * 3 + b;
    predicate loop_inv(integer a, integer b, integer temp_sum, integer count, integer sum) = 
        a_in_range(a) && b_in_range(b) && temp_sum >= 0 && 
        sum_valid(a, b, sum) && temp_sum + 2 * count == sum;
 */

/*@ logic integer compute_expected(integer a, integer b) = (a * 3 + b) / 2 - a; */

/*@ lemma overflow_bound_a3: \forall integer a; a_in_range(a) ==> a * 3 <= 300;
    lemma overflow_bound_sum: \forall integer a, integer b; a_in_range(a) && b_in_range(b) ==> a * 3 + b <= 400;
 */

/*@ requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    ensures \result == compute_expected(a, b);
    assigns \nothing;
 */
int32_t func(uint32_t a, uint32_t b)
{
    //@ assert a * 3 <= 300;
    //@ assert a * 3 + b <= 400;
    
    uint32_t sum = a * 3 + b;
    int32_t result = 0;
    uint32_t temp_sum = sum;
    uint32_t count = 0;
    
    /*@ loop invariant loop_inv(a, b, temp_sum, count, sum);
        loop assigns temp_sum, count;
        loop variant temp_sum;
     */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    
    result = (int32_t)count;
    int32_t final_result = result - (int32_t)a;
    //@ assert final_result == compute_expected(a, b);
    return final_result;
}
