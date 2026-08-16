#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_sum(integer a, integer b, integer c) =
      a + b == c || a + c == b || b + c == a;
*/

bool find_value(unsigned long a, unsigned long b, unsigned long c) {
    bool is_valid = false;
    unsigned long sum1;
    unsigned long sum2;
    unsigned long sum3;

    sum1 = a + b;
    sum2 = a + c;
    sum3 = b + c;

    //@ assert sum1 == a + b;
    //@ assert sum2 == a + c;
    //@ assert sum3 == b + c;

    if (sum1 == c || sum2 == b || sum3 == a) {
        is_valid = true;
    }

    //@ assert is_valid == (sum1 == c || sum2 == b || sum3 == a);
    return is_valid;
}

/*@
    predicate non_negative(integer x) = x >= 0;
    predicate k_in_range(integer k) = 1 <= k && k <= 200;
*/

int32_t func(int32_t a, int32_t b, int32_t c, int64_t k)
{
    int32_t a_local = a;
    int64_t k_local = k;
    int32_t b_local;
    int32_t c_local;
    int32_t result;

    if (k_local > (int64_t)a_local)
    {
        k_local = k_local - (int64_t)a_local;
        a_local = 0;
    }
    else
    {
        a_local = a_local - (int32_t)k_local;
        k_local = 0;
    }

    b_local = b;
    if (k_local > (int64_t)b_local)
    {
        k_local = k_local - (int64_t)b_local;
        b_local = 0;
    }
    else
    {
        b_local = b_local - (int32_t)k_local;
        k_local = 0;
    }

    c_local = c;
    if (k_local > (int64_t)c_local)
    {
        k_local = k_local - (int64_t)c_local;
        c_local = 0;
    }
    else
    {
        c_local = c_local - (int32_t)k_local;
        k_local = 0;
    }

    result = a_local - c_local;
    if (result < 0)
    {
        result = 0;
    }

    //@ assert result <= a_local;
    //@ assert result >= 0;

    return result;
}

/* Scenario: Resource Allocation Validation System
 * 
 * Description: In a resource-constrained embedded system, we have three resource pools (a, b, c)
 * with sizes between 1 and 100. A valid allocation must satisfy that one resource pool's size
 * equals the sum of the other two (is_valid_sum). We then simulate a consumption process where
 * k units (1 to 200) are consumed sequentially from the pools. The final result is the remaining
 * resource in pool a after subtracting pool c's remaining, clamped to non-negative. The high-level
 * property asserts that if the initial allocation is valid (one pool equals sum of other two),
 * then after consumption, the result cannot exceed the original pool a size.
 */

int32_t resource_validation(unsigned long a, unsigned long b, unsigned long c, int64_t k)
{
    bool valid_allocation = find_value(a, b, c);
    
    int32_t result = func((int32_t)a, (int32_t)b, (int32_t)c, k);
    
    //@ assert (valid_allocation == 1) ==> (result <= a);
    
    return result;
}
