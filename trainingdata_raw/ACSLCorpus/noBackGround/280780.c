#include <stdbool.h>

/*@
    requires 100 <= n <= 999;
    ensures \result == true <==> (((n) / 100 == 7) || (((n) / 10) % 10 == 7) || ((n) % 10 == 7));
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int n_100;
    unsigned int n_10;
    unsigned int n_1;
    bool n_100_bool;
    bool n_10_bool;
    bool n_1_bool;
    bool result;

    n_100 = n / 100;
    n_10 = (n / 10) % 10;
    n_1 = n % 10;

    n_100_bool = (n_100 == 7);
    n_10_bool = (n_10 == 7);
    n_1_bool = (n_1 == 7);

    //@ assert n_100_bool == (n / 100 == 7);
    //@ assert n_10_bool == ((n / 10) % 10 == 7);
    //@ assert n_1_bool == (n % 10 == 7);

    result = n_100_bool || n_10_bool || n_1_bool;
    return result;
}
