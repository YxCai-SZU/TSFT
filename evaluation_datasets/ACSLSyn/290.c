#include <stdint.h>
#include <stdbool.h>

/* First function - XOR parity check with position search */
/*@
    predicate valid_array_size(integer n) = 2 <= n && n <= 100000;
    predicate array_bounds(int64_t *a, integer n) = 0 <= n && \valid(a + (0 .. n-1));
    predicate array_values_bounded(int64_t *a, integer n) = 
        \forall integer i; 0 <= i < n ==> a[i] <= 100000000000000000;
*/

int64_t find_xor_match(uint64_t n, int64_t *a) {
    uint64_t cnt = 0;
    uint64_t i = 0;
    
    while (i < n) {
        cnt ^= a[i];
        i++;
    }
    
    bool is_zero = true;
    uint64_t j = 0;
    
    while (j < 64) {
        if (((cnt >> j) & 1) != 0) {
            is_zero = false;
            break;
        }
        j++;
    }
    
    if (is_zero) {
        return 0;
    } else {
        uint64_t k = 0;
        
        while (k < n) {
            uint64_t sub = cnt ^ a[k];
            //@ assert sub >= 0;
            if (sub == 0) {
                return k;
            }
            k++;
        }
        return -1;
    }
}

/* Second function - compute bound for large numbers */
/*@
    predicate x_in_range(integer x) = 101 <= x <= 1000000000000000000;
    logic integer bound(integer x) = (x - 100) / 100 + 1;
*/

uint64_t compute_bound(uint64_t x)
{
    uint64_t ans;
    uint64_t i;
    
    //@ assert x_in_range(x);
    if (x < 100) {
        ans = 0;
    } else {
        ans = (x - 100) / 100 + 1;
    }
    
    i = 1;
    while (i <= (x - 100) / 100 + 1) {
        //@ assert i > 0;
        //@ assert i <= bound(x) + 1;
        //@ assert bound(x) <= bound(x);
        //@ assert ans <= bound(x);
        i = i + 1;
    }
    
    return ans;
}

/* Third function - count minimum occurrences */
/*@
    predicate min_of_three(integer a, integer b, integer c, integer m) =
        m == a || m == b || m == c;
    predicate in_range(integer x) = 1 <= x && x <= 100;
    logic integer count_matches(integer a, integer b, integer c, integer m) =
        (a == m ? 1 : 0) + (b == m ? 1 : 0) + (c == m ? 1 : 0);
    lemma result_bounds:
        \forall integer a, b, c, m;
            in_range(a) && in_range(b) && in_range(c) && min_of_three(a, b, c, m) ==>
            1 <= count_matches(a, b, c, m) && count_matches(a, b, c, m) <= 3;
*/

int count_min_occurrences(int a, int b, int c)
{
    int min_ab;
    int min_all;
    int result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    
    if (c < min_ab) {
        min_all = c;
    } else {
        min_all = min_ab;
    }
    
    //@ assert min_of_three(a, b, c, min_all);
    
    result = 0;
    
    if (a == min_all) {
        result += 1;
    }
    if (b == min_all) {
        result += 1;
    }
    if (c == min_all) {
        result += 1;
    }
    
    //@ assert result == count_matches(a, b, c, min_all);
    //@ assert result >= 1;
    
    return result;
}

/* Synthesized complex function - Data validation pipeline
 * Scenario: Validates a data packet by:
 * 1. Checking XOR parity consistency across data blocks
 * 2. Computing a bound for a large parameter
 * 3. Counting minimum value occurrences for priority classification
 * The function ensures that if XOR match is found and bound is valid,
 * the minimum count is consistent with the priority classification range.
 */
int data_validation_pipeline(uint64_t n, int64_t *a, uint64_t x, int p1, int p2, int p3)
{
    int64_t xor_result;
    uint64_t bound_result;
    int min_count;
    
    xor_result = find_xor_match(n, a);
    
    bound_result = compute_bound(x);
    
    min_count = count_min_occurrences(p1, p2, p3);
    
    //@ assert (xor_result >= 0 || xor_result == -1);
    //@ assert bound_result <= (x - 100) / 100 + 1;
    //@ assert min_count >= 1 && min_count <= 3;
    
    //@ assert (xor_result >= 0 && bound_result > 0) ==> (min_count >= 1 && min_count <= 3);
    
    return min_count;
}
