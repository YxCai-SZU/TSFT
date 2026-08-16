#include <stdbool.h>

/*@
    requires 100 <= n <= 999;
    ensures \result == true <==> ((n) / 100 == 7 || ((n) / 10) % 10 == 7 || (n) % 10 == 7);
    assigns \nothing;
*/
bool func(int n)
{
    int n_100;
    int n_10;
    int n_mod_10;
    int n_mod_100;
    int n_mod_100_10;
    bool contains_seven;

    n_100 = n / 100;
    n_10 = n / 10;
    n_mod_10 = n - n_10 * 10;
    n_mod_100 = n - n_100 * 100;
    n_mod_100_10 = n_mod_100 / 10;
    contains_seven = false;

    if (n_100 == 7)
    {
        contains_seven = true;
    }
    //@ assert contains_seven == (n_100 == 7);

    if (n_mod_100_10 == 7)
    {
        contains_seven = true;
    }
    //@ assert contains_seven == (n_100 == 7 || n_mod_100_10 == 7);

    if (n_mod_10 == 7)
    {
        contains_seven = true;
    }
    //@ assert contains_seven == (n_100 == 7 || n_mod_100_10 == 7 || n_mod_10 == 7);

    return contains_seven;
}
