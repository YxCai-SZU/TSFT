#include <limits.h>

/*@
    predicate is_valid_N(integer N) = 1 <= N && N <= 1000000;
    
    logic integer mod_100(integer N) = N % 100;
    
    lemma mod_range: \forall integer N; is_valid_N(N) ==> 0 <= mod_100(N) && mod_100(N) <= 99;
*/

/*@
    requires is_valid_N(N);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> mod_100(N) * 21 >= N;
    ensures \result == 0 ==> mod_100(N) * 21 < N;
*/
int func(long N) {
    long n_mod_100;
    
    // First loop: reduce n_mod_100 to < 100
    n_mod_100 = N;
    /*@
        loop invariant 0 <= n_mod_100 <= N;
        loop invariant n_mod_100 == N % 100 + 100 * (n_mod_100 / 100);
        loop assigns n_mod_100;
        loop variant n_mod_100;
    */
    while (n_mod_100 >= 100) {
        //@ assert n_mod_100 >= 100;
        n_mod_100 -= 100;
    }
    
    // Second loop: ensure n_mod_100 is non-negative
    /*@
        loop invariant n_mod_100 < 100;
        loop invariant n_mod_100 == N % 100 + 100 * (n_mod_100 / 100);
        loop assigns n_mod_100;
        loop variant 100 - n_mod_100;
    */
    while (n_mod_100 < 0) {
        //@ assert n_mod_100 < 0;
        n_mod_100 += 100;
    }
    
    //@ assert n_mod_100 >= 0 && n_mod_100 < 100;
    //@ assert n_mod_100 * 21 >= N || n_mod_100 * 21 < N;
    
    if (n_mod_100 * 21 >= N) {
        return 1;
    } else {
        return 0;
    }
}
