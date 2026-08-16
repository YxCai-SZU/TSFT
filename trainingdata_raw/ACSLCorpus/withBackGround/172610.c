#include <stdint.h>

/*@ predicate valid_range(integer n) = 2 <= n <= 100; */

/*@ logic integer compute_result(integer n, integer m) = (n - 1) * (m - 1); */

/*@ lemma subtraction_positive: 
      \forall integer n, m; valid_range(n) && valid_range(m) ==> n - 1 >= 1 && m - 1 >= 1; */

/*@ lemma multiplication_bounded: 
      \forall integer n, m; valid_range(n) && valid_range(m) ==> (n - 1) * (m - 1) <= 99 * 99; */

/*@
    requires valid_range(N) && valid_range(M);
    ensures \result == compute_result(N, M);
*/
int32_t func(int32_t N, int32_t M)
{
    // Variable declarations at top of scope
    int32_t ans;
    
    //@ assert N > 1 && M > 1;
    //@ assert N <= 100 && M <= 100;
    //@ assert N - 1 >= 1 && M - 1 >= 1;
    //@ assert (N - 1) * (M - 1) <= 99 * 99;
    
    ans = (N - 1) * (M - 1);
    return ans;
}
