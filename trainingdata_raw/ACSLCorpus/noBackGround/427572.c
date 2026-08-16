#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == ((((n) / 100 == 7) || (((n) / 10) % 10 == 7) || ((n) % 10 == 7) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int n_100;
    unsigned int n_10;
    unsigned int n_1;

    //@ assert (100 <= (n) && (n) <= 999);
    n_100 = n / 100;
    n_10 = (n / 10) % 10;
    n_1 = n % 10;

    //@ assert n_100 == n / 100;
    return (n_100 == 7) || (n_10 == 7) || (n_1 == 7);
}
