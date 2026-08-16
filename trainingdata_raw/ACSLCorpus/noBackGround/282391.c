#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    int n_mod = n;

    /*@
        loop invariant 0 <= n_mod <= n;
        loop invariant n_mod % 500 == n % 500;
        loop assigns n_mod;
    */
    while (n_mod >= 500)
    {
        n_mod -= 500;
    }

    //@ assert n_mod == n % 500;
    return n_mod <= a;
}
