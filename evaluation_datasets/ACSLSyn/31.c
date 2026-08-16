#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Predicates from first function */
/*@
    predicate valid_range(integer k, integer x) =
        1 <= k && k <= 100 && 1 <= x && x <= 100000;
    
    predicate condition_holds(integer k, integer x) =
        500 * k >= x;
*/

/* First function - checks if budget k is sufficient for x units */
bool func_budget(unsigned int k, unsigned int x)
{
    bool ans;
    
    //@ assert valid_range(k, x);
    ans = (500U * k >= x);
    
    //@ assert condition_holds(k, x) ==> ans == true;
    return ans;
}

/* Predicates from second function */

/* Second function - finds maximum consecutive non-decreasing sequence length */
int64_t func_streak(size_t N, const int64_t* Hs) {
    int64_t max_count = 0;
    int64_t tmp_max = 0;
    int64_t prev = 0;
    size_t index = 0;

    while (index < N) {
        int64_t H = Hs[index];
        if (H >= prev) {
            tmp_max++;
        } else {
            //@ assert max_count >= 0 && tmp_max >= 0;
            max_count = (max_count > tmp_max) ? max_count : tmp_max;
            tmp_max = 0;
        }
        prev = H;
        index++;
    }

    //@ assert max_count >= 0 && tmp_max >= 0;
    max_count = (max_count > tmp_max) ? max_count : tmp_max;
    return max_count;
}

/* Synthesized function: Resource Planning for Non-decreasing Production Runs
 * 
 * Scenario: A factory manager needs to plan production runs. Each run has a 
 * budget k (1-100) and target output x (1-100000). The manager wants to know 
 * if the budget is sufficient (500*k >= x). Additionally, the manager tracks 
 * historical production data (array Hs of length N) and wants to know the 
 * maximum length of consecutive non-decreasing production values.
 * 
 * This function combines both checks: it verifies budget sufficiency and 
 * computes the longest non-decreasing streak, but only if the budget is 
 * sufficient for the first production target.
 * 
 * @param k: budget parameter (1-100)
 * @param x: production target (1-100000)  
 * @param N: length of historical production array
 * @param Hs: array of historical production values
 * @return: -1 if budget insufficient, otherwise maximum non-decreasing streak length
 */

int64_t resource_planning(unsigned int k, unsigned int x, size_t N, const int64_t* Hs) {
    bool budget_ok = func_budget(k, x);
    
    if (!budget_ok) {
        //@ assert !condition_holds(k, x);
        return -1;
    }
    
    //@ assert condition_holds(k, x);
    int64_t max_streak = func_streak(N, Hs);
    
    //@ assert 0 <= max_streak && max_streak <= (int64_t)N;
    //@ assert condition_holds(k, x) ==> (0 <= max_streak && max_streak <= (int64_t)N);
    
    return max_streak;
}
