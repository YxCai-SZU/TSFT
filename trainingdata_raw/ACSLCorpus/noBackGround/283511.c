#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> ((x) % 100) * 21 <= x;
    ensures \result == 0 ==> ((x) % 100) * 21 > x;
*/
int func(int x)
{
    int n_mod_100;
    n_mod_100 = x;

    /*@
        loop invariant (1 <= (x) <= 100000);
        loop invariant 0 <= n_mod_100;
        loop invariant n_mod_100 == x || n_mod_100 % 100 == x % 100;
        loop assigns n_mod_100;
        loop variant n_mod_100;
    */
    while (n_mod_100 >= 100)
    {
        //@ assert n_mod_100 >= 100;
        n_mod_100 -= 100;
    }

    /*@
        loop invariant (1 <= (x) <= 100000);
        loop invariant n_mod_100 < 100;
        loop invariant n_mod_100 == x % 100 || n_mod_100 == x % 100 + 100;
        loop assigns n_mod_100;
        loop variant 100 + n_mod_100;
    */
    while (n_mod_100 < 0)
    {
        //@ assert n_mod_100 < 0;
        n_mod_100 += 100;
    }

    //@ assert n_mod_100 == x % 100;
    
    if (n_mod_100 * 21 <= x)
    {
        //@ assert ((x) % 100) * 21 <= x;
        return 1;
    }
    else
    {
        //@ assert ((x) % 100) * 21 > x;
        return 0;
    }
}
