#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* Predicates and lemmas from the first function */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;
    logic integer compute_res(integer n) = (n + 1) / 2;
    lemma res_positive: \forall integer n; is_valid_n(n) ==> compute_res(n) > 0;
*/

/* Predicates and lemmas from the second function */
/*@
    predicate valid_input(int32_t *input) =
        \valid(input + (0..2)) &&
        1 <= input[0] <= 100 &&
        1 <= input[1] <= 100 &&
        1 <= input[2] <= 100;

    logic integer expected_result(integer a, integer b, integer c) =
        (a - 1) * (b - 1) * (c - 1) +
        (a - 1) * (b - 1) +
        (b - 1) * (c - 1) +
        (a - 1) * (c - 1) +
        (a - 1) +
        (b - 1) +
        (c - 1) + 1;
*/

/* Predicates and lemmas from the third function */
/*@ predicate is_even(integer x) = x % 2 == 0; */

/* Predicates and lemmas from the fourth function */
/*@
    predicate valid_vector(int64_t *v, size_t len) =
        len == 4 &&
        \valid(v + (0 .. 3)) &&
        1 <= v[0] <= 10000 &&
        1 <= v[1] <= 10000 &&
        1 <= v[2] <= 10000 &&
        1 <= v[3] <= 10000;

    logic integer min(integer x, integer y) = x < y ? x : y;
*/

/* First function: compute (n+1)/2 */
uint32_t func1(uint32_t n)
{
    uint32_t ans;
    ans = (n + 1) / 2;
    //@ assert ans == compute_res(n);
    //@ assert ans > 0;
    return ans;
}

/* Second function: compute combinatorial count */
int32_t func2(const int32_t *input)
{
    int32_t a, b, c, t;
    a = input[0];
    b = input[1];
    c = input[2];
    //@ assert 0 <= a - 1 <= 99;
    //@ assert 0 <= b - 1 <= 99;
    //@ assert 0 <= c - 1 <= 99;
    t = (a - 1) * (b - 1) * (c - 1) +
        (a - 1) * (b - 1) +
        (b - 1) * (c - 1) +
        (a - 1) * (c - 1) +
        (a - 1) +
        (b - 1) +
        (c - 1) + 1;
    //@ assert t == expected_result(a, b, c);
    return t;
}

/* Third function: produce even number */
uint32_t func3(uint32_t n)
{
    uint32_t ans;
    if (n % 2 == 0) {
        ans = n;
    } else {
        ans = 2 * n;
    }
    //@ assert is_even(ans);
    //@ assert ans >= 2;
    //@ assert ans == n || ans == 2 * n;
    return ans;
}

/* Fourth function: compute vector comparison count */
int32_t func4(int64_t *v, size_t len)
{
    int64_t a, b, c, d, sa, sc, s;
    int32_t r;
    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];
    r = 0;
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;
    sa = a < b ? a : b;
    sc = c < d ? c : d;
    s = sa + sc;
    //@ assert s == min(a, b) + min(c, d);
    if (s < a + c) r += 1;
    if (s < a + d) r += 1;
    if (s < b + c) r += 1;
    if (s < b + d) r += 1;
    //@ assert r >= 0;
    //@ assert r <= 4;
    if (r == 0) {
        return -1;
    } else {
        return r;
    }
}

/* Synthesized function: Resource allocation optimizer
   Scenario: Given resource counts and configuration parameters,
   compute an optimized allocation that satisfies all constraints.
   Data flow:
   1. func1 computes initial allocation size from total resources
   2. func2 computes combinatorial complexity from config parameters
   3. func3 ensures allocation size is even for alignment
   4. func4 validates allocation against resource vector limits
   The final result is the allocation size if valid, otherwise -1
*/
int32_t resource_allocator(uint32_t n, const int32_t *config, uint32_t n2, int64_t *v, size_t len)
{
    uint32_t base_size;
    int32_t complexity;
    uint32_t aligned_size;
    int32_t validation_result;
    
    /* Step 1: Compute base allocation size from total resources */
    base_size = func1(n);
    //@ assert base_size == compute_res(n);
    //@ assert base_size > 0;
    
    /* Step 2: Compute combinatorial complexity from config parameters */
    complexity = func2(config);
    //@ assert complexity == expected_result(config[0], config[1], config[2]);
    
    /* Step 3: Ensure allocation size is even for memory alignment */
    aligned_size = func3(n2);
    //@ assert is_even(aligned_size);
    //@ assert aligned_size >= 2;
    
    /* Step 4: Validate the allocation against resource vector limits */
    validation_result = func4(v, len);
    
    /* High-level property: The allocation satisfies all constraints
       if validation passes (result positive) */
    //@ assert validation_result > 0 ==> (is_even(aligned_size) && aligned_size >= 2);
    
    if (validation_result > 0) {
        return (int32_t)aligned_size;
    } else {
        return -1;
    }
}
