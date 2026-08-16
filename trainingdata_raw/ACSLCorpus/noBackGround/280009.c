#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result >= 0;
    ensures \result <= 1;
    assigns \nothing;
*/
int func(int n, int k)
{
    int n_mod = n;
    int k_mod = k;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 1 <= k <= 100;
        loop invariant 0 <= n_mod <= n;
        loop invariant (((n_mod) % 2) == (n % 2));
        loop assigns n_mod;
        loop variant n_mod;
    */
    while (n_mod >= 2)
    {
        n_mod -= 2;
    }
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 1 <= k <= 100;
        loop invariant 0 <= k_mod <= k;
        loop invariant (((k_mod) % 2) == (k % 2));
        loop assigns k_mod;
        loop variant k_mod;
    */
    while (k_mod >= 2)
    {
        k_mod -= 2;
    }
    
    //@ assert n_mod == 0 || n_mod == 1;
    //@ assert k_mod == 0 || k_mod == 1;
    
    if ((n_mod == 1 && k_mod == 0) || (n_mod == 0 && k_mod == 1))
    {
        //@ assert n_mod == 1 && k_mod == 0 || n_mod == 0 && k_mod == 1;
        return 1;
    }
    else
    {
        //@ assert n_mod == 0 && k_mod == 0 || n_mod == 1 && k_mod == 1;
        return 0;
    }
}
