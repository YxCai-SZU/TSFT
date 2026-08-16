#include <stdbool.h>
#include <stdint.h>

/* First function: resource allocation */
/*@
    predicate valid_params(integer x, integer a, integer b) =
        1 <= x <= 10000 &&
        1 <= a <= 10000 &&
        1 <= b <= 10000 &&
        a + b <= x;

    logic integer remaining(integer x, integer a, integer b, integer result) =
        x - a - b - 2 * result;

    lemma result_bounds:
        \forall integer x, a, b, result;
        valid_params(x, a, b) && 0 <= result && result <= x &&
        remaining(x, a, b, result) >= 0 ==>
        result >= 0 && result <= x;
*/

long resource_alloc(long x, long a, long b)
{
    long rest;
    long result;
    bool is_a_turn;

    //@ assert valid_params(x, a, b);
    rest = x - a - b;
    result = 0;
    is_a_turn = true;

    while (rest >= 2 && is_a_turn)
    {
        //@ assert rest >= 2;
        result += 1;
        rest -= 2;
        is_a_turn = !is_a_turn;
        //@ assert rest == remaining(x, a, b, result);
    }

    if (is_a_turn)
    {
        //@ assert rest >= 0;
        result += 1;
        //@ assert result <= x;
    }

    //@ assert result >= 0;
    //@ assert result <= x;
    return result;
}

/* Second function: compute allocation limit */
/*@
    predicate valid_params2(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= n;

    logic integer func_result(integer n, integer k) =
        n > k * 2 ? k :
        n == k * 2 ? k - 1 + (n - k) :
        0;

    lemma result_bounds2: \forall integer n, k;
        valid_params2(n, k) ==> 0 <= func_result(n, k) && func_result(n, k) <= n;
*/

int64_t compute_limit(uint64_t n, uint64_t k)
{
    int64_t n_i64 = (int64_t)n;
    int64_t k_i64 = (int64_t)k;
    int64_t result;
    
    //@ assert valid_params2(n, k);
    
    if (n_i64 > k_i64 * 2) {
        result = k_i64;
    } else if (n_i64 == k_i64 * 2) {
        result = k_i64 - 1 + (n_i64 - k_i64);
    } else {
        result = 0;
    }
    
    //@ assert result == func_result(n_i64, k_i64);
    
    int64_t i = 0;
    while (i < k_i64) {
        i = i + 1;
    }
    
    //@ assert result >= 0 && result <= n_i64;
    
    return result;
}

/* Third function: compute maximum with bounds */
/*@
    predicate bounds(integer a, integer b) =
        2 <= a && a <= 20 &&
        1 <= b && b <= 50;
*/

/*@
    logic integer max(integer a, integer b) =
        a > b ? a : b;
*/

/*@
    lemma ans_bounds:
        \forall integer a, b, ans;
        bounds(a, b) && ans == max(a, b) ==>
        ans >= 1 * b && ans >= a && ans <= 100;
*/

uint32_t compute_max(uint32_t a, uint32_t b)
{
    uint32_t ans;

    //@ assert b <= 50;
    //@ assert a <= 20;
    //@ assert a * 1 <= 20 * 1;

    if (a > b * 1)
    {
        ans = a;
    }
    else
    {
        ans = b * 1;
    }

    //@ assert ans >= 1 * b;
    //@ assert ans >= a;
    //@ assert ans <= 100;

    //@ assert ans >= 1;
    //@ assert ans <= 100;
    //@ assert ans >= 1 * b;

    return ans;
}

/* Synthesized function: Resource allocation system with limit and max validation */
long resource_manager(
    long total_resources, 
    long res_a, 
    long res_b,
    uint64_t process_count,
    uint64_t max_processes,
    uint32_t priority_a,
    uint32_t priority_b)
{
    int64_t limit = compute_limit(process_count, max_processes);
    
    uint32_t max_priority = compute_max(priority_a, priority_b);
    
    long allocated = resource_alloc(total_resources, res_a, res_b);
    
    //@ assert allocated >= 0;
    //@ assert limit >= 0;
    //@ assert max_priority >= priority_a && max_priority >= priority_b;
    
    //@ assert (allocated <= limit) ==> (allocated >= 0 && max_priority >= 1);
    
    return allocated;
}
