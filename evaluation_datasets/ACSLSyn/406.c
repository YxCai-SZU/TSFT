#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Predicates from first function */
/*@
    predicate is_increasing(integer a, integer b, integer c) =
        a < b && b < c;
    predicate is_decreasing(integer a, integer b, integer c) =
        a > b && b > c;
    predicate is_monotonic(integer a, integer b, integer c) =
        is_increasing(a, b, c) || is_decreasing(a, b, c);
*/

/*@
    lemma monotonic_equivalence:
        \forall integer a, b, c;
            (a < b && b < c) || (a > b && b > c) <==> is_monotonic(a, b, c);
*/

bool func_monotonic(const unsigned int* x) {
    bool increasing;
    bool decreasing;
    bool result;

    //@ assert x[0] > 0 && x[1] > 0 && x[2] > 0;
    //@ assert x[0] <= 100 && x[1] <= 100 && x[2] <= 100;

    increasing = (x[0] < x[1]) && (x[1] < x[2]);
    decreasing = (x[0] > x[1]) && (x[1] > x[2]);
    result = increasing || decreasing;

    //@ assert result == true <==> is_monotonic(x[0], x[1], x[2]);
    return result;
}

/* Predicates from second function */
/*@
    predicate is_valid_range(integer n) =
        1 <= n && n <= 1000000;

    logic integer mod_result(integer n) =
        n % 1000;

    logic integer conditional_result(integer n) =
        (1000 - (n % 1000) < 1000) ? 
        (1000 - (n % 1000)) : 0;

    lemma mod_bound: \forall integer n; is_valid_range(n) ==> 0 <= n % 1000 && n % 1000 < 1000;
    lemma no_overflow: \forall integer n; is_valid_range(n) ==> 0 <= 1000 - (n % 1000) && 1000 - (n % 1000) <= 1000;
*/

size_t func_roundup(size_t n)
{
    size_t mo;
    size_t result;

    //@ assert n % 1000 == n % 1000;
    mo = n % 1000;
    
    if (1000 - mo < 1000) {
        result = 1000 - mo;
    } else {
        result = 0;
    }
    
    return result;
}

/* Predicates from third function */
/*@ predicate valid_range_count(integer n) = 1 <= n <= 100; */
/*@ predicate valid_number(integer x) = 1 <= x <= 1000; */
/*@ predicate valid_array(int32_t *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> valid_number(arr[i]); */

uint32_t func_count_multiples(uint32_t n, int32_t *arr) {
    uint32_t count = 0;
    uint32_t index = 0;
    
    while (index < n) {
        int32_t i = arr[index];
        bool condition = false;
        
        if ((i % 2 == 0 && i % 3 == 0 && i % 5 == 0) ||
            (i % 2 == 0 && i % 3 == 0 && i % 5 != 0) ||
            (i % 2 == 0 && i % 3 != 0 && i % 5 == 0) ||
            (i % 2 != 0 && i % 3 == 0 && i % 5 == 0)) {
            condition = true;
        }
        
        if (condition) {
            //@ assert count + 1 <= n;
            count += 1;
        }
        
        index += 1;
    }
    
    return count;
}

/* Predicates from fourth function */
/*@
    predicate valid_range_hour(integer x) = 0 <= x && x <= 23;

    logic integer mod24(integer x) = x % 24;

    lemma sum_bound: \forall integer a, b; 
        valid_range_hour(a) && valid_range_hour(b) ==> a + b < 48;
*/

uint32_t func_add_hours(uint32_t a, uint32_t b) {
    uint32_t result;

    //@ assert valid_range_hour(a);
    //@ assert valid_range_hour(b);
    //@ assert a + b < 48;

    result = a + b;
    return result % 24;
}

/* 
 * Scenario: Automated Quality Control System for a Manufacturing Plant
 * 
 * This synthesized function processes batches of product measurements. Each batch:
 * - Takes three consecutive measurements (x[0], x[1], x[2]) to check monotonic trends
 * - Counts how many products in an array meet specific quality criteria (multiples of 2,3,5)
 * - Rounds up the count to the nearest multiple of 1000 for reporting
 * - Converts the final result to a 24-hour timestamp format for logging
 * 
 * The function ensures that the final timestamp is valid (0-23) and that all 
 * intermediate steps maintain their respective invariants.
 */

uint32_t process_quality_batch(const unsigned int* x, uint32_t n, int32_t *arr, 
                                size_t roundup_target, uint32_t base_hour) 
{
    bool monotonic;
    uint32_t quality_count;
    size_t rounded_count;
    uint32_t final_timestamp;
    
    monotonic = func_monotonic(x);
    
    quality_count = func_count_multiples(n, arr);
    
    if (monotonic && quality_count > 0) {
        size_t adjusted_target = (size_t)(quality_count % 1000000 + 1);
        rounded_count = func_roundup(adjusted_target);
    } else {
        rounded_count = 0;
    }
    
    uint32_t hours_to_add = (uint32_t)(rounded_count % 24);
    final_timestamp = func_add_hours(base_hour, hours_to_add);
    
    //@ assert valid_range_hour(final_timestamp);
    return final_timestamp;
}
