#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == true <==> ((n) / 100) == ((n) % 10);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long n_100;
    unsigned long n_10;
    bool result;

    //@ assert (100 <= (n) && (n) <= 999);
    n_100 = n / 100;
    n_10 = n % 10;

    if (n_100 != n_10) {
        //@ assert n_100 != n_10;
        result = false;
        return result;
    }

    //@ assert n_100 == n_10;
    result = true;
    return result;
}
