#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* ========== Original function 1 (adapted with specification) ========== */

/*@ predicate is_valid_range(integer n) = 1 <= n && n <= 100; */

/*@ lemma square_bound: 
      \forall integer n; is_valid_range(n) ==> n * n <= 10000; */

int32_t func(int32_t n)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    return n * n;
}

int32_t read_int(void)
{
    return 0;
}

/* ========== Original function 2 (adapted with specification) ========== */

/*@ predicate valid_array(integer n, int *a) =
      n >= 1 && n <= 200 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer j; 0 <= j < n ==> a[j] >= 1 && a[j] <= 200;
*/


size_t func2(size_t n, size_t k, int *a) {
    size_t count = 0;
    size_t i = 0;
    
    while (i < n) {
        //@ assert valid_array(n, a);
        if (a[i] <= k || (k % 2 != 0 && a[i] <= (k / 2 + 1))) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

/* ========== Original function 3 (adapted with specification) ========== */

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= n;

    logic integer find_all_ways_result(integer n, integer k) =
        n - k + 1;

    lemma result_bounds:
        \forall integer n, integer k;
        valid_params(n, k) ==>
        find_all_ways_result(n, k) >= 1 &&
        find_all_ways_result(n, k) <= 100;
*/

int find_all_ways(int n, int k, int* return_value)
{
    int ret;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= k && k <= n;
    //@ assert n - k >= 0;
    
    ret = n - k + 1;
    *return_value = ret;
    return 0;
}

/* ========== Synthesized high-level function ========== */

/* 
   Scenario: Game leaderboard processing.
   Given a player's score n (1..100), we compute its square (score energy).
   Then we have an array a of length n (1..100) representing other player scores (1..200).
   We count how many players have scores satisfying a condition relative to k = n.
   Finally, we compute the number of ways to select k players from n for a team.
   The high-level property: the final result (team selection count) is bounded.
*/

int process_leaderboard(int n, int *a) {
    int32_t squared_score;
    size_t count_satisfied;
    int ways_result;
    int status;

    squared_score = func(n);

    count_satisfied = func2((size_t)n, (size_t)n, a);

    status = find_all_ways(n, n, &ways_result);

    //@ assert ways_result == 1;  // n - n + 1 = 1
    //@ assert 1 <= ways_result && ways_result <= 100;

    return ways_result;
}
