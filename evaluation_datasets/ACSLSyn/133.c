#include <stddef.h>
#include <stdint.h>

/* First function: count runs in an array */

/*@
    logic integer total_elements(integer n) = n;

    lemma ans_bound: \forall integer i, ans; 0 <= ans <= i ==> ans <= total_elements(i);
    lemma ac_bounds: \forall integer n, int *ac; 
        (\forall integer k; 0 <= k < n ==> ac[k] >= 0 && ac[k] < 100) ==> 
        \forall integer k; 0 <= k < n ==> ac[k] <= 99;
*/

int func1(size_t n, int *aa) {
    int ac[100];
    size_t i = 0;
    
    while (i < n) {
        //@ assert 0 <= i && i < n;
        ac[i] = aa[i] - 1;
        i++;
    }
    
    int ans = 0;
    int b = 0;
    i = 0;
    
    while (i < n) {
        //@ assert 0 <= i && i < n;
        int a = ac[i];
        if (b == a) {
            ans++;
        } else {
            b = a;
        }
        i++;
        //@ assert ans <= i;
    }
    
    //@ assert ans >= 0 && ans <= n;
    return ans;
}

/* Second function: compute difference or return -1 */
/*@ predicate valid_input(integer n, integer m) =
    n >= 1 && n <= 100 &&
    m >= 0 && m <= 100;
*/

/*@ logic integer compute_result(integer n, integer m) =
    m >= n ? m - n : -1;
*/

/*@ lemma result_correctness:
    \forall integer n, m;
    valid_input(n, m) ==>
    (m >= n ==> compute_result(n, m) == m - n) &&
    (m < n ==> compute_result(n, m) == -1);
*/

int32_t func2(uint32_t v[2]) {
    uint32_t n;
    uint32_t m;
    int32_t res;
    
    n = v[0];
    m = v[1];
    
    //@ assert valid_input(n, m);
    
    if (m >= n) {
        //@ assert m >= n;
        res = (int32_t)(m - n);
        //@ assert res == compute_result(n, m);
        return res;
    } else {
        //@ assert m < n;
        res = -1;
        //@ assert res == compute_result(n, m);
        return res;
    }
}

/* Synthesized function: analyze packet run lengths and compute adjustment
 * 
 * Real-world scenario: Network packet analysis - we have a sequence of packet sizes (aa)
 * that are transformed to run-length encoded offsets (ac = aa-1). The number of distinct
 * runs (ans from func1) indicates protocol state transitions. Then, given a maximum 
 * allowed packet size (v[0]) and current buffer size (v[1]), we compute the buffer 
 * adjustment needed (func2). The combined result ensures the adjustment is valid
 * relative to the number of state transitions.
 */
int32_t packet_analysis(size_t n, int *aa, uint32_t v[2]) {
    int runs = func1(n, aa);
    int32_t adjustment = func2(v);
    
    //@ assert runs >= 0 && runs <= (int)n;
    //@ assert adjustment == compute_result(v[0], v[1]);
    
    /* High-level property: The number of runs (state transitions) is bounded by the array size,
     * and the buffer adjustment is consistent with the input parameters.
     * Specifically, if the buffer size (v[1]) is at least the max packet size (v[0]),
     * the adjustment is non-negative and within valid range; otherwise it's -1.
     */
    //@ assert (v[1] >= v[0] ==> adjustment >= 0 && adjustment <= 100) && (v[1] < v[0] ==> adjustment == -1);
    
    return adjustment;
}
