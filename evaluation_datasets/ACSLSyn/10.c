#include <limits.h>
#include <stdbool.h>

/* ===== Scenario: Resource Allocation Scoring System =====
 * In a resource allocation system, we have three resource pools (a, b, c)
 * each with capacity 1-10000. We need to compute an allocation score that
 * measures how balanced the remaining resources are after a proposed
 * allocation. The score is based on the minimum difference between any
 * single resource and the sum of the other two, normalized to a positive
 * range. This function processes allocation proposals from two sources.
 */

/* --- Original func1 (renamed): computes normalized min-difference score --- */
/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer min_diff(integer a, integer b, integer c) =
        (a - (b + c) < b - (c + a)) ?
            ((a - (b + c) < c - (a + b)) ? a - (b + c) : c - (a + b))
        :
            ((b - (c + a) < c - (a + b)) ? b - (c + a) : c - (a + b));

    lemma diff_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            -19999 <= a - (b + c) <= 10000 &&
            -19999 <= b - (c + a) <= 10000 &&
            -19999 <= c - (a + b) <= 10000;

    lemma result_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            (min_diff(a, b, c) < 0 ? 0 : min_diff(a, b, c)) + 1 <= 20000;
*/

int compute_score(int a, int b, int c)
{
    int ans;
    int temp;
    int local_a;
    int local_b;
    int local_c;

    ans = INT_MAX;
    local_a = a;
    local_b = b;
    local_c = c;
    temp = 0;

    //@ assert valid_range(local_a) && valid_range(local_b) && valid_range(local_c);

    if (local_a < local_b)
    {
        temp = local_a;
        local_a = local_b;
        local_b = temp;
    }
    //@ assert local_a >= local_b;

    if (local_b < local_c)
    {
        temp = local_b;
        local_b = local_c;
        local_c = temp;
    }
    //@ assert local_b >= local_c;

    if (local_a < local_b)
    {
        temp = local_a;
        local_a = local_b;
        local_b = temp;
    }
    //@ assert local_a >= local_b && local_b >= local_c;

    //@ assert valid_range(local_a);
    //@ assert valid_range(local_b);
    //@ assert valid_range(local_c);
    //@ assert -19999 <= local_a - (local_b + local_c) <= 10000;

    if (local_a - (local_b + local_c) < ans)
    {
        ans = local_a - (local_b + local_c);
    }

    //@ assert -19999 <= local_b - (local_c + local_a) <= 10000;
    if (local_b - (local_c + local_a) < ans)
    {
        ans = local_b - (local_c + local_a);
    }

    //@ assert -19999 <= local_c - (local_a + local_b) <= 10000;
    if (local_c - (local_a + local_b) < ans)
    {
        ans = local_c - (local_a + local_b);
    }

    //@ assert ans >= -19999;
    if (ans < 0)
    {
        ans = 0;
    }
    //@ assert ans >= 0 && ans <= 10000;

    return ans + 1;
}

/* --- Original func2 (renamed): multiplies two resource weights --- */
/*@
    predicate is_valid_index(integer idx) = 0 <= idx < 2;
    
    logic integer array_value{L}(int *arr, integer idx) = 
        \at(arr[idx], L);
*/

/*@
    lemma multiplication_bounds:
        \forall integer x, y; 
        1 <= x <= 100 && 1 <= y <= 100 ==> x * y <= 10000;
*/

int compute_weight_product(int *a) {
    int result;
    
    //@ assert 1 <= a[0] && a[0] <= 100;
    //@ assert 1 <= a[1] && a[1] <= 100;
    
    //@ assert a[0] * a[1] <= 10000;
    
    result = a[0] * a[1];
    
    //@ assert result == a[0] * a[1];
    
    return result;
}

/* ===== Synthesized Function: Combined Allocation Scoring =====
 * This function takes three resource pool capacities (a, b, c) and
 * a weight array (weights[2]) that scales the score. The final score
 * is the product of the normalized min-difference score and the weight
 * product. The high-level property: the final score is always positive
 * and bounded by the product of the individual function outputs.
 */
int combined_allocation_score(int a, int b, int c, int *weights) {
    int score = compute_score(a, b, c);   // returns 1..20000
    int weight_product = compute_weight_product(weights);  // returns 1..10000
    
    //@ assert 1 <= score <= 20000;
    //@ assert 1 <= weight_product <= 10000;
    
    int result = score * weight_product;
    
    //@ assert result > 0 && result <= 20000 * 10000;
    
    return result;
}
