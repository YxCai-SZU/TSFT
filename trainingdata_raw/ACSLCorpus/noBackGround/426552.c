#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - (((n) / 15) * 200) - ((((n) % 15) / 5) * 20) - ((n) % 5));
    assigns \nothing;
*/
int func(int n)
{
    int n_div_15 = 0;
    int temp_n = n;
    int n_mod_15_div_5 = 0;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert n_div_15 >= 0;
    //@ assert temp_n >= 0;
    //@ assert n == temp_n + n_div_15 * 15;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant n_div_15 >= 0;
        loop invariant temp_n >= 0;
        loop invariant n == temp_n + n_div_15 * 15;
        loop invariant n_div_15 == (n - temp_n) / 15;
        loop assigns temp_n, n_div_15;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n = temp_n - 15;
        n_div_15 = n_div_15 + 1;
        //@ assert n == temp_n + n_div_15 * 15;
    }

    //@ assert n_mod_15_div_5 >= 0;
    //@ assert n == temp_n + n_div_15 * 15 + n_mod_15_div_5 * 5;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant n_div_15 >= 0;
        loop invariant temp_n >= 0;
        loop invariant n_mod_15_div_5 >= 0;
        loop invariant n == temp_n + n_div_15 * 15 + n_mod_15_div_5 * 5;
        loop invariant n_mod_15_div_5 == (n - n_div_15 * 15 - temp_n) / 5;
        loop assigns temp_n, n_mod_15_div_5;
        loop variant temp_n;
    */
    while (temp_n >= 5)
    {
        //@ assert temp_n >= 5;
        temp_n = temp_n - 5;
        n_mod_15_div_5 = n_mod_15_div_5 + 1;
        //@ assert n == temp_n + n_div_15 * 15 + n_mod_15_div_5 * 5;
    }

    //@ assert n_div_15 == n / 15;
    //@ assert n_mod_15_div_5 == (n % 15) / 5;
    //@ assert temp_n == n % 5;
    //@ assert n * 800 - n_div_15 * 200 - n_mod_15_div_5 * 20 - temp_n == ((n) * 800 - (((n) / 15) * 200) - ((((n) % 15) / 5) * 20) - ((n) % 5));
    return n * 800 - n_div_15 * 200 - n_mod_15_div_5 * 20 - temp_n;
}
