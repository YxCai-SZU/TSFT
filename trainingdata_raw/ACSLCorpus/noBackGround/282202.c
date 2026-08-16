#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == ((n % 500) <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    unsigned int n_unsigned;
    unsigned int a_unsigned;
    unsigned int remainder;
    bool result;

    n_unsigned = n;
    a_unsigned = a;
    remainder = n_unsigned % 500;

    //@ assert ((remainder) == (n_unsigned) % 500);

    result = remainder <= a_unsigned;
    return result;
}
