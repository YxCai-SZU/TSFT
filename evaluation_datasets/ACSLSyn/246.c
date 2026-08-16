#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

/* Helper functions from snippets */

/*@
    logic integer max(integer x, integer y) =
        (x > y) ? x : y;

    lemma max_is_total:
        \forall integer x, y;
            max(x, y) == x || max(x, y) == y;
*/

int max_func(int x, int y) {
    int result;
    
    if (x > y) {
        result = x;
    } else {
        result = y;
    }
    
    return result;
}

/*@ predicate valid_array(int64_t *a, integer n) =
      \forall integer i; 0 <= i < n ==> a[i] <= 100000000000000000;
*/

/*@ predicate distinct_elements(int64_t *a, integer n) =
      \forall integer i, j; 0 <= i < j < n ==> a[i] != a[j];
*/

int64_t find_increasing_triple(int64_t n, int64_t a[]) {
    int64_t ans = -1;
    int64_t i = 1;
    
    while (i < n - 1) {
        if (a[i - 1] < a[i] && a[i] < a[i + 1]) {
            ans = i;
            break;
        }
        i += 1;
    }
    return ans;
}

/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100;
    
    logic integer expected_result(integer n) = (n / 2) * ((n + 1) / 2);
    
    lemma result_bound: \forall integer n; is_valid_n(n) ==> expected_result(n) <= 2500;
*/

uint64_t compute_product(uint64_t n)
{
    uint32_t n_u32;
    uint32_t res_u32;
    uint64_t res_u64;
    
    n_u32 = (uint32_t)n;
    
    res_u32 = (n_u32 / 2) * ((n_u32 + 1) / 2);
    res_u64 = (uint64_t)res_u32;
    
    return res_u64;
}

/* Synthesized complex function: Array pattern analysis with size validation
 * 
 * Scenario: Given an array of distinct integers, find if there exists an 
 * increasing triple (three consecutive elements in strictly increasing order).
 * If found, return the product based on the array size, otherwise return 0.
 * The function uses max_func to compare the array size with a threshold,
 * find_increasing_triple to locate the pattern, and compute_product to 
 * compute the result based on the size.
 */

uint64_t analyze_array_pattern(int64_t n, int64_t a[]) {
    int64_t triple_index;
    uint64_t result;
    int threshold_comparison;
    
    threshold_comparison = max_func((int)n, 50);
    
    triple_index = find_increasing_triple(n, a);
    
    result = compute_product((uint64_t)n);
    
    if (triple_index == -1) {
        result = 0;
    }
    
    return result;
}
