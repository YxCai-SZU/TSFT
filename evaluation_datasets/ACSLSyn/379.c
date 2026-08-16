#include <stdint.h>
#include <stdbool.h>

/* ACSL predicates and lemmas from the first snippet */
/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bounds:
        \forall integer x, y;
        valid_range(x) && valid_range(y) ==> 
        product(x, y) >= 1 && product(x, y) <= 100000000;
*/

/* ACSL predicates from the second snippet */
/*@
    predicate sorted(unsigned long *arr, integer len) =
        \forall integer m, n; 0 <= m < n < len ==> arr[n] >= arr[m];

    logic integer diff(unsigned long x, unsigned long y) = x - y;

    lemma diff_nonnegative:
        \forall unsigned long *arr, integer i, integer j, integer len;
            sorted(arr, len) && 0 <= i <= j < len ==> diff(arr[j], arr[i]) >= 0;
*/

/* ACSL predicates from the third snippet */
/*@ predicate is_valid_index(integer i, integer len) =
      0 <= i && i < len;
*/

/*@ predicate element_in_range(integer val) =
      1 <= val && val <= 5;
*/

/*@ predicate vector_properties(int *v, integer len) =
      len == 5 &&
      \forall integer i; 0 <= i < len ==> element_in_range(v[i]) &&
      \exists integer i; 0 <= i < len && v[i] == 0;
*/

/*@ lemma exists_zero_element: 
      \forall int *v, integer len; 
      vector_properties(v, len) ==> 
      \exists integer i; 0 <= i < len && v[i] == 0;
*/

/* ACSL predicates from the fourth snippet */
/*@
    predicate valid_vec(int *v, integer len) =
        len >= 3 &&
        1 <= v[0] <= 100 &&
        1 <= v[1] <= 20 &&
        1 <= v[2] <= 2000;

    predicate loop_inv(int *v, integer len, integer i, integer m) =
        0 <= i <= v[1] &&
        1 <= v[0] <= 100 &&
        1 <= v[1] <= 20 &&
        m <= v[2] &&
        m >= 0 &&
        len >= 3 &&
        m <= i * 100;
*/

/* Original function 1: computes max of two products */
int64_t func1(const int64_t v[4])
{
    int64_t a;
    int64_t b;
    int64_t c;
    int64_t d;
    int64_t ans;
    int64_t max_val;
    int64_t temp_val;
    
    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    //@ assert product(a, b) <= 100000000;
    //@ assert product(c, d) <= 100000000;
    
    max_val = a * b;
    temp_val = c * d;
    
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    ans = max_val;
    
    //@ assert ans == product(a, b) || ans == product(c, d);
    //@ assert product(a, b) >= 1;
    //@ assert product(c, d) >= 1;
    //@ assert ans >= 1;
    
    return ans;
}

/* Original function 2: checks if any pair of sorted values has difference <= k */
bool func2(unsigned long a, unsigned long b, unsigned long c,
          unsigned long d, unsigned long e, unsigned long k)
{
    unsigned long dist[5];
    unsigned long n;
    unsigned long i;
    unsigned long j;
    bool found = false;

    dist[0] = a;
    dist[1] = b;
    dist[2] = c;
    dist[3] = d;
    dist[4] = e;
    n = 5;

    //@ assert sorted(&dist[0], n);

    i = 0;
    while (i < n && !found)
    {
        j = i + 1;
        while (j < n && !found)
        {
            //@ assert diff(dist[j], dist[i]) >= 0;
            if (dist[j] - dist[i] <= k)
            {
                found = true;
            }
            j += 1;
        }
        i += 1;
    }
    return found;
}

/* Original function 3: finds the last index+1 where v[i] == 0 */
int func3(int *v) {
    int ans = 0;
    unsigned int index = 0;
    
    while (index < 5) {
        int a = v[index];
        if (a == 0) {
            ans = (int)index + 1;
        }
        index++;
    }
    return ans;
}

/* Original function 4: accumulates v[0] at most v[1] times without exceeding v[2] */
int func4(int *v) {
    int m;
    int i;
    
    m = 0;
    i = 0;
    
    while (i < v[1]) {
        //@ assert m <= v[2];
        if (m + v[0] < v[2]) {
            m += v[0];
        } else {
            break;
        }
        i += 1;
        //@ assert m <= i * 100;
    }
    
    return m;
}

/* 
 * Synthesized function: Resource allocation with budget and capacity constraints
 * 
 * Scenario: A batch processing system allocates resources to jobs.
 * - Input array 'v' defines: v[0] = unit resource cost (1-100), v[1] = max job count (1-20), 
 *   v[2] = total budget (1-2000)
 * - Input array 'ratios' defines four scaling factors (1-10000 each) for different resource pools
 * - Input 'k' is a proximity threshold (<=123) for checking if sorted resource pool indices 
 *   are close enough to trigger merging
 * - Input 'pool_indices' contains 5 strictly increasing values (sorted) representing pool identifiers
 * - Input 'zero_marker' is a 5-element vector with values 1-5 containing exactly one zero, 
 *   marking which pool has a special flag
 * 
 * Data flow:
 * 1. func4 computes the maximum affordable resource units (m) given budget and unit cost
 * 2. func1 computes the maximum product of scaling factors from different pool pairs, 
 *    representing the best scaling combination
 * 3. func3 finds the zero marker position in zero_marker (1-indexed), identifying the special pool
 * 4. func2 checks if any two consecutive pool indices are within threshold k, indicating proximity
 * 5. The synthesized function combines these: if pools are close (func2 true) AND the special pool 
 *    (from func3) aligns with a high-value pool (from func1), then allocate more resources; 
 *    otherwise use the basic allocation
 * 
 * High-level property: The final allocation amount is at most the total budget (v[2]), 
 * and the allocation respects the scaling factor constraints.
 */

int synthesized_func(int *v, const int64_t ratios[4], 
                     unsigned long a, unsigned long b, unsigned long c,
                     unsigned long d, unsigned long e, unsigned long k,
                     int *zero_marker)
{
    int base_allocation;
    int64_t best_scaling;
    int special_pool;
    bool pools_close;
    int final_allocation;
    
    /* Step 1: Compute base allocation from budget constraints */
    base_allocation = func4(v);
    //@ assert base_allocation >= 0 && base_allocation <= v[2];
    
    /* Step 2: Compute best scaling factor from resource pool ratios */
    best_scaling = func1(ratios);
    //@ assert best_scaling >= 1;
    
    /* Step 3: Find which pool has the special zero marker */
    special_pool = func3(zero_marker);
    //@ assert 1 <= special_pool && special_pool <= 5;
    
    /* Step 4: Check if any pool indices are close (within threshold k) */
    pools_close = func2(a, b, c, d, e, k);
    
    /* Step 5: Combine results - if pools are close and special pool aligns with high scaling,
       we use a boosted allocation; otherwise use base allocation */
    if (pools_close && special_pool <= 3) {
        /* Boost allocation: scale up base allocation but cap at budget */
        if (base_allocation + (int)best_scaling / 1000 <= v[2]) {
            final_allocation = base_allocation + (int)best_scaling / 1000;
        } else {
            final_allocation = v[2];
        }
    } else {
        final_allocation = base_allocation;
    }
    
    //@ assert final_allocation >= 0 && final_allocation <= v[2];
    
    return final_allocation;
}
