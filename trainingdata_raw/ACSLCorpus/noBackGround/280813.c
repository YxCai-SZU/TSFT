#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == (((n) / 100) == 7 || (((n) / 10) % 10) == 7 || ((n) % 10) == 7);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long n_100;
    unsigned long n_10;
    unsigned long n_1;
    bool result;

    //@ assert 0 <= n / 100 && n / 100 <= 9;
    //@ assert 0 <= (n / 10) % 10 && (n / 10) % 10 <= 9;
    //@ assert 0 <= n % 10 && n % 10 <= 9;

    n_100 = n / 100;
    n_10 = (n / 10) % 10;
    n_1 = n % 10;

    result = false;
    if (n_100 == 7 || n_10 == 7 || n_1 == 7)
    {
        result = true;
    }

    //@ assert result == (n_100 == 7 || n_10 == 7 || n_1 == 7);

    return result;
}
