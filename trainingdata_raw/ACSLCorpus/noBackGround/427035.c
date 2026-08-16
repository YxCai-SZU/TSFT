#include <stdbool.h>

/*@
    requires (1000 <= (n) && (n) <= 9999);
    ensures \result == (n % 1110 < 10 || n % 1000 < 110 || n % 100 < 10 || n % 10 == 0);
*/
bool func(unsigned int n)
{
    unsigned int n_mod_1110;
    unsigned int n_mod_1000;
    unsigned int n_mod_100;
    unsigned int n_mod_10;
    bool result;

    n_mod_1110 = n % 1110;
    n_mod_1000 = n % 1000;
    n_mod_100 = n % 100;
    n_mod_10 = n % 10;

    //@ assert n_mod_1110 == ((n) % 1110);
    //@ assert n_mod_1000 == ((n) % 1000);
    //@ assert n_mod_100 == ((n) % 100);
    //@ assert n_mod_10 == ((n) % 10);

    if (n_mod_1110 < 10 || n_mod_1000 < 110 || n_mod_100 < 10 || n_mod_10 == 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
