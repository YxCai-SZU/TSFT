#include <stdbool.h>

/*@
    requires 100 <= n && n <= 999;
    ensures \result == true <==> (((n) / 100) == 7 ||
        ((n) / 10 % 10) == 7 ||
        ((n) % 10) == 7);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long n_100;
    unsigned long n_10;
    unsigned long n_mod_10;
    unsigned long n_10_mod_10;
    bool result;

    n_100 = n / 100;
    n_10 = n / 10;
    n_mod_10 = n % 10;
    n_10_mod_10 = n_10 % 10;

    //@ assert n_100 == n / 100;
    //@ assert n_10_mod_10 == n / 10 % 10;
    //@ assert n_mod_10 == n % 10;

    if (n_100 == 7 || n_10_mod_10 == 7 || n_mod_10 == 7)
    {
        result = true;
        //@ assert (((n) / 100) == 7 ||         ((n) / 10 % 10) == 7 ||         ((n) % 10) == 7);
    }
    else
    {
        result = false;
        //@ assert !(((n) / 100) == 7 ||         ((n) / 10 % 10) == 7 ||         ((n) % 10) == 7);
    }

    return result;
}
