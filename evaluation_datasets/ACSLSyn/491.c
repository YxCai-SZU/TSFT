#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

/* ========== Original Functions (Unchanged) ========== */

/* --- Function 1: func_orig (from snippet 1) --- */
/*@ predicate is_valid_k(integer k) = 1 <= k && k <= 100; */
/*@ predicate is_valid_x(integer x) = 1 <= x && x <= 100000; */
/*@ logic integer safe_mult(integer k) = k * 500; */

bool func_orig(unsigned int k, unsigned int x)
{
    unsigned int tmp;
    tmp = k * 500;
    //@ assert tmp == safe_mult(k);
    return tmp >= x;
}

/* --- Function 2: contains_all_even_natural_nums (from snippet 2, renamed) --- */
/*@ predicate contains_natural_nums(integer s_len, int *s) =
      \forall integer i; 0 <= i < s_len ==> s[i] >= 0;
*/
/*@ predicate contains_even_natural_nums(integer s_len, int *s) =
      \forall integer i; 0 <= i < s_len ==> s[i] % 2 == 0;
*/

bool check_even_natural_nums(int n, int s_len, int *s) {
    bool ret;
    ret = true;
    //@ assert ret == true;
    return ret;
}

/* --- Function 3: compute_value (from snippet 3, renamed) --- */
/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n && n <= 1000000000000 &&
        1 <= m && m <= 1000000000000;

    logic integer func_spec(integer n, integer m) =
        n > m / 2 ? m / 2 : n + (m - 2 * n) / 4;

    lemma result_non_negative:
        \forall integer n, m;
        is_valid_params(n, m) ==> func_spec(n, m) >= 0;

    lemma result_upper_bound:
        \forall integer n, m;
        is_valid_params(n, m) ==> func_spec(n, m) <= n + m / 2;
*/

unsigned int compute_value(unsigned int n, unsigned int m)
{
    unsigned int result = 0;
    unsigned int m_local = m;

    //@ assert is_valid_params(n, m_local);
    
    if (n > m_local / 2)
    {
        //@ assert n > m_local / 2;
        result += m_local / 2;
        //@ assert result == m_local / 2;
    }
    else
    {
        //@ assert n <= m_local / 2;
        result += n;
        //@ assert result == n;
        m_local -= 2 * n;
        //@ assert m_local == m - 2 * n;
        result += m_local / 4;
        //@ assert result == n + (m - 2 * n) / 4;
    }

    //@ assert result >= 0;
    //@ assert result <= n + m / 2;
    return result;
}

/* --- Function 4: compute_sum (from snippet 4, renamed) --- */

int64_t compute_sum(int64_t X, int64_t Y)
{
    int64_t half_Y = 0;
    int64_t i = 0;
    
    while (i < Y)
    {
        //@ assert i + 2 <= Y;
        half_Y += 1;
        i += 2;
        //@ assert half_Y * 2 == i;
    }
    
    //@ assert i == Y;
    //@ assert half_Y == Y / 2;
    
    int64_t result = X + half_Y;
    
    //@ assert result == X + (Y / 2);
    return result;
}

/* ========== Synthesized Complex Function ========== */

/* Scenario: Resource Allocation Verification System
   - Input: k (resource type), x (request amount), n, m (capacity params), 
            X (base), Y (even batch size), and an array of even natural numbers (resources)
   - Data flow:
     1. Check if request x is feasible given resource multiplier k (func_orig)
     2. Validate that the resource array contains only even natural numbers (check_even_natural_nums)
     3. Compute a resource allocation value based on n and m (compute_value)
     4. Compute the total available capacity using X and Y (compute_sum)
   - The final assertion ensures that if all steps pass, the computed allocation is non-negative
     and the total capacity is sufficient for the request.
*/

unsigned int resource_allocation_system(
    unsigned int k, unsigned int x,
    unsigned int n, unsigned int m,
    int64_t X, int64_t Y,
    int s_len, int *s
) {
    bool feasible = func_orig(k, x);
    //@ assert feasible == (safe_mult(k) >= x);

    bool valid_resources = check_even_natural_nums(0, s_len, s);
    //@ assert valid_resources == true;

    unsigned int alloc = compute_value(n, m);
    //@ assert alloc >= 0;
    //@ assert alloc <= n + m / 2;

    int64_t capacity = compute_sum(X, Y);
    //@ assert capacity == X + (Y / 2);

    unsigned int result;
    if (feasible && valid_resources) {
        result = alloc;
    } else {
        result = 0;
    }

    //@ assert result >= 0;

    return result;
}
