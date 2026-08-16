#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == (n / 10 == 9 || n % 10 == 9);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long n_10;
    unsigned long n_01;
    bool result;

    n_10 = n / 10;
    n_01 = n % 10;

    //@ assert n_10 == n / 10;
    //@ assert n_01 == n % 10;

    result = (n_10 == 9) || (n_01 == 9);
    return result;
}
