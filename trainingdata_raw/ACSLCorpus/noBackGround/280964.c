#include <limits.h>

/*@
    requires (1 <= (N) <= 10000);
    ensures (N % 1000 == 0 ==> \result == 0);
    ensures (N % 1000 != 0 ==> \result == 1000 - (N % 1000));
*/
int func(int N) {
    int n_mod_1000;
    int result;
    
    n_mod_1000 = N;

    //@ assert (1 <= (N) <= 10000);
    //@ assert n_mod_1000 >= 0 && n_mod_1000 <= N;
    //@ assert n_mod_1000 == N || n_mod_1000 % 1000 == N % 1000;

    /*@
        loop invariant 1 <= N <= 10000;
        loop invariant n_mod_1000 >= 0;
        loop invariant n_mod_1000 <= N;
        loop invariant n_mod_1000 == N || n_mod_1000 % 1000 == N % 1000;
        loop assigns n_mod_1000;
        loop variant n_mod_1000;
    */
    while (n_mod_1000 >= 1000) {
        //@ assert n_mod_1000 >= 1000;
        n_mod_1000 -= 1000;
        //@ assert n_mod_1000 >= 0 && n_mod_1000 <= N;
        //@ assert n_mod_1000 == N || n_mod_1000 % 1000 == N % 1000;
    }

    //@ assert n_mod_1000 < 1000;
    //@ assert n_mod_1000 == N % 1000 || n_mod_1000 == N % 1000 + 1000;

    /*@
        loop invariant 1 <= N <= 10000;
        loop invariant n_mod_1000 < 1000;
        loop invariant n_mod_1000 == N % 1000 || n_mod_1000 == N % 1000 + 1000;
        loop assigns n_mod_1000;
        loop variant 1000 + n_mod_1000;
    */
    while (n_mod_1000 < 0) {
        //@ assert n_mod_1000 < 0;
        n_mod_1000 += 1000;
        //@ assert n_mod_1000 < 1000;
        //@ assert n_mod_1000 == N % 1000 || n_mod_1000 == N % 1000 + 1000;
    }

    //@ assert n_mod_1000 == N % 1000;
    
    if (n_mod_1000 == 0) {
        result = 0;
        //@ assert N % 1000 == 0 ==> result == 0;
    } else {
        result = 1000 - n_mod_1000;
        //@ assert N % 1000 != 0 ==> result == 1000 - (N % 1000);
    }
    
    return result;
}
