#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ACSL predicates and lemmas from original snippets */
/*@ predicate is_less_than_100(integer x) = x < 100; */

/*@
    predicate a_in_range(integer a) = a >= 1;
    predicate b_in_range(integer b) = b <= 10000;
    predicate c_in_range(integer c) = c >= 1;
    predicate d_in_range(integer d) = d <= 10000;
    
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        (a >= c && a <= d) || (c >= a && c <= b);
*/

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a <= 100 &&
        0 <= b <= 100 &&
        0 <= c <= 100 &&
        1 <= k <= 3;

    logic integer min(integer x, integer y) = x < y ? x : y;
    logic integer max(integer x, integer y) = x > y ? x : y;

    lemma min_nonnegative: \forall integer x, y; x >= 0 && y >= 0 ==> min(x, y) >= 0;
    lemma max_nonnegative: \forall integer x, y; x >= 0 && y >= 0 ==> max(x, y) >= 0;
*/

/* Original function 1: process_list */
bool process_list(const int* v, size_t len) {
    size_t j;
    bool result = true;
    
    for (j = 0; j < len; ++j) {
        //@ assert is_less_than_100(v[j]);
        if (!(v[j] < 100)) {
            result = false;
            break;
        }
    }
    
    //@ assert result == true;
    return result;
}

/* Original function 2: interval overlap check */
bool func_interval(long long a, long long b, long long c, long long d)
{
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert c_in_range(c);
    //@ assert d_in_range(d);
    
    if ((a >= c && a <= d) || (c >= a && c <= b)) {
        return true;
    } else {
        return false;
    }
}

/* Original function 3: resource allocation calculation */
int64_t func_resource(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t res = 0;
    int64_t k_remaining = k;
    int64_t a_remaining = a;

    //@ assert 0 <= a && a <= 100;
    //@ assert 1 <= k && k <= 3;

    int64_t min_a_k = a < k_remaining ? a : k_remaining;
    //@ assert min_a_k == min(a, k_remaining);
    res += min_a_k;
    k_remaining -= min_a_k;
    a_remaining -= min_a_k;

    int64_t max_0_k_remaining = 0 > k_remaining ? 0 : k_remaining;
    //@ assert max_0_k_remaining == max(0, k_remaining);
    k_remaining -= max_0_k_remaining;

    int64_t min_b_k = b < k_remaining ? b : k_remaining;
    //@ assert min_b_k == min(b, k_remaining);
    k_remaining -= min_b_k;

    res -= k_remaining;

    //@ assert res >= 0;
    //@ assert res <= k;
    return res;
}

/* Synthesized function: smart resource scheduling with validation
 * Scenario: A system that validates resource availability (via process_list),
 * checks if resource intervals overlap (via func_interval), and then
 * calculates the optimal resource allocation (via func_resource).
 * The high-level property: if all resources are valid and intervals overlap,
 * the allocation result is non-negative and bounded by the resource limit.
 */
int64_t smart_resource_scheduler(const int* v, size_t len,
                                  long long a, long long b, long long c, long long d,
                                  int64_t res_a, int64_t res_b, int64_t res_c, int64_t k)
{
    bool list_valid = process_list(v, len);
    //@ assert list_valid == true;
    
    bool overlap = func_interval(a, b, c, d);
    //@ assert overlap == true;
    
    int64_t allocation = func_resource(res_a, res_b, res_c, k);
    
    //@ assert allocation >= 0 && allocation <= k;
    
    return allocation;
}
