#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == ((n / 10) == 9 || (n % 10) == 9);
    assigns \nothing;
*/
bool func(int n)
{
    int n_tens;
    int n_ones;
    bool result;

    n_tens = n / 10;
    n_ones = n % 10;

    //@ assert n_tens == n / 10;
    //@ assert n_ones == n % 10;

    result = (n_tens == 9) || (n_ones == 9);
    return result;
}
