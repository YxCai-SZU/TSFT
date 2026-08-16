#include <stdbool.h>

/*@
    predicate valid_params(integer N, integer K) =
        1 <= N <= 100 && 1 <= K <= 100;
    
    logic integer half_plus_one(integer N) = (N + 1) / 2;
    
    lemma arithmetic_bounds:
        \forall integer N; 1 <= N <= 100 ==> N + 1 <= 101;
    
    lemma division_bounds:
        \forall integer N; 1 <= N <= 100 ==> (N + 1) / 2 <= 50;
*/

/*@
    requires valid_params(N, K);
    ensures \result == ((N + 1) / 2 >= K);
    assigns \nothing;
*/
bool func(unsigned int N, unsigned int K) {
    // Variable declarations at scope top
    bool result;
    
    //@ assert N + 1 <= 101;
    //@ assert (N + 1) / 2 <= 50;
    
    result = ((N + 1) / 2) >= K;
    return result;
}
