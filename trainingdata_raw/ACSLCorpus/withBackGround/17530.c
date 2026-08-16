#include <limits.h>

/*@
    predicate valid_range(integer N) = 1 <= N <= 100;

    logic integer compute_result(integer N) = 
        (N * 800) - ((N / 15) * 200);

    lemma quotient_bound: 
        \forall integer N; valid_range(N) ==> (N / 15) <= 6;
*/

/*@
    requires valid_range(N);
    ensures \result == compute_result(N);
    assigns \nothing;
*/
long func(long N) {
    // Variable declarations at top
    long x;
    long quotient = 0;
    long temp_N = N;
    long y;
    long result;
    
    // Precondition check
    //@ assert valid_range(N);
    
    // Ensure no overflow in N * 800
    //@ assert N * 800 <= 100 * 800;
    
    x = N * 800;
    
    /*@
        loop invariant 1 <= N <= 100;
        loop invariant 0 <= quotient <= N / 15;
        loop invariant temp_N == N - quotient * 15;
        loop invariant valid_range(N);
        loop assigns quotient, temp_N;
        loop variant temp_N;
    */
    while (temp_N >= 15) {
        quotient = quotient + 1;
        temp_N = temp_N - 15;
    }
    
    // Ensure quotient bound
    //@ assert quotient <= 6;
    
    y = quotient * 200;
    result = x - y;
    
    // Postcondition verification
    //@ assert result == compute_result(N);
    
    return result;
}
