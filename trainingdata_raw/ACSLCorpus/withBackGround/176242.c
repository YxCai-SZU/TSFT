#include <stdbool.h>

/*@
    predicate N_mod_500_remainder(integer N, integer n_mod) =
        n_mod == N % 500;

    lemma mod_property:
        \forall integer N, integer n_mod;
        N_mod_500_remainder(N, n_mod) ==> n_mod == N % 500;
*/

/*@
    requires 1 <= N <= 10000;
    requires 0 <= A <= 1000;
    ensures \result == (N % 500 <= A);
    assigns \nothing;
*/
bool func(long N, long A) {
    long n_mod;
    n_mod = N;

    /*@
        loop invariant 0 <= n_mod <= N;
        loop invariant n_mod % 500 == N % 500;
        loop assigns n_mod;
    */
    while (n_mod >= 500) {
        n_mod = n_mod - 500;
    }

    //@ assert n_mod == N % 500;
    return n_mod <= A;
}
