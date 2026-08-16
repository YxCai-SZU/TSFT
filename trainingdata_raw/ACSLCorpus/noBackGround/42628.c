#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 - a <= 0);
    assigns \nothing;
*/
bool func(int n, int a) {
    int n_mod_500;
    n_mod_500 = n;

    /*@
        loop invariant 0 <= n_mod_500 <= n;
        loop invariant n_mod_500 == n - 500 * ((n - n_mod_500) / 500);
        loop invariant (n - n_mod_500) % 500 == 0;
        loop assigns n_mod_500;
    */
    while (n_mod_500 >= 500) {
        //@ assert n_mod_500 - 500 >= 0;
        n_mod_500 -= 500;
    }

    //@ assert n_mod_500 == n % 500;

    if (n_mod_500 - a > 0) {
        //@ assert n % 500 - a > 0;
        return false;
    } else {
        //@ assert n % 500 - a <= 0;
        return true;
    }
}
