#include <limits.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == 0 || \result == 1 || \result == 2;
    ensures \result == 0 ==> n % 3 == 0;
    ensures \result == 1 ==> n % 3 == 1;
    ensures \result == 2 ==> n % 3 == 2;
*/
int func(int n)
{
    int n_mod_3;
    
    n_mod_3 = n;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= n_mod_3 <= n;
        loop invariant n_mod_3 == n || n_mod_3 % 3 == n % 3;
        loop assigns n_mod_3;
        loop variant n_mod_3;
    */
    while (n_mod_3 >= 3)
    {
        //@ assert n_mod_3 >= 3;
        n_mod_3 = n_mod_3 - 3;
    }
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant -2 <= n_mod_3 < 3;
        loop invariant n_mod_3 == n % 3;
        loop assigns n_mod_3;
        loop variant 3 + n_mod_3;
    */
    while (n_mod_3 < 0)
    {
        //@ assert n_mod_3 < 0;
        n_mod_3 = n_mod_3 + 3;
    }
    
    //@ assert 0 <= n_mod_3 <= 2;
    //@ assert n_mod_3 == n % 3;
    return n_mod_3;
}
