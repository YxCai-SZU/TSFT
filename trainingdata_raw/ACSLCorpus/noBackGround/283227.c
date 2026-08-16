#include <stdbool.h>

/*@
    requires 100 <= n <= 999;
    ensures \result == true <==> ((n) % 10 == 7 || ((n) / 10) % 10 == 7 || ((n) / 100) % 10 == 7);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long n_100;
    unsigned long n_10;
    unsigned long n_1;
    bool result;

    n_100 = n / 100;
    n_10 = (n % 100) / 10;
    n_1 = n % 10;

    //@ assert n_100 == n / 100;
    //@ assert n_10 == (n % 100) / 10;
    //@ assert n_1 == n % 10;

    result = (n_100 == 7 || n_10 == 7 || n_1 == 7);
    return result;
}
