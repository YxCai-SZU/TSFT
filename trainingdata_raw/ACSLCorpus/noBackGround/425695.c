#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (n % 100) * 21 <= n;
    ensures \result == 0 ==> (n % 100) * 21 > n;
*/
int func(int n)
{
    int n_mod_100;
    n_mod_100 = n;

    //@ ghost int original_n = n;

    /*@
        loop invariant 1 <= original_n && original_n <= 100000;
        loop invariant 0 <= n_mod_100;
        loop invariant n_mod_100 <= original_n;
        loop invariant n_mod_100 == original_n || n_mod_100 % 100 == original_n % 100;
        loop assigns n_mod_100;
        loop variant n_mod_100;
    */
    while (n_mod_100 >= 100)
    {
        n_mod_100 -= 100;
    }

    /*@
        loop invariant 1 <= original_n && original_n <= 100000;
        loop invariant n_mod_100 < 100;
        loop invariant n_mod_100 == original_n % 100 || n_mod_100 == original_n % 100 + 100;
        loop assigns n_mod_100;
        loop variant 100 + n_mod_100;
    */
    while (n_mod_100 < 0)
    {
        n_mod_100 += 100;
    }

    //@ assert n_mod_100 == original_n % 100;

    if (n_mod_100 * 21 <= n)
    {
        //@ assert (n % 100) * 21 <= n;
        return 1;
    }
    else
    {
        //@ assert (n % 100) * 21 > n;
        return 0;
    }
}
