#include <stdbool.h>

/*@
    requires (10 <= (n) <= 99);
    ensures \result == (((n) / 10) == 9 || ((n) % 10) == 9);
*/
bool func(int n)
{
    int n_abs;
    int div;
    int temp;
    int mod_result;

    n_abs = n;
    //@ assert n_abs == n;
    if (n < 0)
    {
        n_abs = -n;
    }
    //@ assert n_abs == ((n) >= 0 ? (n) : -(n));

    //@ assert (10 <= (n_abs) <= 99);
    div = 0;
    temp = n_abs;

    /*@
        loop invariant 10 <= n_abs <= 99;
        loop invariant 0 <= temp <= n_abs;
        loop invariant temp == n_abs - 10 * div;
        loop invariant div >= 0;
        loop assigns temp, div;
    */
    while (temp >= 10)
    {
        //@ assert temp >= 10;
        temp -= 10;
        div += 1;
    }
    //@ assert temp == n_abs % 10;
    //@ assert div == n_abs / 10;

    mod_result = n_abs;
    /*@
        loop invariant 10 <= n_abs <= 99;
        loop invariant 0 <= mod_result <= n_abs;
        loop invariant mod_result == n_abs - 10 * ((n_abs - mod_result) / 10);
        loop invariant (n_abs - mod_result) % 10 == 0;
        loop assigns mod_result;
    */
    while (mod_result >= 10)
    {
        //@ assert mod_result >= 10;
        mod_result -= 10;
    }
    //@ assert mod_result == n_abs % 10;

    //@ assert div == ((n_abs) / 10);
    //@ assert mod_result == ((n_abs) % 10);
    return div == 9 || mod_result == 9;
}
