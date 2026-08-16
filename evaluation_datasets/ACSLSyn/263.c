#include <stdint.h>
#include <stddef.h>

/* ========== First underlying function: compute padding to next multiple of 1000 ========== */

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;
    
    logic integer compute_res(integer n) =
        (1000 - n % 1000 == 1000) ? 0 : (1000 - n % 1000);
*/

int32_t func_padding(int32_t n)
{
    uint32_t n_unsigned;
    uint32_t res_unsigned;
    int32_t ans;
    
    n_unsigned = (uint32_t)n;
    res_unsigned = (n_unsigned / 1000U + 1U) * 1000U - n_unsigned;
    ans = (int32_t)res_unsigned;
    
    //@ assert 0 <= ans && ans <= 1000;
    
    if (ans == 1000)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}

/* ========== Second underlying function: count numbers <= n satisfying i*108 <= n ========== */

/*@
    predicate is_valid_n2(integer n) = 1 <= n && n <= 10000;
    predicate loop_inv(integer n, integer i, integer ans) =
        is_valid_n2(n) &&
        1 <= i && i <= 1001 &&
        0 <= ans && ans <= i - 1;
    lemma ans_bound: \forall integer n, i, ans; loop_inv(n, i, ans) ==> ans <= 1000;
*/

unsigned int func_count(unsigned int n)
{
    unsigned int ans = 0;
    unsigned int i = 1;
    
    while (i < 1001)
    {
        //@ assert loop_inv(n, i, ans);
        if (i * 108 <= n) {
            ans = ans + 1;
        }
        i = i + 1;
    }
    //@ assert ans <= 1000;
    return ans;
}

/* ========== Third underlying function: compute minimal gap deficit ========== */

/*@
    predicate sorted_array(int32_t *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];

    predicate bounded_array(int32_t *arr, integer len, integer k) =
        \forall integer i; 0 <= i < len ==> 0 <= arr[i] && arr[i] < k;

    lemma sorted_bounds_preserved:
        \forall int32_t *arr, integer len, integer k;
        sorted_array(arr, len) && bounded_array(arr, len, k) ==>
            \forall integer i; 0 <= i < len ==> 0 <= arr[i] && arr[i] < k;
*/

int32_t func_min_gap(int32_t k, size_t n, int32_t *a)
{
    int32_t m = k;
    size_t i = 0;

    while (i < n - 1)
    {
        int32_t next_a = a[i + 1];
        int32_t diff = next_a - a[i];
        int32_t candidate = k - diff;

        //@ assert 0 <= diff < k;
        //@ assert 0 <= candidate <= k;

        if (candidate < m)
        {
            m = candidate;
        }
        else
        {
            m = m;
        }

        //@ assert 0 <= m <= k;
        i += 1;
    }

    //@ assert 0 <= m <= k;
    return m;
}

/* ========== Synthesized function: validate a memory allocation request ========== */

int32_t validate_allocation(int32_t n, int32_t k, size_t size, int32_t *arr)
{
    int32_t padding = func_padding(n);
    unsigned int count = func_count((unsigned int)n);
    int32_t min_gap = func_min_gap(k, size, arr);
    
    int32_t result;
    
    if (padding > 0 && count > 0 && min_gap > 0) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert (result == 1) ==> (padding > 0 && count > 0 && min_gap > 0);
    
    return result;
}
