#include <stdbool.h>

/* ACSL predicates from original functions */
/*@
    predicate a_bounds(integer a) = 0 <= a <= 100;
    predicate b_bounds(integer b) = 0 <= b <= 100;
    predicate x_bounds(integer x) = 0 <= x <= 100;
*/

/*@
    predicate valid_params(integer n, integer m, integer k) =
        1 <= n && n <= 1000 &&
        1 <= m && m <= 1000 &&
        0 <= k && k <= n * m;

    logic integer remainder_val(integer n, integer m, integer k) = n * m - k;

    predicate result_condition(integer n, integer m, integer k) =
        remainder_val(n, m, k) < 2 || remainder_val(n, m, k) >= 5;
*/

/* Original function 1: checks if x is within a certain range relative to a and b */
bool func1(unsigned int a, unsigned int b, unsigned int x)
{
    bool res;
    
    //@ assert a_bounds(a) && b_bounds(b) && x_bounds(x);
    
    if (x > a + b || a > x) {
        res = false;
        //@ assert !(x <= a + b && a <= x);
    } else {
        //@ assert x <= a + b && a <= x;
        res = true;
    }
    
    //@ assert res == (x <= a + b && a <= x);
    return res;
}

/* Original function 2: checks remainder condition */
bool func2(unsigned int n, unsigned int m, unsigned int k)
{
    unsigned int remainder;
    bool is_less_than_2;
    bool is_greater_than_or_equal_to_5;
    bool result;

    //@ assert 1 <= n && n <= 1000;
    //@ assert 1 <= m && m <= 1000;
    //@ assert 0 <= k && k <= n * m;
    
    //@ assert n * m <= 1000000;
    remainder = n * m;
    
    //@ assert remainder >= k;
    remainder = remainder - k;
    
    is_less_than_2 = remainder < 2;
    is_greater_than_or_equal_to_5 = remainder >= 5;
    result = is_less_than_2 || is_greater_than_or_equal_to_5;
    
    //@ assert result == (remainder < 2 || remainder >= 5);
    return result;
}

/* Scenario: Memory allocation validation in an embedded system
 * 
 * Given a memory block of size n*m with k bytes already used,
 * we want to allocate a buffer of size x from the remaining space.
 * The allocation is valid if:
 * - x is within bounds [a, a+b] (where a is a fixed base, b is tolerance)
 * - The remaining memory after allocation is either very small (<2 bytes)
 *   or sufficiently large (>=5 bytes) to avoid fragmentation issues
 */

/*@
    predicate valid_allocation(integer a, integer b, integer x, integer n, integer m, integer k) =
        a_bounds(a) && b_bounds(b) && x_bounds(x) &&
        valid_params(n, m, k) &&
        (x <= a + b && a <= x) &&
        (remainder_val(n, m, k + x) < 2 || remainder_val(n, m, k + x) >= 5);
*/

bool memory_allocation_check(unsigned int a, unsigned int b, unsigned int x,
                             unsigned int n, unsigned int m, unsigned int k)
{
    bool range_check_result;
    bool remainder_check_result;
    bool final_result;
    
    range_check_result = func1(a, b, x);
    
    remainder_check_result = func2(n, m, k + x);
    
    final_result = range_check_result && remainder_check_result;
    
    //@ assert final_result == (range_check_result && remainder_check_result);
    
    //@ assert final_result ==> valid_allocation(a, b, x, n, m, k);
    
    return final_result;
}
