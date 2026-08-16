#include <stdbool.h>

/*@
    requires 1 <= N <= 10000;
    requires 0 <= A <= 1000;
    ensures \result == ((N % 500) <= A);
*/
bool func(unsigned long N, unsigned long A)
{
    unsigned long n_mod_500;
    
    n_mod_500 = N;
    
    /*@
        loop invariant 0 <= n_mod_500 <= N;
        loop invariant ((n_mod_500) % 500 == (N) % 500);
        loop assigns n_mod_500;
    */
    while (n_mod_500 >= 500)
    {
        //@ assert n_mod_500 % 500 == N % 500;
        n_mod_500 -= 500;
        //@ assert n_mod_500 % 500 == N % 500;
    }
    
    //@ assert n_mod_500 == N % 500;
    return n_mod_500 <= A;
}
