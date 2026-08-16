#include <stdint.h>

/*@
    predicate valid_inputs(integer N, integer X_N, integer T) =
        1 <= N <= 10000 &&
        1 <= X_N <= 10000 &&
        1 <= T <= 10000;

    logic integer ans_value(integer N, integer X_N, integer T) =
        (N % X_N == 0) ? (N / X_N) * T : (N / X_N + 1) * T;

    lemma division_bound: \forall integer N, X_N; 
        valid_inputs(N, X_N, 1) ==> N / X_N <= 10000;

    lemma addition_bound: \forall integer N, X_N; 
        valid_inputs(N, X_N, 1) ==> N / X_N + 1 <= 10001;

    lemma mul1_bound: \forall integer N, X_N, T; 
        valid_inputs(N, X_N, T) ==> (N / X_N) * T <= 10000 * 10000;

    lemma mul2_bound: \forall integer N, X_N, T; 
        valid_inputs(N, X_N, T) ==> (N / X_N + 1) * T <= 10001 * 10000;
*/


uint64_t func(uint64_t N, uint64_t X_N, uint64_t T) {
    uint64_t ans;
    
    //@ assert N / X_N <= 10000;
    //@ assert N / X_N + 1 <= 10001;
    //@ assert (N / X_N) * T <= 10000 * 10000;
    //@ assert (N / X_N + 1) * T <= 10001 * 10000;
    
    if (N % X_N == 0) {
        ans = (N / X_N) * T;
    } else {
        ans = (N / X_N + 1) * T;
    }
    
    //@ assert ans == ans_value(N, X_N, T);
    return ans;
}
