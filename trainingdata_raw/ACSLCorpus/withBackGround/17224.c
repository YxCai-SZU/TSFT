#include <stdbool.h>

/*@ predicate is_equal(integer n, integer m) = n == m; */

/*@ lemma trivial_equality: 
      \forall integer n, m; 
        n == m ==> n == m; */

/*@ requires 1 <= N <= 100 && 0 <= M <= N;
    ensures \result == (N == M);
    assigns \nothing;
 */
bool func(int N, int M)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert N == M ==> N == M;
    
    result = (N == M);
    return result;
}
