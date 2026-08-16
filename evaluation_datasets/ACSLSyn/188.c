#include <stddef.h>
#include <stdbool.h>

/* 
 * Scenario: Resource allocation with budget constraints
 * Given a budget x and a list of resource costs a[0..n-1],
 * first compute the maximum number of tasks that can be allocated
 * respecting both an upper bound on tasks (from func) and budget constraints (from func2).
 * The synthesized function combines both constraints.
 */

/* ===== First function: compute upper bound on tasks ===== */
/*@
    predicate valid_range(integer n) = 1 <= n && n <= 100;

    logic integer compute_ans(integer n) = 
        (n % 2 == 0) ? ((n + 1) / 2 - 1) : ((n + 1) / 2);

    lemma ans_bound: 
        \forall integer n; valid_range(n) ==> compute_ans(n) <= n;
*/

size_t func(size_t n) {
    size_t ans;
    
    ans = (n + 1) / 2;
    
    if (n % 2 == 0) {
        ans = ans - 1;
    }
    
    //@ assert ans == compute_ans(n);
    //@ assert ans <= n;
    
    return ans;
}

/* ===== Second function: count tasks within budget ===== */
/*@ predicate valid_params(integer n, integer x, long long *a) =
    (1 <= n <= 200) &&
    (1 <= x <= 1000000000000) &&
    (\valid(a + (0..n-1))) &&
    (\forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000000000);
*/

long long func2(long long n, long long x, const long long *a) {
    long long cnt = 0;
    long long v = 0;
    long long index = 0;
    
    while (index < n && v + a[index] <= x) {
        //@ assert 0 <= index < n;
        v += a[index];
        cnt += 1;
        index += 1;
    }
    
    //@ assert 0 <= cnt <= n;
    return cnt;
}

/* ===== Synthesized function ===== */

long long resource_allocation(size_t n, long long x, const long long *a) {
    size_t max_tasks = func(n);
    
    long long budget_count = func2((long long)n, x, a);
    
    long long result;
    if (budget_count <= (long long)max_tasks) {
        result = budget_count;
    } else {
        result = (long long)max_tasks;
    }
    
    //@ assert result <= compute_ans(n);
    //@ assert 0 <= result <= n;
    
    return result;
}
