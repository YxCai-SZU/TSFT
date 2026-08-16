#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == ((((n) / 100 == 7 || ((n) / 10) % 10 == 7 || (n) % 10 == 7) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int n_100;
    unsigned int n_10;
    unsigned int n_1;
    bool result;

    n_100 = n / 100;
    n_10 = (n / 10) % 10;
    n_1 = n % 10;

    //@ assert n_100 <= 9;
    //@ assert n_10 <= 9;
    //@ assert n_1 <= 9;

    if (n_100 == 7 || n_10 == 7 || n_1 == 7)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
