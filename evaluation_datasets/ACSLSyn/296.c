#include <stdbool.h>
#include <stdint.h>

/* ACSL predicates and logic functions from the first snippet */
/*@
    predicate is_ordered(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e) =
        a < b && b < c && c < d && d < e;
*/

/* ACSL from the second snippet */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    predicate is_valid_r(integer r) = 0 <= r && r <= 4111;
    
    logic integer max_val(integer n) = (n >= 10) ? n : 10;
    
    logic integer expected_result(integer n, integer r) = 
        r + ((n >= 10) ? 0 : 100 * (10 - n));
*/

/* ACSL from the third snippet */
/*@ predicate valid_range(integer N, integer K) = 
      1 <= K <= N <= 50;
*/

/*@ logic integer abs(integer x) = 
      x < 0 ? -x : x;
*/

/*@ predicate valid_inputs(integer A, integer B) = 
      1 <= A <= 50 && 1 <= B <= 50;
*/

/* Original function 1: checks if k >= (e - a) given ordered inputs */
bool func_ordered_check(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned k) {
    bool result;
    
    //@ assert is_ordered(a, b, c, d, e);
    
    if (k >= (e - a)) {
        //@ assert k >= (e - a);
        result = true;
    } else {
        //@ assert !(k >= (e - a));
        result = false;
    }
    
    return result;
}

/* Original function 2: computes r + (max_val - n) * 100 */
int func_adjust(int n, int r)
{
    int max_val;
    int ans;
    
    //@ assert is_valid_n(n) && is_valid_r(r);
    
    if (n >= 10) {
        max_val = n;
    } else {
        max_val = 10;
    }
    
    //@ assert max_val == max_val(n);
    //@ assert max_val == 10 || max_val == n;
    //@ assert 0 <= max_val - n && max_val - n <= 9;
    
    ans = r + (max_val - n) * 100;
    
    //@ assert ans == expected_result(n, r);
    
    return ans;
}

/* Original functions 3a and 3b: compute N-K+1 and absolute difference */
int64_t func_range_count(int64_t N, int64_t K)
{
    //@ assert N - K + 1 == N - K + 1;
    return N - K + 1;
}

int64_t func_abs_diff(int64_t A, int64_t B)
{
    int64_t result = 0;
    
    if (A > B) {
        result = A - B;
    } else {
        result = B - A;
    }
    
    //@ assert result == abs(A - B);
    return result;
}

/* 
 * Scenario: Network packet payload validation and adjustment
 * 
 * Data flow:
 * 1. Given a packet with 5 ordered sequence numbers (a,b,c,d,e) and a timeout k,
 *    check if the packet is "long-lived" (k >= e - a).
 * 2. If long-lived, adjust a payload counter n (number of retransmissions) 
 *    with a base value r to compute an adjustment value.
 * 3. Compute the final quality metric: range_count(N, K) + abs_diff(A, B)
 *    where N and K come from the packet metadata.
 *
 * The synthesized function verifies that the final quality metric is non-negative.
 */

int64_t process_packet_quality(
    unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned k,
    int n, int r,
    int64_t N, int64_t K,
    int64_t A, int64_t B
)
{
    bool long_lived;
    int adjustment;
    int64_t range_val;
    int64_t diff_val;
    int64_t quality_metric;
    
    long_lived = func_ordered_check(a, b, c, d, e, k);
    
    adjustment = func_adjust(n, r);
    
    range_val = func_range_count(N, K);
    diff_val = func_abs_diff(A, B);
    
    if (long_lived) {
        quality_metric = (int64_t)adjustment + range_val + diff_val;
    } else {
        quality_metric = range_val + diff_val;
    }
    
    //@ assert quality_metric >= 0;
    
    return quality_metric;
}
